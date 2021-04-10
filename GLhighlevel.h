/* clmagic/opengl/GLhighlevel:{
	Author:"LongJiangnan",
	Date:"2021",
	License:"Please identify Author"
} */
#pragma once


#include "GLcontext.h"
#include <vector>
#include <map>

// { GPUmemory[bytesize], ArrayBuffer, ElementArrayBuffer, AtomicCounterBuffer, TransformFeedbackBuffer }
class GLbuffer {
public:
	GLuint  identifier = GL_INVALID_INDEX;
	GLenum  target    = GL_NONE;
	GLsizei bytesize = 0;
	GLenum  usage  = GL_NONE;
	GLhighlevelCommandInterface* _Mydeleter = nullptr;

	GLbuffer() = default;

	GLbuffer(const GLbuffer&) = delete;
	
	GLbuffer(GLbuffer&& right) noexcept {
		right.swap(*this);
		right.release();
	}
		
	~GLbuffer() { this->release(); }
	
	GLbuffer& operator=(const GLbuffer&) = delete;

	GLbuffer& operator=(GLbuffer&& right) noexcept {
		right.swap(*this);
		right.release();
		return *this;
	}
	
	GLboolean operator==(const GLbuffer& right) const {
		return identifier == right.identifier;
	}
	
	GLboolean operator!=(const GLbuffer& right) const {
		return identifier != right.identifier;
	}
	
	operator GLuint() const {
		return identifier;
	}

	void release() {
		if (_Mydeleter) {
			_Mydeleter->DeleteBuffer(*this);
		}
	}
	
	void swap(GLbuffer& right) {
		std::swap(identifier, right.identifier);
		std::swap(target, right.target);
		std::swap(usage, right.usage);
		std::swap(bytesize, right.bytesize);
	}
};

// { OnlyRead Image }
struct GLconstimage {
	GLenum format = GL_RGBA;
	GLenum type = GL_UNSIGNED_BYTE;
	const void* __pixels = nullptr;
	const void* pixels() const { return __pixels; }
};

// { ReadWrite Image }
struct GLimage : GLconstimage {
	void* pixels() const { return const_cast<void*>(GLconstimage::__pixels); }
};

// { GPUmemory[width*height*depth] }
class GLtexture {
public:
	GLuint identifier = GL_INVALID_INDEX;
	GLenum  target = GL_NONE;
	GLenum  format = GL_NONE;// internalformat
	GLsizei width  = 0;
	GLsizei height = 0;
	GLsizei depth  = 0;
	GLint  samples   = 0;
	GLenum wrapx     = GL_NONE;
	GLenum wrapy     = GL_NONE;
	GLenum wrapz     = GL_NONE;
	GLenum minfilter = GL_NONE;
	GLenum magfilter = GL_NONE;
	GLhighlevelCommandInterface* _Mydeleter = nullptr;

	GLtexture() = default;

	GLtexture(const GLtexture&) = delete;
	
	GLtexture(GLtexture&& right) noexcept {
		right.swap(*this);
		right.release();
	}

	~GLtexture() { this->release(); }
	
	GLtexture& operator=(const GLtexture&) = delete;
	
	GLtexture& operator=(GLtexture&& right) noexcept {
		right.swap(*this);
		right.release();
		return *this;
	}
	
	GLboolean operator==(const GLtexture& right) const {
		return this->identifier == right.identifier;
	}
	
	GLboolean operator!=(const GLtexture& right) const {
		return this->identifier != right.identifier;
	}
	
	operator GLuint() const {
		return identifier;
	}		

	void release() {
		if (_Mydeleter) {
			_Mydeleter->DeleteTexture(*this);
		}
	}
	
	void swap(GLtexture& right) {
		std::swap(identifier, right.identifier);

		std::swap(target, right.target);
		std::swap(format, right.format);
		std::swap(width, right.width);
		std::swap(height, right.height);
		std::swap(depth, right.depth);
		
		std::swap(samples, right.samples);
		std::swap(wrapx, right.wrapx);
		std::swap(wrapy, right.wrapy);
		std::swap(wrapz, right.wrapz);
		std::swap(minfilter, right.minfilter);
		std::swap(magfilter, right.magfilter);
	}
};

#include "GLSLinterpreter.h"

class GLshader { 
public:
	GLuint identifier = GL_INVALID_INDEX;
	GLenum target = GL_NONE;
	std::string source;
	GLhighlevelCommandInterface* _Mydeleter = nullptr;

	GLshader() = default;
	
	GLshader(const GLshader&) = delete;
	
	GLshader(GLshader&& right) noexcept {
		*this = std::move(right);
	}

	~GLshader() { this->release(); }
	
	GLshader& operator=(const GLshader&) = delete;
	
	GLshader& operator=(GLshader&& right) noexcept {
		right.swap(*this);
		right.release();
		return *this;
	}
	
	operator GLuint() const {
		return this->identifier;
	}
	
	GLboolean operator==(const GLshader& right) const {
		return target == right.target && identifier == right.identifier;
	}
	
	GLboolean operator!=(const GLshader& right) const {
		return !(*this == right);
	}
	
	void release() {
		if (_Mydeleter) {
			_Mydeleter->DeleteShader(*this);
		}
	}
	
	void swap(GLshader& right) {
		std::swap(this->identifier, right.identifier);
		std::swap(this->target, right.target);
		std::swap(this->source, right.source);
	}
};

struct GLvarying_register {
// { example: { 4, GL_FLOAT, GL_FALSE, sizeof(float)*4, 0/*bytes*/ } }
	GLint	  size       = 4;// unit:[scalar]
	GLenum    type       = GL_FLOAT;
	GLboolean normalized = GL_FALSE;
	GLsizei   stride     = 16;// unit:[bytes]
	GLint     offset     = 0; // unit:[bytes]
};

struct GLblend_state {
	GLboolean enable = false;
	GLenum sfactor = GL_SRC_ALPHA;
	GLenum dfactor = GL_ONE_MINUS_SRC_ALPHA;
	GLenum func = GL_ADD;
};

struct GLrasterizer_state {
	GLenum cull = GL_FRONT_AND_BACK;
	GLenum fill = GL_FILL;
	GLboolean depthtest = GL_TRUE;
};

class GLprogram {
public:
	GLuint identifier = static_cast<GLuint>(-1);
	GLSLinformation information;
	GLhighlevelCommandInterface* _Mydeleter = nullptr;
	//std::map<GLenum, GLshader> shaders;
	std::vector<GLvarying_register> inputlayout;
	GLrasterizer_state rasterizer_state;
	GLblend_state blend_state[8];
	GLsizei rendertargets = 1;

	GLprogram() = default;

	GLprogram(const GLprogram&) = delete;
	
	GLprogram(GLprogram&& right) noexcept {
		*this = std::move(right);
	}
	
	~GLprogram() { this->release(); }
	
	GLprogram& operator=(const GLprogram&) = delete;

	GLprogram& operator=(GLprogram&& right) noexcept {
		right.swap(*this);
		right.release();
		return *this;
	}
	
	operator GLuint() const {
		return this->identifier;
	}
	
	GLboolean operator==(const GLprogram& right) const {
		return identifier == right.identifier;
	}
	
	GLboolean operator!=(const GLprogram& right) const {
		return !(*this == right);
	}
	
	void release() {
		if (_Mydeleter) {
			_Mydeleter->DeleteProgram(*this);
		}
	}
	
	void swap(GLprogram& right) {
		std::swap(this->identifier, right.identifier);
		//std::swap(this->shaders, right.shaders);
		std::swap(this->information, right.information);

		std::swap(this->inputlayout, right.inputlayout);
		std::swap(this->rasterizer_state, right.rasterizer_state);
		std::swap(this->blend_state, right.blend_state);
		std::swap(this->rendertargets, right.rendertargets);
	}
};




struct GPUlocation {
	GLenum target;
	GPUlocation(GLenum target) : target(target){}
};

struct GPUlocationi {
	GLenum target;
	GLuint index;
	GPUlocationi(GLenum target, GLuint index) : target(target), index(index) {}
};

//using _ContextTy = GLcontext440;
template<typename _ContextTy>
class GLhighlevel : public GLhighlevelCommandInterface {
public:
	_ContextTy gl;

	GLhighlevel() = default;

	explicit GLhighlevel(HDC device) : gl(device) {}

public: // Global Setting
	GLenum GetError() {
		return gl.GetError();
	}

	void EnablePointSpirit() {
		gl.Enable(GL_POINT_SPRITE);
	}

	void DisablePointSpirit() {
		gl.Disable(GL_POINT_SPRITE);
	}
	
	void EnableProgramPointSize() {
		gl.Enable(GL_PROGRAM_POINT_SIZE);
	}

	void DisableProgramPointSize() {
		gl.Disable(GL_PROGRAM_POINT_SIZE);
	}

	void EnableDepthTest() {
		gl.Enable(GL_DEPTH_TEST);
	}

	void DisableDepthTest() {
		gl.Disable(GL_DEPTH_TEST);
	}

	void EnableBlend(GLenum sfactor, GLenum dfactor, GLenum mode) {
		gl.Enable(GL_BLEND);
		gl.BlendFunc(sfactor, dfactor);
		gl.BlendEquation(mode);
	}

	void DisableBlend() {
		gl.Disable(GL_BLEND);
	}

	// GL_POLYGON, GL_LINE, GL_POINT
	void RasterizeMode(GLenum mode) {
		gl.PolygonMode(GL_FRONT_AND_BACK, mode);
	}

public: // Global Setting
	void SetClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
		gl.ClearColor(r, g, b, a);
	}

	void SetClearDepth(GLclampd depth) {
		gl.ClearDepth(depth);
	}

	void SetClearStencil(GLint s) {
		gl.ClearStencil(s);
	}

	void Clear(GLbitfield mask) {
		gl.Clear(mask);
	}

	void SetPatchi(GLenum pname, GLint param) {
		gl.PatchParameteri(pname, param);
	}

public: // Highlevel Buffer
	virtual 
	void DeleteBuffer(GLbuffer& buffer) {
		if ( gl.IsBuffer(buffer) ) {
			gl.DeleteBuffers(1, &buffer.identifier);
			buffer.identifier = GL_INVALID_INDEX;
			buffer.bytesize   = 0;
			buffer.usage      = GL_NONE;
			buffer._Mydeleter = nullptr;
		}
	}

	// alloc GPUmemory[target,usage](bytesize), and copy data into buffer
	void CreateBuffer(GLenum target, GLenum usage, GLsizei bytesize, const void* data, GLbuffer& buffer) {
		assert( bytesize != 0 );
		if ( gl.IsBuffer(buffer) ) { 
			gl.DeleteBuffers(1, &buffer.identifier); 
		}
		gl.GenBuffers(1, &buffer.identifier);
		gl.BindBuffer(target, buffer);
		gl.BufferData(target, bytesize, data, usage);
		gl.BindBuffer(target, 0);
		assert( gl.IsBuffer(buffer) );
		buffer.target   = target;
		buffer.bytesize = bytesize;
		buffer.usage    = usage;
		buffer._Mydeleter = this;
	}
	
	// alloc GPUmemory[target,usage](bytesize)
	void CreateBuffer(GLenum target, GLenum usage, GLsizei bytesize, GLbuffer& buffer) {
		CreateBuffer(target, usage, bytesize, nullptr, (buffer));
	}

	// Return true if buffer valid
	bool IsBuffer(const GLbuffer& buffer) {
		return gl.IsBuffer(buffer);
	}

	// Bind buffer to location
	void BindBuffer(const GLbuffer& buffer, GPUlocation location) {
		gl.BindBuffer(location.target, buffer.identifier);
	}

	// Bind buffer to location
	void BindBuffer(const GLbuffer& buffer, GPUlocationi location) {
		gl.BindBufferBase(location.target, location.index, buffer.identifier);
	}

	// Upload [source, ...) into [location+offset, location+offset+size)
	void UploadBuffer(const void* source, GPUlocation location, GLintptr offset, size_t bytesize) {
		gl.BufferSubData(location.target, offset, bytesize, source);
	}

	// Upload [source, ...) into [location, location+bytesize)
	void UploadBuffer(const void* source, GPUlocation location) {
		GLint bytesize;
		gl.GetBufferParameteriv(location.target, GL_BUFFER_SIZE, &bytesize);
		UploadBuffer(source, location, 0, bytesize);
	}

	// Readback [location+offset, location+offset+size) into [destination, ...)
	void ReadbackBuffer(GPUlocation location, GLintptr offset, GLsizeiptr bytesize, void* destination) {
		gl.GetBufferSubData(location.target, offset, bytesize, destination);
	}

	// Copy [source+soffset, source+soffset+copybytes) into [destination+doffset, ...)
	void CopyBuffer(const GLbuffer& source, GLintptr soffset, size_t copybytess, GLbuffer& destination, GLintptr doffset) {
		assert( gl.CopyBufferSubData != nullptr );
		gl.BindBuffer(GL_COPY_READ_BUFFER, source);
		gl.BindBuffer(GL_COPY_WRITE_BUFFER, destination);
		gl.CopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, soffset, doffset, copybytess);
	}

	// Set GPU-registers, that is global properties
	void SetVaryingRegisters(const GLvarying_register* register_array, size_t array_size) {
		// set and enable VertexAttrib
		GLsizei i = 0;
		for ( ; i != array_size; ++i ) {
			const GLvarying_register& the_register = register_array[i];
			switch ( the_register.type ) {
			case GL_INT:
			case GL_UNSIGNED_INT:
				gl.VertexAttribIPointer(i, the_register.size, the_register.type, the_register.stride, (void*)(the_register.offset));
				gl.EnableVertexAttribArray(i); 
				break;
			case GL_FLOAT:
				gl.VertexAttribPointer(i, the_register.size, the_register.type, the_register.normalized, the_register.stride, (void*)(the_register.offset));
				gl.EnableVertexAttribArray(i);
				break;
			case GL_DOUBLE:// in glsl "#version 400 core\n"
				gl.VertexAttribLPointer(i, the_register.size, the_register.type, the_register.stride, (void*)(the_register.offset));
				gl.EnableVertexAttribArray(i);
				break;
			default:
				break;
			}
		}

		// disable unused VertexAttrib
		GLint enabled;
		gl.GetVertexAttribiv(i, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled);
		if ( enabled == GL_TRUE ) {
			GLint max_vertex_attribs;
			gl.GetIntegerv(GL_MAX_VERTEX_ATTRIBS, &max_vertex_attribs);
			
			gl.DisableVertexAttribArray(i++);
			for (; i != max_vertex_attribs; ) {
				gl.GetVertexAttribiv(i, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled);
				if (enabled == GL_FALSE) {
					break;
				}
				gl.DisableVertexAttribArray(i++);
			}
		}
	}

	// Set GPU-registers, that is global properties
	void SetVaryingRegisters(const std::vector<GLvarying_register>& registers) {
		SetVaryingRegisters(registers.data(), registers.size());
	}

	// Tidy GPU-registers, that is global properties
	void TidyVaryingRegisters() {
		GLint max_vertex_attribs;
		gl.GetIntegerv(GL_MAX_VERTEX_ATTRIBS, &max_vertex_attribs);
		for (GLint i = 0; i != max_vertex_attribs; ++i) {
			gl.DisableVertexAttribArray(i);
		}
	}

public: // Highlevel Texture
	// 1, 2, 4, 8, ...
	void SetPixelAlignment(GLint alignment) {
		gl.PixelStorei(GL_UNPACK_ALIGNMENT, alignment);
	}

	virtual 
	void DeleteTexture(GLtexture& texture) {
		if ( gl.IsTexture(texture) ) {
			gl.DeleteTextures(1, &texture.identifier);
			texture.identifier = GL_INVALID_INDEX;
			texture.target = GL_NONE;
			texture.format = GL_NONE;
			texture.width  = 0;
			texture.height = 0;
			texture.depth  = 0;
			texture.samples   = 0;
			texture.wrapx     = GL_NONE;
			texture.wrapy     = GL_NONE;
			texture.wrapz     = GL_NONE;
			texture.minfilter = GL_NONE;
			texture.magfilter = GL_NONE;
			texture._Mydeleter = nullptr;
		}
	}

	void CreateTexture2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum wrapx, GLenum wrapy, GLenum minfilter, GLenum magfilter, GLtexture& texture) {
		assert( width != 0 && height != 0 );
		if ( gl.IsBuffer(texture) ) {
			gl.DeleteTextures(1, &texture.identifier);
		}
		gl.GenTextures(1, &texture.identifier);
		gl.BindTexture(target, texture);
		gl.TexStorage2D(target, 1, internalformat, width, height);
		gl.TexParameteri(target, GL_TEXTURE_WRAP_S, wrapx);
		gl.TexParameteri(target, GL_TEXTURE_WRAP_T, wrapy);
		gl.TexParameteri(target, GL_TEXTURE_MIN_FILTER, minfilter);
		gl.TexParameteri(target, GL_TEXTURE_MAG_FILTER, magfilter);
		gl.BindTexture(target, 0);
		assert( gl.IsTexture(texture) );
		texture.target = target;
		texture.format = internalformat;
		texture.width  = width;
		texture.height = height;
		texture.depth  = 1;
		texture.samples = 1;
		texture.wrapx   = wrapx;
		texture.wrapy    = wrapy;
		texture.minfilter = minfilter;
		texture.magfilter = magfilter;
		texture._Mydeleter = this;
	}
	
	void CreateTexture2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum wrapx, GLenum wrapy, GLenum minfilter, GLenum magfilter,  GLconstimage image, GLtexture& texture) {
		assert( width != 0 && height != 0 );
		if ( gl.IsBuffer(texture) ) {
			gl.DeleteTextures(1, &texture.identifier);
		}
		gl.GenTextures(1, &texture.identifier);
		gl.BindTexture(target, texture);
		gl.TexImage2D(target, 0, internalformat, width, height, 0, image.format, image.type, image.pixels());
		gl.TexParameteri(target, GL_TEXTURE_WRAP_S, wrapx);
		gl.TexParameteri(target, GL_TEXTURE_WRAP_T, wrapy);
		gl.TexParameteri(target, GL_TEXTURE_MIN_FILTER, minfilter);
		gl.TexParameteri(target, GL_TEXTURE_MAG_FILTER, magfilter);
		gl.GenerateMipmap(target);
		gl.BindTexture(target, 0);
		assert( gl.IsTexture(texture) );
		texture.target = target;
		texture.format = internalformat;
		texture.width  = width;
		texture.height = height;
		texture.depth  = 1;
		texture.samples = 1;
		texture.wrapx   = wrapx;
		texture.wrapy    = wrapy;
		texture.minfilter = minfilter;
		texture.magfilter = magfilter;
		texture._Mydeleter = this;
	}

	void CreateTexture2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLtexture& texture) {
		CreateTexture2D(target, internalformat, width, height, GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, (texture));
	}

	void CreateTexture2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLconstimage image, GLtexture& texture) {
		CreateTexture2D(target, internalformat, width, height, GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, image, (texture));
	}

	void CreateTexture3D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLenum wrapx, GLenum wrapy, GLenum wrapz, GLenum minfilter, GLenum magfilter, GLtexture& texture) {
		assert( width != 0 && height != 0 );
		if ( gl.IsBuffer(texture) ) {
			gl.DeleteTextures(1, &texture.identifier);
		}
		gl.GenTextures(1, &texture.identifier);
		gl.BindTexture(target, texture);
		gl.TexStorage3D(target, 1, internalformat, width, height, depth);
		gl.TexParameteri(target, GL_TEXTURE_WRAP_S, wrapx);
		gl.TexParameteri(target, GL_TEXTURE_WRAP_T, wrapy);
		gl.TexParameteri(target, GL_TEXTURE_WRAP_R, wrapz);
		gl.TexParameteri(target, GL_TEXTURE_MIN_FILTER, minfilter);
		gl.TexParameteri(target, GL_TEXTURE_MAG_FILTER, magfilter);
		gl.BindTexture(target, 0);
		assert( gl.IsTexture(texture) );
		texture.target = GL_TEXTURE_3D;
		texture.format = internalformat;
		texture.width  = width;
		texture.height = height;
		texture.depth  = depth;
		texture.samples = 1;
		texture.wrapx   = wrapx;
		texture.wrapy    = wrapy;
		texture.minfilter = minfilter;
		texture.magfilter = magfilter;
		texture._Mydeleter = this;
	}

	void CreateTexture3D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLtexture& texture) {
		CreateTexture3D(target, internalformat, width, height, depth, GL_REPEAT, GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, (texture));
	}

	bool IsTexture(const GLtexture& texture) {
		return gl.IsTexture(texture);
	}

	void BindTexture(const GLtexture& texture, GPUlocation location) {
		gl.BindTexture(location.target, texture.identifier);
	}

	void BindTexture(const GLtexture& texture, GPUlocationi location) {
		gl.ActiveTexture(GL_TEXTURE0 + location.index);
		gl.BindTexture(location.target, texture.identifier);
	}

	void SetTexturei(GPUlocation location, GLenum pname, GLint param) {
		gl.TexParameteri(location.target, pname, param);
	}

	void SetTexturef(GPUlocation location, GLenum pname, GLfloat param) {
		gl.TexParameterf(location.target, pname, param);
	}

	// Upload [image.pixels, ...) into [location + xoffset + yoffset*width, ... + width*height)
	void UploadTexture(GLconstimage image, GPUlocation location, GLint xoffset, GLint yoffset, GLint width, GLint height) {
		gl.TexSubImage2D(location.target, 0, xoffset, yoffset, width, height, image.format, image.type, image.pixels());
	}

	// Upload [image.pixels, ...) into [location, location+width*height)
	void UploadTexture(GLconstimage image, GPUlocation location) {
		GLint width, height;
		gl.GetTexLevelParameteriv(location.target, 0, GL_TEXTURE_WIDTH, &width);
		gl.GetTexLevelParameteriv(location.target, 0, GL_TEXTURE_HEIGHT, &height);
		UploadTexture(image, location, 0, 0, width, height);
	}

	// Readback [location, location + width*height) into [image.pixels, ...)
	void ReadbackTexture(GPUlocation location, GLimage image) {
		gl.GetTexImage(location.target, 0, image.format, image.type, image.pixels());
	}

public: // Highlevel Shader
	virtual 
	void DeleteShader(GLshader& shader) {
		if ( gl.IsShader(shader) ) {
			gl.DeleteShader(shader);
			shader.identifier = GL_INVALID_INDEX;
			shader.target     = GL_NONE;
			shader._Mydeleter = nullptr;
		}
	}
	
	void CreateShader(GLenum target, const std::string& source, GLshader& shader) {
		if (source.empty()) {
			return;
		}

		// create shader
		if ( gl.IsShader(shader) ) {
			gl.DeleteShader(shader);
		}
		shader.identifier = gl.CreateShader(target);
		shader.target = target;
		shader.source = source;
		shader._Mydeleter = this;
		// compile shader
		const GLchar* sources[1] = { source.c_str() };
		gl.ShaderSource(shader, 1, sources, nullptr);
		gl.CompileShader(shader);
		// get error
		GLint status;
		gl.GetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if ( status == GL_FALSE ) {
			char message[1024];
			GLsizei message_size = 0;
			gl.GetShaderInfoLog(shader, 1023, &message_size, message);
			message[message_size] = '\0';
			throw std::exception(message);
		}
	}

	virtual 
	void DeleteProgram(GLprogram& program) {
		if ( gl.IsProgram(program) ) {
			gl.DeleteProgram(program);
			program.identifier = GL_INVALID_INDEX;
			//program.shaders = std::map<GLenum, GLshader>();
			program.information.clear();
			program.inputlayout.clear();
			program.rasterizer_state = GLrasterizer_state();
			program.blend_state[0] = GLblend_state();
			program.rendertargets = 1;
			program._Mydeleter = nullptr;
		}
	}
	
	void CreateProgram(const std::vector<GLshader>& shaders, GLprogram& program) {
		// create program and link shaders
		if ( gl.IsProgram(program) ) { 
			gl.DeleteProgram(program); }
		program.identifier = gl.CreateProgram();
		for (const auto& shader : shaders) {
			if ( gl.IsShader(shader) ) {
				gl.AttachShader(program, shader); } }
		gl.LinkProgram(program);
		
		// get error and return ...
		GLint status;
		gl.GetProgramiv(program, GL_LINK_STATUS, &status);
		if ( status == GL_FALSE ) {
			char message[1024]; GLsizei message_size = 0;
			gl.GetProgramInfoLog(program, 1023, &message_size, message); message[message_size] = '\0';
			throw std::exception(message);
		}
		for ( const auto& shader : shaders ) {
			if (gl.IsShader(shader) && shader.source.empty()) {
				return;
			}
		}


		// get information
		GLSLinformation input_info;
		GLSLinformation all_info;
		for (const auto& shader : shaders) {
			if ( gl.IsShader(shader) ) {
				auto info = GLSLinformation(shader.source);
				if (shader.target == GL_VERTEX_SHADER) {
					input_info.merge_from(info);
				}
				all_info.merge_from(std::move(info));
			}
		}

		// cast inputinformation to inputlayout
		std::vector<GLvarying_register> inputlayout;
		for (const auto& varying : input_info.varyings) {
			assert( varying.second.qualifers.contains("location") );
			// layout(location = ..)
			GLint location = atoi(varying.second.qualifers.find("location")->second.c_str());
			GLenum type = GL_NONE;
			GLsizei size = 0;
			GLsizei sizeof_v = 0;
			// type
			if (varying.second.type == "float") {
				type = GL_FLOAT;
				size = 1;
				sizeof_v = sizeof(float) * size;
			} else if (varying.second.type == "double") {
				type = GL_DOUBLE;
				size = 1;
				sizeof_v = sizeof(double) * size;
			} else if (varying.second.type == "int") {
				type = GL_INT;
				size = 1;
				sizeof_v = sizeof(int) * size;
			} else if (varying.second.type == "vec2") {
				type = GL_FLOAT;
				size = 2;
				sizeof_v = sizeof(float) * size;
			} else if (varying.second.type == "vec3") {
				type = GL_FLOAT;
				size = 3;
				sizeof_v = sizeof(float) * size;
			} else if (varying.second.type == "vec4") {
				type = GL_FLOAT;
				size = 4;
				sizeof_v = sizeof(float) * size;
			} else if (varying.second.type == "dvec2") {
				type = GL_DOUBLE;
				size = 2;
				sizeof_v = sizeof(double) * size;
			} else if (varying.second.type == "dvec3") {
				type = GL_DOUBLE;
				size = 3;
				sizeof_v = sizeof(double) * size;
			} else if (varying.second.type == "dvec4") {
				type = GL_DOUBLE;
				size = 4;
				sizeof_v = sizeof(double) * size;
			} else if (varying.second.type == "mat4") {
				type = GL_FLOAT;
				size = 16;
				sizeof_v = sizeof(float) * size;
			} else if (varying.second.type == "dmat4") {
				type = GL_DOUBLE;
				size = 16;
				sizeof_v = sizeof(double) * size;
			} else if (varying.second.type == "imat4") {
				type = GL_INT;
				size = 16;
				sizeof_v = sizeof(int) * size;
			}

			if (inputlayout.size() <= size_t(location)) {
				inputlayout.resize(location + 1);
			}
			inputlayout[location] = { size, type, GL_FALSE, sizeof_v, 0/*bytes*/ };
		}

		// output the informations
		program.inputlayout = inputlayout;
		program.information = all_info;
	}

	void CreateProgram(const std::string& vertex_shader_source, const std::string& fragment_shader_source, GLprogram& program) {
		std::vector<GLshader> shaders;
		shaders.resize(2);
		
		CreateShader(GL_VERTEX_SHADER, vertex_shader_source, (shaders[0]));

		CreateShader(GL_FRAGMENT_SHADER, fragment_shader_source, (shaders[1]));
		
		CreateProgram(shaders, (program));
	}

	void CreateProgram(const std::filesystem::path& vertex_shader_filename, const std::filesystem::path& fragment_shader_filename, GLprogram& program) {
		CreateProgram(GLSLpreprocessor::read_file(vertex_shader_filename), GLSLpreprocessor::read_file(fragment_shader_filename), (program));
	}

	void BindProgram(const GLprogram& program) {
		gl.UseProgram(program);
		// rasterizer
		gl.PolygonMode(program.rasterizer_state.cull, program.rasterizer_state.fill);
		if (program.rasterizer_state.depthtest) {
			gl.Enable(GL_DEPTH_TEST);
		} else {
			gl.Disable(GL_DEPTH_TEST);
		}
		// blend
		for (GLsizei i = 0; i != program.rendertargets; ++i) {
			if (program.blend_state[i].enable) {
				gl.Enablei(GL_BLEND, i);
				gl.BlendFunci(i, program.blend_state[i].sfactor, program.blend_state[i].dfactor);
				gl.BlendEquationi(i, program.blend_state[i].func);
			} else {
				gl.Disablei(GL_BLEND, i);
			}
		}
	}

	void Uniform2f(GLint location, GLfloat v0, GLfloat v1) {
		gl.Uniform2f(location, v0, v1);
	}

	void Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
		gl.Uniform3f(location, v0, v1, v2);
	}

	void Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
		gl.Uniform4f(location, v0, v1, v2, v3);
	}

	void Uniform2fv(GLint location, GLsizei count, const GLfloat* value) {
		gl.Uniform2fv(location, count, value);
	}

	void Uniform3fv(GLint location, GLsizei count, const GLfloat* value) {
		gl.Uniform3fv(location, count, value);
	}

	void Uniform4fv(GLint location, GLsizei count, const GLfloat* value) {
		gl.Uniform4fv(location, count, value);
	}

	void Uniform2dv(GLint location, GLsizei count, const GLdouble* value) {
		gl.Uniform2dv(location, count, value);
	}

	void Uniform3dv(GLint location, GLsizei count, const GLdouble* value) {
		gl.Uniform3dv(location, count, value);
	}

	void Uniform4dv(GLint location, GLsizei count, const GLdouble* value) {
		gl.Uniform4dv(location, count, value);
	}

	void UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
		gl.UniformMatrix2fv(location, count, transpose, value);
	}

	void UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
		gl.UniformMatrix3fv(location, count, transpose, value);
	}

	void UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
		gl.UniformMatrix4fv(location, count, transpose, value);
	}
	
	void UniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
		gl.UniformMatrix2dv(location, count, transpose, value);
	}

	void UniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
		gl.UniformMatrix3dv(location, count, transpose, value);
	}

	void UniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
		gl.UniformMatrix4dv(location, count, transpose, value);
	}

	void DrawArrays(GLenum mode, GLint first, GLsizei count) {
		gl.DrawArrays(mode, first, count);
	}

	void DrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices) {
		gl.DrawElements(mode, count, type, indices);
	}
};

using GLhighlevel440 = GLhighlevel<GLcontext440>;

/*<note>
								readonly  read_write     readonly        readonly
@_Interface: Shader-Resource: sampler*,   image*,   uniform varient, uniform_block
@_Describ: This series of classes don't manage real memory, for example: @Free, @Alloc
</note>*/