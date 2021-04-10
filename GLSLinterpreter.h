/*{ "clmagic/opengl/GLSLinterpreter":{
  "Author":"LongJiangnan",
  "Date":"2021",
  "License":"Please identify Author"
} }*/
#pragma once


#include <map>
#include <list>
#include <string>
#include <fstream>
#include <filesystem>
#include <regex>
#include <algorithm>

/* { preprocess } */
class GLSLpreprocessor {
public:
	std::list<std::filesystem::path> _My_includes;
	std::map<std::filesystem::path, std::string> _My_sources;

	GLSLpreprocessor() = default;

	explicit GLSLpreprocessor(const std::filesystem::path& source_path, const std::map<std::string,std::string>& macros = {}) {
		preprocess_includefile(source_path, read_file(source_path));
		preprocess_replacemacros(macros);
	}

	explicit GLSLpreprocessor(const std::string& source, const std::map<std::string,std::string>& macros = {}){
		preprocess_includefile("", source);
		preprocess_replacemacros(macros);
	}
	
	static std::string read_file(const std::filesystem::path& _Path) {
		if ( !std::filesystem::exists(_Path) ) {
			std::string _Message = "GLSLpreprocessor::read_file::NotFoundFile" + _Path.string();
			throw std::exception(_Message.c_str());
		}

		std::string _Source;
		std::ifstream _Fin;
		_Fin.open(_Path.string());
		_Fin.seekg(0, std::ios::end);
		_Source.resize(size_t(_Fin.tellg()), ' ');
		_Fin.seekg(std::ios::beg);
		_Fin.read(&_Source[0], _Source.size());
		_Fin.close();
		return std::move(_Source);
	}

	void preprocess_includefile(const std::filesystem::path& source_path, const std::string& source) {
		std::regex include_model = std::regex("[#]include(\\s*)[\"](.+)[\"]");

		// find all-format[ #include(\s*)"the_path" ], and recursive processing
		std::vector<std::pair<size_t, size_t>> exprviews;
		std::string_view content = std::string_view(source.data(), source.size());
		while (true) {
			size_t include_first = content.find("#include");
			if ( include_first == std::string::npos ) {
				break;
			}

			size_t include_mid = content.find("\"", include_first);
			if ( include_mid == std::string::npos ) {
				throw std::exception("GLSLpreprocessor::preprocess_includefile::SyntaxError");
			}

			size_t include_last = content.find("\"", include_mid + 1);
			if ( include_mid == std::string::npos ) {
				throw std::exception("GLSLpreprocessor::preprocess_includefile::SyntaxError");
			}

			std::string_view includeexpr = content.substr(include_first, include_last-include_first + 1);
			if ( !std::regex_match(includeexpr.begin(), includeexpr.end(), include_model) ) {
				throw std::exception("GLSLpreprocessor::preprocess_includefile::SyntaxError");
			}

			std::string_view filenameexpr = content.substr(include_mid, include_last - include_mid);
			filenameexpr = filenameexpr.substr(1);
			auto filename_first = std::find_if_not(filenameexpr.begin(), filenameexpr.end(), isspace);
			auto filename_last = std::find_if_not(filenameexpr.rbegin(), filenameexpr.rend(), isspace).base();
			if (std::distance(filename_first, filename_last) == 0) {
				throw std::exception("GLSLpreprocessor::preprocess_includefile::SyntaxError");
			}

			auto the_path = std::filesystem::path(filename_first, filename_last);
			auto the_project_related_path = source_path.parent_path() / the_path;
			if (the_project_related_path == source_path) {
				throw std::exception("GLSLpreprocessor::preprocess_includefile::SyntaxError::Recursive");
			}
			if (std::find(_My_includes.begin(), _My_includes.end(), the_project_related_path) == _My_includes.end()) {
				this->preprocess_includefile(the_project_related_path, read_file(the_project_related_path));
			}

			content = content.substr(include_last);
			exprviews.push_back({ std::distance(source.data(),includeexpr.data()), includeexpr.size() });
		}

		// erase all includeexpr
		std::string copied_source = source;
		for (auto first = exprviews.rbegin(), last = exprviews.rend(); first != last; ++first) {
			copied_source.erase(first->first, first->second);
		}
		
		// push_back the sourcefile and source
		_My_includes.push_back(source_path);
		_My_sources.insert_or_assign(source_path, std::move(copied_source));
	}

	void preprocess_replacemacros(const std::map<std::string,std::string>& macros) {
		if (macros.empty()) {
			return;
		}
		
		for (const auto& macro_pair : macros) {
			// construct regex-expression
			std::regex macro_model = std::regex{
				"("
					"[#]define(\\s+)" + macro_pair.first + "(.*)[\\\\](\\s*)[\n]"
					"((.*)[\\\\](\\s*)[\n])*"
					"(.*)[\n]"
				")"
				"|("
					"[#]define(\\s+)" + macro_pair.first + "(.*)"
				")"
				};
			for (auto& source_pair : _My_sources) {
				// for each check syntax
				std::smatch result;
				if ( std::regex_search(source_pair.second, result, macro_model) ) {
					source_pair.second.erase(result.position(), result.length());
					// replace all-macroexpr
					while (true) {
						size_t finded = source_pair.second.rfind(macro_pair.first);
						if (finded == std::string::npos) {
							break;
						}

						source_pair.second.replace(finded, macro_pair.first.size(), macro_pair.second);
					}
				}
			}
		}
	}

	void clear() {
		_My_includes.clear();
		_My_sources.clear();
	}

	std::string source() const {
		std::string result;
		std::for_each(_My_includes.begin(), _My_includes.end(),
			[&result, this](const std::filesystem::path& the_path) {
				result += _My_sources.find(the_path)->second;
				result += '\n'; });
		return std::move(result);
	}
};

/* { intepret } */
class GLSLinformation {
public:
	struct VaryingRegisterLayout {
		std::map<std::string, std::string> qualifers;
		std::string type;
		std::string name;
	};

	struct UniformRegisterLayout {
		std::map<std::string, std::string> qualifers;
		std::string type;
		std::string name;
	};

	struct UniformBlockRegisterLayout {
		std::map<std::string, std::string> qualifers;
		std::string name;
		std::map<std::string, UniformRegisterLayout> members;
	};

	std::map<std::string, VaryingRegisterLayout> varyings;
	std::map<std::string, UniformRegisterLayout> uniforms;
	std::map<std::string, UniformBlockRegisterLayout> uniformblocks;

	GLSLinformation() = default;

	explicit GLSLinformation(const std::string& source) {
		this->reset(source);
	}

	template<typename _BidIt>
	static void _Decomposite_layoutexpression(_BidIt __first, _BidIt __last, std::map<std::string,std::string>& __dest) {
		// create regex-expression
		std::regex qualifier_model = std::regex("((\\w+)(\\s*)[=](\\s*)(\\w+))|(\\w+)");
		std::regex name_or_value_model = std::regex("\\w+");

		// create regex-iterator
		std::regex_iterator<_BidIt> first = std::regex_iterator<_BidIt>(__first, __last, qualifier_model);
		std::regex_iterator<_BidIt> last;
		for ( ; first != last; ++first) {
			// reference each qualifier-expression
			std::string_view qualifier_expression = std::string_view((*first)[0].first, (*first)[0].second);
			
			// intepret the qualifier-expression
			if ( qualifier_expression.find('=') == std::string::npos ) {
				__dest.insert_or_assign(std::string(qualifier_expression), "");
			} else {
				auto name_first = qualifier_expression.begin();
				auto name_last  = std::find_if(qualifier_expression.begin(), qualifier_expression.end(), [](char ch) { return isspace(ch) || ch == '='; });
				auto value_first = qualifier_expression.rbegin();
				auto value_last  = std::find_if(qualifier_expression.rbegin(), qualifier_expression.rend(), [](char ch) { return isspace(ch) || ch == '='; });
				__dest.insert_or_assign(std::string(name_first, name_last), std::string(value_first, value_last));
			}
		}
	}

	template<typename _BidIt>/* same as _Decomposite_uniformexpression */
	static void _Decomposite_varyingexpression(_BidIt __first, _BidIt __last, std::map<std::string,VaryingRegisterLayout>& __dest) {
		std::regex varying_model = std::regex{
			"layout(\\s*)"
			"[(]"
				"("
					"((\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "((\\s*)(\\w+)(\\s*))"
				")"
				"("
					"([,](\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "([,](\\s*)(\\w+)(\\s*))"
				")*"
			"[)](\\s*)"
			"in(\\s+)(\\w+)(\\s+)(\\w+)(\\s*);" 
			};
		std::regex layout_model = std::regex{
			"layout(\\s*)"
			"[(]"
				"("
					"((\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "((\\s*)(\\w+)(\\s*))"
				")"
				"("
					"([,](\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "([,](\\s*)(\\w+)(\\s*))"
				")*"
			"[)]"
			};

		// create regex-iterator
		std::regex_iterator<_BidIt> first = std::regex_iterator<_BidIt>(__first, __last, varying_model);
		std::regex_iterator<_BidIt> last;
		for ( ; first != last; ++first) {
			VaryingRegisterLayout varying_information;

			// reference each member-expression
			std::string_view varyingexpr = std::string_view((*first)[0].first, (*first)[0].second);

			// intepret layout-qualifiers from the member-expression
			std::match_results<std::string_view::const_iterator> the_layout;
			if ( std::regex_search(varyingexpr.begin(), varyingexpr.end(), the_layout/*_Dest*/, layout_model) ) {
				_Decomposite_layoutexpression(
					the_layout[0].first + strlen("layout"),
					the_layout[0].second,
					varying_information.qualifers/*_Dest*/
					);
			}

			// intepret type and name from the member-expression
			varyingexpr = varyingexpr.substr( the_layout.length() );
			varyingexpr = varyingexpr.substr( varyingexpr.find('i') + strlen("in") );
			auto type_first = std::find_if_not(varyingexpr.begin(), varyingexpr.end(), isspace);
			auto type_last  = std::find_if(type_first, varyingexpr.end(), isspace);
			auto name_first = std::find_if_not(type_last, varyingexpr.end(), isspace);
			auto name_last  = std::find_if(name_first, varyingexpr.end(), [](char ch){ return isspace(ch) || ch == ';'; });
			varying_information.type = std::string(type_first, type_last);
			varying_information.name = std::string(name_first, name_last);

			// ouput the information
			__dest.insert_or_assign(varying_information.name, varying_information);
		}
	}

	template<typename _BidIt>/* same as _Decomposite_varyingexpression */
	static void _Decomposite_uniformexpression(_BidIt __first, _BidIt __last, std::map<std::string,UniformRegisterLayout>& __dest) {
		// create regex-expression
		std::regex uniform_model = std::regex{
			"("
				"layout(\\s*)"
				"[(]"
					"("
						"((\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "((\\s*)(\\w+)(\\s*))"
					")"
					"("
						"([,](\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "([,](\\s*)(\\w+)(\\s*))"
					")*"
				"[)](\\s*)"
			")?"
			"uniform(\\s+)(\\w+)(\\s+)(\\w+)(\\s*);" 
			};
		std::regex layout_model = std::regex{
			"layout(\\s*)"
			"[(]"
				"("
					"((\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "((\\s*)(\\w+)(\\s*))"
				")"
				"("
					"([,](\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "([,](\\s*)(\\w+)(\\s*))"
				")*"
			"[)]"
			};

		// create regex-iterator
		std::regex_iterator<_BidIt> first = std::regex_iterator<_BidIt>(__first, __last, uniform_model);
		std::regex_iterator<_BidIt> last;
		for ( ; first != last; ++first) {
			UniformRegisterLayout uniform_information;

			// reference each member-expression
			std::string_view uniformexpr = std::string_view((*first)[0].first, (*first)[0].second);

			// intepret layout-qualifiers from the member-expression
			std::match_results<std::string_view::const_iterator> the_layout;
			if ( std::regex_search(uniformexpr.begin(), uniformexpr.end(), the_layout/*_Dest*/, layout_model) ) {
				_Decomposite_layoutexpression(
					the_layout[0].first + strlen("layout"),
					the_layout[0].second,
					uniform_information.qualifers/*_Dest*/
					);
			}

			// intepret type and name from the member-expression
			uniformexpr = uniformexpr.substr( the_layout.length() );
			uniformexpr = uniformexpr.substr( uniformexpr.find('u') + strlen("uniform") );
			auto type_first = std::find_if_not(uniformexpr.begin(), uniformexpr.end(), isspace);
			auto type_last  = std::find_if(type_first, uniformexpr.end(), isspace);
			auto name_first = std::find_if_not(type_last, uniformexpr.end(), isspace);
			auto name_last  = std::find_if(name_first, uniformexpr.end(), [](char ch){ return isspace(ch) || ch == ';'; });
			uniform_information.type = std::string(type_first, type_last);
			uniform_information.name = std::string(name_first, name_last);

			// ouput the information
			__dest.insert_or_assign(uniform_information.name, uniform_information);
		}
	}

	template<typename _BidIt>
	static void _Decomposite_uniformblockexpression(_BidIt __first, _BidIt __last, std::map<std::string,UniformBlockRegisterLayout>& __dest) {
		// create regex-expression
		std::regex uniformblock_model = std::regex{
			"("
				"layout(\\s*)"
				"[(]"
					"("
						"((\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "((\\s*)(\\w+)(\\s*))"
					")"
					"("
						"([,](\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "([,](\\s*)(\\w+)(\\s*))"
					")*"
				"[)](\\s*)"
			")?"
			"uniform(\\s+)(\\w+)(\\s*)"
			"[{](\\s*)"
				"("
					"("
						"layout(\\s*)"
						"[(]"
							"("
								"((\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "((\\s*)(\\w+)(\\s*))"
							")"
							"("
								"([,](\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "([,](\\s*)(\\w+)(\\s*))"
							")*"
						"[)](\\s*)"
					")?"
					"(\\w+)(\\s+)(\\w+)(\\s*);(\\s*)"
				")+"
			"[}](\\s*);"
			};
		std::regex blockmember_model = std::regex{
			"("
				"layout(\\s*)"
				"[(]"
					"("
						"((\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "((\\s*)(\\w+)(\\s*))"
					")"
					"("
						"([,](\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "([,](\\s*)(\\w+)(\\s*))"
					")*"
				"[)](\\s*)"
			")?"
			"(\\w+)(\\s+)(\\w+)(\\s*);"
			};
		std::regex layout_model = std::regex{
			"layout(\\s*)"
			"[(]"
				"("
					"((\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "((\\s*)(\\w+)(\\s*))"
				")"
				"("
					"([,](\\s*)(\\w+)(\\s*)[=](\\s*)(\\w+)(\\s*))" "|" "([,](\\s*)(\\w+)(\\s*))"
				")*"
			"[)]"
			};

		// create regex-iterator to match uniformblock
		std::regex_iterator<_BidIt> _Bfirst = std::regex_iterator<_BidIt>(__first, __last, uniformblock_model);
		std::regex_iterator<_BidIt> _Blast;
		for ( ; _Bfirst != _Blast; ++_Bfirst) {
			UniformBlockRegisterLayout block_information;
			
			// reference each uniformblock-expression
			std::string_view blockexpr = std::string_view((*_Bfirst)[0].first, (*_Bfirst)[0].second);

			// intepret layout-qualifiers from the uniformblock-expression
			std::match_results<std::string_view::const_iterator> the_layout;
			if ( std::regex_search(blockexpr.begin(), blockexpr.end(), the_layout/*_Dest*/, layout_model) ) {
				_Decomposite_layoutexpression(
					the_layout[0].first + strlen("layout"),
					the_layout[0].second,
					block_information.qualifers/*_Dest*/
					);
			}

			// intepret name from the uniformblock-expression
			blockexpr = blockexpr.substr( the_layout.length() );
			blockexpr = blockexpr.substr( blockexpr.find('u') + strlen("uniform") );
			auto name_first  = std::find_if_not(blockexpr.begin(), blockexpr.end(), isspace);
			auto name_last   = std::find_if(name_first, blockexpr.end(), [](char ch) { return isspace(ch) || ch == '{'; });
			block_information.name = std::string(name_first, name_last);
			
			// intepret members from the uniformblock-expression
			blockexpr = blockexpr.substr( blockexpr.find('{') );
			auto _Mfirst = std::regex_iterator<std::string_view::const_iterator>(blockexpr.begin(), blockexpr.end(), blockmember_model);
			auto _Mlast = decltype(_Mfirst)();
			for ( ; _Mfirst != _Mlast; ++_Mfirst) {
				UniformRegisterLayout uniform_information;

				// reference each member-expression
				std::string_view memberexpr = std::string_view((*_Mfirst)[0].first, (*_Mfirst)[0].second);

				// intepret layout-qualifiers from the member-expression
				std::match_results<std::string_view::const_iterator> the_layout;
				if ( std::regex_search(memberexpr.begin(), memberexpr.end(), the_layout/*_Dest*/, layout_model) ) {
					_Decomposite_layoutexpression(
						the_layout[0].first + strlen("layout"),
						the_layout[0].second,
						uniform_information.qualifers/*_Dest*/
						);
				}

				// intepret type and name from the member-expression
				memberexpr = memberexpr.substr( the_layout.length() );
				auto type_first = std::find_if_not(memberexpr.begin(), memberexpr.end(), isspace);
				auto type_last  = std::find_if(type_first, memberexpr.end(), isspace);
				auto name_first = std::find_if_not(type_last, memberexpr.end(), isspace);
				auto name_last  = std::find_if(name_first, memberexpr.end(), [](char ch){ return isspace(ch) || ch == ';'; });
				uniform_information.type = std::string(type_first, type_last);
				uniform_information.name = std::string(name_first, name_last);

				// ouput
				block_information.members.insert_or_assign(uniform_information.name, uniform_information);
			}

			// output the information
			__dest.insert_or_assign(block_information.name, block_information);
		}
	}

	void clear() {
		this->varyings.clear();
		this->uniforms.clear();
		this->uniformblocks.clear();
	}

	void reset(const std::string& source) {
		this->varyings.clear();
		this->uniforms.clear();
		this->uniformblocks.clear();
		_Decomposite_varyingexpression(source.begin(), source.end(), this->varyings);
		_Decomposite_uniformexpression(source.begin(), source.end(), this->uniforms);
		_Decomposite_uniformblockexpression(source.begin(), source.end(), this->uniformblocks);
	}

	void merge_from(const GLSLinformation& right) {
		for (const auto& varying : right.varyings) {
			if ( !this->varyings.contains(varying.first) ) {
				this->varyings.insert(varying);
			}
		}
		for (const auto& uniform : right.uniforms) {
			if (!this->uniforms.contains(uniform.first)) {
				this->uniforms.insert(uniform);
			}
		}
		for (const auto& uniformblock : right.uniformblocks) {
			if (!this->uniformblocks.contains(uniformblock.first)) {
				this->uniformblocks.insert(uniformblock);
			}
		}
	}
};

/*
std::cout << "layout(binding = 1) Ablock" << '\n'
	<< "not have body\t" << std::regex_search("layout(binding = 1) Ablock", block_model) << "\n\n";
std::cout << "layout(binding = 1) { \n  asdasd;\n};" << '\n'
	<< "not have name\t"<< std::regex_search("layout(binding = 1) { \n  asdasd;};", block_model) << "\n\n";
std::cout << "layout(binding = 1) Ablock{ int asdasd; };" << '\n'
	<< "correct block\t" << std::regex_search("layout(binding = 1) Ablock{ int asdasd; };", block_model) << "\n\n";

std::cout << "layout(binding = 1) uniform sampler3D scatteringtexture;" << '\n'
	<< "correct sampler\t" << std::regex_search("layout(binding = 1) uniform sampler3D scatteringtexture;", sampler_model) << "\n\n";
std::cout << "layout(binding = 1) uniform image2D precomputation_result;" << '\n'
	<< "correct image\t" << std::regex_search("layout(binding = 1) uniform image2D precomputation_result;", image_model) << "\n\n";

std::cout << "layout(binding = 1) uniform vec2 sunsize;" << '\n'
	<< "qualifer error\t" << std::regex_search("layout(binding = 1) uniform vec2 sunsize;", uniformvar_model) << "\n\n";
std::cout << "layout(location = 1) uniform vec2 sunsize;" << '\n'
	<< "correct uniformvar\t" << std::regex_search("layout(location = 1) uniform vec2 sunsize;", uniformvar_model) << "\n\n";
std::cout << "layout(location = 1) uniform vec2 sunsize = vec2(0.0057, 0.000314);" << '\n'
	<< "correct uniformvar\t" << std::regex_search("layout(location = 1) uniform vec2 sunsize = vec2(0.0057, 0.000314);", uniformvar_model) << "\n\n";

std::cout << "layout(location = 1) in vec2 position = vec2(50.0, 50.0);" << '\n'
	<< "cannot explicit assign\t" << std::regex_search("layout(location = 1) in vec2 position = vec2(50.0, 50.0);", varying_model) << "\n\n";
std::cout << "layout(location = 1) in vec2 position ;" << '\n'
	<< "correct inputlayout\t" << std::regex_search("layout(location = 1) in vec2 position ;", varying_model) << "\n\n";
*/