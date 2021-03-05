/* clmagic/opengl/GLhighestlevel:{
	Author:"LongJiangnan",
	Date:"2021",
	Owner:"LongJiangnan",
	License:"PI(Please identify the Owner)"
} */
#pragma once


#include "GLhighlevel.h"

class GLgeometry {
public:
	GLbuffer vertex_data;
	std::vector<GLvarying_register> 
			vertex_structure;
	GLsizei vertex_count = 0;
	GLenum primitive_type;

	virtual bool match(const GLprogram& program) {
		if (program.inputlayout.size() != this->vertex_structure.size()) {
			return false;
		}

		for (size_t i = 0; i != program.inputlayout.size(); ++i) {
			if (program.inputlayout[i].size != this->vertex_structure[i].size) {
				return false;
			}
			if (program.inputlayout[i].type != this->vertex_structure[i].type) {
				return false;
			}
			if (program.inputlayout[i].normalized != this->vertex_structure[i].normalized) {
				return false;
			}
		}

		return true;
	}
};

class GLgeometry_indexed : public GLgeometry {
public:
	// index property
	GLbuffer index_data;
	GLenum   index_type = GL_UNSIGNED_INT;
	GLsizei  index_count = 0;
};

class GLmaterial {
public:
	std::map<std::string, 
		std::pair<std::shared_ptr<GLbuffer>, GLint>> _My_ublocks;
	std::map<std::string, 
		std::pair<std::shared_ptr<GLtexture>, GLint>> _My_textures;

	GLmaterial() = default;

	GLmaterial(std::initializer_list<std::pair<std::string, std::shared_ptr<GLtexture>>> textures) {
		for (auto& texture_pair : textures) {
			_My_textures.insert_or_assign(
				texture_pair.first, 
				std::pair(texture_pair.second, GLint(-1))
				);
		}
	}

	bool match(const GLprogram& program) {
		// match uniform-blocks and get (GLint)block-binding
		for (auto& block : _My_ublocks) {
			auto _Finded = program.information.uniformblocks.find(block.first);
			if ( _Finded == program.information.uniformblocks.end() ) {
				throw std::exception();
			}

			auto _Finded_binding = _Finded->second.qualifers.find("binding");
			if ( _Finded_binding != _Finded->second.qualifers.end() ) {
				block.second.second = std::atoi(_Finded_binding->second.c_str());
			} else {
				auto& gl = *reinterpret_cast<GLcontext330*>(program._Mydeleter);
				block.second.second = gl.GetUniformBlockIndex(program, block.first.c_str());
			}
		}

		// match textureXDs and get (GLint)texture-binding
		size_t unbinding_count = 0;
		for (auto& texture : _My_textures) {
			auto _Finded = program.information.uniforms.find(texture.first);
			if ( _Finded == program.information.uniforms.end() ) {
				throw std::exception();
			}
			if ( !_Finded->second.type.starts_with("sampler") ) {
				throw std::exception();
			}

			auto _Finded_binding = _Finded->second.qualifers.find("binding");
			if ( _Finded_binding != _Finded->second.qualifers.end() ) {
				texture.second.second = std::atoi(_Finded_binding->second.c_str());
			}
		}

		// match textureXDs ...
		if (unbinding_count == 0) {
			// do nothing
		} else if (unbinding_count != _My_textures.size()) {
			throw std::exception();
		} else {
			auto& gl = *reinterpret_cast<GLcontext330*>(program._Mydeleter);
			GLuint binding = 0;
			for (auto& texture : _My_textures) {
				gl.Uniform1i( gl.GetUniformLocation(program, texture.first.c_str()), binding );
				texture.second.second = binding;
			}
		}

		return true; 
	}

	bool connect(const std::string& slotname, std::shared_ptr<GLtexture> texture) {
		if (_My_ublocks.find(slotname) != _My_ublocks.end()) {
			throw std::exception("GLMaterial::connect(slotname, texture){ redefined_slotname }");
		}

		auto inserted_pos = _My_textures.find(slotname);
		if (inserted_pos == _My_textures.end()) {
			_My_textures.insert_or_assign(slotname, std::pair{ texture, GLint(-1) });
		} else {
			inserted_pos->second.first = texture;
		}

		return true;
	}

	bool connect(const std::string& slotname, std::shared_ptr<GLbuffer> ublock) {
		if (_My_textures.find(slotname) != _My_textures.end()) {
			throw std::exception("GLMaterial::connect(slotname, ublock){ redefined_slotname }");
		}

		auto inserted_pos = _My_ublocks.find(slotname);
		if (inserted_pos == _My_ublocks.end()) {
			_My_ublocks.insert_or_assign(slotname, std::pair{ ublock, GLint(-1) });
		} else {
			inserted_pos->second.first = ublock;
		}

		return true;
	}

	bool connect(std::initializer_list<std::pair<std::string, std::shared_ptr<GLtexture>>> textures) {
		bool result;
		for (auto& texture_pair : textures) {
			result &= this->connect(texture_pair.first, texture_pair.second);
		}

		return result;
	}

	bool connect(std::initializer_list<std::pair<std::string, std::shared_ptr<GLbuffer>>> ublocks) {
		bool result;
		for (auto& ublock_pair : ublocks) {
			result &= this->connect(ublock_pair.first, ublock_pair.second);
		}

		return result;
	}

	void disconnect(const std::string slotname) {
		_My_textures.erase(slotname);
		_My_ublocks.erase(slotname);
	}

	void disconnect(std::initializer_list<std::string> slotnames) {
		for (const std::string& slotname : slotnames) {
			this->disconnect(slotname);
		}
	}
};

//using _ContextTy = GLcontext420;
template<typename _ContextTy = GLcontext420>
class GLhighestlevel : public GLhighlevel<_ContextTy> {
	using _Mybase = GLhighlevel<_ContextTy>;
public:
	explicit GLhighestlevel(HDC device) : _Mybase(device) {}

	template<typename Vertex>
	void CreateGeometry(
		const std::vector<GLvarying_register>& vertex_structure, const Vertex* vertex_data, size_t vertex_count, GLenum vertex_data_usage,
		GLenum primitive_type, 
		GLgeometry& geometry
	) {
		_Mybase::CreateBuffer(GL_ARRAY_BUFFER, vertex_data_usage, sizeof(Vertex) * vertex_count,
			std::ref(geometry.vertex_data));
		_Mybase::BindBuffer(geometry.vertices, GPUlocation(GL_ARRAY_BUFFER));
		_Mybase::UploadBuffer(vertex_data, GPUlocation(GL_ARRAY_BUFFER));
		geometry.vertex_structure = vertex_structure;
		geometry.vertex_count = vertex_count;
		geometry.primitive_type = primitive_type;
	}

	template<typename Vertex, typename Integer>
	void CreateGeometry(
		const std::vector<GLvarying_register>& vertex_structure, const Vertex* vertex_data, size_t vertex_count, GLenum vertex_data_usage,
		const Integer* index_data, size_t index_count, GLenum index_data_usage,
		GLenum primitive_type,
		GLgeometry_indexed& geometry
	) {
		CreateGeometry(vertex_structure, vertex_data, vertex_count, vertex_data_usage, 
			primitive_type, 
			std::ref(geometry) );

		_Mybase::CreateBuffer(GL_ELEMENT_ARRAY_BUFFER, index_data_usage, sizeof(Integer) * index_count,
			std::ref(geometry.index_data));
		_Mybase::BindBuffer(geometry.index_data, GPUlocation(GL_ELEMENT_ARRAY_BUFFER));
		_Mybase::UploadBuffer(index_data, GPUlocation(GL_ELEMENT_ARRAY_BUFFER));
		geometry.index_type = (sizeof(Integer) == 2) 
							? GL_UNSIGNED_SHORT 
							: (sizeof(Integer) == 4 ? GL_UNSIGNED_INT : 0);
		geometry.index_count = index_count;
	}

	void BindMaterial(const GLmaterial& material) {
		for (const auto& buffer_pair : material._My_ublocks) {
		#ifdef  _DEBUG
			if (buffer_pair.second.first == nullptr) { 
				continue;
			}
		#endif
			_Mybase::BindBuffer(
				*buffer_pair.second.first, 
				GPUlocationi(GL_UNIFORM_BUFFER, buffer_pair.second.second)
				);
		}

		for (const auto& texture_pair : material._My_textures) {
		#ifdef  _DEBUG
			if (texture_pair.second.first == nullptr) {
				continue;
			}
		#endif
			_Mybase::BindTexture(
				*texture_pair.second.first, 
				GPUlocationi(texture_pair.second.first->target, texture_pair.second.second)
				);
		}
	}

	void DrawGeometry(const GLgeometry& geometry) {
		_Mybase::BindBuffer(geometry.vertex_data, GPUlocation(GL_ARRAY_BUFFER));
		_Mybase::DrawArrays(geometry.primitive_type, 0, geometry.vertex_count);
	}

	void DrawGeometry(const GLgeometry_indexed& geometry) {
		_Mybase::BindBuffer(geometry.vertex_data, GPUlocation(GL_ARRAY_BUFFER));
		_Mybase::BindBuffer(geometry.index_data, GPUlocation(GL_ELEMENT_ARRAY_BUFFER));
		_Mybase::DrawElements(geometry.primitive_type, geometry.index_count, geometry.index_type, nullptr);
	}

	template<typename _Iter, typename _Fn1, typename _Fn2>
	void DrawObjects(const GLprogram& renderer, _Iter object_first, _Iter object_last, _Fn1 setup_function, _Fn2 render_function) {
		// setup processor
		_Mybase::BindProgram(renderer);
		// set some global-property to processor
		setup_function(renderer, *this);
		// processor(render) objects...
		for ( ; object_first != object_last; ++object_first) {
			render_function(*object_first);
		}
	}
};