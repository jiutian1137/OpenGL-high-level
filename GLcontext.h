/*{ "clmagic/opengl/GLcontext":{
  "Author": "LongJiangnan",
  "Date":   "2021",
  "License": "Please identify Author"
} }*/
#pragma once

#include <assert.h>
#include <windows.h>
#include <wingdi.h>
//#pragma comment(lib, "opengl32.lib") // copy to main.cpp

class GLcontextBase {
public:
	GLcontextBase() = default;
	
	GLcontextBase(HDC device) {
		HDC _My_device = wglGetCurrentDC();
		HGLRC _My_context = wglGetCurrentContext();
		// create context if null-context
		if ( !_My_context ) { 
			_My_context = wglCreateContext(device); 
		}
		assert(_My_context != nullptr);
		// make current if difference between device and current_device
		if ( _My_device != device ) { 
			wglMakeCurrent(device, _My_context); 
		}
	}

	HGLRC GetCurrentContext() {
		return wglGetCurrentContext();
	}

	HDC GetCurrentDC() {
		return wglGetCurrentDC();
	}
};

typedef char GLchar;
typedef void GLvoid;
typedef short GLshort;
typedef int GLint;
typedef long long GLint64;
typedef unsigned int GLuint;
typedef unsigned short GLushort;
typedef unsigned long GLulong;
typedef unsigned long long GLuint64;
typedef float GLfloat;
typedef double GLdouble;
typedef unsigned int GLenum;
typedef unsigned int GLbitfield;
typedef int GLsizei;
typedef unsigned char GLboolean;
typedef signed char GLbyte;
typedef unsigned char GLubyte;
typedef float GLclampf;
typedef double GLclampd;
typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;
typedef struct __GLsync* GLsync;

/* PolygonMode */
#define GL_POINT 0x1B00
#define GL_LINE  0x1B01
#define GL_FILL  0x1B02

/* PrimitiveMode */
#define GL_POINTS         0x0000
#define GL_LINES          0x0001
#define GL_LINE_LOOP      0x0002
#define GL_LINE_STRIP     0x0003
#define GL_TRIANGLES      0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN   0x0006
#define GL_QUADS          0x0007
#define GL_QUAD_STRIP     0x0008

/* glEnable(GL_BLEND) or glEnablei(GL_BLEND) */
#define GL_BLEND               0x0BE2
/* BlendFactor */
#define GL_ZERO                0
#define GL_ONE                 1
#define GL_SRC_COLOR           0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA           0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA           0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR           0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE  0x0308

/* TextureUnit */
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF

/* TextureTarget 110 */
#define GL_TEXTURE_1D                     0x0DE0
#define GL_TEXTURE_2D                     0x0DE1
#define GL_PROXY_TEXTURE_1D               0x8063
#define GL_PROXY_TEXTURE_2D               0x8064
#define GL_TEXTURE_BINDING_1D             0x8068
#define GL_TEXTURE_BINDING_2D             0x8069
/* TextureTarget 120 */
#define GL_TEXTURE_3D                     0x806F
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_PROXY_TEXTURE_3D               0x8070
/* TextureTarget 130 */
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
/* TextureTarget 300 */
#define GL_TEXTURE_1D_ARRAY               0x8C18
#define GL_TEXTURE_2D_ARRAY               0x8C1A
#define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
/* TextureTarget 310 */
#define GL_TEXTURE_RECTANGLE              0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE      0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE        0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE     0x84F8
/* TextureTarget 400 */
#define GL_TEXTURE_CUBE_MAP_ARRAY         0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY   0x900B

/* BaseInternalFormat 110 */
#define GL_STENCIL_INDEX   0x1901
#define GL_DEPTH_COMPONENT 0x1902
#define GL_RED             0x1903
#define GL_GREEN           0x1904
#define GL_BLUE            0x1905
#define GL_ALPHA           0x1906
#define GL_RGB             0x1907
#define GL_RGBA            0x1908
/* BaseInternalFormat ARB */
#define GL_DEPTH_STENCIL   0x84F9
/* BaseInternalFormat 130 */
#define GL_BGR             0x80E0
#define GL_BGRA            0x80E1
/* BaseInternalFormat 310 */
#define GL_RED_SNORM       0x8F90
#define GL_RG_SNORM        0x8F91
#define GL_RGB_SNORM       0x8F92
#define GL_RGBA_SNORM      0x8F93
/* SizedInternalFormat 110 */
#define GL_RGB4            0x804F
#define GL_RGB5            0x8050
#define GL_RGB8            0x8051
#define GL_RGB10           0x8052
#define GL_RGB12           0x8053
#define GL_RGB16           0x8054
#define GL_RGBA2           0x8055
#define GL_RGBA4           0x8056
#define GL_RGB5_A1         0x8057
#define GL_RGBA8           0x8058
#define GL_RGB10_A2        0x8059
#define GL_RGBA12          0x805A
#define GL_RGBA16          0x805B
/* SizedInternalFormat 130 */
#define GL_DEPTH24_STENCIL8  0x88F0
/* SizedInternalFormat 140 */
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
/* SizedInternalFormat 300 */
#define GL_RGBA32F           0x8814
#define GL_RGB32F            0x8815
#define GL_RGBA16F           0x881A
#define GL_RGB16F            0x881B
#define GL_RGBA32UI          0x8D70
#define GL_RGB32UI           0x8D71
#define GL_RGBA16UI          0x8D76
#define GL_RGB16UI           0x8D77
#define GL_RGBA8UI           0x8D7C
#define GL_RGB8UI            0x8D7D
#define GL_RGBA32I           0x8D82
#define GL_RGB32I            0x8D83
#define GL_RGBA16I           0x8D88
#define GL_RGB16I            0x8D89
#define GL_RGBA8I            0x8D8E
#define GL_RGB8I             0x8D8F
/* SizedInternalFormat 310 */
#define GL_R8_SNORM          0x8F94
#define GL_RG8_SNORM         0x8F95
#define GL_RGB8_SNORM        0x8F96
#define GL_RGBA8_SNORM       0x8F97
#define GL_R16_SNORM         0x8F98
#define GL_RG16_SNORM        0x8F99
#define GL_RGB16_SNORM       0x8F9A
#define GL_RGBA16_SNORM      0x8F9B
/* SizedInternalFormat ARB */
#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_DEPTH32F_STENCIL8  0x8CAD
#define GL_STENCIL_INDEX1     0x8D46
#define GL_STENCIL_INDEX4     0x8D47
#define GL_STENCIL_INDEX8     0x8D48
#define GL_STENCIL_INDEX16    0x8D49
/* SizedInternalFormat ARB */
#define GL_R8                 0x8229
#define GL_R16                0x822A
#define GL_RG8                0x822B
#define GL_RG16               0x822C
#define GL_R16F               0x822D
#define GL_R32F               0x822E
#define GL_RG16F              0x822F
#define GL_RG32F              0x8230
#define GL_R8I                0x8231
#define GL_R8UI               0x8232
#define GL_R16I               0x8233
#define GL_R16UI              0x8234
#define GL_R32I               0x8235
#define GL_R32UI              0x8236
#define GL_RG8I               0x8237
#define GL_RG8UI              0x8238
#define GL_RG16I              0x8239
#define GL_RG16UI             0x823A
#define GL_RG32I              0x823B
#define GL_RG32UI             0x823C
/* CompressedInternalFormat ARB */
#define GL_COMPRESSED_RED_RGTC1        0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define GL_COMPRESSED_RG_RGTC2         0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2  0x8DBE

/* TextureFormat 110 */
//#define GL_STENCIL_INDEX   0x1901
//#define GL_DEPTH_COMPONENT 0x1902
//#define GL_RED             0x1903
//#define GL_GREEN           0x1904
//#define GL_BLUE            0x1905
//#define GL_ALPHA           0x1906
//#define GL_RGB             0x1907
//#define GL_RGBA            0x1908
/* TextureFormat 130 */
//#define GL_BGR             0x80E0
//#define GL_BGRA            0x80E1
/* TextureFormat 300 */
#define GL_RED_INTEGER       0x8D94
#define GL_GREEN_INTEGER     0x8D95
#define GL_BLUE_INTEGER      0x8D96
#define GL_ALPHA_INTEGER     0x8D97
#define GL_RGB_INTEGER       0x8D98
#define GL_RGBA_INTEGER      0x8D99
#define GL_BGR_INTEGER       0x8D9A
#define GL_BGRA_INTEGER      0x8D9B
/* TextureFormat ARB */
#define GL_COMPRESSED_RED    0x8225
#define GL_COMPRESSED_RG     0x8226
#define GL_RG                0x8227
#define GL_RG_INTEGER        0x8228

/* Type 110 */
#define GL_BYTE              0x1400
#define GL_UNSIGNED_BYTE     0x1401
#define GL_SHORT             0x1402
#define GL_UNSIGNED_SHORT    0x1403
#define GL_INT               0x1404
#define GL_UNSIGNED_INT      0x1405
#define GL_FLOAT             0x1406
#define GL_DOUBLE            0x140A
/* PixelType 120 */
#define GL_UNSIGNED_BYTE_3_3_2        0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4     0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1     0x8034
#define GL_UNSIGNED_INT_8_8_8_8       0x8035
#define GL_UNSIGNED_INT_10_10_10_2    0x8036
/* PixelType 130 */
#define GL_UNSIGNED_BYTE_2_3_3_REV    0x8362
#define GL_UNSIGNED_SHORT_5_6_5       0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV   0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV   0x8367
/* PixelType 300 */
#define GL_R11F_G11F_B10F             0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_RGB9_E5                    0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV   0x8C3E
/* PixelType 330 */
#define GL_RGB10_A2UI                 0x906F
/* PixelType ARB */
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_UNSIGNED_INT_24_8          0x84FA

/* TexParameterPname 110 */
#define GL_TEXTURE_WRAP_S          0x2802
#define GL_TEXTURE_WRAP_T          0x2803
#define GL_TEXTURE_MAG_FILTER      0x2800
#define GL_TEXTURE_MIN_FILTER      0x2801
/* TexParameterPname 120 */
#define GL_TEXTURE_WRAP_R          0x8072
/* TexParameterPname ARB */
#define GL_TEXTURE_SWIZZLE_R       0x8E42
#define GL_TEXTURE_SWIZZLE_G       0x8E43
#define GL_TEXTURE_SWIZZLE_B       0x8E44
#define GL_TEXTURE_SWIZZLE_A       0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA    0x8E46

/* TextureWrap 110 */
#define GL_CLAMP                   0x2900
#define GL_REPEAT                  0x2901
/* TextureWrap 120 */
#define GL_CLAMP_TO_EDGE           0x812F
/* TextureWrap 130 */
#define GL_CLAMP_TO_BORDER         0x812D
/* TextureWrap 140 */
#define GL_MIRRORED_REPEAT         0x8370
/* TextureWrap ARB */
#define GL_MIRROR_CLAMP_TO_EDGE    0x8743

/* TextureFilter 110 */
#define GL_NEAREST                 0x2600
#define GL_LINEAR                  0x2601
#define GL_NEAREST_MIPMAP_NEAREST  0x2700
#define GL_LINEAR_MIPMAP_NEAREST   0x2701
#define GL_NEAREST_MIPMAP_LINEAR   0x2702
#define GL_LINEAR_MIPMAP_LINEAR    0x2703
/* TextureFilter ARB, glTexParameterf(..., GL_TEXTURE_MAX_ANISOTROPY, glGetFloatv(.GL_MAX_TEXTURE_MAX_ANISOTROPY.))  */
#define GL_TEXTURE_MAX_ANISOTROPY  0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY 0x84FF

/* TextureCompararisonFunction 110 */
#define GL_LEQUAL                  0x0203
#define GL_GEQUAL                  0x0206
#define GL_LESS                    0x0201
#define GL_GREATER                 0x0204
#define GL_EQUAL                   0x0202
#define GL_NOTEQUAL                0x0205
#define GL_ALWAYS                  0x0207
#define GL_NEVER                   0x0200

/* GetParameter 110 */
#define GL_MAX_TEXTURE_SIZE        0x0D33
/* GetTexParameter 110 */
#define GL_TEXTURE_WIDTH           0x1000
#define GL_TEXTURE_HEIGHT          0x1001
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_BORDER_COLOR    0x1004
#define GL_TEXTURE_BORDER          0x1005
/* GetTexParameter 120 */
#define GL_TEXTURE_DEPTH           0x8071
/* GetTexParameter ARB */
#define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F


/* BufferTarget 150 */
#define GL_ARRAY_BUFFER                 0x8892
#define GL_ELEMENT_ARRAY_BUFFER         0x8893
#define GL_ARRAY_BUFFER_BINDING         0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
/* BufferTarget 210 */
#define GL_PIXEL_PACK_BUFFER            0x88EB
#define GL_PIXEL_UNPACK_BUFFER          0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING    0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING  0x88EF
/* BufferTarget 300 */
#define GL_TRANSFORM_FEEDBACK_BUFFER    0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
/* BufferTarget 310 */
#define GL_UNIFORM_BUFFER 0x8A11
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
/* BufferTarget 420 */
#define GL_ATOMIC_COUNTER_BUFFER         0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1

/* MapBufferAccess */
#define GL_READ_ONLY    0x88B8
#define GL_WRITE_ONLY   0x88B9
#define GL_READ_WRITE   0x88BA

/* BufferUsage */
#define GL_STREAM_DRAW  0x88E0
#define GL_STREAM_READ  0x88E1
#define GL_STREAM_COPY  0x88E2
#define GL_STATIC_DRAW  0x88E4
#define GL_STATIC_READ  0x88E5
#define GL_STATIC_COPY  0x88E6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_DYNAMIC_COPY 0x88EA

/* GetBufferParameter 150 */
#define GL_BUFFER_SIZE        0x8764
#define GL_BUFFER_USAGE       0x8765
#define GL_BUFFER_ACCESS      0x88BB
#define GL_BUFFER_MAPPED      0x88BC
#define GL_BUFFER_MAP_POINTER 0x88BD
/* GetBufferParameter 310 */
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_LENGTH  0x9120
#define GL_BUFFER_MAP_OFFSET  0x9121


/* ShaderTarget 200 */
#define GL_VERTEX_SHADER   0x8B31
#define GL_FRAGMENT_SHADER 0x8B30
/* ShaderTarget 320 */
#define GL_GEOMETRY_SHADER 0x8DD9
/* ShaderTarget 400 */
#define GL_TESS_EVALUATION_SHADER 0x8E87
#define GL_TESS_CONTROL_SHADER    0x8E88

/* GetVertexAttrib */
#define GL_MAX_VERTEX_ATTRIBS          0x8869
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE    0x8623
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE  0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE    0x8625
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_CURRENT_VERTEX_ATTRIB       0x8626

/* SamplerTarget 200 */
#define GL_SAMPLER_1D              0x8B5D
#define GL_SAMPLER_2D              0x8B5E
#define GL_SAMPLER_3D              0x8B5F
#define GL_SAMPLER_CUBE            0x8B60
#define GL_SAMPLER_1D_SHADOW       0x8B61
#define GL_SAMPLER_2D_SHADOW       0x8B62
/* SamplerTarget 300 */
#define GL_SAMPLER_1D_ARRAY        0x8DC0
#define GL_SAMPLER_2D_ARRAY        0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW     0x8DC5
#define GL_INT_SAMPLER_1D          0x8DC9
#define GL_INT_SAMPLER_2D          0x8DCA
#define GL_INT_SAMPLER_3D          0x8DCB
#define GL_INT_SAMPLER_CUBE        0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY    0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY    0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
/* SamplerTarget 310 */
#define GL_SAMPLER_2D_RECT         0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW  0x8B64
/* SamplerTarget 400 */
#define GL_SAMPLER_CUBE_MAP_ARRAY  0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F

/* FrambufferTarget ARB */
#define GL_FRAMEBUFFER 0x8D40
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA

/* FramebufferAttachment ARB */
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A

/* GetFramebufferParameter ARB */
#define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH 0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS 0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318

/* DrawBuffer with Framebuffer */
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834

/* RenderbufferTarget ARB */
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8

/* GetRenderbufferParameter ARB */
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55

/* BarrierBit ARB */
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT       0x00000002
#define GL_UNIFORM_BARRIER_BIT             0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT       0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT             0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT        0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT      0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT       0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT         0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT  0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT      0x00001000
#define GL_ALL_BARRIER_BITS                0xFFFFFFFF
/* BarrierBit 430ARB */
#define GL_SHADER_STORAGE_BARRIER_BIT      0x2000


/* GetUniformParameter ARB */
#define GL_MAX_UNIFORM_LOCATIONS 0x826E
/* Unknown */
#define GL_INDEX 0x8222
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_SRGB 0x8C40

// { #version 110 }
class GLcontext110 : public GLcontextBase {
	#define GL_INVALID_INDEX 0xFFFFFFFFu
	#define GL_NONE 0
	#define GL_FALSE 0
	#define GL_TRUE  1
	#define GL_NO_ERROR 0
	#define GL_LOGIC_OP 0x0BF1
	#define GL_TEXTURE_COMPONENTS 0x1003
	#define GL_CURRENT_BIT 0x00000001
	#define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
	#define GL_POINT_BIT 0x00000002
	#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
	#define GL_LINE_BIT 0x00000004
	#define GL_POLYGON_BIT 0x00000008
	#define GL_POLYGON 0x0009
	#define GL_POLYGON_STIPPLE_BIT 0x00000010
	#define GL_PIXEL_MODE_BIT 0x00000020
	#define GL_LIGHTING_BIT 0x00000040
	#define GL_FOG_BIT 0x00000080
	#define GL_DEPTH_BUFFER_BIT 0x00000100
	#define GL_ACCUM 0x0100
	#define GL_LOAD 0x0101
	#define GL_RETURN 0x0102
	#define GL_MULT 0x0103
	#define GL_ADD  0x0104
	#define GL_ACCUM_BUFFER_BIT 0x00000200
	#define GL_STENCIL_BUFFER_BIT 0x00000400
	#define GL_FRONT_LEFT 0x0400
	#define GL_FRONT_RIGHT 0x0401
	#define GL_BACK_LEFT 0x0402
	#define GL_BACK_RIGHT 0x0403
	#define GL_FRONT 0x0404
	#define GL_BACK 0x0405
	#define GL_LEFT 0x0406
	#define GL_RIGHT 0x0407
	#define GL_FRONT_AND_BACK 0x0408
	#define GL_AUX0 0x0409
	#define GL_AUX1 0x040A
	#define GL_AUX2 0x040B
	#define GL_AUX3 0x040C
	#define GL_INVALID_ENUM 0x0500
	#define GL_INVALID_VALUE 0x0501
	#define GL_INVALID_OPERATION 0x0502
	#define GL_STACK_OVERFLOW 0x0503
	#define GL_STACK_UNDERFLOW 0x0504
	#define GL_OUT_OF_MEMORY 0x0505
	#define GL_CW 0x0900
	#define GL_CCW 0x0901
	#define GL_POINT_SMOOTH 0x0B10
	#define GL_POINT_SIZE 0x0B11
	#define GL_POINT_SIZE_RANGE 0x0B12
	#define GL_POINT_SIZE_GRANULARITY 0x0B13
	#define GL_LINE_SMOOTH 0x0B20
	#define GL_LINE_WIDTH 0x0B21
	#define GL_LINE_WIDTH_RANGE 0x0B22
	#define GL_LINE_WIDTH_GRANULARITY 0x0B23
	#define GL_LINE_STIPPLE 0x0B24
	#define GL_LINE_STIPPLE_PATTERN 0x0B25
	#define GL_LINE_STIPPLE_REPEAT 0x0B26
	#define GL_LIST_MODE 0x0B30
	#define GL_MAX_LIST_NESTING 0x0B31
	#define GL_LIST_BASE 0x0B32
	#define GL_LIST_INDEX 0x0B33
	#define GL_POLYGON_MODE 0x0B40
	#define GL_POLYGON_SMOOTH 0x0B41
	#define GL_POLYGON_STIPPLE 0x0B42
	#define GL_EDGE_FLAG 0x0B43
	#define GL_CULL_FACE 0x0B44
	#define GL_CULL_FACE_MODE 0x0B45
	#define GL_FRONT_FACE 0x0B46
	#define GL_DEPTH_RANGE 0x0B70
	#define GL_DEPTH_TEST 0x0B71
	#define GL_DEPTH_WRITEMASK 0x0B72
	#define GL_DEPTH_CLEAR_VALUE 0x0B73
	#define GL_DEPTH_FUNC 0x0B74
	#define GL_ACCUM_CLEAR_VALUE 0x0B80
	#define GL_STENCIL_TEST 0x0B90
	#define GL_STENCIL_CLEAR_VALUE 0x0B91
	#define GL_STENCIL_FUNC 0x0B92
	#define GL_STENCIL_VALUE_MASK 0x0B93
	#define GL_STENCIL_FAIL 0x0B94
	#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
	#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
	#define GL_STENCIL_REF 0x0B97
	#define GL_STENCIL_WRITEMASK 0x0B98
	/*#define GL_2D 0x0600
	#define GL_3D 0x0601
	#define GL_3D_COLOR 0x0602
	#define GL_3D_COLOR_TEXTURE 0x0603
	#define GL_4D_COLOR_TEXTURE 0x0604
	#define GL_PASS_THROUGH_TOKEN 0x0700
	#define GL_POINT_TOKEN 0x0701
	#define GL_LINE_TOKEN 0x0702
	#define GL_POLYGON_TOKEN 0x0703
	#define GL_BITMAP_TOKEN 0x0704
	#define GL_DRAW_PIXEL_TOKEN 0x0705
	#define GL_COPY_PIXEL_TOKEN 0x0706
	#define GL_LINE_RESET_TOKEN 0x0707
	#define GL_EXP 0x0800
	#define GL_VIEWPORT_BIT 0x00000800
	#define GL_EXP2 0x0801
	#define GL_COEFF 0x0A00
	#define GL_ORDER 0x0A01
	#define GL_DOMAIN 0x0A02
	#define GL_CURRENT_COLOR 0x0B00
	#define GL_CURRENT_INDEX 0x0B01
	#define GL_CURRENT_NORMAL 0x0B02
	#define GL_CURRENT_TEXTURE_COORDS 0x0B03
	#define GL_CURRENT_RASTER_COLOR 0x0B04
	#define GL_CURRENT_RASTER_INDEX 0x0B05
	#define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
	#define GL_CURRENT_RASTER_POSITION 0x0B07
	#define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
	#define GL_CURRENT_RASTER_DISTANCE 0x0B09*/
	/*#define GL_LIGHTING 0x0B50
	#define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
	#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
	#define GL_LIGHT_MODEL_AMBIENT 0x0B53
	#define GL_SHADE_MODEL 0x0B54
	#define GL_COLOR_MATERIAL_FACE 0x0B55
	#define GL_COLOR_MATERIAL_PARAMETER 0x0B56
	#define GL_COLOR_MATERIAL 0x0B57
	#define GL_FOG 0x0B60
	#define GL_FOG_INDEX 0x0B61
	#define GL_FOG_DENSITY 0x0B62
	#define GL_FOG_START 0x0B63
	#define GL_FOG_END 0x0B64
	#define GL_FOG_MODE 0x0B65
	#define GL_FOG_COLOR 0x0B66*/
	/*#define GL_MATRIX_MODE 0x0BA0
	#define GL_NORMALIZE 0x0BA1
	#define GL_VIEWPORT 0x0BA2
	#define GL_MODELVIEW_STACK_DEPTH 0x0BA3
	#define GL_PROJECTION_STACK_DEPTH 0x0BA4
	#define GL_TEXTURE_STACK_DEPTH 0x0BA5
	#define GL_MODELVIEW_MATRIX 0x0BA6
	#define GL_PROJECTION_MATRIX 0x0BA7
	#define GL_TEXTURE_MATRIX 0x0BA8
	#define GL_ATTRIB_STACK_DEPTH 0x0BB0
	#define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
	#define GL_ALPHA_TEST 0x0BC0
	#define GL_ALPHA_TEST_FUNC 0x0BC1
	#define GL_ALPHA_TEST_REF 0x0BC2
	#define GL_DITHER 0x0BD0
	#define GL_BLEND_DST 0x0BE0
	#define GL_BLEND_SRC 0x0BE1
	#define GL_LOGIC_OP_MODE 0x0BF0
	#define GL_INDEX_LOGIC_OP 0x0BF1
	#define GL_COLOR_LOGIC_OP 0x0BF2
	#define GL_AUX_BUFFERS 0x0C00
	#define GL_DRAW_BUFFER 0x0C01
	#define GL_READ_BUFFER 0x0C02
	#define GL_SCISSOR_BOX 0x0C10
	#define GL_SCISSOR_TEST 0x0C11
	#define GL_INDEX_CLEAR_VALUE 0x0C20
	#define GL_INDEX_WRITEMASK 0x0C21
	#define GL_COLOR_CLEAR_VALUE 0x0C22
	#define GL_COLOR_WRITEMASK 0x0C23
	#define GL_INDEX_MODE 0x0C30
	#define GL_RGBA_MODE 0x0C31
	#define GL_DOUBLEBUFFER 0x0C32
	#define GL_STEREO 0x0C33
	#define GL_RENDER_MODE 0x0C40
	#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
	#define GL_POINT_SMOOTH_HINT 0x0C51
	#define GL_LINE_SMOOTH_HINT 0x0C52
	#define GL_POLYGON_SMOOTH_HINT 0x0C53
	#define GL_FOG_HINT 0x0C54
	#define GL_TEXTURE_GEN_S 0x0C60
	#define GL_TEXTURE_GEN_T 0x0C61
	#define GL_TEXTURE_GEN_R 0x0C62
	#define GL_TEXTURE_GEN_Q 0x0C63
	#define GL_PIXEL_MAP_I_TO_I 0x0C70
	#define GL_PIXEL_MAP_S_TO_S 0x0C71
	#define GL_PIXEL_MAP_I_TO_R 0x0C72
	#define GL_PIXEL_MAP_I_TO_G 0x0C73
	#define GL_PIXEL_MAP_I_TO_B 0x0C74
	#define GL_PIXEL_MAP_I_TO_A 0x0C75
	#define GL_PIXEL_MAP_R_TO_R 0x0C76
	#define GL_PIXEL_MAP_G_TO_G 0x0C77
	#define GL_PIXEL_MAP_B_TO_B 0x0C78
	#define GL_PIXEL_MAP_A_TO_A 0x0C79
	#define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
	#define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
	#define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
	#define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
	#define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
	#define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
	#define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
	#define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
	#define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
	#define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
	#define GL_UNPACK_SWAP_BYTES 0x0CF0
	#define GL_UNPACK_LSB_FIRST 0x0CF1
	#define GL_UNPACK_ROW_LENGTH 0x0CF2
	#define GL_UNPACK_SKIP_ROWS 0x0CF3
	#define GL_UNPACK_SKIP_PIXELS 0x0CF4
	#define GL_UNPACK_ALIGNMENT 0x0CF5
	#define GL_PACK_SWAP_BYTES 0x0D00
	#define GL_PACK_LSB_FIRST 0x0D01
	#define GL_PACK_ROW_LENGTH 0x0D02
	#define GL_PACK_SKIP_ROWS 0x0D03
	#define GL_PACK_SKIP_PIXELS 0x0D04
	#define GL_PACK_ALIGNMENT 0x0D05
	#define GL_MAP_COLOR 0x0D10
	#define GL_MAP_STENCIL 0x0D11
	#define GL_INDEX_SHIFT 0x0D12
	#define GL_INDEX_OFFSET 0x0D13
	#define GL_RED_SCALE 0x0D14
	#define GL_RED_BIAS 0x0D15
	#define GL_ZOOM_X 0x0D16
	#define GL_ZOOM_Y 0x0D17
	#define GL_GREEN_SCALE 0x0D18
	#define GL_GREEN_BIAS 0x0D19
	#define GL_BLUE_SCALE 0x0D1A
	#define GL_BLUE_BIAS 0x0D1B
	#define GL_ALPHA_SCALE 0x0D1C
	#define GL_ALPHA_BIAS 0x0D1D
	#define GL_DEPTH_SCALE 0x0D1E
	#define GL_DEPTH_BIAS 0x0D1F
	#define GL_MAX_EVAL_ORDER 0x0D30
	#define GL_MAX_LIGHTS 0x0D31
	#define GL_MAX_CLIP_PLANES 0x0D32
	#define GL_MAX_PIXEL_MAP_TABLE 0x0D34
	#define GL_MAX_ATTRIB_STACK_DEPTH 0x0D35
	#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
	#define GL_MAX_NAME_STACK_DEPTH 0x0D37
	#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
	#define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
	#define GL_MAX_VIEWPORT_DIMS 0x0D3A
	#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
	#define GL_SUBPIXEL_BITS 0x0D50
	#define GL_INDEX_BITS 0x0D51
	#define GL_RED_BITS 0x0D52
	#define GL_GREEN_BITS 0x0D53
	#define GL_BLUE_BITS 0x0D54
	#define GL_ALPHA_BITS 0x0D55
	#define GL_DEPTH_BITS 0x0D56
	#define GL_STENCIL_BITS 0x0D57
	#define GL_ACCUM_RED_BITS 0x0D58
	#define GL_ACCUM_GREEN_BITS 0x0D59
	#define GL_ACCUM_BLUE_BITS 0x0D5A
	#define GL_ACCUM_ALPHA_BITS 0x0D5B
	#define GL_NAME_STACK_DEPTH 0x0D70
	#define GL_AUTO_NORMAL 0x0D80
	#define GL_MAP1_COLOR_4 0x0D90
	#define GL_MAP1_INDEX 0x0D91
	#define GL_MAP1_NORMAL 0x0D92
	#define GL_MAP1_TEXTURE_COORD_1 0x0D93
	#define GL_MAP1_TEXTURE_COORD_2 0x0D94
	#define GL_MAP1_TEXTURE_COORD_3 0x0D95
	#define GL_MAP1_TEXTURE_COORD_4 0x0D96
	#define GL_MAP1_VERTEX_3 0x0D97
	#define GL_MAP1_VERTEX_4 0x0D98
	#define GL_MAP2_COLOR_4 0x0DB0
	#define GL_MAP2_INDEX 0x0DB1
	#define GL_MAP2_NORMAL 0x0DB2
	#define GL_MAP2_TEXTURE_COORD_1 0x0DB3
	#define GL_MAP2_TEXTURE_COORD_2 0x0DB4
	#define GL_MAP2_TEXTURE_COORD_3 0x0DB5
	#define GL_MAP2_TEXTURE_COORD_4 0x0DB6
	#define GL_MAP2_VERTEX_3 0x0DB7
	#define GL_MAP2_VERTEX_4 0x0DB8
	#define GL_MAP1_GRID_DOMAIN 0x0DD0
	#define GL_MAP1_GRID_SEGMENTS 0x0DD1
	#define GL_MAP2_GRID_DOMAIN 0x0DD2
	#define GL_MAP2_GRID_SEGMENTS 0x0DD3
	#define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
	#define GL_FEEDBACK_BUFFER_SIZE 0x0DF1
	#define GL_FEEDBACK_BUFFER_TYPE 0x0DF2
	#define GL_SELECTION_BUFFER_POINTER 0x0DF3
	#define GL_SELECTION_BUFFER_SIZE 0x0DF4
	#define GL_TRANSFORM_BIT 0x00001000
	#define GL_DONT_CARE 0x1100
	#define GL_FASTEST 0x1101
	#define GL_NICEST 0x1102
	#define GL_AMBIENT 0x1200
	#define GL_DIFFUSE 0x1201
	#define GL_SPECULAR 0x1202
	#define GL_POSITION 0x1203
	#define GL_SPOT_DIRECTION 0x1204
	#define GL_SPOT_EXPONENT 0x1205
	#define GL_SPOT_CUTOFF 0x1206
	#define GL_CONSTANT_ATTENUATION 0x1207
	#define GL_LINEAR_ATTENUATION 0x1208
	#define GL_QUADRATIC_ATTENUATION 0x1209
	#define GL_COMPILE 0x1300
	#define GL_COMPILE_AND_EXECUTE 0x1301
	#define GL_2_BYTES 0x1407
	#define GL_3_BYTES 0x1408
	#define GL_4_BYTES 0x1409
	#define GL_CLEAR 0x1500
	#define GL_AND 0x1501
	#define GL_AND_REVERSE 0x1502
	#define GL_COPY 0x1503
	#define GL_AND_INVERTED 0x1504
	#define GL_NOOP 0x1505
	#define GL_XOR 0x1506
	#define GL_OR 0x1507
	#define GL_NOR 0x1508
	#define GL_EQUIV 0x1509
	#define GL_INVERT 0x150A
	#define GL_OR_REVERSE 0x150B
	#define GL_COPY_INVERTED 0x150C
	#define GL_OR_INVERTED 0x150D
	#define GL_NAND 0x150E
	#define GL_SET 0x150F
	#define GL_EMISSION 0x1600
	#define GL_SHININESS 0x1601
	#define GL_AMBIENT_AND_DIFFUSE 0x1602
	#define GL_COLOR_INDEXES 0x1603
	#define GL_MODELVIEW 0x1700
	#define GL_PROJECTION 0x1701
	#define GL_TEXTURE 0x1702
	#define GL_COLOR 0x1800
	#define GL_DEPTH 0x1801
	#define GL_STENCIL 0x1802
	#define GL_COLOR_INDEX 0x1900
	#define GL_LUMINANCE 0x1909
	#define GL_LUMINANCE_ALPHA 0x190A
	#define GL_BITMAP 0x1A00
	#define GL_RENDER 0x1C00
	#define GL_FEEDBACK 0x1C01
	#define GL_SELECT 0x1C02
	#define GL_FLAT 0x1D00
	#define GL_SMOOTH 0x1D01
	#define GL_KEEP 0x1E00
	#define GL_REPLACE 0x1E01
	#define GL_INCR 0x1E02
	#define GL_DECR 0x1E03
	#define GL_VENDOR 0x1F00
	#define GL_RENDERER 0x1F01
	#define GL_VERSION 0x1F02
	#define GL_EXTENSIONS 0x1F03
	#define GL_ENABLE_BIT 0x00002000
	#define GL_S 0x2000
	#define GL_T 0x2001
	#define GL_R 0x2002
	#define GL_Q 0x2003
	#define GL_MODULATE 0x2100
	#define GL_DECAL 0x2101
	#define GL_TEXTURE_ENV_MODE 0x2200
	#define GL_TEXTURE_ENV_COLOR 0x2201
	#define GL_TEXTURE_ENV 0x2300
	#define GL_EYE_LINEAR 0x2400
	#define GL_OBJECT_LINEAR 0x2401
	#define GL_SPHERE_MAP 0x2402
	#define GL_TEXTURE_GEN_MODE 0x2500
	#define GL_OBJECT_PLANE 0x2501
	#define GL_EYE_PLANE 0x2502
	#define GL_POLYGON_OFFSET_UNITS 0x2A00
	#define GL_POLYGON_OFFSET_POINT 0x2A01
	#define GL_POLYGON_OFFSET_LINE 0x2A02
	#define GL_R3_G3_B2 0x2A10
	#define GL_V2F 0x2A20
	#define GL_V3F 0x2A21
	#define GL_C4UB_V2F 0x2A22
	#define GL_C4UB_V3F 0x2A23
	#define GL_C3F_V3F 0x2A24
	#define GL_N3F_V3F 0x2A25
	#define GL_C4F_N3F_V3F 0x2A26
	#define GL_T2F_V3F 0x2A27
	#define GL_T4F_V4F 0x2A28
	#define GL_T2F_C4UB_V3F 0x2A29
	#define GL_T2F_C3F_V3F 0x2A2A
	#define GL_T2F_N3F_V3F 0x2A2B
	#define GL_T2F_C4F_N3F_V3F 0x2A2C
	#define GL_T4F_C4F_N3F_V4F 0x2A2D
	#define GL_CLIP_PLANE0 0x3000
	#define GL_CLIP_PLANE1 0x3001
	#define GL_CLIP_PLANE2 0x3002
	#define GL_CLIP_PLANE3 0x3003
	#define GL_CLIP_PLANE4 0x3004
	#define GL_CLIP_PLANE5 0x3005
	#define GL_LIGHT0 0x4000
	#define GL_COLOR_BUFFER_BIT 0x00004000
	#define GL_LIGHT1 0x4001
	#define GL_LIGHT2 0x4002
	#define GL_LIGHT3 0x4003
	#define GL_LIGHT4 0x4004
	#define GL_LIGHT5 0x4005
	#define GL_LIGHT6 0x4006
	#define GL_LIGHT7 0x4007
	#define GL_HINT_BIT 0x00008000
	#define GL_POLYGON_OFFSET_FILL 0x8037
	#define GL_POLYGON_OFFSET_FACTOR 0x8038
	#define GL_ALPHA4 0x803B
	#define GL_ALPHA8 0x803C
	#define GL_ALPHA12 0x803D
	#define GL_ALPHA16 0x803E
	#define GL_LUMINANCE4 0x803F
	#define GL_LUMINANCE8 0x8040
	#define GL_LUMINANCE12 0x8041
	#define GL_LUMINANCE16 0x8042
	#define GL_LUMINANCE4_ALPHA4 0x8043
	#define GL_LUMINANCE6_ALPHA2 0x8044
	#define GL_LUMINANCE8_ALPHA8 0x8045
	#define GL_LUMINANCE12_ALPHA4 0x8046
	#define GL_LUMINANCE12_ALPHA12 0x8047
	#define GL_LUMINANCE16_ALPHA16 0x8048
	#define GL_INTENSITY 0x8049
	#define GL_INTENSITY4 0x804A
	#define GL_INTENSITY8 0x804B
	#define GL_INTENSITY12 0x804C
	#define GL_INTENSITY16 0x804D
	#define GL_TEXTURE_RED_SIZE 0x805C
	#define GL_TEXTURE_GREEN_SIZE 0x805D
	#define GL_TEXTURE_BLUE_SIZE 0x805E
	#define GL_TEXTURE_ALPHA_SIZE 0x805F
	#define GL_TEXTURE_LUMINANCE_SIZE 0x8060
	#define GL_TEXTURE_INTENSITY_SIZE 0x8061
	#define GL_TEXTURE_PRIORITY 0x8066
	#define GL_TEXTURE_RESIDENT 0x8067
	#define GL_VERTEX_ARRAY 0x8074
	#define GL_NORMAL_ARRAY 0x8075
	#define GL_COLOR_ARRAY 0x8076
	#define GL_INDEX_ARRAY 0x8077
	#define GL_TEXTURE_COORD_ARRAY 0x8078
	#define GL_EDGE_FLAG_ARRAY 0x8079
	#define GL_VERTEX_ARRAY_SIZE 0x807A
	#define GL_VERTEX_ARRAY_TYPE 0x807B
	#define GL_VERTEX_ARRAY_STRIDE 0x807C
	#define GL_NORMAL_ARRAY_TYPE 0x807E
	#define GL_NORMAL_ARRAY_STRIDE 0x807F
	#define GL_COLOR_ARRAY_SIZE 0x8081
	#define GL_COLOR_ARRAY_TYPE 0x8082
	#define GL_COLOR_ARRAY_STRIDE 0x8083
	#define GL_INDEX_ARRAY_TYPE 0x8085
	#define GL_INDEX_ARRAY_STRIDE 0x8086
	#define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
	#define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
	#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
	#define GL_EDGE_FLAG_ARRAY_STRIDE 0x808C
	#define GL_VERTEX_ARRAY_POINTER 0x808E
	#define GL_NORMAL_ARRAY_POINTER 0x808F
	#define GL_COLOR_ARRAY_POINTER 0x8090
	#define GL_INDEX_ARRAY_POINTER 0x8091
	#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
	#define GL_EDGE_FLAG_ARRAY_POINTER 0x8093
	#define GL_COLOR_INDEX1_EXT 0x80E2
	#define GL_COLOR_INDEX2_EXT 0x80E3
	#define GL_COLOR_INDEX4_EXT 0x80E4
	#define GL_COLOR_INDEX8_EXT 0x80E5
	#define GL_COLOR_INDEX12_EXT 0x80E6
	#define GL_COLOR_INDEX16_EXT 0x80E7
	#define GL_EVAL_BIT 0x00010000
	#define GL_LIST_BIT 0x00020000
	#define GL_TEXTURE_BIT 0x00040000
	#define GL_SCISSOR_BIT 0x00080000
	#define GL_ALL_ATTRIB_BITS 0x000fffff
	#define GL_CLIENT_ALL_ATTRIB_BITS 0xffffffff*/
	typedef void (_stdcall* glAccum)(GLenum op, GLfloat value);
	typedef void (_stdcall* glAlphaFunc)(GLenum func, GLclampf ref);
	typedef GLboolean(_stdcall* glAreTexturesResident)(GLsizei n, const GLuint* textures, GLboolean* residences);
	typedef void (_stdcall* glArrayElement)(GLint i);
	typedef void (_stdcall* glBegin)(GLenum mode);
	typedef void (_stdcall* glBindTexture)(GLenum target, GLuint texture);
	typedef void (_stdcall* glBitmap)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte* bitmap);
	typedef void (_stdcall* glBlendFunc)(GLenum sfactor, GLenum dfactor);
	typedef void (_stdcall* glCallList)(GLuint list);
	typedef void (_stdcall* glCallLists)(GLsizei n, GLenum type, const void* lists);
	typedef void (_stdcall* glClear)(GLbitfield mask);
	typedef void (_stdcall* glClearAccum)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	typedef void (_stdcall* glClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	typedef void (_stdcall* glClearDepth)(GLclampd depth);
	typedef void (_stdcall* glClearIndex)(GLfloat c);
	typedef void (_stdcall* glClearStencil)(GLint s);
	typedef void (_stdcall* glClipPlane)(GLenum plane, const GLdouble* equation);
	typedef void (_stdcall* glColor3b)(GLbyte red, GLbyte green, GLbyte blue);
	typedef void (_stdcall* glColor3bv)(const GLbyte* v);
	typedef void (_stdcall* glColor3d)(GLdouble red, GLdouble green, GLdouble blue);
	typedef void (_stdcall* glColor3dv)(const GLdouble* v);
	typedef void (_stdcall* glColor3f)(GLfloat red, GLfloat green, GLfloat blue);
	typedef void (_stdcall* glColor3fv)(const GLfloat* v);
	typedef void (_stdcall* glColor3i)(GLint red, GLint green, GLint blue);
	typedef void (_stdcall* glColor3iv)(const GLint* v);
	typedef void (_stdcall* glColor3s)(GLshort red, GLshort green, GLshort blue);
	typedef void (_stdcall* glColor3sv)(const GLshort* v);
	typedef void (_stdcall* glColor3ub)(GLubyte red, GLubyte green, GLubyte blue);
	typedef void (_stdcall* glColor3ubv)(const GLubyte* v);
	typedef void (_stdcall* glColor3ui)(GLuint red, GLuint green, GLuint blue);
	typedef void (_stdcall* glColor3uiv)(const GLuint* v);
	typedef void (_stdcall* glColor3us)(GLushort red, GLushort green, GLushort blue);
	typedef void (_stdcall* glColor3usv)(const GLushort* v);
	typedef void (_stdcall* glColor4b)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
	typedef void (_stdcall* glColor4bv)(const GLbyte* v);
	typedef void (_stdcall* glColor4d)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
	typedef void (_stdcall* glColor4dv)(const GLdouble* v);
	typedef void (_stdcall* glColor4f)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	typedef void (_stdcall* glColor4fv)(const GLfloat* v);
	typedef void (_stdcall* glColor4i)(GLint red, GLint green, GLint blue, GLint alpha);
	typedef void (_stdcall* glColor4iv)(const GLint* v);
	typedef void (_stdcall* glColor4s)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
	typedef void (_stdcall* glColor4sv)(const GLshort* v);
	typedef void (_stdcall* glColor4ub)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
	typedef void (_stdcall* glColor4ubv)(const GLubyte* v);
	typedef void (_stdcall* glColor4ui)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
	typedef void (_stdcall* glColor4uiv)(const GLuint* v);
	typedef void (_stdcall* glColor4us)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
	typedef void (_stdcall* glColor4usv)(const GLushort* v);
	typedef void (_stdcall* glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
	typedef void (_stdcall* glColorMaterial)(GLenum face, GLenum mode);
	typedef void (_stdcall* glColorPointer)(GLint size, GLenum type, GLsizei stride, const void* pointer);
	typedef void (_stdcall* glCopyPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
	typedef void (_stdcall* glCopyTexImage1D)(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
	typedef void (_stdcall* glCopyTexImage2D)(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	typedef void (_stdcall* glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	typedef void (_stdcall* glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	typedef void (_stdcall* glCullFace)(GLenum mode);
	typedef void (_stdcall* glDeleteLists)(GLuint list, GLsizei range);
	typedef void (_stdcall* glDeleteTextures)(GLsizei n, const GLuint* textures);
	typedef void (_stdcall* glDepthFunc)(GLenum func);
	typedef void (_stdcall* glDepthMask)(GLboolean flag);
	typedef void (_stdcall* glDepthRange)(GLclampd zNear, GLclampd zFar);
	typedef void (_stdcall* glDisable)(GLenum cap);
	typedef void (_stdcall* glDisableClientState)(GLenum array);
	typedef void (_stdcall* glDrawArrays)(GLenum mode, GLint first, GLsizei count);
	typedef void (_stdcall* glDrawBuffer)(GLenum mode);
	typedef void (_stdcall* glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void* indices);
	typedef void (_stdcall* glDrawPixels)(GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
	typedef void (_stdcall* glEdgeFlag)(GLboolean flag);
	typedef void (_stdcall* glEdgeFlagPointer)(GLsizei stride, const void* pointer);
	typedef void (_stdcall* glEdgeFlagv)(const GLboolean* flag);
	typedef void (_stdcall* glEnable)(GLenum cap);
	typedef void (_stdcall* glEnableClientState)(GLenum array);
	typedef void (_stdcall* glEnd)(void);
	typedef void (_stdcall* glEndList)(void);
	typedef void (_stdcall* glEvalCoord1d)(GLdouble u);
	typedef void (_stdcall* glEvalCoord1dv)(const GLdouble* u);
	typedef void (_stdcall* glEvalCoord1f)(GLfloat u);
	typedef void (_stdcall* glEvalCoord1fv)(const GLfloat* u);
	typedef void (_stdcall* glEvalCoord2d)(GLdouble u, GLdouble v);
	typedef void (_stdcall* glEvalCoord2dv)(const GLdouble* u);
	typedef void (_stdcall* glEvalCoord2f)(GLfloat u, GLfloat v);
	typedef void (_stdcall* glEvalCoord2fv)(const GLfloat* u);
	typedef void (_stdcall* glEvalMesh1)(GLenum mode, GLint i1, GLint i2);
	typedef void (_stdcall* glEvalMesh2)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
	typedef void (_stdcall* glEvalPoint1)(GLint i);
	typedef void (_stdcall* glEvalPoint2)(GLint i, GLint j);
	typedef void (_stdcall* glFeedbackBuffer)(GLsizei size, GLenum type, GLfloat* buffer);
	typedef void (_stdcall* glFinish)(void);
	typedef void (_stdcall* glFlush)(void);
	typedef void (_stdcall* glFogf)(GLenum pname, GLfloat param);
	typedef void (_stdcall* glFogfv)(GLenum pname, const GLfloat* params);
	typedef void (_stdcall* glFogi)(GLenum pname, GLint param);
	typedef void (_stdcall* glFogiv)(GLenum pname, const GLint* params);
	typedef void (_stdcall* glFrontFace)(GLenum mode);
	typedef void (_stdcall* glFrustum)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
	typedef GLuint (_stdcall* glGenLists)(GLsizei range);
	typedef void (_stdcall* glGenTextures)(GLsizei n, GLuint* textures);
	typedef void (_stdcall* glGetBooleanv)(GLenum pname, GLboolean* params);
	typedef void (_stdcall* glGetClipPlane)(GLenum plane, GLdouble* equation);
	typedef void (_stdcall* glGetDoublev)(GLenum pname, GLdouble* params);
	typedef GLenum (_stdcall* glGetError)(void);
	typedef void (_stdcall* glGetFloatv)(GLenum pname, GLfloat* params);
	typedef void (_stdcall* glGetIntegerv)(GLenum pname, GLint* params);
	typedef void (_stdcall* glGetLightfv)(GLenum light, GLenum pname, GLfloat* params);
	typedef void (_stdcall* glGetLightiv)(GLenum light, GLenum pname, GLint* params);
	typedef void (_stdcall* glGetMapdv)(GLenum target, GLenum query, GLdouble* v);
	typedef void (_stdcall* glGetMapfv)(GLenum target, GLenum query, GLfloat* v);
	typedef void (_stdcall* glGetMapiv)(GLenum target, GLenum query, GLint* v);
	typedef void (_stdcall* glGetMaterialfv)(GLenum face, GLenum pname, GLfloat* params);
	typedef void (_stdcall* glGetMaterialiv)(GLenum face, GLenum pname, GLint* params);
	typedef void (_stdcall* glGetPixelMapfv)(GLenum map, GLfloat* values);
	typedef void (_stdcall* glGetPixelMapuiv)(GLenum map, GLuint* values);
	typedef void (_stdcall* glGetPixelMapusv)(GLenum map, GLushort* values);
	typedef void (_stdcall* glGetPointerv)(GLenum pname, void** params);
	typedef void (_stdcall* glGetPolygonStipple)(GLubyte* mask);
	typedef const GLubyte* (_stdcall* glGetString)(GLenum name);
	typedef void (_stdcall* glGetTexEnvfv)(GLenum target, GLenum pname, GLfloat* params);
	typedef void (_stdcall* glGetTexEnviv)(GLenum target, GLenum pname, GLint* params);
	typedef void (_stdcall* glGetTexGendv)(GLenum coord, GLenum pname, GLdouble* params);
	typedef void (_stdcall* glGetTexGenfv)(GLenum coord, GLenum pname, GLfloat* params);
	typedef void (_stdcall* glGetTexGeniv)(GLenum coord, GLenum pname, GLint* params);
	typedef void (_stdcall* glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
	typedef void (_stdcall* glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat* params);
	typedef void (_stdcall* glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint* params);
	typedef void (_stdcall* glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat* params);
	typedef void (_stdcall* glGetTexParameteriv)(GLenum target, GLenum pname, GLint* params);
	typedef void (_stdcall* glHint)(GLenum target, GLenum mode);
	typedef void (_stdcall* glIndexMask)(GLuint mask);
	typedef void (_stdcall* glIndexPointer)(GLenum type, GLsizei stride, const void* pointer);
	typedef void (_stdcall* glIndexd)(GLdouble c);
	typedef void (_stdcall* glIndexdv)(const GLdouble* c);
	typedef void (_stdcall* glIndexf)(GLfloat c);
	typedef void (_stdcall* glIndexfv)(const GLfloat* c);
	typedef void (_stdcall* glIndexi)(GLint c);
	typedef void (_stdcall* glIndexiv)(const GLint* c);
	typedef void (_stdcall* glIndexs)(GLshort c);
	typedef void (_stdcall* glIndexsv)(const GLshort* c);
	typedef void (_stdcall* glIndexub)(GLubyte c);
	typedef void (_stdcall* glIndexubv)(const GLubyte* c);
	typedef void (_stdcall* glInitNames)(void);
	typedef void (_stdcall* glInterleavedArrays)(GLenum format, GLsizei stride, const void* pointer);
	typedef GLboolean (_stdcall* glIsEnabled)(GLenum cap);
	typedef GLboolean (_stdcall* glIsList)(GLuint list);
	typedef GLboolean (_stdcall* glIsTexture)(GLuint texture);
	typedef void (_stdcall* glLightModelf)(GLenum pname, GLfloat param);
	typedef void (_stdcall* glLightModelfv)(GLenum pname, const GLfloat* params);
	typedef void (_stdcall* glLightModeli)(GLenum pname, GLint param);
	typedef void (_stdcall* glLightModeliv)(GLenum pname, const GLint* params);
	typedef void (_stdcall* glLightf)(GLenum light, GLenum pname, GLfloat param);
	typedef void (_stdcall* glLightfv)(GLenum light, GLenum pname, const GLfloat* params);
	typedef void (_stdcall* glLighti)(GLenum light, GLenum pname, GLint param);
	typedef void (_stdcall* glLightiv)(GLenum light, GLenum pname, const GLint* params);
	typedef void (_stdcall* glLineStipple)(GLint factor, GLushort pattern);
	typedef void (_stdcall* glLineWidth)(GLfloat width);
	typedef void (_stdcall* glListBase)(GLuint base);
	typedef void (_stdcall* glLoadIdentity)(void);
	typedef void (_stdcall* glLoadMatrixd)(const GLdouble* m);
	typedef void (_stdcall* glLoadMatrixf)(const GLfloat* m);
	typedef void (_stdcall* glLoadName)(GLuint name);
	typedef void (_stdcall* glLogicOp)(GLenum opcode);
	typedef void (_stdcall* glMap1d)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble* points);
	typedef void (_stdcall* glMap1f)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat* points);
	typedef void (_stdcall* glMap2d)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble* points);
	typedef void (_stdcall* glMap2f)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat* points);
	typedef void (_stdcall* glMapGrid1d)(GLint un, GLdouble u1, GLdouble u2);
	typedef void (_stdcall* glMapGrid1f)(GLint un, GLfloat u1, GLfloat u2);
	typedef void (_stdcall* glMapGrid2d)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
	typedef void (_stdcall* glMapGrid2f)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
	typedef void (_stdcall* glMaterialf)(GLenum face, GLenum pname, GLfloat param);
	typedef void (_stdcall* glMaterialfv)(GLenum face, GLenum pname, const GLfloat* params);
	typedef void (_stdcall* glMateriali)(GLenum face, GLenum pname, GLint param);
	typedef void (_stdcall* glMaterialiv)(GLenum face, GLenum pname, const GLint* params);
	typedef void (_stdcall* glMatrixMode)(GLenum mode);
	typedef void (_stdcall* glMultMatrixd)(const GLdouble* m);
	typedef void (_stdcall* glMultMatrixf)(const GLfloat* m);
	typedef void (_stdcall* glNewList)(GLuint list, GLenum mode);
	typedef void (_stdcall* glNormal3b)(GLbyte nx, GLbyte ny, GLbyte nz);
	typedef void (_stdcall* glNormal3bv)(const GLbyte* v);
	typedef void (_stdcall* glNormal3d)(GLdouble nx, GLdouble ny, GLdouble nz);
	typedef void (_stdcall* glNormal3dv)(const GLdouble* v);
	typedef void (_stdcall* glNormal3f)(GLfloat nx, GLfloat ny, GLfloat nz);
	typedef void (_stdcall* glNormal3fv)(const GLfloat* v);
	typedef void (_stdcall* glNormal3i)(GLint nx, GLint ny, GLint nz);
	typedef void (_stdcall* glNormal3iv)(const GLint* v);
	typedef void (_stdcall* glNormal3s)(GLshort nx, GLshort ny, GLshort nz);
	typedef void (_stdcall* glNormal3sv)(const GLshort* v);
	typedef void (_stdcall* glNormalPointer)(GLenum type, GLsizei stride, const void* pointer);
	typedef void (_stdcall* glOrtho)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
	typedef void (_stdcall* glPassThrough)(GLfloat token);
	typedef void (_stdcall* glPixelMapfv)(GLenum map, GLsizei mapsize, const GLfloat* values);
	typedef void (_stdcall* glPixelMapuiv)(GLenum map, GLsizei mapsize, const GLuint* values);
	typedef void (_stdcall* glPixelMapusv)(GLenum map, GLsizei mapsize, const GLushort* values);
	typedef void (_stdcall* glPixelStoref)(GLenum pname, GLfloat param);
	typedef void (_stdcall* glPixelStorei)(GLenum pname, GLint param);
	typedef void (_stdcall* glPixelTransferf)(GLenum pname, GLfloat param);
	typedef void (_stdcall* glPixelTransferi)(GLenum pname, GLint param);
	typedef void (_stdcall* glPixelZoom)(GLfloat xfactor, GLfloat yfactor);
	typedef void (_stdcall* glPointSize)(GLfloat size);
	typedef void (_stdcall* glPolygonMode)(GLenum face, GLenum mode);
	typedef void (_stdcall* glPolygonOffset)(GLfloat factor, GLfloat units);
	typedef void (_stdcall* glPolygonStipple)(const GLubyte* mask);
	typedef void (_stdcall* glPopAttrib)(void);
	typedef void (_stdcall* glPopClientAttrib)(void);
	typedef void (_stdcall* glPopMatrix)(void);
	typedef void (_stdcall* glPopName)(void);
	typedef void (_stdcall* glPrioritizeTextures)(GLsizei n, const GLuint* textures, const GLclampf* priorities);
	typedef void (_stdcall* glPushAttrib)(GLbitfield mask);
	typedef void (_stdcall* glPushClientAttrib)(GLbitfield mask);
	typedef void (_stdcall* glPushMatrix)(void);
	typedef void (_stdcall* glPushName)(GLuint name);
	typedef void (_stdcall* glRasterPos2d)(GLdouble x, GLdouble y);
	typedef void (_stdcall* glRasterPos2dv)(const GLdouble* v);
	typedef void (_stdcall* glRasterPos2f)(GLfloat x, GLfloat y);
	typedef void (_stdcall* glRasterPos2fv)(const GLfloat* v);
	typedef void (_stdcall* glRasterPos2i)(GLint x, GLint y);
	typedef void (_stdcall* glRasterPos2iv)(const GLint* v);
	typedef void (_stdcall* glRasterPos2s)(GLshort x, GLshort y);
	typedef void (_stdcall* glRasterPos2sv)(const GLshort* v);
	typedef void (_stdcall* glRasterPos3d)(GLdouble x, GLdouble y, GLdouble z);
	typedef void (_stdcall* glRasterPos3dv)(const GLdouble* v);
	typedef void (_stdcall* glRasterPos3f)(GLfloat x, GLfloat y, GLfloat z);
	typedef void (_stdcall* glRasterPos3fv)(const GLfloat* v);
	typedef void (_stdcall* glRasterPos3i)(GLint x, GLint y, GLint z);
	typedef void (_stdcall* glRasterPos3iv)(const GLint* v);
	typedef void (_stdcall* glRasterPos3s)(GLshort x, GLshort y, GLshort z);
	typedef void (_stdcall* glRasterPos3sv)(const GLshort* v);
	typedef void (_stdcall* glRasterPos4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	typedef void (_stdcall* glRasterPos4dv)(const GLdouble* v);
	typedef void (_stdcall* glRasterPos4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	typedef void (_stdcall* glRasterPos4fv)(const GLfloat* v);
	typedef void (_stdcall* glRasterPos4i)(GLint x, GLint y, GLint z, GLint w);
	typedef void (_stdcall* glRasterPos4iv)(const GLint* v);
	typedef void (_stdcall* glRasterPos4s)(GLshort x, GLshort y, GLshort z, GLshort w);
	typedef void (_stdcall* glRasterPos4sv)(const GLshort* v);
	typedef void (_stdcall* glReadBuffer)(GLenum mode);
	typedef void (_stdcall* glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels);
	typedef void (_stdcall* glRectd)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
	typedef void (_stdcall* glRectdv)(const GLdouble* v1, const GLdouble* v2);
	typedef void (_stdcall* glRectf)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
	typedef void (_stdcall* glRectfv)(const GLfloat* v1, const GLfloat* v2);
	typedef void (_stdcall* glRecti)(GLint x1, GLint y1, GLint x2, GLint y2);
	typedef void (_stdcall* glRectiv)(const GLint* v1, const GLint* v2);
	typedef void (_stdcall* glRects)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
	typedef void (_stdcall* glRectsv)(const GLshort* v1, const GLshort* v2);
	typedef GLint (_stdcall* glRenderMode)(GLenum mode);
	typedef void (_stdcall* glRotated)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
	typedef void (_stdcall* glRotatef)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
	typedef void (_stdcall* glScaled)(GLdouble x, GLdouble y, GLdouble z);
	typedef void (_stdcall* glScalef)(GLfloat x, GLfloat y, GLfloat z);
	typedef void (_stdcall* glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
	typedef void (_stdcall* glSelectBuffer)(GLsizei size, GLuint* buffer);
	typedef void (_stdcall* glShadeModel)(GLenum mode);
	typedef void (_stdcall* glStencilFunc)(GLenum func, GLint ref, GLuint mask);
	typedef void (_stdcall* glStencilMask)(GLuint mask);
	typedef void (_stdcall* glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
	typedef void (_stdcall* glTexCoord1d)(GLdouble s);
	typedef void (_stdcall* glTexCoord1dv)(const GLdouble* v);
	typedef void (_stdcall* glTexCoord1f)(GLfloat s);
	typedef void (_stdcall* glTexCoord1fv)(const GLfloat* v);
	typedef void (_stdcall* glTexCoord1i)(GLint s);
	typedef void (_stdcall* glTexCoord1iv)(const GLint* v);
	typedef void (_stdcall* glTexCoord1s)(GLshort s);
	typedef void (_stdcall* glTexCoord1sv)(const GLshort* v);
	typedef void (_stdcall* glTexCoord2d)(GLdouble s, GLdouble t);
	typedef void (_stdcall* glTexCoord2dv)(const GLdouble* v);
	typedef void (_stdcall* glTexCoord2f)(GLfloat s, GLfloat t);
	typedef void (_stdcall* glTexCoord2fv)(const GLfloat* v);
	typedef void (_stdcall* glTexCoord2i)(GLint s, GLint t);
	typedef void (_stdcall* glTexCoord2iv)(const GLint* v);
	typedef void (_stdcall* glTexCoord2s)(GLshort s, GLshort t);
	typedef void (_stdcall* glTexCoord2sv)(const GLshort* v);
	typedef void (_stdcall* glTexCoord3d)(GLdouble s, GLdouble t, GLdouble r);
	typedef void (_stdcall* glTexCoord3dv)(const GLdouble* v);
	typedef void (_stdcall* glTexCoord3f)(GLfloat s, GLfloat t, GLfloat r);
	typedef void (_stdcall* glTexCoord3fv)(const GLfloat* v);
	typedef void (_stdcall* glTexCoord3i)(GLint s, GLint t, GLint r);
	typedef void (_stdcall* glTexCoord3iv)(const GLint* v);
	typedef void (_stdcall* glTexCoord3s)(GLshort s, GLshort t, GLshort r);
	typedef void (_stdcall* glTexCoord3sv)(const GLshort* v);
	typedef void (_stdcall* glTexCoord4d)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	typedef void (_stdcall* glTexCoord4dv)(const GLdouble* v);
	typedef void (_stdcall* glTexCoord4f)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	typedef void (_stdcall* glTexCoord4fv)(const GLfloat* v);
	typedef void (_stdcall* glTexCoord4i)(GLint s, GLint t, GLint r, GLint q);
	typedef void (_stdcall* glTexCoord4iv)(const GLint* v);
	typedef void (_stdcall* glTexCoord4s)(GLshort s, GLshort t, GLshort r, GLshort q);
	typedef void (_stdcall* glTexCoord4sv)(const GLshort* v);
	typedef void (_stdcall* glTexCoordPointer)(GLint size, GLenum type, GLsizei stride, const void* pointer);
	typedef void (_stdcall* glTexEnvf)(GLenum target, GLenum pname, GLfloat param);
	typedef void (_stdcall* glTexEnvfv)(GLenum target, GLenum pname, const GLfloat* params);
	typedef void (_stdcall* glTexEnvi)(GLenum target, GLenum pname, GLint param);
	typedef void (_stdcall* glTexEnviv)(GLenum target, GLenum pname, const GLint* params);
	typedef void (_stdcall* glTexGend)(GLenum coord, GLenum pname, GLdouble param);
	typedef void (_stdcall* glTexGendv)(GLenum coord, GLenum pname, const GLdouble* params);
	typedef void (_stdcall* glTexGenf)(GLenum coord, GLenum pname, GLfloat param);
	typedef void (_stdcall* glTexGenfv)(GLenum coord, GLenum pname, const GLfloat* params);
	typedef void (_stdcall* glTexGeni)(GLenum coord, GLenum pname, GLint param);
	typedef void (_stdcall* glTexGeniv)(GLenum coord, GLenum pname, const GLint* params);
	typedef void (_stdcall* glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
	typedef void (_stdcall* glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
	typedef void (_stdcall* glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
	typedef void (_stdcall* glTexParameterfv)(GLenum target, GLenum pname, const GLfloat* params);
	typedef void (_stdcall* glTexParameteri)(GLenum target, GLenum pname, GLint param);
	typedef void (_stdcall* glTexParameteriv)(GLenum target, GLenum pname, const GLint* params);
	typedef void (_stdcall* glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
	typedef void (_stdcall* glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
	typedef void (_stdcall* glTranslated)(GLdouble x, GLdouble y, GLdouble z);
	typedef void (_stdcall* glTranslatef)(GLfloat x, GLfloat y, GLfloat z);
	typedef void (_stdcall* glVertex2d)(GLdouble x, GLdouble y);
	typedef void (_stdcall* glVertex2dv)(const GLdouble* v);
	typedef void (_stdcall* glVertex2f)(GLfloat x, GLfloat y);
	typedef void (_stdcall* glVertex2fv)(const GLfloat* v);
	typedef void (_stdcall* glVertex2i)(GLint x, GLint y);
	typedef void (_stdcall* glVertex2iv)(const GLint* v);
	typedef void (_stdcall* glVertex2s)(GLshort x, GLshort y);
	typedef void (_stdcall* glVertex2sv)(const GLshort* v);
	typedef void (_stdcall* glVertex3d)(GLdouble x, GLdouble y, GLdouble z);
	typedef void (_stdcall* glVertex3dv)(const GLdouble* v);
	typedef void (_stdcall* glVertex3f)(GLfloat x, GLfloat y, GLfloat z);
	typedef void (_stdcall* glVertex3fv)(const GLfloat* v);
	typedef void (_stdcall* glVertex3i)(GLint x, GLint y, GLint z);
	typedef void (_stdcall* glVertex3iv)(const GLint* v);
	typedef void (_stdcall* glVertex3s)(GLshort x, GLshort y, GLshort z);
	typedef void (_stdcall* glVertex3sv)(const GLshort* v);
	typedef void (_stdcall* glVertex4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	typedef void (_stdcall* glVertex4dv)(const GLdouble* v);
	typedef void (_stdcall* glVertex4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	typedef void (_stdcall* glVertex4fv)(const GLfloat* v);
	typedef void (_stdcall* glVertex4i)(GLint x, GLint y, GLint z, GLint w);
	typedef void (_stdcall* glVertex4iv)(const GLint* v);
	typedef void (_stdcall* glVertex4s)(GLshort x, GLshort y, GLshort z, GLshort w);
	typedef void (_stdcall* glVertex4sv)(const GLshort* v);
	typedef void (_stdcall* glVertexPointer)(GLint size, GLenum type, GLsizei stride, const void* pointer);
	typedef void (_stdcall* glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
public:
	glAccum Accum;
	glAlphaFunc AlphaFunc;
	glAreTexturesResident AreTexturesResident;
	glArrayElement ArrayElement;
	glBegin Begin;
	glBindTexture BindTexture;
	glBitmap Bitmap;
	glBlendFunc BlendFunc;
	glCallList CallList;
	glCallLists CallLists;
	glClear Clear;
	glClearAccum ClearAccum;
	glClearColor ClearColor;
	glClearDepth ClearDepth;
	glClearIndex ClearIndex;
	glClearStencil ClearStencil;
	glClipPlane ClipPlane;
	glColor3b Color3b;
	glColor3bv Color3bv;
	glColor3d Color3d;
	glColor3dv Color3dv;
	glColor3f Color3f;
	glColor3fv Color3fv;
	glColor3i Color3i;
	glColor3iv Color3iv;
	glColor3s Color3s;
	glColor3sv Color3sv;
	glColor3ub Color3ub;
	glColor3ubv Color3ubv;
	glColor3ui Color3ui;
	glColor3uiv Color3uiv;
	glColor3us Color3us;
	glColor3usv Color3usv;
	glColor4b Color4b;
	glColor4bv Color4bv;
	glColor4d Color4d;
	glColor4dv Color4dv;
	glColor4f Color4f;
	glColor4fv Color4fv;
	glColor4i Color4i;
	glColor4iv Color4iv;
	glColor4s Color4s;
	glColor4sv Color4sv;
	glColor4ub Color4ub;
	glColor4ubv Color4ubv;
	glColor4ui Color4ui;
	glColor4uiv Color4uiv;
	glColor4us Color4us;
	glColor4usv Color4usv;
	glColorMask ColorMask;
	glColorMaterial ColorMaterial;
	glColorPointer ColorPointer;
	glCopyPixels CopyPixels;
	glCopyTexImage1D CopyTexImage1D;
	glCopyTexImage2D CopyTexImage2D;
	glCopyTexSubImage1D CopyTexSubImage1D;
	glCopyTexSubImage2D CopyTexSubImage2D;
	glCullFace CullFace;
	glDeleteLists DeleteLists;
	glDeleteTextures DeleteTextures;
	glDepthFunc DepthFunc;
	glDepthMask DepthMask;
	glDepthRange DepthRange;
	glDisable Disable;
	glDisableClientState DisableClientState;
	glDrawArrays DrawArrays;
	glDrawBuffer DrawBuffer;
	glDrawElements DrawElements;
	glDrawPixels DrawPixels;
	glEdgeFlag EdgeFlag;
	glEdgeFlagPointer EdgeFlagPointer;
	glEdgeFlagv EdgeFlagv;
	glEnable Enable;
	glEnableClientState EnableClientState;
	glEnd End;
	glEndList EndList;
	glEvalCoord1d EvalCoord1d;
	glEvalCoord1dv EvalCoord1dv;
	glEvalCoord1f EvalCoord1f;
	glEvalCoord1fv EvalCoord1fv;
	glEvalCoord2d EvalCoord2d;
	glEvalCoord2dv EvalCoord2dv;
	glEvalCoord2f EvalCoord2f;
	glEvalCoord2fv EvalCoord2fv;
	glEvalMesh1 EvalMesh1;
	glEvalMesh2 EvalMesh2;
	glEvalPoint1 EvalPoint1;
	glEvalPoint2 EvalPoint2;
	glFeedbackBuffer FeedbackBuffer;
	glFinish Finish;
	glFlush Flush;
	glFogf Fogf;
	glFogfv Fogfv;
	glFogi Fogi;
	glFogiv Fogiv;
	glFrontFace FrontFace;
	glFrustum Frustum;
	glGenLists GenLists;
	glGenTextures GenTextures;
	glGetBooleanv GetBooleanv;
	glGetClipPlane GetClipPlane;
	glGetDoublev GetDoublev;
	glGetError GetError;
	glGetFloatv GetFloatv;
	glGetIntegerv GetIntegerv;
	glGetLightfv GetLightfv;
	glGetLightiv GetLightiv;
	glGetMapdv GetMapdv;
	glGetMapfv GetMapfv;
	glGetMapiv GetMapiv;
	glGetMaterialfv GetMaterialfv;
	glGetMaterialiv GetMaterialiv;
	glGetPixelMapfv GetPixelMapfv;
	glGetPixelMapuiv GetPixelMapuiv;
	glGetPixelMapusv GetPixelMapusv;
	glGetPointerv GetPointerv;
	glGetPolygonStipple GetPolygonStipple;
	glGetString GetString;
	glGetTexEnvfv GetTexEnvfv;
	glGetTexEnviv GetTexEnviv;
	glGetTexGendv GetTexGendv;
	glGetTexGenfv GetTexGenfv;
	glGetTexGeniv GetTexGeniv;
	glGetTexImage GetTexImage;
	glGetTexLevelParameterfv GetTexLevelParameterfv;
	glGetTexLevelParameteriv GetTexLevelParameteriv;
	glGetTexParameterfv GetTexParameterfv;
	glGetTexParameteriv GetTexParameteriv;
	glHint Hint;
	glIndexMask IndexMask;
	glIndexPointer IndexPointer;
	glIndexd Indexd;
	glIndexdv Indexdv;
	glIndexf Indexf;
	glIndexfv Indexfv;
	glIndexi Indexi;
	glIndexiv Indexiv;
	glIndexs Indexs;
	glIndexsv Indexsv;
	glIndexub Indexub;
	glIndexubv Indexubv;
	glInitNames InitNames;
	glInterleavedArrays InterleavedArrays;
	glIsEnabled IsEnabled;
	glIsList IsList;
	glIsTexture IsTexture;
	glLightModelf LightModelf;
	glLightModelfv LightModelfv;
	glLightModeli LightModeli;
	glLightModeliv LightModeliv;
	glLightf Lightf;
	glLightfv Lightfv;
	glLighti Lighti;
	glLightiv Lightiv;
	glLineStipple LineStipple;
	glLineWidth LineWidth;
	glListBase ListBase;
	glLoadIdentity LoadIdentity;
	glLoadMatrixd LoadMatrixd;
	glLoadMatrixf LoadMatrixf;
	glLoadName LoadName;
	glLogicOp LogicOp;
	glMap1d Map1d;
	glMap1f Map1f;
	glMap2d Map2d;
	glMap2f Map2f;
	glMapGrid1d MapGrid1d;
	glMapGrid1f MapGrid1f;
	glMapGrid2d MapGrid2d;
	glMapGrid2f MapGrid2f;
	glMaterialf Materialf;
	glMaterialfv Materialfv;
	glMateriali Materiali;
	glMaterialiv Materialiv;
	glMatrixMode MatrixMode;
	glMultMatrixd MultMatrixd;
	glMultMatrixf MultMatrixf;
	glNewList NewList;
	glNormal3b Normal3b;
	glNormal3bv Normal3bv;
	glNormal3d Normal3d;
	glNormal3dv Normal3dv;
	glNormal3f Normal3f;
	glNormal3fv Normal3fv;
	glNormal3i Normal3i;
	glNormal3iv Normal3iv;
	glNormal3s Normal3s;
	glNormal3sv Normal3sv;
	glNormalPointer NormalPointer;
	glOrtho Ortho;
	glPassThrough PassThrough;
	glPixelMapfv PixelMapfv;
	glPixelMapuiv PixelMapuiv;
	glPixelMapusv PixelMapusv;
	glPixelStoref PixelStoref;
	glPixelStorei PixelStorei;
	glPixelTransferf PixelTransferf;
	glPixelTransferi PixelTransferi;
	glPixelZoom PixelZoom;
	glPointSize PointSize;
	glPolygonMode PolygonMode;
	glPolygonOffset PolygonOffset;
	glPolygonStipple PolygonStipple;
	glPopAttrib PopAttrib;
	glPopClientAttrib PopClientAttrib;
	glPopMatrix PopMatrix;
	glPopName PopName;
	glPrioritizeTextures PrioritizeTextures;
	glPushAttrib PushAttrib;
	glPushClientAttrib PushClientAttrib;
	glPushMatrix PushMatrix;
	glPushName PushName;
	glRasterPos2d RasterPos2d;
	glRasterPos2dv RasterPos2dv;
	glRasterPos2f RasterPos2f;
	glRasterPos2fv RasterPos2fv;
	glRasterPos2i RasterPos2i;
	glRasterPos2iv RasterPos2iv;
	glRasterPos2s RasterPos2s;
	glRasterPos2sv RasterPos2sv;
	glRasterPos3d RasterPos3d;
	glRasterPos3dv RasterPos3dv;
	glRasterPos3f RasterPos3f;
	glRasterPos3fv RasterPos3fv;
	glRasterPos3i RasterPos3i;
	glRasterPos3iv RasterPos3iv;
	glRasterPos3s RasterPos3s;
	glRasterPos3sv RasterPos3sv;
	glRasterPos4d RasterPos4d;
	glRasterPos4dv RasterPos4dv;
	glRasterPos4f RasterPos4f;
	glRasterPos4fv RasterPos4fv;
	glRasterPos4i RasterPos4i;
	glRasterPos4iv RasterPos4iv;
	glRasterPos4s RasterPos4s;
	glRasterPos4sv RasterPos4sv;
	glReadBuffer ReadBuffer;
	glReadPixels ReadPixels;
	glRectd Rectd;
	glRectdv Rectdv;
	glRectf Rectf;
	glRectfv Rectfv;
	glRecti Recti;
	glRectiv Rectiv;
	glRects Rects;
	glRectsv Rectsv;
	glRenderMode RenderMode;
	glRotated Rotated;
	glRotatef Rotatef;
	glScaled Scaled;
	glScalef Scalef;
	glScissor Scissor;
	glSelectBuffer SelectBuffer;
	glShadeModel ShadeModel;
	glStencilFunc StencilFunc;
	glStencilMask StencilMask;
	glStencilOp StencilOp;
	glTexCoord1d TexCoord1d;
	glTexCoord1dv TexCoord1dv;
	glTexCoord1f TexCoord1f;
	glTexCoord1fv TexCoord1fv;
	glTexCoord1i TexCoord1i;
	glTexCoord1iv TexCoord1iv;
	glTexCoord1s TexCoord1s;
	glTexCoord1sv TexCoord1sv;
	glTexCoord2d TexCoord2d;
	glTexCoord2dv TexCoord2dv;
	glTexCoord2f TexCoord2f;
	glTexCoord2fv TexCoord2fv;
	glTexCoord2i TexCoord2i;
	glTexCoord2iv TexCoord2iv;
	glTexCoord2s TexCoord2s;
	glTexCoord2sv TexCoord2sv;
	glTexCoord3d TexCoord3d;
	glTexCoord3dv TexCoord3dv;
	glTexCoord3f TexCoord3f;
	glTexCoord3fv TexCoord3fv;
	glTexCoord3i TexCoord3i;
	glTexCoord3iv TexCoord3iv;
	glTexCoord3s TexCoord3s;
	glTexCoord3sv TexCoord3sv;
	glTexCoord4d TexCoord4d;
	glTexCoord4dv TexCoord4dv;
	glTexCoord4f TexCoord4f;
	glTexCoord4fv TexCoord4fv;
	glTexCoord4i TexCoord4i;
	glTexCoord4iv TexCoord4iv;
	glTexCoord4s TexCoord4s;
	glTexCoord4sv TexCoord4sv;
	glTexCoordPointer TexCoordPointer;
	glTexEnvf TexEnvf;
	glTexEnvfv TexEnvfv;
	glTexEnvi TexEnvi;
	glTexEnviv TexEnviv;
	glTexGend TexGend;
	glTexGendv TexGendv;
	glTexGenf TexGenf;
	glTexGenfv TexGenfv;
	glTexGeni TexGeni;
	glTexGeniv TexGeniv;
	glTexImage1D TexImage1D;
	glTexImage2D TexImage2D;
	glTexParameterf TexParameterf;
	glTexParameterfv TexParameterfv;
	glTexParameteri TexParameteri;
	glTexParameteriv TexParameteriv;
	glTexSubImage1D TexSubImage1D;
	glTexSubImage2D TexSubImage2D;
	glTranslated Translated;
	glTranslatef Translatef;
	glVertex2d Vertex2d;
	glVertex2dv Vertex2dv;
	glVertex2f Vertex2f;
	glVertex2fv Vertex2fv;
	glVertex2i Vertex2i;
	glVertex2iv Vertex2iv;
	glVertex2s Vertex2s;
	glVertex2sv Vertex2sv;
	glVertex3d Vertex3d;
	glVertex3dv Vertex3dv;
	glVertex3f Vertex3f;
	glVertex3fv Vertex3fv;
	glVertex3i Vertex3i;
	glVertex3iv Vertex3iv;
	glVertex3s Vertex3s;
	glVertex3sv Vertex3sv;
	glVertex4d Vertex4d;
	glVertex4dv Vertex4dv;
	glVertex4f Vertex4f;
	glVertex4fv Vertex4fv;
	glVertex4i Vertex4i;
	glVertex4iv Vertex4iv;
	glVertex4s Vertex4s;
	glVertex4sv Vertex4sv;
	glVertexPointer VertexPointer;
	glViewport Viewport;
	GLcontext110() = default;
	explicit GLcontext110(HDC device) : GLcontextBase(device) {
		// DefaultLoadLibrary("Windows/Sys____/opengl32.dll")
		HMODULE opengl32 = GetModuleHandle(L"opengl32.dll");
		assert(opengl32 != nullptr);
		this->Accum = reinterpret_cast<glAccum>(GetProcAddress(opengl32, "glAccum"));
		this->AlphaFunc = reinterpret_cast<glAlphaFunc>(GetProcAddress(opengl32, "glAlphaFunc"));
		this->AreTexturesResident = reinterpret_cast<glAreTexturesResident>(GetProcAddress(opengl32, "glAreTexturesResident"));
		this->ArrayElement = reinterpret_cast<glArrayElement>(GetProcAddress(opengl32, "glArrayElement"));
		this->Begin = reinterpret_cast<glBegin>(GetProcAddress(opengl32, "glBegin"));
		this->BindTexture = reinterpret_cast<glBindTexture>(GetProcAddress(opengl32, "glBindTexture"));
		this->Bitmap = reinterpret_cast<glBitmap>(GetProcAddress(opengl32, "glBitmap"));
		this->BlendFunc = reinterpret_cast<glBlendFunc>(GetProcAddress(opengl32, "glBlendFunc"));
		this->CallList = reinterpret_cast<glCallList>(GetProcAddress(opengl32, "glCallList"));
		this->CallLists = reinterpret_cast<glCallLists>(GetProcAddress(opengl32, "glCallLists"));
		this->Clear = reinterpret_cast<glClear>(GetProcAddress(opengl32, "glClear"));
		this->ClearAccum = reinterpret_cast<glClearAccum>(GetProcAddress(opengl32, "glClearAccum"));
		this->ClearColor = reinterpret_cast<glClearColor>(GetProcAddress(opengl32, "glClearColor"));
		this->ClearDepth = reinterpret_cast<glClearDepth>(GetProcAddress(opengl32, "glClearDepth"));
		this->ClearIndex = reinterpret_cast<glClearIndex>(GetProcAddress(opengl32, "glClearIndex"));
		this->ClearStencil = reinterpret_cast<glClearStencil>(GetProcAddress(opengl32, "glClearStencil"));
		this->ClipPlane = reinterpret_cast<glClipPlane>(GetProcAddress(opengl32, "glClipPlane"));
		this->Color3b = reinterpret_cast<glColor3b>(GetProcAddress(opengl32, "glColor3b"));
		this->Color3bv = reinterpret_cast<glColor3bv>(GetProcAddress(opengl32, "glColor3bv"));
		this->Color3d = reinterpret_cast<glColor3d>(GetProcAddress(opengl32, "glColor3d"));
		this->Color3dv = reinterpret_cast<glColor3dv>(GetProcAddress(opengl32, "glColor3dv"));
		this->Color3f = reinterpret_cast<glColor3f>(GetProcAddress(opengl32, "glColor3f"));
		this->Color3fv = reinterpret_cast<glColor3fv>(GetProcAddress(opengl32, "glColor3fv"));
		this->Color3i = reinterpret_cast<glColor3i>(GetProcAddress(opengl32, "glColor3i"));
		this->Color3iv = reinterpret_cast<glColor3iv>(GetProcAddress(opengl32, "glColor3iv"));
		this->Color3s = reinterpret_cast<glColor3s>(GetProcAddress(opengl32, "glColor3s"));
		this->Color3sv = reinterpret_cast<glColor3sv>(GetProcAddress(opengl32, "glColor3sv"));
		this->Color3ub = reinterpret_cast<glColor3ub>(GetProcAddress(opengl32, "glColor3ub"));
		this->Color3ubv = reinterpret_cast<glColor3ubv>(GetProcAddress(opengl32, "glColor3ubv"));
		this->Color3ui = reinterpret_cast<glColor3ui>(GetProcAddress(opengl32, "glColor3ui"));
		this->Color3uiv = reinterpret_cast<glColor3uiv>(GetProcAddress(opengl32, "glColor3uiv"));
		this->Color3us = reinterpret_cast<glColor3us>(GetProcAddress(opengl32, "glColor3us"));
		this->Color3usv = reinterpret_cast<glColor3usv>(GetProcAddress(opengl32, "glColor3usv"));
		this->Color4b = reinterpret_cast<glColor4b>(GetProcAddress(opengl32, "glColor4b"));
		this->Color4bv = reinterpret_cast<glColor4bv>(GetProcAddress(opengl32, "glColor4bv"));
		this->Color4d = reinterpret_cast<glColor4d>(GetProcAddress(opengl32, "glColor4d"));
		this->Color4dv = reinterpret_cast<glColor4dv>(GetProcAddress(opengl32, "glColor4dv"));
		this->Color4f = reinterpret_cast<glColor4f>(GetProcAddress(opengl32, "glColor4f"));
		this->Color4fv = reinterpret_cast<glColor4fv>(GetProcAddress(opengl32, "glColor4fv"));
		this->Color4i = reinterpret_cast<glColor4i>(GetProcAddress(opengl32, "glColor4i"));
		this->Color4iv = reinterpret_cast<glColor4iv>(GetProcAddress(opengl32, "glColor4iv"));
		this->Color4s = reinterpret_cast<glColor4s>(GetProcAddress(opengl32, "glColor4s"));
		this->Color4sv = reinterpret_cast<glColor4sv>(GetProcAddress(opengl32, "glColor4sv"));
		this->Color4ub = reinterpret_cast<glColor4ub>(GetProcAddress(opengl32, "glColor4ub"));
		this->Color4ubv = reinterpret_cast<glColor4ubv>(GetProcAddress(opengl32, "glColor4ubv"));
		this->Color4ui = reinterpret_cast<glColor4ui>(GetProcAddress(opengl32, "glColor4ui"));
		this->Color4uiv = reinterpret_cast<glColor4uiv>(GetProcAddress(opengl32, "glColor4uiv"));
		this->Color4us = reinterpret_cast<glColor4us>(GetProcAddress(opengl32, "glColor4us"));
		this->Color4usv = reinterpret_cast<glColor4usv>(GetProcAddress(opengl32, "glColor4usv"));
		this->ColorMask = reinterpret_cast<glColorMask>(GetProcAddress(opengl32, "glColorMask"));
		this->ColorMaterial = reinterpret_cast<glColorMaterial>(GetProcAddress(opengl32, "glColorMaterial"));
		this->ColorPointer = reinterpret_cast<glColorPointer>(GetProcAddress(opengl32, "glColorPointer"));
		this->CopyPixels = reinterpret_cast<glCopyPixels>(GetProcAddress(opengl32, "glCopyPixels"));
		this->CopyTexImage1D = reinterpret_cast<glCopyTexImage1D>(GetProcAddress(opengl32, "glCopyTexImage1D"));
		this->CopyTexImage2D = reinterpret_cast<glCopyTexImage2D>(GetProcAddress(opengl32, "glCopyTexImage2D"));
		this->CopyTexSubImage1D = reinterpret_cast<glCopyTexSubImage1D>(GetProcAddress(opengl32, "glCopyTexSubImage1D"));
		this->CopyTexSubImage2D = reinterpret_cast<glCopyTexSubImage2D>(GetProcAddress(opengl32, "glCopyTexSubImage2D"));
		this->CullFace = reinterpret_cast<glCullFace>(GetProcAddress(opengl32, "glCullFace"));
		this->DeleteLists = reinterpret_cast<glDeleteLists>(GetProcAddress(opengl32, "glDeleteLists"));
		this->DeleteTextures = reinterpret_cast<glDeleteTextures>(GetProcAddress(opengl32, "glDeleteTextures"));
		this->DepthFunc = reinterpret_cast<glDepthFunc>(GetProcAddress(opengl32, "glDepthFunc"));
		this->DepthMask = reinterpret_cast<glDepthMask>(GetProcAddress(opengl32, "glDepthMask"));
		this->DepthRange = reinterpret_cast<glDepthRange>(GetProcAddress(opengl32, "glDepthRange"));
		this->Disable = reinterpret_cast<glDisable>(GetProcAddress(opengl32, "glDisable"));
		this->DisableClientState = reinterpret_cast<glDisableClientState>(GetProcAddress(opengl32, "glDisableClientState"));
		this->DrawArrays = reinterpret_cast<glDrawArrays>(GetProcAddress(opengl32, "glDrawArrays"));
		this->DrawBuffer = reinterpret_cast<glDrawBuffer>(GetProcAddress(opengl32, "glDrawBuffer"));
		this->DrawElements = reinterpret_cast<glDrawElements>(GetProcAddress(opengl32, "glDrawElements"));
		this->DrawPixels = reinterpret_cast<glDrawPixels>(GetProcAddress(opengl32, "glDrawPixels"));
		this->EdgeFlag = reinterpret_cast<glEdgeFlag>(GetProcAddress(opengl32, "glEdgeFlag"));
		this->EdgeFlagPointer = reinterpret_cast<glEdgeFlagPointer>(GetProcAddress(opengl32, "glEdgeFlagPointer"));
		this->EdgeFlagv = reinterpret_cast<glEdgeFlagv>(GetProcAddress(opengl32, "glEdgeFlagv"));
		this->Enable = reinterpret_cast<glEnable>(GetProcAddress(opengl32, "glEnable"));
		this->EnableClientState = reinterpret_cast<glEnableClientState>(GetProcAddress(opengl32, "glEnableClientState"));
		this->End = reinterpret_cast<glEnd>(GetProcAddress(opengl32, "glEnd"));
		this->EndList = reinterpret_cast<glEndList>(GetProcAddress(opengl32, "glEndList"));
		this->EvalCoord1d = reinterpret_cast<glEvalCoord1d>(GetProcAddress(opengl32, "glEvalCoord1d"));
		this->EvalCoord1dv = reinterpret_cast<glEvalCoord1dv>(GetProcAddress(opengl32, "glEvalCoord1dv"));
		this->EvalCoord1f = reinterpret_cast<glEvalCoord1f>(GetProcAddress(opengl32, "glEvalCoord1f"));
		this->EvalCoord1fv = reinterpret_cast<glEvalCoord1fv>(GetProcAddress(opengl32, "glEvalCoord1fv"));
		this->EvalCoord2d = reinterpret_cast<glEvalCoord2d>(GetProcAddress(opengl32, "glEvalCoord2d"));
		this->EvalCoord2dv = reinterpret_cast<glEvalCoord2dv>(GetProcAddress(opengl32, "glEvalCoord2dv"));
		this->EvalCoord2f = reinterpret_cast<glEvalCoord2f>(GetProcAddress(opengl32, "glEvalCoord2f"));
		this->EvalCoord2fv = reinterpret_cast<glEvalCoord2fv>(GetProcAddress(opengl32, "glEvalCoord2fv"));
		this->EvalMesh1 = reinterpret_cast<glEvalMesh1>(GetProcAddress(opengl32, "glEvalMesh1"));
		this->EvalMesh2 = reinterpret_cast<glEvalMesh2>(GetProcAddress(opengl32, "glEvalMesh2"));
		this->EvalPoint1 = reinterpret_cast<glEvalPoint1>(GetProcAddress(opengl32, "glEvalPoint1"));
		this->EvalPoint2 = reinterpret_cast<glEvalPoint2>(GetProcAddress(opengl32, "glEvalPoint2"));
		this->FeedbackBuffer = reinterpret_cast<glFeedbackBuffer>(GetProcAddress(opengl32, "glFeedbackBuffer"));
		this->Finish = reinterpret_cast<glFinish>(GetProcAddress(opengl32, "glFinish"));
		this->Flush = reinterpret_cast<glFlush>(GetProcAddress(opengl32, "glFlush"));
		this->Fogf = reinterpret_cast<glFogf>(GetProcAddress(opengl32, "glFogf"));
		this->Fogfv = reinterpret_cast<glFogfv>(GetProcAddress(opengl32, "glFogfv"));
		this->Fogi = reinterpret_cast<glFogi>(GetProcAddress(opengl32, "glFogi"));
		this->Fogiv = reinterpret_cast<glFogiv>(GetProcAddress(opengl32, "glFogiv"));
		this->FrontFace = reinterpret_cast<glFrontFace>(GetProcAddress(opengl32, "glFrontFace"));
		this->Frustum = reinterpret_cast<glFrustum>(GetProcAddress(opengl32, "glFrustum"));
		this->GenLists = reinterpret_cast<glGenLists>(GetProcAddress(opengl32, "glGenLists"));
		this->GenTextures = reinterpret_cast<glGenTextures>(GetProcAddress(opengl32, "glGenTextures"));
		this->GetBooleanv = reinterpret_cast<glGetBooleanv>(GetProcAddress(opengl32, "glGetBooleanv"));
		this->GetClipPlane = reinterpret_cast<glGetClipPlane>(GetProcAddress(opengl32, "glGetClipPlane"));
		this->GetDoublev = reinterpret_cast<glGetDoublev>(GetProcAddress(opengl32, "glGetDoublev"));
		this->GetError = reinterpret_cast<glGetError>(GetProcAddress(opengl32, "glGetError"));
		this->GetFloatv = reinterpret_cast<glGetFloatv>(GetProcAddress(opengl32, "glGetFloatv"));
		this->GetIntegerv = reinterpret_cast<glGetIntegerv>(GetProcAddress(opengl32, "glGetIntegerv"));
		this->GetLightfv = reinterpret_cast<glGetLightfv>(GetProcAddress(opengl32, "glGetLightfv"));
		this->GetLightiv = reinterpret_cast<glGetLightiv>(GetProcAddress(opengl32, "glGetLightiv"));
		this->GetMapdv = reinterpret_cast<glGetMapdv>(GetProcAddress(opengl32, "glGetMapdv"));
		this->GetMapfv = reinterpret_cast<glGetMapfv>(GetProcAddress(opengl32, "glGetMapfv"));
		this->GetMapiv = reinterpret_cast<glGetMapiv>(GetProcAddress(opengl32, "glGetMapiv"));
		this->GetMaterialfv = reinterpret_cast<glGetMaterialfv>(GetProcAddress(opengl32, "glGetMaterialfv"));
		this->GetMaterialiv = reinterpret_cast<glGetMaterialiv>(GetProcAddress(opengl32, "glGetMaterialiv"));
		this->GetPixelMapfv = reinterpret_cast<glGetPixelMapfv>(GetProcAddress(opengl32, "glGetPixelMapfv"));
		this->GetPixelMapuiv = reinterpret_cast<glGetPixelMapuiv>(GetProcAddress(opengl32, "glGetPixelMapuiv"));
		this->GetPixelMapusv = reinterpret_cast<glGetPixelMapusv>(GetProcAddress(opengl32, "glGetPixelMapusv"));
		this->GetPointerv = reinterpret_cast<glGetPointerv>(GetProcAddress(opengl32, "glGetPointerv"));
		this->GetPolygonStipple = reinterpret_cast<glGetPolygonStipple>(GetProcAddress(opengl32, "glGetPolygonStipple"));
		this->GetString = reinterpret_cast<glGetString>(GetProcAddress(opengl32, "glGetString"));
		this->GetTexEnvfv = reinterpret_cast<glGetTexEnvfv>(GetProcAddress(opengl32, "glGetTexEnvfv"));
		this->GetTexEnviv = reinterpret_cast<glGetTexEnviv>(GetProcAddress(opengl32, "glGetTexEnviv"));
		this->GetTexGendv = reinterpret_cast<glGetTexGendv>(GetProcAddress(opengl32, "glGetTexGendv"));
		this->GetTexGenfv = reinterpret_cast<glGetTexGenfv>(GetProcAddress(opengl32, "glGetTexGenfv"));
		this->GetTexGeniv = reinterpret_cast<glGetTexGeniv>(GetProcAddress(opengl32, "glGetTexGeniv"));
		this->GetTexImage = reinterpret_cast<glGetTexImage>(GetProcAddress(opengl32, "glGetTexImage"));
		this->GetTexLevelParameterfv = reinterpret_cast<glGetTexLevelParameterfv>(GetProcAddress(opengl32, "glGetTexLevelParameterfv"));
		this->GetTexLevelParameteriv = reinterpret_cast<glGetTexLevelParameteriv>(GetProcAddress(opengl32, "glGetTexLevelParameteriv"));
		this->GetTexParameterfv = reinterpret_cast<glGetTexParameterfv>(GetProcAddress(opengl32, "glGetTexParameterfv"));
		this->GetTexParameteriv = reinterpret_cast<glGetTexParameteriv>(GetProcAddress(opengl32, "glGetTexParameteriv"));
		this->Hint = reinterpret_cast<glHint>(GetProcAddress(opengl32, "glHint"));
		this->IndexMask = reinterpret_cast<glIndexMask>(GetProcAddress(opengl32, "glIndexMask"));
		this->IndexPointer = reinterpret_cast<glIndexPointer>(GetProcAddress(opengl32, "glIndexPointer"));
		this->Indexd = reinterpret_cast<glIndexd>(GetProcAddress(opengl32, "glIndexd"));
		this->Indexdv = reinterpret_cast<glIndexdv>(GetProcAddress(opengl32, "glIndexdv"));
		this->Indexf = reinterpret_cast<glIndexf>(GetProcAddress(opengl32, "glIndexf"));
		this->Indexfv = reinterpret_cast<glIndexfv>(GetProcAddress(opengl32, "glIndexfv"));
		this->Indexi = reinterpret_cast<glIndexi>(GetProcAddress(opengl32, "glIndexi"));
		this->Indexiv = reinterpret_cast<glIndexiv>(GetProcAddress(opengl32, "glIndexiv"));
		this->Indexs = reinterpret_cast<glIndexs>(GetProcAddress(opengl32, "glIndexs"));
		this->Indexsv = reinterpret_cast<glIndexsv>(GetProcAddress(opengl32, "glIndexsv"));
		this->Indexub = reinterpret_cast<glIndexub>(GetProcAddress(opengl32, "glIndexub"));
		this->Indexubv = reinterpret_cast<glIndexubv>(GetProcAddress(opengl32, "glIndexubv"));
		this->InitNames = reinterpret_cast<glInitNames>(GetProcAddress(opengl32, "glInitNames"));
		this->InterleavedArrays = reinterpret_cast<glInterleavedArrays>(GetProcAddress(opengl32, "glInterleavedArrays"));
		this->IsEnabled = reinterpret_cast<glIsEnabled>(GetProcAddress(opengl32, "glIsEnabled"));
		this->IsList = reinterpret_cast<glIsList>(GetProcAddress(opengl32, "glIsList"));
		this->IsTexture = reinterpret_cast<glIsTexture>(GetProcAddress(opengl32, "glIsTexture"));
		this->LightModelf = reinterpret_cast<glLightModelf>(GetProcAddress(opengl32, "glLightModelf"));
		this->LightModelfv = reinterpret_cast<glLightModelfv>(GetProcAddress(opengl32, "glLightModelfv"));
		this->LightModeli = reinterpret_cast<glLightModeli>(GetProcAddress(opengl32, "glLightModeli"));
		this->LightModeliv = reinterpret_cast<glLightModeliv>(GetProcAddress(opengl32, "glLightModeliv"));
		this->Lightf = reinterpret_cast<glLightf>(GetProcAddress(opengl32, "glLightf"));
		this->Lightfv = reinterpret_cast<glLightfv>(GetProcAddress(opengl32, "glLightfv"));
		this->Lighti = reinterpret_cast<glLighti>(GetProcAddress(opengl32, "glLighti"));
		this->Lightiv = reinterpret_cast<glLightiv>(GetProcAddress(opengl32, "glLightiv"));
		this->LineStipple = reinterpret_cast<glLineStipple>(GetProcAddress(opengl32, "glLineStipple"));
		this->LineWidth = reinterpret_cast<glLineWidth>(GetProcAddress(opengl32, "glLineWidth"));
		this->ListBase = reinterpret_cast<glListBase>(GetProcAddress(opengl32, "glListBase"));
		this->LoadIdentity = reinterpret_cast<glLoadIdentity>(GetProcAddress(opengl32, "glLoadIdentity"));
		this->LoadMatrixd = reinterpret_cast<glLoadMatrixd>(GetProcAddress(opengl32, "glLoadMatrixd"));
		this->LoadMatrixf = reinterpret_cast<glLoadMatrixf>(GetProcAddress(opengl32, "glLoadMatrixf"));
		this->LoadName = reinterpret_cast<glLoadName>(GetProcAddress(opengl32, "glLoadName"));
		this->LogicOp = reinterpret_cast<glLogicOp>(GetProcAddress(opengl32, "glLogicOp"));
		this->Map1d = reinterpret_cast<glMap1d>(GetProcAddress(opengl32, "glMap1d"));
		this->Map1f = reinterpret_cast<glMap1f>(GetProcAddress(opengl32, "glMap1f"));
		this->Map2d = reinterpret_cast<glMap2d>(GetProcAddress(opengl32, "glMap2d"));
		this->Map2f = reinterpret_cast<glMap2f>(GetProcAddress(opengl32, "glMap2f"));
		this->MapGrid1d = reinterpret_cast<glMapGrid1d>(GetProcAddress(opengl32, "glMapGrid1d"));
		this->MapGrid1f = reinterpret_cast<glMapGrid1f>(GetProcAddress(opengl32, "glMapGrid1f"));
		this->MapGrid2d = reinterpret_cast<glMapGrid2d>(GetProcAddress(opengl32, "glMapGrid2d"));
		this->MapGrid2f = reinterpret_cast<glMapGrid2f>(GetProcAddress(opengl32, "glMapGrid2f"));
		this->Materialf = reinterpret_cast<glMaterialf>(GetProcAddress(opengl32, "glMaterialf"));
		this->Materialfv = reinterpret_cast<glMaterialfv>(GetProcAddress(opengl32, "glMaterialfv"));
		this->Materiali = reinterpret_cast<glMateriali>(GetProcAddress(opengl32, "glMateriali"));
		this->Materialiv = reinterpret_cast<glMaterialiv>(GetProcAddress(opengl32, "glMaterialiv"));
		this->MatrixMode = reinterpret_cast<glMatrixMode>(GetProcAddress(opengl32, "glMatrixMode"));
		this->MultMatrixd = reinterpret_cast<glMultMatrixd>(GetProcAddress(opengl32, "glMultMatrixd"));
		this->MultMatrixf = reinterpret_cast<glMultMatrixf>(GetProcAddress(opengl32, "glMultMatrixf"));
		this->NewList = reinterpret_cast<glNewList>(GetProcAddress(opengl32, "glNewList"));
		this->Normal3b = reinterpret_cast<glNormal3b>(GetProcAddress(opengl32, "glNormal3b"));
		this->Normal3bv = reinterpret_cast<glNormal3bv>(GetProcAddress(opengl32, "glNormal3bv"));
		this->Normal3d = reinterpret_cast<glNormal3d>(GetProcAddress(opengl32, "glNormal3d"));
		this->Normal3dv = reinterpret_cast<glNormal3dv>(GetProcAddress(opengl32, "glNormal3dv"));
		this->Normal3f = reinterpret_cast<glNormal3f>(GetProcAddress(opengl32, "glNormal3f"));
		this->Normal3fv = reinterpret_cast<glNormal3fv>(GetProcAddress(opengl32, "glNormal3fv"));
		this->Normal3i = reinterpret_cast<glNormal3i>(GetProcAddress(opengl32, "glNormal3i"));
		this->Normal3iv = reinterpret_cast<glNormal3iv>(GetProcAddress(opengl32, "glNormal3iv"));
		this->Normal3s = reinterpret_cast<glNormal3s>(GetProcAddress(opengl32, "glNormal3s"));
		this->Normal3sv = reinterpret_cast<glNormal3sv>(GetProcAddress(opengl32, "glNormal3sv"));
		this->NormalPointer = reinterpret_cast<glNormalPointer>(GetProcAddress(opengl32, "glNormalPointer"));
		this->Ortho = reinterpret_cast<glOrtho>(GetProcAddress(opengl32, "glOrtho"));
		this->PassThrough = reinterpret_cast<glPassThrough>(GetProcAddress(opengl32, "glPassThrough"));
		this->PixelMapfv = reinterpret_cast<glPixelMapfv>(GetProcAddress(opengl32, "glPixelMapfv"));
		this->PixelMapuiv = reinterpret_cast<glPixelMapuiv>(GetProcAddress(opengl32, "glPixelMapuiv"));
		this->PixelMapusv = reinterpret_cast<glPixelMapusv>(GetProcAddress(opengl32, "glPixelMapusv"));
		this->PixelStoref = reinterpret_cast<glPixelStoref>(GetProcAddress(opengl32, "glPixelStoref"));
		this->PixelStorei = reinterpret_cast<glPixelStorei>(GetProcAddress(opengl32, "glPixelStorei"));
		this->PixelTransferf = reinterpret_cast<glPixelTransferf>(GetProcAddress(opengl32, "glPixelTransferf"));
		this->PixelTransferi = reinterpret_cast<glPixelTransferi>(GetProcAddress(opengl32, "glPixelTransferi"));
		this->PixelZoom = reinterpret_cast<glPixelZoom>(GetProcAddress(opengl32, "glPixelZoom"));
		this->PointSize = reinterpret_cast<glPointSize>(GetProcAddress(opengl32, "glPointSize"));
		this->PolygonMode = reinterpret_cast<glPolygonMode>(GetProcAddress(opengl32, "glPolygonMode"));
		this->PolygonOffset = reinterpret_cast<glPolygonOffset>(GetProcAddress(opengl32, "glPolygonOffset"));
		this->PolygonStipple = reinterpret_cast<glPolygonStipple>(GetProcAddress(opengl32, "glPolygonStipple"));
		this->PopAttrib = reinterpret_cast<glPopAttrib>(GetProcAddress(opengl32, "glPopAttrib"));
		this->PopClientAttrib = reinterpret_cast<glPopClientAttrib>(GetProcAddress(opengl32, "glPopClientAttrib"));
		this->PopMatrix = reinterpret_cast<glPopMatrix>(GetProcAddress(opengl32, "glPopMatrix"));
		this->PopName = reinterpret_cast<glPopName>(GetProcAddress(opengl32, "glPopName"));
		this->PrioritizeTextures = reinterpret_cast<glPrioritizeTextures>(GetProcAddress(opengl32, "glPrioritizeTextures"));
		this->PushAttrib = reinterpret_cast<glPushAttrib>(GetProcAddress(opengl32, "glPushAttrib"));
		this->PushClientAttrib = reinterpret_cast<glPushClientAttrib>(GetProcAddress(opengl32, "glPushClientAttrib"));
		this->PushMatrix = reinterpret_cast<glPushMatrix>(GetProcAddress(opengl32, "glPushMatrix"));
		this->PushName = reinterpret_cast<glPushName>(GetProcAddress(opengl32, "glPushName"));
		this->RasterPos2d = reinterpret_cast<glRasterPos2d>(GetProcAddress(opengl32, "glRasterPos2d"));
		this->RasterPos2dv = reinterpret_cast<glRasterPos2dv>(GetProcAddress(opengl32, "glRasterPos2dv"));
		this->RasterPos2f = reinterpret_cast<glRasterPos2f>(GetProcAddress(opengl32, "glRasterPos2f"));
		this->RasterPos2fv = reinterpret_cast<glRasterPos2fv>(GetProcAddress(opengl32, "glRasterPos2fv"));
		this->RasterPos2i = reinterpret_cast<glRasterPos2i>(GetProcAddress(opengl32, "glRasterPos2i"));
		this->RasterPos2iv = reinterpret_cast<glRasterPos2iv>(GetProcAddress(opengl32, "glRasterPos2iv"));
		this->RasterPos2s = reinterpret_cast<glRasterPos2s>(GetProcAddress(opengl32, "glRasterPos2s"));
		this->RasterPos2sv = reinterpret_cast<glRasterPos2sv>(GetProcAddress(opengl32, "glRasterPos2sv"));
		this->RasterPos3d = reinterpret_cast<glRasterPos3d>(GetProcAddress(opengl32, "glRasterPos3d"));
		this->RasterPos3dv = reinterpret_cast<glRasterPos3dv>(GetProcAddress(opengl32, "glRasterPos3dv"));
		this->RasterPos3f = reinterpret_cast<glRasterPos3f>(GetProcAddress(opengl32, "glRasterPos3f"));
		this->RasterPos3fv = reinterpret_cast<glRasterPos3fv>(GetProcAddress(opengl32, "glRasterPos3fv"));
		this->RasterPos3i = reinterpret_cast<glRasterPos3i>(GetProcAddress(opengl32, "glRasterPos3i"));
		this->RasterPos3iv = reinterpret_cast<glRasterPos3iv>(GetProcAddress(opengl32, "glRasterPos3iv"));
		this->RasterPos3s = reinterpret_cast<glRasterPos3s>(GetProcAddress(opengl32, "glRasterPos3s"));
		this->RasterPos3sv = reinterpret_cast<glRasterPos3sv>(GetProcAddress(opengl32, "glRasterPos3sv"));
		this->RasterPos4d = reinterpret_cast<glRasterPos4d>(GetProcAddress(opengl32, "glRasterPos4d"));
		this->RasterPos4dv = reinterpret_cast<glRasterPos4dv>(GetProcAddress(opengl32, "glRasterPos4dv"));
		this->RasterPos4f = reinterpret_cast<glRasterPos4f>(GetProcAddress(opengl32, "glRasterPos4f"));
		this->RasterPos4fv = reinterpret_cast<glRasterPos4fv>(GetProcAddress(opengl32, "glRasterPos4fv"));
		this->RasterPos4i = reinterpret_cast<glRasterPos4i>(GetProcAddress(opengl32, "glRasterPos4i"));
		this->RasterPos4iv = reinterpret_cast<glRasterPos4iv>(GetProcAddress(opengl32, "glRasterPos4iv"));
		this->RasterPos4s = reinterpret_cast<glRasterPos4s>(GetProcAddress(opengl32, "glRasterPos4s"));
		this->RasterPos4sv = reinterpret_cast<glRasterPos4sv>(GetProcAddress(opengl32, "glRasterPos4sv"));
		this->ReadBuffer = reinterpret_cast<glReadBuffer>(GetProcAddress(opengl32, "glReadBuffer"));
		this->ReadPixels = reinterpret_cast<glReadPixels>(GetProcAddress(opengl32, "glReadPixels"));
		this->Rectd = reinterpret_cast<glRectd>(GetProcAddress(opengl32, "glRectd"));
		this->Rectdv = reinterpret_cast<glRectdv>(GetProcAddress(opengl32, "glRectdv"));
		this->Rectf = reinterpret_cast<glRectf>(GetProcAddress(opengl32, "glRectf"));
		this->Rectfv = reinterpret_cast<glRectfv>(GetProcAddress(opengl32, "glRectfv"));
		this->Recti = reinterpret_cast<glRecti>(GetProcAddress(opengl32, "glRecti"));
		this->Rectiv = reinterpret_cast<glRectiv>(GetProcAddress(opengl32, "glRectiv"));
		this->Rects = reinterpret_cast<glRects>(GetProcAddress(opengl32, "glRects"));
		this->Rectsv = reinterpret_cast<glRectsv>(GetProcAddress(opengl32, "glRectsv"));
		this->RenderMode = reinterpret_cast<glRenderMode>(GetProcAddress(opengl32, "glRenderMode"));
		this->Rotated = reinterpret_cast<glRotated>(GetProcAddress(opengl32, "glRotated"));
		this->Rotatef = reinterpret_cast<glRotatef>(GetProcAddress(opengl32, "glRotatef"));
		this->Scaled = reinterpret_cast<glScaled>(GetProcAddress(opengl32, "glScaled"));
		this->Scalef = reinterpret_cast<glScalef>(GetProcAddress(opengl32, "glScalef"));
		this->Scissor = reinterpret_cast<glScissor>(GetProcAddress(opengl32, "glScissor"));
		this->SelectBuffer = reinterpret_cast<glSelectBuffer>(GetProcAddress(opengl32, "glSelectBuffer"));
		this->ShadeModel = reinterpret_cast<glShadeModel>(GetProcAddress(opengl32, "glShadeModel"));
		this->StencilFunc = reinterpret_cast<glStencilFunc>(GetProcAddress(opengl32, "glStencilFunc"));
		this->StencilMask = reinterpret_cast<glStencilMask>(GetProcAddress(opengl32, "glStencilMask"));
		this->StencilOp = reinterpret_cast<glStencilOp>(GetProcAddress(opengl32, "glStencilOp"));
		this->TexCoord1d = reinterpret_cast<glTexCoord1d>(GetProcAddress(opengl32, "glTexCoord1d"));
		this->TexCoord1dv = reinterpret_cast<glTexCoord1dv>(GetProcAddress(opengl32, "glTexCoord1dv"));
		this->TexCoord1f = reinterpret_cast<glTexCoord1f>(GetProcAddress(opengl32, "glTexCoord1f"));
		this->TexCoord1fv = reinterpret_cast<glTexCoord1fv>(GetProcAddress(opengl32, "glTexCoord1fv"));
		this->TexCoord1i = reinterpret_cast<glTexCoord1i>(GetProcAddress(opengl32, "glTexCoord1i"));
		this->TexCoord1iv = reinterpret_cast<glTexCoord1iv>(GetProcAddress(opengl32, "glTexCoord1iv"));
		this->TexCoord1s = reinterpret_cast<glTexCoord1s>(GetProcAddress(opengl32, "glTexCoord1s"));
		this->TexCoord1sv = reinterpret_cast<glTexCoord1sv>(GetProcAddress(opengl32, "glTexCoord1sv"));
		this->TexCoord2d = reinterpret_cast<glTexCoord2d>(GetProcAddress(opengl32, "glTexCoord2d"));
		this->TexCoord2dv = reinterpret_cast<glTexCoord2dv>(GetProcAddress(opengl32, "glTexCoord2dv"));
		this->TexCoord2f = reinterpret_cast<glTexCoord2f>(GetProcAddress(opengl32, "glTexCoord2f"));
		this->TexCoord2fv = reinterpret_cast<glTexCoord2fv>(GetProcAddress(opengl32, "glTexCoord2fv"));
		this->TexCoord2i = reinterpret_cast<glTexCoord2i>(GetProcAddress(opengl32, "glTexCoord2i"));
		this->TexCoord2iv = reinterpret_cast<glTexCoord2iv>(GetProcAddress(opengl32, "glTexCoord2iv"));
		this->TexCoord2s = reinterpret_cast<glTexCoord2s>(GetProcAddress(opengl32, "glTexCoord2s"));
		this->TexCoord2sv = reinterpret_cast<glTexCoord2sv>(GetProcAddress(opengl32, "glTexCoord2sv"));
		this->TexCoord3d = reinterpret_cast<glTexCoord3d>(GetProcAddress(opengl32, "glTexCoord3d"));
		this->TexCoord3dv = reinterpret_cast<glTexCoord3dv>(GetProcAddress(opengl32, "glTexCoord3dv"));
		this->TexCoord3f = reinterpret_cast<glTexCoord3f>(GetProcAddress(opengl32, "glTexCoord3f"));
		this->TexCoord3fv = reinterpret_cast<glTexCoord3fv>(GetProcAddress(opengl32, "glTexCoord3fv"));
		this->TexCoord3i = reinterpret_cast<glTexCoord3i>(GetProcAddress(opengl32, "glTexCoord3i"));
		this->TexCoord3iv = reinterpret_cast<glTexCoord3iv>(GetProcAddress(opengl32, "glTexCoord3iv"));
		this->TexCoord3s = reinterpret_cast<glTexCoord3s>(GetProcAddress(opengl32, "glTexCoord3s"));
		this->TexCoord3sv = reinterpret_cast<glTexCoord3sv>(GetProcAddress(opengl32, "glTexCoord3sv"));
		this->TexCoord4d = reinterpret_cast<glTexCoord4d>(GetProcAddress(opengl32, "glTexCoord4d"));
		this->TexCoord4dv = reinterpret_cast<glTexCoord4dv>(GetProcAddress(opengl32, "glTexCoord4dv"));
		this->TexCoord4f = reinterpret_cast<glTexCoord4f>(GetProcAddress(opengl32, "glTexCoord4f"));
		this->TexCoord4fv = reinterpret_cast<glTexCoord4fv>(GetProcAddress(opengl32, "glTexCoord4fv"));
		this->TexCoord4i = reinterpret_cast<glTexCoord4i>(GetProcAddress(opengl32, "glTexCoord4i"));
		this->TexCoord4iv = reinterpret_cast<glTexCoord4iv>(GetProcAddress(opengl32, "glTexCoord4iv"));
		this->TexCoord4s = reinterpret_cast<glTexCoord4s>(GetProcAddress(opengl32, "glTexCoord4s"));
		this->TexCoord4sv = reinterpret_cast<glTexCoord4sv>(GetProcAddress(opengl32, "glTexCoord4sv"));
		this->TexCoordPointer = reinterpret_cast<glTexCoordPointer>(GetProcAddress(opengl32, "glTexCoordPointer"));
		this->TexEnvf = reinterpret_cast<glTexEnvf>(GetProcAddress(opengl32, "glTexEnvf"));
		this->TexEnvfv = reinterpret_cast<glTexEnvfv>(GetProcAddress(opengl32, "glTexEnvfv"));
		this->TexEnvi = reinterpret_cast<glTexEnvi>(GetProcAddress(opengl32, "glTexEnvi"));
		this->TexEnviv = reinterpret_cast<glTexEnviv>(GetProcAddress(opengl32, "glTexEnviv"));
		this->TexGend = reinterpret_cast<glTexGend>(GetProcAddress(opengl32, "glTexGend"));
		this->TexGendv = reinterpret_cast<glTexGendv>(GetProcAddress(opengl32, "glTexGendv"));
		this->TexGenf = reinterpret_cast<glTexGenf>(GetProcAddress(opengl32, "glTexGenf"));
		this->TexGenfv = reinterpret_cast<glTexGenfv>(GetProcAddress(opengl32, "glTexGenfv"));
		this->TexGeni = reinterpret_cast<glTexGeni>(GetProcAddress(opengl32, "glTexGeni"));
		this->TexGeniv = reinterpret_cast<glTexGeniv>(GetProcAddress(opengl32, "glTexGeniv"));
		this->TexImage1D = reinterpret_cast<glTexImage1D>(GetProcAddress(opengl32, "glTexImage1D"));
		this->TexImage2D = reinterpret_cast<glTexImage2D>(GetProcAddress(opengl32, "glTexImage2D"));
		this->TexParameterf = reinterpret_cast<glTexParameterf>(GetProcAddress(opengl32, "glTexParameterf"));
		this->TexParameterfv = reinterpret_cast<glTexParameterfv>(GetProcAddress(opengl32, "glTexParameterfv"));
		this->TexParameteri = reinterpret_cast<glTexParameteri>(GetProcAddress(opengl32, "glTexParameteri"));
		this->TexParameteriv = reinterpret_cast<glTexParameteriv>(GetProcAddress(opengl32, "glTexParameteriv"));
		this->TexSubImage1D = reinterpret_cast<glTexSubImage1D>(GetProcAddress(opengl32, "glTexSubImage1D"));
		this->TexSubImage2D = reinterpret_cast<glTexSubImage2D>(GetProcAddress(opengl32, "glTexSubImage2D"));
		this->Translated = reinterpret_cast<glTranslated>(GetProcAddress(opengl32, "glTranslated"));
		this->Translatef = reinterpret_cast<glTranslatef>(GetProcAddress(opengl32, "glTranslatef"));
		this->Vertex2d = reinterpret_cast<glVertex2d>(GetProcAddress(opengl32, "glVertex2d"));
		this->Vertex2dv = reinterpret_cast<glVertex2dv>(GetProcAddress(opengl32, "glVertex2dv"));
		this->Vertex2f = reinterpret_cast<glVertex2f>(GetProcAddress(opengl32, "glVertex2f"));
		this->Vertex2fv = reinterpret_cast<glVertex2fv>(GetProcAddress(opengl32, "glVertex2fv"));
		this->Vertex2i = reinterpret_cast<glVertex2i>(GetProcAddress(opengl32, "glVertex2i"));
		this->Vertex2iv = reinterpret_cast<glVertex2iv>(GetProcAddress(opengl32, "glVertex2iv"));
		this->Vertex2s = reinterpret_cast<glVertex2s>(GetProcAddress(opengl32, "glVertex2s"));
		this->Vertex2sv = reinterpret_cast<glVertex2sv>(GetProcAddress(opengl32, "glVertex2sv"));
		this->Vertex3d = reinterpret_cast<glVertex3d>(GetProcAddress(opengl32, "glVertex3d"));
		this->Vertex3dv = reinterpret_cast<glVertex3dv>(GetProcAddress(opengl32, "glVertex3dv"));
		this->Vertex3f = reinterpret_cast<glVertex3f>(GetProcAddress(opengl32, "glVertex3f"));
		this->Vertex3fv = reinterpret_cast<glVertex3fv>(GetProcAddress(opengl32, "glVertex3fv"));
		this->Vertex3i = reinterpret_cast<glVertex3i>(GetProcAddress(opengl32, "glVertex3i"));
		this->Vertex3iv = reinterpret_cast<glVertex3iv>(GetProcAddress(opengl32, "glVertex3iv"));
		this->Vertex3s = reinterpret_cast<glVertex3s>(GetProcAddress(opengl32, "glVertex3s"));
		this->Vertex3sv = reinterpret_cast<glVertex3sv>(GetProcAddress(opengl32, "glVertex3sv"));
		this->Vertex4d = reinterpret_cast<glVertex4d>(GetProcAddress(opengl32, "glVertex4d"));
		this->Vertex4dv = reinterpret_cast<glVertex4dv>(GetProcAddress(opengl32, "glVertex4dv"));
		this->Vertex4f = reinterpret_cast<glVertex4f>(GetProcAddress(opengl32, "glVertex4f"));
		this->Vertex4fv = reinterpret_cast<glVertex4fv>(GetProcAddress(opengl32, "glVertex4fv"));
		this->Vertex4i = reinterpret_cast<glVertex4i>(GetProcAddress(opengl32, "glVertex4i"));
		this->Vertex4iv = reinterpret_cast<glVertex4iv>(GetProcAddress(opengl32, "glVertex4iv"));
		this->Vertex4s = reinterpret_cast<glVertex4s>(GetProcAddress(opengl32, "glVertex4s"));
		this->Vertex4sv = reinterpret_cast<glVertex4sv>(GetProcAddress(opengl32, "glVertex4sv"));
		this->VertexPointer = reinterpret_cast<glVertexPointer>(GetProcAddress(opengl32, "glVertexPointer"));
		this->Viewport = reinterpret_cast<glViewport>(GetProcAddress(opengl32, "glViewport"));
	}
};

// { #version 120 }
class GLcontext120 : public GLcontext110 {
	/* Unknown */
	/*#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
	#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
	#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
	#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
	#define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8
	#define GL_SINGLE_COLOR 0x81F9
	#define GL_SEPARATE_SPECULAR_COLOR 0x81FA
	#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
	#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
	#define GL_RESCALE_NORMAL 0x803A
	#define GL_PACK_SKIP_IMAGES 0x806B
	#define GL_PACK_IMAGE_HEIGHT 0x806C
	#define GL_UNPACK_SKIP_IMAGES 0x806D
	#define GL_UNPACK_IMAGE_HEIGHT 0x806E*/
	/* TextureParameter */
	typedef void(_stdcall* glCopyTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	typedef void(_stdcall* glDrawRangeElements) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
	typedef void(_stdcall* glTexImage3D) (GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
	typedef void(_stdcall* glTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
public:
	glCopyTexSubImage3D CopyTexSubImage3D;
	glDrawRangeElements DrawRangeElements;
	glTexImage3D TexImage3D;
	glTexSubImage3D TexSubImage3D;
	GLcontext120() = default;
	explicit GLcontext120(HDC device) : GLcontext110(device) {
		this->CopyTexSubImage3D = reinterpret_cast<glCopyTexSubImage3D>(wglGetProcAddress("glCopyTexSubImage3D"));
		this->DrawRangeElements = reinterpret_cast<glDrawRangeElements>(wglGetProcAddress("glDrawRangeElements"));
		this->TexImage3D = reinterpret_cast<glTexImage3D>(wglGetProcAddress("glTexImage3D"));
		this->TexSubImage3D = reinterpret_cast<glTexSubImage3D>(wglGetProcAddress("glTexSubImage3D"));
	}
};

// { #version 130 }
class GLcontext130 : public GLcontext120 {
	/* GetParameter */
	#define GL_ACTIVE_TEXTURE 0x84E0
	#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
	#define GL_MAX_TEXTURE_UNITS 0x84E2
	#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
	#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
	#define GL_TEXTURE_COMPRESSED 0x86A1
	#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
	#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
	/* GetTexParameter */
	#define GL_MAX_3D_TEXTURE_SIZE 0x8073
	#define GL_MAX_ELEMENTS_VERTICES 0x80E8
	#define GL_MAX_ELEMENTS_INDICES 0x80E9
	#define GL_TEXTURE_MIN_LOD 0x813A
	#define GL_TEXTURE_MAX_LOD 0x813B
	#define GL_TEXTURE_BASE_LEVEL 0x813C
	#define GL_TEXTURE_MAX_LEVEL 0x813D
	/* Unknown */
	/*#define GL_MULTISAMPLE 0x809D
	#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
	#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
	#define GL_SAMPLE_COVERAGE 0x80A0
	#define GL_SAMPLE_BUFFERS 0x80A8
	#define GL_SAMPLES 0x80A9
	#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
	#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
	#define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
	#define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
	#define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
	#define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
	#define GL_SUBTRACT 0x84E7
	#define GL_COMPRESSED_ALPHA 0x84E9
	#define GL_COMPRESSED_LUMINANCE 0x84EA
	#define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
	#define GL_COMPRESSED_INTENSITY 0x84EC
	#define GL_COMPRESSED_RGB 0x84ED
	#define GL_COMPRESSED_RGBA 0x84EE
	#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
	#define GL_NORMAL_MAP 0x8511
	#define GL_REFLECTION_MAP 0x8512
	#define GL_COMBINE 0x8570
	#define GL_COMBINE_RGB 0x8571
	#define GL_COMBINE_ALPHA 0x8572
	#define GL_RGB_SCALE 0x8573
	#define GL_ADD_SIGNED 0x8574
	#define GL_INTERPOLATE 0x8575
	#define GL_CONSTANT 0x8576
	#define GL_PRIMARY_COLOR 0x8577
	#define GL_PREVIOUS 0x8578
	#define GL_SOURCE0_RGB 0x8580
	#define GL_SOURCE1_RGB 0x8581
	#define GL_SOURCE2_RGB 0x8582
	#define GL_SOURCE0_ALPHA 0x8588
	#define GL_SOURCE1_ALPHA 0x8589
	#define GL_SOURCE2_ALPHA 0x858A
	#define GL_OPERAND0_RGB 0x8590
	#define GL_OPERAND1_RGB 0x8591
	#define GL_OPERAND2_RGB 0x8592
	#define GL_OPERAND0_ALPHA 0x8598
	#define GL_OPERAND1_ALPHA 0x8599
	#define GL_OPERAND2_ALPHA 0x859A
	#define GL_DOT3_RGB 0x86AE
	#define GL_DOT3_RGBA 0x86AF
	#define GL_MULTISAMPLE_BIT 0x20000000*/
	typedef void (_stdcall* glActiveTexture) (GLenum texture);
	typedef void (_stdcall* glClientActiveTexture) (GLenum texture);
	typedef void (_stdcall* glCompressedTexImage1D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data);
	typedef void (_stdcall* glCompressedTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data);
	typedef void (_stdcall* glCompressedTexImage3D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data);
	typedef void (_stdcall* glCompressedTexSubImage1D) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
	typedef void (_stdcall* glCompressedTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
	typedef void (_stdcall* glCompressedTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
	typedef void (_stdcall* glGetCompressedTexImage) (GLenum target, GLint lod, void* img);
	typedef void (_stdcall* glLoadTransposeMatrixd) (const GLdouble m[16]);
	typedef void (_stdcall* glLoadTransposeMatrixf) (const GLfloat m[16]);
	typedef void (_stdcall* glMultTransposeMatrixd) (const GLdouble m[16]);
	typedef void (_stdcall* glMultTransposeMatrixf) (const GLfloat m[16]);
	typedef void (_stdcall* glMultiTexCoord1d) (GLenum target, GLdouble s);
	typedef void (_stdcall* glMultiTexCoord1dv) (GLenum target, const GLdouble* v);
	typedef void (_stdcall* glMultiTexCoord1f) (GLenum target, GLfloat s);
	typedef void (_stdcall* glMultiTexCoord1fv) (GLenum target, const GLfloat* v);
	typedef void (_stdcall* glMultiTexCoord1i) (GLenum target, GLint s);
	typedef void (_stdcall* glMultiTexCoord1iv) (GLenum target, const GLint* v);
	typedef void (_stdcall* glMultiTexCoord1s) (GLenum target, GLshort s);
	typedef void (_stdcall* glMultiTexCoord1sv) (GLenum target, const GLshort* v);
	typedef void (_stdcall* glMultiTexCoord2d) (GLenum target, GLdouble s, GLdouble t);
	typedef void (_stdcall* glMultiTexCoord2dv) (GLenum target, const GLdouble* v);
	typedef void (_stdcall* glMultiTexCoord2f) (GLenum target, GLfloat s, GLfloat t);
	typedef void (_stdcall* glMultiTexCoord2fv) (GLenum target, const GLfloat* v);
	typedef void (_stdcall* glMultiTexCoord2i) (GLenum target, GLint s, GLint t);
	typedef void (_stdcall* glMultiTexCoord2iv) (GLenum target, const GLint* v);
	typedef void (_stdcall* glMultiTexCoord2s) (GLenum target, GLshort s, GLshort t);
	typedef void (_stdcall* glMultiTexCoord2sv) (GLenum target, const GLshort* v);
	typedef void (_stdcall* glMultiTexCoord3d) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
	typedef void (_stdcall* glMultiTexCoord3dv) (GLenum target, const GLdouble* v);
	typedef void (_stdcall* glMultiTexCoord3f) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
	typedef void (_stdcall* glMultiTexCoord3fv) (GLenum target, const GLfloat* v);
	typedef void (_stdcall* glMultiTexCoord3i) (GLenum target, GLint s, GLint t, GLint r);
	typedef void (_stdcall* glMultiTexCoord3iv) (GLenum target, const GLint* v);
	typedef void (_stdcall* glMultiTexCoord3s) (GLenum target, GLshort s, GLshort t, GLshort r);
	typedef void (_stdcall* glMultiTexCoord3sv) (GLenum target, const GLshort* v);
	typedef void (_stdcall* glMultiTexCoord4d) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	typedef void (_stdcall* glMultiTexCoord4dv) (GLenum target, const GLdouble* v);
	typedef void (_stdcall* glMultiTexCoord4f) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	typedef void (_stdcall* glMultiTexCoord4fv) (GLenum target, const GLfloat* v);
	typedef void (_stdcall* glMultiTexCoord4i) (GLenum target, GLint s, GLint t, GLint r, GLint q);
	typedef void (_stdcall* glMultiTexCoord4iv) (GLenum target, const GLint* v);
	typedef void (_stdcall* glMultiTexCoord4s) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
	typedef void (_stdcall* glMultiTexCoord4sv) (GLenum target, const GLshort* v);
	typedef void (_stdcall* glSampleCoverage) (GLclampf value, GLboolean invert);
public:
	glActiveTexture ActiveTexture;
	glClientActiveTexture ClientActiveTexture;
	glCompressedTexImage1D CompressedTexImage1D;
	glCompressedTexImage2D CompressedTexImage2D;
	glCompressedTexImage3D CompressedTexImage3D;
	glCompressedTexSubImage1D CompressedTexSubImage1D;
	glCompressedTexSubImage2D CompressedTexSubImage2D;
	glCompressedTexSubImage3D CompressedTexSubImage3D;
	glGetCompressedTexImage GetCompressedTexImage;
	glLoadTransposeMatrixd LoadTransposeMatrixd;
	glLoadTransposeMatrixf LoadTransposeMatrixf;
	glMultTransposeMatrixd MultTransposeMatrixd;
	glMultTransposeMatrixf MultTransposeMatrixf;
	glMultiTexCoord1d MultiTexCoord1d;
	glMultiTexCoord1dv MultiTexCoord1dv;
	glMultiTexCoord1f MultiTexCoord1f;
	glMultiTexCoord1fv MultiTexCoord1fv;
	glMultiTexCoord1i MultiTexCoord1i;
	glMultiTexCoord1iv MultiTexCoord1iv;
	glMultiTexCoord1s MultiTexCoord1s;
	glMultiTexCoord1sv MultiTexCoord1sv;
	glMultiTexCoord2d MultiTexCoord2d;
	glMultiTexCoord2dv MultiTexCoord2dv;
	glMultiTexCoord2f MultiTexCoord2f;
	glMultiTexCoord2fv MultiTexCoord2fv;
	glMultiTexCoord2i MultiTexCoord2i;
	glMultiTexCoord2iv MultiTexCoord2iv;
	glMultiTexCoord2s MultiTexCoord2s;
	glMultiTexCoord2sv MultiTexCoord2sv;
	glMultiTexCoord3d MultiTexCoord3d;
	glMultiTexCoord3dv MultiTexCoord3dv;
	glMultiTexCoord3f MultiTexCoord3f;
	glMultiTexCoord3fv MultiTexCoord3fv;
	glMultiTexCoord3i MultiTexCoord3i;
	glMultiTexCoord3iv MultiTexCoord3iv;
	glMultiTexCoord3s MultiTexCoord3s;
	glMultiTexCoord3sv MultiTexCoord3sv;
	glMultiTexCoord4d MultiTexCoord4d;
	glMultiTexCoord4dv MultiTexCoord4dv;
	glMultiTexCoord4f MultiTexCoord4f;
	glMultiTexCoord4fv MultiTexCoord4fv;
	glMultiTexCoord4i MultiTexCoord4i;
	glMultiTexCoord4iv MultiTexCoord4iv;
	glMultiTexCoord4s MultiTexCoord4s;
	glMultiTexCoord4sv MultiTexCoord4sv;
	glSampleCoverage SampleCoverage;
	GLcontext130() = default;
	explicit GLcontext130(HDC device) : GLcontext120(device) {
		this->ActiveTexture = reinterpret_cast<glActiveTexture>(wglGetProcAddress("glActiveTexture"));
		this->ClientActiveTexture = reinterpret_cast<glClientActiveTexture>(wglGetProcAddress("glClientActiveTexture"));
		this->CompressedTexImage1D = reinterpret_cast<glCompressedTexImage1D>(wglGetProcAddress("glCompressedTexImage1D"));
		this->CompressedTexImage2D = reinterpret_cast<glCompressedTexImage2D>(wglGetProcAddress("glCompressedTexImage2D"));
		this->CompressedTexImage3D = reinterpret_cast<glCompressedTexImage3D>(wglGetProcAddress("glCompressedTexImage3D"));
		this->CompressedTexSubImage1D = reinterpret_cast<glCompressedTexSubImage1D>(wglGetProcAddress("glCompressedTexSubImage1D"));
		this->CompressedTexSubImage2D = reinterpret_cast<glCompressedTexSubImage2D>(wglGetProcAddress("glCompressedTexSubImage2D"));
		this->CompressedTexSubImage3D = reinterpret_cast<glCompressedTexSubImage3D>(wglGetProcAddress("glCompressedTexSubImage3D"));
		this->GetCompressedTexImage = reinterpret_cast<glGetCompressedTexImage>(wglGetProcAddress("glGetCompressedTexImage"));
		this->LoadTransposeMatrixd = reinterpret_cast<glLoadTransposeMatrixd>(wglGetProcAddress("glLoadTransposeMatrixd"));
		this->LoadTransposeMatrixf = reinterpret_cast<glLoadTransposeMatrixf>(wglGetProcAddress("glLoadTransposeMatrixf"));
		this->MultTransposeMatrixd = reinterpret_cast<glMultTransposeMatrixd>(wglGetProcAddress("glMultTransposeMatrixd"));
		this->MultTransposeMatrixf = reinterpret_cast<glMultTransposeMatrixf>(wglGetProcAddress("glMultTransposeMatrixf"));
		this->MultiTexCoord1d = reinterpret_cast<glMultiTexCoord1d>(wglGetProcAddress("glMultiTexCoord1d"));
		this->MultiTexCoord1dv = reinterpret_cast<glMultiTexCoord1dv>(wglGetProcAddress("glMultiTexCoord1dv"));
		this->MultiTexCoord1f = reinterpret_cast<glMultiTexCoord1f>(wglGetProcAddress("glMultiTexCoord1f"));
		this->MultiTexCoord1fv = reinterpret_cast<glMultiTexCoord1fv>(wglGetProcAddress("glMultiTexCoord1fv"));
		this->MultiTexCoord1i = reinterpret_cast<glMultiTexCoord1i>(wglGetProcAddress("glMultiTexCoord1i"));
		this->MultiTexCoord1iv = reinterpret_cast<glMultiTexCoord1iv>(wglGetProcAddress("glMultiTexCoord1iv"));
		this->MultiTexCoord1s = reinterpret_cast<glMultiTexCoord1s>(wglGetProcAddress("glMultiTexCoord1s"));
		this->MultiTexCoord1sv = reinterpret_cast<glMultiTexCoord1sv>(wglGetProcAddress("glMultiTexCoord1sv"));
		this->MultiTexCoord2d = reinterpret_cast<glMultiTexCoord2d>(wglGetProcAddress("glMultiTexCoord2d"));
		this->MultiTexCoord2dv = reinterpret_cast<glMultiTexCoord2dv>(wglGetProcAddress("glMultiTexCoord2dv"));
		this->MultiTexCoord2f = reinterpret_cast<glMultiTexCoord2f>(wglGetProcAddress("glMultiTexCoord2f"));
		this->MultiTexCoord2fv = reinterpret_cast<glMultiTexCoord2fv>(wglGetProcAddress("glMultiTexCoord2fv"));
		this->MultiTexCoord2i = reinterpret_cast<glMultiTexCoord2i>(wglGetProcAddress("glMultiTexCoord2i"));
		this->MultiTexCoord2iv = reinterpret_cast<glMultiTexCoord2iv>(wglGetProcAddress("glMultiTexCoord2iv"));
		this->MultiTexCoord2s = reinterpret_cast<glMultiTexCoord2s>(wglGetProcAddress("glMultiTexCoord2s"));
		this->MultiTexCoord2sv = reinterpret_cast<glMultiTexCoord2sv>(wglGetProcAddress("glMultiTexCoord2sv"));
		this->MultiTexCoord3d = reinterpret_cast<glMultiTexCoord3d>(wglGetProcAddress("glMultiTexCoord3d"));
		this->MultiTexCoord3dv = reinterpret_cast<glMultiTexCoord3dv>(wglGetProcAddress("glMultiTexCoord3dv"));
		this->MultiTexCoord3f = reinterpret_cast<glMultiTexCoord3f>(wglGetProcAddress("glMultiTexCoord3f"));
		this->MultiTexCoord3fv = reinterpret_cast<glMultiTexCoord3fv>(wglGetProcAddress("glMultiTexCoord3fv"));
		this->MultiTexCoord3i = reinterpret_cast<glMultiTexCoord3i>(wglGetProcAddress("glMultiTexCoord3i"));
		this->MultiTexCoord3iv = reinterpret_cast<glMultiTexCoord3iv>(wglGetProcAddress("glMultiTexCoord3iv"));
		this->MultiTexCoord3s = reinterpret_cast<glMultiTexCoord3s>(wglGetProcAddress("glMultiTexCoord3s"));
		this->MultiTexCoord3sv = reinterpret_cast<glMultiTexCoord3sv>(wglGetProcAddress("glMultiTexCoord3sv"));
		this->MultiTexCoord4d = reinterpret_cast<glMultiTexCoord4d>(wglGetProcAddress("glMultiTexCoord4d"));
		this->MultiTexCoord4dv = reinterpret_cast<glMultiTexCoord4dv>(wglGetProcAddress("glMultiTexCoord4dv"));
		this->MultiTexCoord4f = reinterpret_cast<glMultiTexCoord4f>(wglGetProcAddress("glMultiTexCoord4f"));
		this->MultiTexCoord4fv = reinterpret_cast<glMultiTexCoord4fv>(wglGetProcAddress("glMultiTexCoord4fv"));
		this->MultiTexCoord4i = reinterpret_cast<glMultiTexCoord4i>(wglGetProcAddress("glMultiTexCoord4i"));
		this->MultiTexCoord4iv = reinterpret_cast<glMultiTexCoord4iv>(wglGetProcAddress("glMultiTexCoord4iv"));
		this->MultiTexCoord4s = reinterpret_cast<glMultiTexCoord4s>(wglGetProcAddress("glMultiTexCoord4s"));
		this->MultiTexCoord4sv = reinterpret_cast<glMultiTexCoord4sv>(wglGetProcAddress("glMultiTexCoord4sv"));
		this->SampleCoverage = reinterpret_cast<glSampleCoverage>(wglGetProcAddress("glSampleCoverage"));
	}
};

// { #version 140 }
class GLcontext140 : public GLcontext130 {
	/* PointParameterName */
	#define GL_POINT_SIZE_MIN 0x8126
	#define GL_POINT_SIZE_MAX 0x8127
	#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
	#define GL_POINT_DISTANCE_ATTENUATION 0x8129
	/* TextureParameterName */
	#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
	#define GL_TEXTURE_FILTER_CONTROL 0x8500
	#define GL_TEXTURE_LOD_BIAS 0x8501
	#define GL_INCR_WRAP 0x8507
	#define GL_DECR_WRAP 0x8508
	#define GL_TEXTURE_DEPTH_SIZE 0x884A
	#define GL_DEPTH_TEXTURE_MODE 0x884B
	#define GL_TEXTURE_COMPARE_MODE 0x884C
	#define GL_TEXTURE_COMPARE_FUNC 0x884D
	#define GL_COMPARE_R_TO_TEXTURE 0x884E
	/* Unknown */
	/*#define GL_BLEND_DST_RGB 0x80C8
	#define GL_BLEND_SRC_RGB 0x80C9
	#define GL_BLEND_DST_ALPHA 0x80CA
	#define GL_BLEND_SRC_ALPHA 0x80CB
	#define GL_GENERATE_MIPMAP 0x8191
	#define GL_GENERATE_MIPMAP_HINT 0x8192
	#define GL_FOG_COORDINATE_SOURCE 0x8450
	#define GL_FOG_COORDINATE 0x8451
	#define GL_FRAGMENT_DEPTH 0x8452
	#define GL_CURRENT_FOG_COORDINATE 0x8453
	#define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
	#define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
	#define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
	#define GL_FOG_COORDINATE_ARRAY 0x8457
	#define GL_COLOR_SUM 0x8458
	#define GL_CURRENT_SECONDARY_COLOR 0x8459
	#define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
	#define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
	#define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
	#define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
	#define GL_SECONDARY_COLOR_ARRAY 0x845E*/
	typedef void (_stdcall* glBlendColor) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	typedef void (_stdcall* glBlendEquation) (GLenum mode);
	typedef void (_stdcall* glBlendFuncSeparate) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	typedef void (_stdcall* glFogCoordPointer) (GLenum type, GLsizei stride, const void* pointer);
	typedef void (_stdcall* glFogCoordd) (GLdouble coord);
	typedef void (_stdcall* glFogCoorddv) (const GLdouble* coord);
	typedef void (_stdcall* glFogCoordf) (GLfloat coord);
	typedef void (_stdcall* glFogCoordfv) (const GLfloat* coord);
	typedef void (_stdcall* glMultiDrawArrays) (GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount);
	typedef void (_stdcall* glMultiDrawElements) (GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount);
	typedef void (_stdcall* glPointParameterf) (GLenum pname, GLfloat param);
	typedef void (_stdcall* glPointParameterfv) (GLenum pname, const GLfloat* params);
	typedef void (_stdcall* glPointParameteri) (GLenum pname, GLint param);
	typedef void (_stdcall* glPointParameteriv) (GLenum pname, const GLint* params);
	typedef void (_stdcall* glSecondaryColor3b) (GLbyte red, GLbyte green, GLbyte blue);
	typedef void (_stdcall* glSecondaryColor3bv) (const GLbyte* v);
	typedef void (_stdcall* glSecondaryColor3d) (GLdouble red, GLdouble green, GLdouble blue);
	typedef void (_stdcall* glSecondaryColor3dv) (const GLdouble* v);
	typedef void (_stdcall* glSecondaryColor3f) (GLfloat red, GLfloat green, GLfloat blue);
	typedef void (_stdcall* glSecondaryColor3fv) (const GLfloat* v);
	typedef void (_stdcall* glSecondaryColor3i) (GLint red, GLint green, GLint blue);
	typedef void (_stdcall* glSecondaryColor3iv) (const GLint* v);
	typedef void (_stdcall* glSecondaryColor3s) (GLshort red, GLshort green, GLshort blue);
	typedef void (_stdcall* glSecondaryColor3sv) (const GLshort* v);
	typedef void (_stdcall* glSecondaryColor3ub) (GLubyte red, GLubyte green, GLubyte blue);
	typedef void (_stdcall* glSecondaryColor3ubv) (const GLubyte* v);
	typedef void (_stdcall* glSecondaryColor3ui) (GLuint red, GLuint green, GLuint blue);
	typedef void (_stdcall* glSecondaryColor3uiv) (const GLuint* v);
	typedef void (_stdcall* glSecondaryColor3us) (GLushort red, GLushort green, GLushort blue);
	typedef void (_stdcall* glSecondaryColor3usv) (const GLushort* v);
	typedef void (_stdcall* glSecondaryColorPointer) (GLint size, GLenum type, GLsizei stride, const void* pointer);
	typedef void (_stdcall* glWindowPos2d) (GLdouble x, GLdouble y);
	typedef void (_stdcall* glWindowPos2dv) (const GLdouble* p);
	typedef void (_stdcall* glWindowPos2f) (GLfloat x, GLfloat y);
	typedef void (_stdcall* glWindowPos2fv) (const GLfloat* p);
	typedef void (_stdcall* glWindowPos2i) (GLint x, GLint y);
	typedef void (_stdcall* glWindowPos2iv) (const GLint* p);
	typedef void (_stdcall* glWindowPos2s) (GLshort x, GLshort y);
	typedef void (_stdcall* glWindowPos2sv) (const GLshort* p);
	typedef void (_stdcall* glWindowPos3d) (GLdouble x, GLdouble y, GLdouble z);
	typedef void (_stdcall* glWindowPos3dv) (const GLdouble* p);
	typedef void (_stdcall* glWindowPos3f) (GLfloat x, GLfloat y, GLfloat z);
	typedef void (_stdcall* glWindowPos3fv) (const GLfloat* p);
	typedef void (_stdcall* glWindowPos3i) (GLint x, GLint y, GLint z);
	typedef void (_stdcall* glWindowPos3iv) (const GLint* p);
	typedef void (_stdcall* glWindowPos3s) (GLshort x, GLshort y, GLshort z);
	typedef void (_stdcall* glWindowPos3sv) (const GLshort* p);
public:
	glBlendColor BlendColor;
	glBlendEquation BlendEquation;
	glBlendFuncSeparate BlendFuncSeparate;
	glFogCoordPointer FogCoordPointer;
	glFogCoordd FogCoordd;
	glFogCoorddv FogCoorddv;
	glFogCoordf FogCoordf;
	glFogCoordfv FogCoordfv;
	glMultiDrawArrays MultiDrawArrays;
	glMultiDrawElements MultiDrawElements;
	glPointParameterf PointParameterf;
	glPointParameterfv PointParameterfv;
	glPointParameteri PointParameteri;
	glPointParameteriv PointParameteriv;
	glSecondaryColor3b SecondaryColor3b;
	glSecondaryColor3bv SecondaryColor3bv;
	glSecondaryColor3d SecondaryColor3d;
	glSecondaryColor3dv SecondaryColor3dv;
	glSecondaryColor3f SecondaryColor3f;
	glSecondaryColor3fv SecondaryColor3fv;
	glSecondaryColor3i SecondaryColor3i;
	glSecondaryColor3iv SecondaryColor3iv;
	glSecondaryColor3s SecondaryColor3s;
	glSecondaryColor3sv SecondaryColor3sv;
	glSecondaryColor3ub SecondaryColor3ub;
	glSecondaryColor3ubv SecondaryColor3ubv;
	glSecondaryColor3ui SecondaryColor3ui;
	glSecondaryColor3uiv SecondaryColor3uiv;
	glSecondaryColor3us SecondaryColor3us;
	glSecondaryColor3usv SecondaryColor3usv;
	glSecondaryColorPointer SecondaryColorPointer;
	glWindowPos2d WindowPos2d;
	glWindowPos2dv WindowPos2dv;
	glWindowPos2f WindowPos2f;
	glWindowPos2fv WindowPos2fv;
	glWindowPos2i WindowPos2i;
	glWindowPos2iv WindowPos2iv;
	glWindowPos2s WindowPos2s;
	glWindowPos2sv WindowPos2sv;
	glWindowPos3d WindowPos3d;
	glWindowPos3dv WindowPos3dv;
	glWindowPos3f WindowPos3f;
	glWindowPos3fv WindowPos3fv;
	glWindowPos3i WindowPos3i;
	glWindowPos3iv WindowPos3iv;
	glWindowPos3s WindowPos3s;
	glWindowPos3sv WindowPos3sv;
	GLcontext140() = default;
	explicit GLcontext140(HDC device) : GLcontext130(device) {
		this->BlendColor = reinterpret_cast<glBlendColor>(wglGetProcAddress("glBlendColor"));
		this->BlendEquation = reinterpret_cast<glBlendEquation>(wglGetProcAddress("glBlendEquation"));
		this->BlendFuncSeparate = reinterpret_cast<glBlendFuncSeparate>(wglGetProcAddress("glBlendFuncSeparate"));
		this->FogCoordPointer = reinterpret_cast<glFogCoordPointer>(wglGetProcAddress("glFogCoordPointer"));
		this->FogCoordd = reinterpret_cast<glFogCoordd>(wglGetProcAddress("glFogCoordd"));
		this->FogCoorddv = reinterpret_cast<glFogCoorddv>(wglGetProcAddress("glFogCoorddv"));
		this->FogCoordf = reinterpret_cast<glFogCoordf>(wglGetProcAddress("glFogCoordf"));
		this->FogCoordfv = reinterpret_cast<glFogCoordfv>(wglGetProcAddress("glFogCoordfv"));
		this->MultiDrawArrays = reinterpret_cast<glMultiDrawArrays>(wglGetProcAddress("glMultiDrawArrays"));
		this->MultiDrawElements = reinterpret_cast<glMultiDrawElements>(wglGetProcAddress("glMultiDrawElements"));
		this->PointParameterf = reinterpret_cast<glPointParameterf>(wglGetProcAddress("glPointParameterf"));
		this->PointParameterfv = reinterpret_cast<glPointParameterfv>(wglGetProcAddress("glPointParameterfv"));
		this->PointParameteri = reinterpret_cast<glPointParameteri>(wglGetProcAddress("glPointParameteri"));
		this->PointParameteriv = reinterpret_cast<glPointParameteriv>(wglGetProcAddress("glPointParameteriv"));
		this->SecondaryColor3b = reinterpret_cast<glSecondaryColor3b>(wglGetProcAddress("glSecondaryColor3b"));
		this->SecondaryColor3bv = reinterpret_cast<glSecondaryColor3bv>(wglGetProcAddress("glSecondaryColor3bv"));
		this->SecondaryColor3d = reinterpret_cast<glSecondaryColor3d>(wglGetProcAddress("glSecondaryColor3d"));
		this->SecondaryColor3dv = reinterpret_cast<glSecondaryColor3dv>(wglGetProcAddress("glSecondaryColor3dv"));
		this->SecondaryColor3f = reinterpret_cast<glSecondaryColor3f>(wglGetProcAddress("glSecondaryColor3f"));
		this->SecondaryColor3fv = reinterpret_cast<glSecondaryColor3fv>(wglGetProcAddress("glSecondaryColor3fv"));
		this->SecondaryColor3i = reinterpret_cast<glSecondaryColor3i>(wglGetProcAddress("glSecondaryColor3i"));
		this->SecondaryColor3iv = reinterpret_cast<glSecondaryColor3iv>(wglGetProcAddress("glSecondaryColor3iv"));
		this->SecondaryColor3s = reinterpret_cast<glSecondaryColor3s>(wglGetProcAddress("glSecondaryColor3s"));
		this->SecondaryColor3sv = reinterpret_cast<glSecondaryColor3sv>(wglGetProcAddress("glSecondaryColor3sv"));
		this->SecondaryColor3ub = reinterpret_cast<glSecondaryColor3ub>(wglGetProcAddress("glSecondaryColor3ub"));
		this->SecondaryColor3ubv = reinterpret_cast<glSecondaryColor3ubv>(wglGetProcAddress("glSecondaryColor3ubv"));
		this->SecondaryColor3ui = reinterpret_cast<glSecondaryColor3ui>(wglGetProcAddress("glSecondaryColor3ui"));
		this->SecondaryColor3uiv = reinterpret_cast<glSecondaryColor3uiv>(wglGetProcAddress("glSecondaryColor3uiv"));
		this->SecondaryColor3us = reinterpret_cast<glSecondaryColor3us>(wglGetProcAddress("glSecondaryColor3us"));
		this->SecondaryColor3usv = reinterpret_cast<glSecondaryColor3usv>(wglGetProcAddress("glSecondaryColor3usv"));
		this->SecondaryColorPointer = reinterpret_cast<glSecondaryColorPointer>(wglGetProcAddress("glSecondaryColorPointer"));
		this->WindowPos2d = reinterpret_cast<glWindowPos2d>(wglGetProcAddress("glWindowPos2d"));
		this->WindowPos2dv = reinterpret_cast<glWindowPos2dv>(wglGetProcAddress("glWindowPos2dv"));
		this->WindowPos2f = reinterpret_cast<glWindowPos2f>(wglGetProcAddress("glWindowPos2f"));
		this->WindowPos2fv = reinterpret_cast<glWindowPos2fv>(wglGetProcAddress("glWindowPos2fv"));
		this->WindowPos2i = reinterpret_cast<glWindowPos2i>(wglGetProcAddress("glWindowPos2i"));
		this->WindowPos2iv = reinterpret_cast<glWindowPos2iv>(wglGetProcAddress("glWindowPos2iv"));
		this->WindowPos2s = reinterpret_cast<glWindowPos2s>(wglGetProcAddress("glWindowPos2s"));
		this->WindowPos2sv = reinterpret_cast<glWindowPos2sv>(wglGetProcAddress("glWindowPos2sv"));
		this->WindowPos3d = reinterpret_cast<glWindowPos3d>(wglGetProcAddress("glWindowPos3d"));
		this->WindowPos3dv = reinterpret_cast<glWindowPos3dv>(wglGetProcAddress("glWindowPos3dv"));
		this->WindowPos3f = reinterpret_cast<glWindowPos3f>(wglGetProcAddress("glWindowPos3f"));
		this->WindowPos3fv = reinterpret_cast<glWindowPos3fv>(wglGetProcAddress("glWindowPos3fv"));
		this->WindowPos3i = reinterpret_cast<glWindowPos3i>(wglGetProcAddress("glWindowPos3i"));
		this->WindowPos3iv = reinterpret_cast<glWindowPos3iv>(wglGetProcAddress("glWindowPos3iv"));
		this->WindowPos3s = reinterpret_cast<glWindowPos3s>(wglGetProcAddress("glWindowPos3s"));
		this->WindowPos3sv = reinterpret_cast<glWindowPos3sv>(wglGetProcAddress("glWindowPos3sv"));
	}
};

// { #version 150 }
class GLcontext150 : public GLcontext140 {
	/* GlobalParameterName */
	#define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
	#define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
	#define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
	#define GL_INDEX_ARRAY_BUFFER_BINDING 0x8899
	#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
	#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
	#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
	#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
	#define GL_WEIGHT_ARRAY_BUFFER_BINDING 0x889E
	#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
	/* Unknown */
	/*#define GL_CURRENT_FOG_COORD GL_CURRENT_FOG_COORDINATE
	#define GL_FOG_COORD GL_FOG_COORDINATE
	#define GL_FOG_COORD_ARRAY GL_FOG_COORDINATE_ARRAY
	#define GL_FOG_COORD_ARRAY_BUFFER_BINDING GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING
	#define GL_FOG_COORD_ARRAY_POINTER GL_FOG_COORDINATE_ARRAY_POINTER
	#define GL_FOG_COORD_ARRAY_STRIDE GL_FOG_COORDINATE_ARRAY_STRIDE
	#define GL_FOG_COORD_ARRAY_TYPE GL_FOG_COORDINATE_ARRAY_TYPE
	#define GL_FOG_COORD_SRC GL_FOG_COORDINATE_SOURCE
	#define GL_SRC0_ALPHA GL_SOURCE0_ALPHA
	#define GL_SRC0_RGB GL_SOURCE0_RGB
	#define GL_SRC1_ALPHA GL_SOURCE1_ALPHA
	#define GL_SRC1_RGB GL_SOURCE1_RGB
	#define GL_SRC2_ALPHA GL_SOURCE2_ALPHA
	#define GL_SRC2_RGB GL_SOURCE2_RGB
	#define GL_QUERY_COUNTER_BITS 0x8864
	#define GL_CURRENT_QUERY 0x8865
	#define GL_QUERY_RESULT 0x8866
	#define GL_QUERY_RESULT_AVAILABLE 0x8867
	#define GL_SAMPLES_PASSED 0x8914*/
	typedef void (_stdcall* glBeginQuery) (GLenum target, GLuint id);
	typedef void (_stdcall* glBindBuffer) (GLenum target, GLuint buffer);
	typedef void (_stdcall* glBufferData) (GLenum target, GLsizeiptr size, const void* data, GLenum usage);
	typedef void (_stdcall* glBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
	typedef void (_stdcall* glDeleteBuffers) (GLsizei n, const GLuint* buffers);
	typedef void (_stdcall* glDeleteQueries) (GLsizei n, const GLuint* ids);
	typedef void (_stdcall* glEndQuery) (GLenum target);
	typedef void (_stdcall* glGenBuffers) (GLsizei n, GLuint* buffers);
	typedef void (_stdcall* glGenQueries) (GLsizei n, GLuint* ids);
	typedef void (_stdcall* glGetBufferParameteriv) (GLenum target, GLenum pname, GLint* params);
	typedef void (_stdcall* glGetBufferPointerv) (GLenum target, GLenum pname, void** params);
	typedef void (_stdcall* glGetBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, void* data);
	typedef void (_stdcall* glGetQueryObjectiv) (GLuint id, GLenum pname, GLint* params);
	typedef void (_stdcall* glGetQueryObjectuiv) (GLuint id, GLenum pname, GLuint* params);
	typedef void (_stdcall* glGetQueryiv) (GLenum target, GLenum pname, GLint* params);
	typedef GLboolean(_stdcall* glIsBuffer) (GLuint buffer);
	typedef GLboolean(_stdcall* glIsQuery) (GLuint id);
	typedef void* (_stdcall* glMapBuffer) (GLenum target, GLenum access);
	typedef GLboolean(_stdcall* glUnmapBuffer) (GLenum target);
public:
	glBeginQuery BeginQuery;
	glBindBuffer BindBuffer;
	glBufferData BufferData;
	glBufferSubData BufferSubData;
	glDeleteBuffers DeleteBuffers;
	glDeleteQueries DeleteQueries;
	glEndQuery EndQuery;
	glGenBuffers GenBuffers;
	glGenQueries GenQueries;
	glGetBufferParameteriv GetBufferParameteriv;
	glGetBufferPointerv GetBufferPointerv;
	glGetBufferSubData GetBufferSubData;
	glGetQueryObjectiv GetQueryObjectiv;
	glGetQueryObjectuiv GetQueryObjectuiv;
	glGetQueryiv GetQueryiv;
	glIsBuffer IsBuffer;
	glIsQuery IsQuery;
	glMapBuffer MapBuffer;
	glUnmapBuffer UnmapBuffer;
	GLcontext150() = default;
	explicit GLcontext150(HDC device) : GLcontext140(device) {
		this->BeginQuery = reinterpret_cast<glBeginQuery>(wglGetProcAddress("glBeginQuery"));
		this->BindBuffer = reinterpret_cast<glBindBuffer>(wglGetProcAddress("glBindBuffer"));
		this->BufferData = reinterpret_cast<glBufferData>(wglGetProcAddress("glBufferData"));
		this->BufferSubData = reinterpret_cast<glBufferSubData>(wglGetProcAddress("glBufferSubData"));
		this->DeleteBuffers = reinterpret_cast<glDeleteBuffers>(wglGetProcAddress("glDeleteBuffers"));
		this->DeleteQueries = reinterpret_cast<glDeleteQueries>(wglGetProcAddress("glDeleteQueries"));
		this->EndQuery = reinterpret_cast<glEndQuery>(wglGetProcAddress("glEndQuery"));
		this->GenBuffers = reinterpret_cast<glGenBuffers>(wglGetProcAddress("glGenBuffers"));
		this->GenQueries = reinterpret_cast<glGenQueries>(wglGetProcAddress("glGenQueries"));
		this->GetBufferParameteriv = reinterpret_cast<glGetBufferParameteriv>(wglGetProcAddress("glGetBufferParameteriv"));
		this->GetBufferPointerv = reinterpret_cast<glGetBufferPointerv>(wglGetProcAddress("glGetBufferPointerv"));
		this->GetBufferSubData = reinterpret_cast<glGetBufferSubData>(wglGetProcAddress("glGetBufferSubData"));
		this->GetQueryObjectiv = reinterpret_cast<glGetQueryObjectiv>(wglGetProcAddress("glGetQueryObjectiv"));
		this->GetQueryObjectuiv = reinterpret_cast<glGetQueryObjectuiv>(wglGetProcAddress("glGetQueryObjectuiv"));
		this->GetQueryiv = reinterpret_cast<glGetQueryiv>(wglGetProcAddress("glGetQueryiv"));
		this->IsBuffer = reinterpret_cast<glIsBuffer>(wglGetProcAddress("glIsBuffer"));
		this->IsQuery = reinterpret_cast<glIsQuery>(wglGetProcAddress("glIsQuery"));
		this->MapBuffer = reinterpret_cast<glMapBuffer>(wglGetProcAddress("glMapBuffer"));
		this->UnmapBuffer = reinterpret_cast<glUnmapBuffer>(wglGetProcAddress("glUnmapBuffer"));
	}
};

// { #version 200 }
class GLcontext200 : public GLcontext150 {
	/* EnableName */
	#define GL_POINT_SPRITE 0x8861
	/* PointParameterName */
	#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
	#define GL_LOWER_LEFT 0x8CA1
	#define GL_UPPER_LEFT 0x8CA2
	/* GetShaderInfoLog & GetProgramInfoLog */
	#define GL_DELETE_STATUS 0x8B80
	#define GL_COMPILE_STATUS 0x8B81
	#define GL_LINK_STATUS 0x8B82
	#define GL_VALIDATE_STATUS 0x8B83
	#define GL_INFO_LOG_LENGTH 0x8B84
	#define GL_ATTACHED_SHADERS 0x8B85
	#define GL_ACTIVE_UNIFORMS 0x8B86
	#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
	#define GL_SHADER_SOURCE_LENGTH 0x8B88
	#define GL_ACTIVE_ATTRIBUTES 0x8B89
	#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
	#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
	#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
	#define GL_CURRENT_PROGRAM 0x8B8D
	/* GlobalParameterName */
	#define GL_MAX_TEXTURE_COORDS 0x8871
	#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
	#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
	#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
	#define GL_MAX_VARYING_FLOATS 0x8B4B
	#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
	#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
	/* Unknown */
	#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
	#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
	#define GL_STENCIL_BACK_FUNC 0x8800
	#define GL_STENCIL_BACK_FAIL 0x8801
	#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
	#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
	#define GL_BLEND_EQUATION_RGB GL_BLEND_EQUATION
	#define GL_BLEND_EQUATION_ALPHA 0x883D
	#define GL_COORD_REPLACE 0x8862
	#define GL_SHADER_TYPE 0x8B4F
	#define GL_FLOAT_VEC2 0x8B50
	#define GL_FLOAT_VEC3 0x8B51
	#define GL_FLOAT_VEC4 0x8B52
	#define GL_INT_VEC2 0x8B53
	#define GL_INT_VEC3 0x8B54
	#define GL_INT_VEC4 0x8B55
	#define GL_BOOL 0x8B56
	#define GL_BOOL_VEC2 0x8B57
	#define GL_BOOL_VEC3 0x8B58
	#define GL_BOOL_VEC4 0x8B59
	#define GL_FLOAT_MAT2 0x8B5A
	#define GL_FLOAT_MAT3 0x8B5B
	#define GL_FLOAT_MAT4 0x8B5C
	#define GL_STENCIL_BACK_REF 0x8CA3
	#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
	#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
	typedef void (_stdcall* glAttachShader) (GLuint program, GLuint shader);
	typedef void (_stdcall* glBindAttribLocation) (GLuint program, GLuint index, const GLchar* name);
	typedef void (_stdcall* glBlendEquationSeparate) (GLenum modeRGB, GLenum modeAlpha);
	typedef void (_stdcall* glCompileShader) (GLuint shader);
	typedef GLuint(_stdcall* glCreateProgram) (void);
	typedef GLuint(_stdcall* glCreateShader) (GLenum type);
	typedef void (_stdcall* glDeleteProgram) (GLuint program);
	typedef void (_stdcall* glDeleteShader) (GLuint shader);
	typedef void (_stdcall* glDetachShader) (GLuint program, GLuint shader);
	typedef void (_stdcall* glDisableVertexAttribArray) (GLuint index);
	typedef void (_stdcall* glDrawBuffers) (GLsizei n, const GLenum* bufs);
	typedef void (_stdcall* glEnableVertexAttribArray) (GLuint index);
	typedef void (_stdcall* glGetActiveAttrib) (GLuint program, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
	typedef void (_stdcall* glGetActiveUniform) (GLuint program, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
	typedef void (_stdcall* glGetAttachedShaders) (GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);
	typedef GLint(_stdcall* glGetAttribLocation) (GLuint program, const GLchar* name);
	typedef void (_stdcall* glGetProgramInfoLog) (GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
	typedef void (_stdcall* glGetProgramiv) (GLuint program, GLenum pname, GLint* param);
	typedef void (_stdcall* glGetShaderInfoLog) (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
	typedef void (_stdcall* glGetShaderSource) (GLuint obj, GLsizei maxLength, GLsizei* length, GLchar* source);
	typedef void (_stdcall* glGetShaderiv) (GLuint shader, GLenum pname, GLint* param);
	typedef GLint(_stdcall* glGetUniformLocation) (GLuint program, const GLchar* name);
	typedef void (_stdcall* glGetUniformfv) (GLuint program, GLint location, GLfloat* params);
	typedef void (_stdcall* glGetUniformiv) (GLuint program, GLint location, GLint* params);
	typedef void (_stdcall* glGetVertexAttribPointerv) (GLuint index, GLenum pname, void** pointer);
	typedef void (_stdcall* glGetVertexAttribdv) (GLuint index, GLenum pname, GLdouble* params);
	typedef void (_stdcall* glGetVertexAttribfv) (GLuint index, GLenum pname, GLfloat* params);
	typedef void (_stdcall* glGetVertexAttribiv) (GLuint index, GLenum pname, GLint* params);
	typedef GLboolean(_stdcall* glIsProgram) (GLuint program);
	typedef GLboolean(_stdcall* glIsShader) (GLuint shader);
	typedef void (_stdcall* glLinkProgram) (GLuint program);
	typedef void (_stdcall* glShaderSource) (GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
	typedef void (_stdcall* glStencilFuncSeparate) (GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
	typedef void (_stdcall* glStencilMaskSeparate) (GLenum face, GLuint mask);
	typedef void (_stdcall* glStencilOpSeparate) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
	typedef void (_stdcall* glUniform1f) (GLint location, GLfloat v0);
	typedef void (_stdcall* glUniform1fv) (GLint location, GLsizei count, const GLfloat* value);
	typedef void (_stdcall* glUniform1i) (GLint location, GLint v0);
	typedef void (_stdcall* glUniform1iv) (GLint location, GLsizei count, const GLint* value);
	typedef void (_stdcall* glUniform2f) (GLint location, GLfloat v0, GLfloat v1);
	typedef void (_stdcall* glUniform2fv) (GLint location, GLsizei count, const GLfloat* value);
	typedef void (_stdcall* glUniform2i) (GLint location, GLint v0, GLint v1);
	typedef void (_stdcall* glUniform2iv) (GLint location, GLsizei count, const GLint* value);
	typedef void (_stdcall* glUniform3f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	typedef void (_stdcall* glUniform3fv) (GLint location, GLsizei count, const GLfloat* value);
	typedef void (_stdcall* glUniform3i) (GLint location, GLint v0, GLint v1, GLint v2);
	typedef void (_stdcall* glUniform3iv) (GLint location, GLsizei count, const GLint* value);
	typedef void (_stdcall* glUniform4f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	typedef void (_stdcall* glUniform4fv) (GLint location, GLsizei count, const GLfloat* value);
	typedef void (_stdcall* glUniform4i) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	typedef void (_stdcall* glUniform4iv) (GLint location, GLsizei count, const GLint* value);
	typedef void (_stdcall* glUniformMatrix2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	typedef void (_stdcall* glUniformMatrix3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	typedef void (_stdcall* glUniformMatrix4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	typedef void (_stdcall* glUseProgram) (GLuint program);
	typedef void (_stdcall* glValidateProgram) (GLuint program);
	typedef void (_stdcall* glVertexAttrib1d) (GLuint index, GLdouble x);
	typedef void (_stdcall* glVertexAttrib1dv) (GLuint index, const GLdouble* v);
	typedef void (_stdcall* glVertexAttrib1f) (GLuint index, GLfloat x);
	typedef void (_stdcall* glVertexAttrib1fv) (GLuint index, const GLfloat* v);
	typedef void (_stdcall* glVertexAttrib1s) (GLuint index, GLshort x);
	typedef void (_stdcall* glVertexAttrib1sv) (GLuint index, const GLshort* v);
	typedef void (_stdcall* glVertexAttrib2d) (GLuint index, GLdouble x, GLdouble y);
	typedef void (_stdcall* glVertexAttrib2dv) (GLuint index, const GLdouble* v);
	typedef void (_stdcall* glVertexAttrib2f) (GLuint index, GLfloat x, GLfloat y);
	typedef void (_stdcall* glVertexAttrib2fv) (GLuint index, const GLfloat* v);
	typedef void (_stdcall* glVertexAttrib2s) (GLuint index, GLshort x, GLshort y);
	typedef void (_stdcall* glVertexAttrib2sv) (GLuint index, const GLshort* v);
	typedef void (_stdcall* glVertexAttrib3d) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
	typedef void (_stdcall* glVertexAttrib3dv) (GLuint index, const GLdouble* v);
	typedef void (_stdcall* glVertexAttrib3f) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
	typedef void (_stdcall* glVertexAttrib3fv) (GLuint index, const GLfloat* v);
	typedef void (_stdcall* glVertexAttrib3s) (GLuint index, GLshort x, GLshort y, GLshort z);
	typedef void (_stdcall* glVertexAttrib3sv) (GLuint index, const GLshort* v);
	typedef void (_stdcall* glVertexAttrib4Nbv) (GLuint index, const GLbyte* v);
	typedef void (_stdcall* glVertexAttrib4Niv) (GLuint index, const GLint* v);
	typedef void (_stdcall* glVertexAttrib4Nsv) (GLuint index, const GLshort* v);
	typedef void (_stdcall* glVertexAttrib4Nub) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	typedef void (_stdcall* glVertexAttrib4Nubv) (GLuint index, const GLubyte* v);
	typedef void (_stdcall* glVertexAttrib4Nuiv) (GLuint index, const GLuint* v);
	typedef void (_stdcall* glVertexAttrib4Nusv) (GLuint index, const GLushort* v);
	typedef void (_stdcall* glVertexAttrib4bv) (GLuint index, const GLbyte* v);
	typedef void (_stdcall* glVertexAttrib4d) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	typedef void (_stdcall* glVertexAttrib4dv) (GLuint index, const GLdouble* v);
	typedef void (_stdcall* glVertexAttrib4f) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	typedef void (_stdcall* glVertexAttrib4fv) (GLuint index, const GLfloat* v);
	typedef void (_stdcall* glVertexAttrib4iv) (GLuint index, const GLint* v);
	typedef void (_stdcall* glVertexAttrib4s) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	typedef void (_stdcall* glVertexAttrib4sv) (GLuint index, const GLshort* v);
	typedef void (_stdcall* glVertexAttrib4ubv) (GLuint index, const GLubyte* v);
	typedef void (_stdcall* glVertexAttrib4uiv) (GLuint index, const GLuint* v);
	typedef void (_stdcall* glVertexAttrib4usv) (GLuint index, const GLushort* v);
	typedef void (_stdcall* glVertexAttribPointer) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
public:
	glAttachShader AttachShader;
	glBindAttribLocation BindAttribLocation;
	glBlendEquationSeparate BlendEquationSeparate;
	glCompileShader CompileShader;
	glCreateProgram CreateProgram;
	glCreateShader CreateShader;
	glDeleteProgram DeleteProgram;
	glDeleteShader DeleteShader;
	glDetachShader DetachShader;
	glDisableVertexAttribArray DisableVertexAttribArray;
	glDrawBuffers DrawBuffers;
	glEnableVertexAttribArray EnableVertexAttribArray;
	glGetActiveAttrib GetActiveAttrib;
	glGetActiveUniform GetActiveUniform;
	glGetAttachedShaders GetAttachedShaders;
	glGetAttribLocation GetAttribLocation;
	glGetProgramInfoLog GetProgramInfoLog;
	glGetProgramiv GetProgramiv;
	glGetShaderInfoLog GetShaderInfoLog;
	glGetShaderSource GetShaderSource;
	glGetShaderiv GetShaderiv;
	glGetUniformLocation GetUniformLocation;
	glGetUniformfv GetUniformfv;
	glGetUniformiv GetUniformiv;
	glGetVertexAttribPointerv GetVertexAttribPointerv;
	glGetVertexAttribdv GetVertexAttribdv;
	glGetVertexAttribfv GetVertexAttribfv;
	glGetVertexAttribiv GetVertexAttribiv;
	glIsProgram IsProgram;
	glIsShader IsShader;
	glLinkProgram LinkProgram;
	glShaderSource ShaderSource;
	glStencilFuncSeparate StencilFuncSeparate;
	glStencilMaskSeparate StencilMaskSeparate;
	glStencilOpSeparate StencilOpSeparate;
	glUniform1f Uniform1f;
	glUniform1fv Uniform1fv;
	glUniform1i Uniform1i;
	glUniform1iv Uniform1iv;
	glUniform2f Uniform2f;
	glUniform2fv Uniform2fv;
	glUniform2i Uniform2i;
	glUniform2iv Uniform2iv;
	glUniform3f Uniform3f;
	glUniform3fv Uniform3fv;
	glUniform3i Uniform3i;
	glUniform3iv Uniform3iv;
	glUniform4f Uniform4f;
	glUniform4fv Uniform4fv;
	glUniform4i Uniform4i;
	glUniform4iv Uniform4iv;
	glUniformMatrix2fv UniformMatrix2fv;
	glUniformMatrix3fv UniformMatrix3fv;
	glUniformMatrix4fv UniformMatrix4fv;
	glUseProgram UseProgram;
	glValidateProgram ValidateProgram;
	glVertexAttrib1d VertexAttrib1d;
	glVertexAttrib1dv VertexAttrib1dv;
	glVertexAttrib1f VertexAttrib1f;
	glVertexAttrib1fv VertexAttrib1fv;
	glVertexAttrib1s VertexAttrib1s;
	glVertexAttrib1sv VertexAttrib1sv;
	glVertexAttrib2d VertexAttrib2d;
	glVertexAttrib2dv VertexAttrib2dv;
	glVertexAttrib2f VertexAttrib2f;
	glVertexAttrib2fv VertexAttrib2fv;
	glVertexAttrib2s VertexAttrib2s;
	glVertexAttrib2sv VertexAttrib2sv;
	glVertexAttrib3d VertexAttrib3d;
	glVertexAttrib3dv VertexAttrib3dv;
	glVertexAttrib3f VertexAttrib3f;
	glVertexAttrib3fv VertexAttrib3fv;
	glVertexAttrib3s VertexAttrib3s;
	glVertexAttrib3sv VertexAttrib3sv;
	glVertexAttrib4Nbv VertexAttrib4Nbv;
	glVertexAttrib4Niv VertexAttrib4Niv;
	glVertexAttrib4Nsv VertexAttrib4Nsv;
	glVertexAttrib4Nub VertexAttrib4Nub;
	glVertexAttrib4Nubv VertexAttrib4Nubv;
	glVertexAttrib4Nuiv VertexAttrib4Nuiv;
	glVertexAttrib4Nusv VertexAttrib4Nusv;
	glVertexAttrib4bv VertexAttrib4bv;
	glVertexAttrib4d VertexAttrib4d;
	glVertexAttrib4dv VertexAttrib4dv;
	glVertexAttrib4f VertexAttrib4f;
	glVertexAttrib4fv VertexAttrib4fv;
	glVertexAttrib4iv VertexAttrib4iv;
	glVertexAttrib4s VertexAttrib4s;
	glVertexAttrib4sv VertexAttrib4sv;
	glVertexAttrib4ubv VertexAttrib4ubv;
	glVertexAttrib4uiv VertexAttrib4uiv;
	glVertexAttrib4usv VertexAttrib4usv;
	glVertexAttribPointer VertexAttribPointer;
	GLcontext200() = default;
	explicit GLcontext200(HDC device) : GLcontext150(device) {
		this->AttachShader = reinterpret_cast<glAttachShader>(wglGetProcAddress("glAttachShader"));
		this->BindAttribLocation = reinterpret_cast<glBindAttribLocation>(wglGetProcAddress("glBindAttribLocation"));
		this->BlendEquationSeparate = reinterpret_cast<glBlendEquationSeparate>(wglGetProcAddress("glBlendEquationSeparate"));
		this->CompileShader = reinterpret_cast<glCompileShader>(wglGetProcAddress("glCompileShader"));
		this->CreateProgram = reinterpret_cast<glCreateProgram>(wglGetProcAddress("glCreateProgram"));
		this->CreateShader = reinterpret_cast<glCreateShader>(wglGetProcAddress("glCreateShader"));
		this->DeleteProgram = reinterpret_cast<glDeleteProgram>(wglGetProcAddress("glDeleteProgram"));
		this->DeleteShader = reinterpret_cast<glDeleteShader>(wglGetProcAddress("glDeleteShader"));
		this->DetachShader = reinterpret_cast<glDetachShader>(wglGetProcAddress("glDetachShader"));
		this->DisableVertexAttribArray = reinterpret_cast<glDisableVertexAttribArray>(wglGetProcAddress("glDisableVertexAttribArray"));
		this->DrawBuffers = reinterpret_cast<glDrawBuffers>(wglGetProcAddress("glDrawBuffers"));
		this->EnableVertexAttribArray = reinterpret_cast<glEnableVertexAttribArray>(wglGetProcAddress("glEnableVertexAttribArray"));
		this->GetActiveAttrib = reinterpret_cast<glGetActiveAttrib>(wglGetProcAddress("glGetActiveAttrib"));
		this->GetActiveUniform = reinterpret_cast<glGetActiveUniform>(wglGetProcAddress("glGetActiveUniform"));
		this->GetAttachedShaders = reinterpret_cast<glGetAttachedShaders>(wglGetProcAddress("glGetAttachedShaders"));
		this->GetAttribLocation = reinterpret_cast<glGetAttribLocation>(wglGetProcAddress("glGetAttribLocation"));
		this->GetProgramInfoLog = reinterpret_cast<glGetProgramInfoLog>(wglGetProcAddress("glGetProgramInfoLog"));
		this->GetProgramiv = reinterpret_cast<glGetProgramiv>(wglGetProcAddress("glGetProgramiv"));
		this->GetShaderInfoLog = reinterpret_cast<glGetShaderInfoLog>(wglGetProcAddress("glGetShaderInfoLog"));
		this->GetShaderSource = reinterpret_cast<glGetShaderSource>(wglGetProcAddress("glGetShaderSource"));
		this->GetShaderiv = reinterpret_cast<glGetShaderiv>(wglGetProcAddress("glGetShaderiv"));
		this->GetUniformLocation = reinterpret_cast<glGetUniformLocation>(wglGetProcAddress("glGetUniformLocation"));
		this->GetUniformfv = reinterpret_cast<glGetUniformfv>(wglGetProcAddress("glGetUniformfv"));
		this->GetUniformiv = reinterpret_cast<glGetUniformiv>(wglGetProcAddress("glGetUniformiv"));
		this->GetVertexAttribPointerv = reinterpret_cast<glGetVertexAttribPointerv>(wglGetProcAddress("glGetVertexAttribPointerv"));
		this->GetVertexAttribdv = reinterpret_cast<glGetVertexAttribdv>(wglGetProcAddress("glGetVertexAttribdv"));
		this->GetVertexAttribfv = reinterpret_cast<glGetVertexAttribfv>(wglGetProcAddress("glGetVertexAttribfv"));
		this->GetVertexAttribiv = reinterpret_cast<glGetVertexAttribiv>(wglGetProcAddress("glGetVertexAttribiv"));
		this->IsProgram = reinterpret_cast<glIsProgram>(wglGetProcAddress("glIsProgram"));
		this->IsShader = reinterpret_cast<glIsShader>(wglGetProcAddress("glIsShader"));
		this->LinkProgram = reinterpret_cast<glLinkProgram>(wglGetProcAddress("glLinkProgram"));
		this->ShaderSource = reinterpret_cast<glShaderSource>(wglGetProcAddress("glShaderSource"));
		this->StencilFuncSeparate = reinterpret_cast<glStencilFuncSeparate>(wglGetProcAddress("glStencilFuncSeparate"));
		this->StencilMaskSeparate = reinterpret_cast<glStencilMaskSeparate>(wglGetProcAddress("glStencilMaskSeparate"));
		this->StencilOpSeparate = reinterpret_cast<glStencilOpSeparate>(wglGetProcAddress("glStencilOpSeparate"));
		this->Uniform1f = reinterpret_cast<glUniform1f>(wglGetProcAddress("glUniform1f"));
		this->Uniform1fv = reinterpret_cast<glUniform1fv>(wglGetProcAddress("glUniform1fv"));
		this->Uniform1i = reinterpret_cast<glUniform1i>(wglGetProcAddress("glUniform1i"));
		this->Uniform1iv = reinterpret_cast<glUniform1iv>(wglGetProcAddress("glUniform1iv"));
		this->Uniform2f = reinterpret_cast<glUniform2f>(wglGetProcAddress("glUniform2f"));
		this->Uniform2fv = reinterpret_cast<glUniform2fv>(wglGetProcAddress("glUniform2fv"));
		this->Uniform2i = reinterpret_cast<glUniform2i>(wglGetProcAddress("glUniform2i"));
		this->Uniform2iv = reinterpret_cast<glUniform2iv>(wglGetProcAddress("glUniform2iv"));
		this->Uniform3f = reinterpret_cast<glUniform3f>(wglGetProcAddress("glUniform3f"));
		this->Uniform3fv = reinterpret_cast<glUniform3fv>(wglGetProcAddress("glUniform3fv"));
		this->Uniform3i = reinterpret_cast<glUniform3i>(wglGetProcAddress("glUniform3i"));
		this->Uniform3iv = reinterpret_cast<glUniform3iv>(wglGetProcAddress("glUniform3iv"));
		this->Uniform4f = reinterpret_cast<glUniform4f>(wglGetProcAddress("glUniform4f"));
		this->Uniform4fv = reinterpret_cast<glUniform4fv>(wglGetProcAddress("glUniform4fv"));
		this->Uniform4i = reinterpret_cast<glUniform4i>(wglGetProcAddress("glUniform4i"));
		this->Uniform4iv = reinterpret_cast<glUniform4iv>(wglGetProcAddress("glUniform4iv"));
		this->UniformMatrix2fv = reinterpret_cast<glUniformMatrix2fv>(wglGetProcAddress("glUniformMatrix2fv"));
		this->UniformMatrix3fv = reinterpret_cast<glUniformMatrix3fv>(wglGetProcAddress("glUniformMatrix3fv"));
		this->UniformMatrix4fv = reinterpret_cast<glUniformMatrix4fv>(wglGetProcAddress("glUniformMatrix4fv"));
		this->UseProgram = reinterpret_cast<glUseProgram>(wglGetProcAddress("glUseProgram"));
		this->ValidateProgram = reinterpret_cast<glValidateProgram>(wglGetProcAddress("glValidateProgram"));
		this->VertexAttrib1d = reinterpret_cast<glVertexAttrib1d>(wglGetProcAddress("glVertexAttrib1d"));
		this->VertexAttrib1dv = reinterpret_cast<glVertexAttrib1dv>(wglGetProcAddress("glVertexAttrib1dv"));
		this->VertexAttrib1f = reinterpret_cast<glVertexAttrib1f>(wglGetProcAddress("glVertexAttrib1f"));
		this->VertexAttrib1fv = reinterpret_cast<glVertexAttrib1fv>(wglGetProcAddress("glVertexAttrib1fv"));
		this->VertexAttrib1s = reinterpret_cast<glVertexAttrib1s>(wglGetProcAddress("glVertexAttrib1s"));
		this->VertexAttrib1sv = reinterpret_cast<glVertexAttrib1sv>(wglGetProcAddress("glVertexAttrib1sv"));
		this->VertexAttrib2d = reinterpret_cast<glVertexAttrib2d>(wglGetProcAddress("glVertexAttrib2d"));
		this->VertexAttrib2dv = reinterpret_cast<glVertexAttrib2dv>(wglGetProcAddress("glVertexAttrib2dv"));
		this->VertexAttrib2f = reinterpret_cast<glVertexAttrib2f>(wglGetProcAddress("glVertexAttrib2f"));
		this->VertexAttrib2fv = reinterpret_cast<glVertexAttrib2fv>(wglGetProcAddress("glVertexAttrib2fv"));
		this->VertexAttrib2s = reinterpret_cast<glVertexAttrib2s>(wglGetProcAddress("glVertexAttrib2s"));
		this->VertexAttrib2sv = reinterpret_cast<glVertexAttrib2sv>(wglGetProcAddress("glVertexAttrib2sv"));
		this->VertexAttrib3d = reinterpret_cast<glVertexAttrib3d>(wglGetProcAddress("glVertexAttrib3d"));
		this->VertexAttrib3dv = reinterpret_cast<glVertexAttrib3dv>(wglGetProcAddress("glVertexAttrib3dv"));
		this->VertexAttrib3f = reinterpret_cast<glVertexAttrib3f>(wglGetProcAddress("glVertexAttrib3f"));
		this->VertexAttrib3fv = reinterpret_cast<glVertexAttrib3fv>(wglGetProcAddress("glVertexAttrib3fv"));
		this->VertexAttrib3s = reinterpret_cast<glVertexAttrib3s>(wglGetProcAddress("glVertexAttrib3s"));
		this->VertexAttrib3sv = reinterpret_cast<glVertexAttrib3sv>(wglGetProcAddress("glVertexAttrib3sv"));
		this->VertexAttrib4Nbv = reinterpret_cast<glVertexAttrib4Nbv>(wglGetProcAddress("glVertexAttrib4Nbv"));
		this->VertexAttrib4Niv = reinterpret_cast<glVertexAttrib4Niv>(wglGetProcAddress("glVertexAttrib4Niv"));
		this->VertexAttrib4Nsv = reinterpret_cast<glVertexAttrib4Nsv>(wglGetProcAddress("glVertexAttrib4Nsv"));
		this->VertexAttrib4Nub = reinterpret_cast<glVertexAttrib4Nub>(wglGetProcAddress("glVertexAttrib4Nub"));
		this->VertexAttrib4Nubv = reinterpret_cast<glVertexAttrib4Nubv>(wglGetProcAddress("glVertexAttrib4Nubv"));
		this->VertexAttrib4Nuiv = reinterpret_cast<glVertexAttrib4Nuiv>(wglGetProcAddress("glVertexAttrib4Nuiv"));
		this->VertexAttrib4Nusv = reinterpret_cast<glVertexAttrib4Nusv>(wglGetProcAddress("glVertexAttrib4Nusv"));
		this->VertexAttrib4bv = reinterpret_cast<glVertexAttrib4bv>(wglGetProcAddress("glVertexAttrib4bv"));
		this->VertexAttrib4d = reinterpret_cast<glVertexAttrib4d>(wglGetProcAddress("glVertexAttrib4d"));
		this->VertexAttrib4dv = reinterpret_cast<glVertexAttrib4dv>(wglGetProcAddress("glVertexAttrib4dv"));
		this->VertexAttrib4f = reinterpret_cast<glVertexAttrib4f>(wglGetProcAddress("glVertexAttrib4f"));
		this->VertexAttrib4fv = reinterpret_cast<glVertexAttrib4fv>(wglGetProcAddress("glVertexAttrib4fv"));
		this->VertexAttrib4iv = reinterpret_cast<glVertexAttrib4iv>(wglGetProcAddress("glVertexAttrib4iv"));
		this->VertexAttrib4s = reinterpret_cast<glVertexAttrib4s>(wglGetProcAddress("glVertexAttrib4s"));
		this->VertexAttrib4sv = reinterpret_cast<glVertexAttrib4sv>(wglGetProcAddress("glVertexAttrib4sv"));
		this->VertexAttrib4ubv = reinterpret_cast<glVertexAttrib4ubv>(wglGetProcAddress("glVertexAttrib4ubv"));
		this->VertexAttrib4uiv = reinterpret_cast<glVertexAttrib4uiv>(wglGetProcAddress("glVertexAttrib4uiv"));
		this->VertexAttrib4usv = reinterpret_cast<glVertexAttrib4usv>(wglGetProcAddress("glVertexAttrib4usv"));
		this->VertexAttribPointer = reinterpret_cast<glVertexAttribPointer>(wglGetProcAddress("glVertexAttribPointer"));
	}
};

// { #version 210 }
class GLcontext210 : public GLcontext200 {
public:
	#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
	#define GL_FLOAT_MAT2x3 0x8B65
	#define GL_FLOAT_MAT2x4 0x8B66
	#define GL_FLOAT_MAT3x2 0x8B67
	#define GL_FLOAT_MAT3x4 0x8B68
	#define GL_FLOAT_MAT4x2 0x8B69
	#define GL_FLOAT_MAT4x3 0x8B6A
	#define GL_SRGB 0x8C40
	#define GL_SRGB8 0x8C41
	#define GL_SRGB_ALPHA 0x8C42
	#define GL_SRGB8_ALPHA8 0x8C43
	/*#define GL_SLUMINANCE_ALPHA 0x8C44
	#define GL_SLUMINANCE8_ALPHA8 0x8C45
	#define GL_SLUMINANCE 0x8C46
	#define GL_SLUMINANCE8 0x8C47*/
	#define GL_COMPRESSED_SRGB 0x8C48
	#define GL_COMPRESSED_SRGB_ALPHA 0x8C49
	#define GL_COMPRESSED_SLUMINANCE 0x8C4A
	#define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B
	typedef void (_stdcall* glUniformMatrix2x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	typedef void (_stdcall* glUniformMatrix2x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	typedef void (_stdcall* glUniformMatrix3x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	typedef void (_stdcall* glUniformMatrix3x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	typedef void (_stdcall* glUniformMatrix4x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	typedef void (_stdcall* glUniformMatrix4x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	glUniformMatrix2x3fv UniformMatrix2x3fv;
	glUniformMatrix2x4fv UniformMatrix2x4fv;
	glUniformMatrix3x2fv UniformMatrix3x2fv;
	glUniformMatrix3x4fv UniformMatrix3x4fv;
	glUniformMatrix4x2fv UniformMatrix4x2fv;
	glUniformMatrix4x3fv UniformMatrix4x3fv;
	GLcontext210() = default;
	explicit GLcontext210(HDC device) : GLcontext200(device) {
		this->UniformMatrix2x3fv = reinterpret_cast<glUniformMatrix2x3fv>(wglGetProcAddress("glUniformMatrix2x3fv"));
		this->UniformMatrix2x4fv = reinterpret_cast<glUniformMatrix2x4fv>(wglGetProcAddress("glUniformMatrix2x4fv"));
		this->UniformMatrix3x2fv = reinterpret_cast<glUniformMatrix3x2fv>(wglGetProcAddress("glUniformMatrix3x2fv"));
		this->UniformMatrix3x4fv = reinterpret_cast<glUniformMatrix3x4fv>(wglGetProcAddress("glUniformMatrix3x4fv"));
		this->UniformMatrix4x2fv = reinterpret_cast<glUniformMatrix4x2fv>(wglGetProcAddress("glUniformMatrix4x2fv"));
		this->UniformMatrix4x3fv = reinterpret_cast<glUniformMatrix4x3fv>(wglGetProcAddress("glUniformMatrix4x3fv"));
	}
};

// { #version 300 }
class GLcontext300 : public GLcontext210 {
	/* GlobalParameterName */
	#define GL_MAX_VARYING_COMPONENTS GL_MAX_VARYING_FLOATS
	#define GL_MAJOR_VERSION 0x821B
	#define GL_MINOR_VERSION 0x821C
	#define GL_NUM_EXTENSIONS 0x821D
	#define GL_DEPTH_BUFFER 0x8223
	#define GL_STENCIL_BUFFER 0x8224
	#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
	#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
	#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
	#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
	#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
	#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
	#define GL_PRIMITIVES_GENERATED 0x8C87
	#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
	#define GL_RASTERIZER_DISCARD 0x8C89
	#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
	#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
	#define GL_INTERLEAVED_ATTRIBS 0x8C8C
	#define GL_SEPARATE_ATTRIBS 0x8C8D
	#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
	#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
	#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
	/* GlobalParameterName ARB */
	#define GL_VERTEX_ARRAY_BINDING 0x85B5
	/* FramebufferOperation ARB */
	#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
	#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
	#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
	#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
	#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
	#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
	#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
	#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
	#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
	#define GL_FRAMEBUFFER_DEFAULT 0x8218
	#define GL_FRAMEBUFFER_UNDEFINED 0x8219
	#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
	#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
	#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
	#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
	#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
	#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
	#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
	#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
	#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
	#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
	#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
	#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
	#define GL_MAX_SAMPLES 0x8D57
	/* MapBufferBit */
	#define GL_MAP_READ_BIT 0x0001
	#define GL_MAP_WRITE_BIT 0x0002
	#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
	#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
	#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
	#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
	/* Unknown */
	#define GL_CLIP_DISTANCE0 GL_CLIP_PLANE0
	#define GL_CLIP_DISTANCE1 GL_CLIP_PLANE1
	#define GL_CLIP_DISTANCE2 GL_CLIP_PLANE2
	#define GL_CLIP_DISTANCE3 GL_CLIP_PLANE3
	#define GL_CLIP_DISTANCE4 GL_CLIP_PLANE4
	#define GL_CLIP_DISTANCE5 GL_CLIP_PLANE5
	#define GL_COMPARE_REF_TO_TEXTURE GL_COMPARE_R_TO_TEXTURE_ARB
	#define GL_MAX_CLIP_DISTANCES GL_MAX_CLIP_PLANES
	#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x0001
	#define GL_CONTEXT_FLAGS 0x821E
	#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
	#define GL_CLAMP_VERTEX_COLOR 0x891A
	#define GL_CLAMP_FRAGMENT_COLOR 0x891B
	#define GL_CLAMP_READ_COLOR 0x891C
	#define GL_FIXED_ONLY 0x891D
	#define GL_TEXTURE_RED_TYPE 0x8C10
	#define GL_TEXTURE_GREEN_TYPE 0x8C11
	#define GL_TEXTURE_BLUE_TYPE 0x8C12
	#define GL_TEXTURE_ALPHA_TYPE 0x8C13
	#define GL_TEXTURE_LUMINANCE_TYPE 0x8C14
	#define GL_TEXTURE_INTENSITY_TYPE 0x8C15
	#define GL_TEXTURE_DEPTH_TYPE 0x8C16
	#define GL_TEXTURE_SHARED_SIZE 0x8C3
	#define GL_UNSIGNED_INT_VEC2 0x8DC6
	#define GL_UNSIGNED_INT_VEC3 0x8DC7
	#define GL_UNSIGNED_INT_VEC4 0x8DC8
	#define GL_QUERY_WAIT 0x8E13
	#define GL_QUERY_NO_WAIT 0x8E14
	#define GL_QUERY_BY_REGION_WAIT 0x8E15
	#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16
	typedef void (_stdcall* glBeginConditionalRender) (GLuint id, GLenum mode);
	typedef void (_stdcall* glBeginTransformFeedback) (GLenum primitiveMode);
	typedef void (_stdcall* glBindFragDataLocation) (GLuint program, GLuint colorNumber, const GLchar* name);
	typedef void (_stdcall* glClampColor) (GLenum target, GLenum clamp);
	typedef void (_stdcall* glClearBufferfi) (GLenum buffer, GLint drawBuffer, GLfloat depth, GLint stencil);
	typedef void (_stdcall* glClearBufferfv) (GLenum buffer, GLint drawBuffer, const GLfloat* value);
	typedef void (_stdcall* glClearBufferiv) (GLenum buffer, GLint drawBuffer, const GLint* value);
	typedef void (_stdcall* glClearBufferuiv) (GLenum buffer, GLint drawBuffer, const GLuint* value);
	typedef void (_stdcall* glColorMaski) (GLuint buf, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
	typedef void (_stdcall* glDisablei) (GLenum cap, GLuint index);
	typedef void (_stdcall* glEnablei) (GLenum cap, GLuint index);
	typedef void (_stdcall* glEndConditionalRender) (void);
	typedef void (_stdcall* glEndTransformFeedback) (void);
	typedef void (_stdcall* glGetBooleani_v) (GLenum pname, GLuint index, GLboolean* data);
	typedef GLint(_stdcall* glGetFragDataLocation) (GLuint program, const GLchar* name);
	typedef const GLubyte* (_stdcall* glGetStringi) (GLenum name, GLuint index);
	typedef void (_stdcall* glGetTexParameterIiv) (GLenum target, GLenum pname, GLint* params);
	typedef void (_stdcall* glGetTexParameterIuiv) (GLenum target, GLenum pname, GLuint* params);
	typedef void (_stdcall* glGetTransformFeedbackVarying) (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
	typedef void (_stdcall* glGetUniformuiv) (GLuint program, GLint location, GLuint* params);
	typedef void (_stdcall* glGetVertexAttribIiv) (GLuint index, GLenum pname, GLint* params);
	typedef void (_stdcall* glGetVertexAttribIuiv) (GLuint index, GLenum pname, GLuint* params);
	typedef GLboolean(_stdcall* glIsEnabledi) (GLenum cap, GLuint index);
	typedef void (_stdcall* glTexParameterIiv) (GLenum target, GLenum pname, const GLint* params);
	typedef void (_stdcall* glTexParameterIuiv) (GLenum target, GLenum pname, const GLuint* params);
	typedef void (_stdcall* glTransformFeedbackVaryings) (GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode);
	typedef void (_stdcall* glUniform1ui) (GLint location, GLuint v0);
	typedef void (_stdcall* glUniform1uiv) (GLint location, GLsizei count, const GLuint* value);
	typedef void (_stdcall* glUniform2ui) (GLint location, GLuint v0, GLuint v1);
	typedef void (_stdcall* glUniform2uiv) (GLint location, GLsizei count, const GLuint* value);
	typedef void (_stdcall* glUniform3ui) (GLint location, GLuint v0, GLuint v1, GLuint v2);
	typedef void (_stdcall* glUniform3uiv) (GLint location, GLsizei count, const GLuint* value);
	typedef void (_stdcall* glUniform4ui) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	typedef void (_stdcall* glUniform4uiv) (GLint location, GLsizei count, const GLuint* value);
	typedef void (_stdcall* glVertexAttribI1i) (GLuint index, GLint v0);
	typedef void (_stdcall* glVertexAttribI1iv) (GLuint index, const GLint* v0);
	typedef void (_stdcall* glVertexAttribI1ui) (GLuint index, GLuint v0);
	typedef void (_stdcall* glVertexAttribI1uiv) (GLuint index, const GLuint* v0);
	typedef void (_stdcall* glVertexAttribI2i) (GLuint index, GLint v0, GLint v1);
	typedef void (_stdcall* glVertexAttribI2iv) (GLuint index, const GLint* v0);
	typedef void (_stdcall* glVertexAttribI2ui) (GLuint index, GLuint v0, GLuint v1);
	typedef void (_stdcall* glVertexAttribI2uiv) (GLuint index, const GLuint* v0);
	typedef void (_stdcall* glVertexAttribI3i) (GLuint index, GLint v0, GLint v1, GLint v2);
	typedef void (_stdcall* glVertexAttribI3iv) (GLuint index, const GLint* v0);
	typedef void (_stdcall* glVertexAttribI3ui) (GLuint index, GLuint v0, GLuint v1, GLuint v2);
	typedef void (_stdcall* glVertexAttribI3uiv) (GLuint index, const GLuint* v0);
	typedef void (_stdcall* glVertexAttribI4bv) (GLuint index, const GLbyte* v0);
	typedef void (_stdcall* glVertexAttribI4i) (GLuint index, GLint v0, GLint v1, GLint v2, GLint v3);
	typedef void (_stdcall* glVertexAttribI4iv) (GLuint index, const GLint* v0);
	typedef void (_stdcall* glVertexAttribI4sv) (GLuint index, const GLshort* v0);
	typedef void (_stdcall* glVertexAttribI4ubv) (GLuint index, const GLubyte* v0);
	typedef void (_stdcall* glVertexAttribI4ui) (GLuint index, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	typedef void (_stdcall* glVertexAttribI4uiv) (GLuint index, const GLuint* v0);
	typedef void (_stdcall* glVertexAttribI4usv) (GLuint index, const GLushort* v0);
	typedef void (_stdcall* glVertexAttribIPointer) (GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
	typedef void(_stdcall* glGenerateMipmap) (GLenum target);
	typedef void(_stdcall* glGenFramebuffers) (GLsizei n, GLuint* framebuffers);
	typedef void(_stdcall* glGenRenderbuffers) (GLsizei n, GLuint* renderbuffers);
	typedef void(_stdcall* glDeleteFramebuffers) (GLsizei n, const GLuint* framebuffers);
	typedef void(_stdcall* glDeleteRenderbuffers) (GLsizei n, const GLuint* renderbuffers);
	typedef void(_stdcall* glBindFramebuffer) (GLenum target, GLuint framebuffer);
	typedef void(_stdcall* glBindRenderbuffer) (GLenum target, GLuint renderbuffer);
	typedef void(_stdcall* glRenderbufferStorage) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	typedef void(_stdcall* glRenderbufferStorageMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	typedef void(_stdcall* glFramebufferRenderbuffer) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	typedef void(_stdcall* glFramebufferTexture1D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	typedef void(_stdcall* glFramebufferTexture2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	typedef void(_stdcall* glFramebufferTexture3D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint layer);
	typedef void(_stdcall* glBlitFramebuffer) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	typedef void(_stdcall* glFramebufferTextureLayer) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	typedef void(_stdcall* glGetRenderbufferParameteriv) (GLenum target, GLenum pname, GLint* params);
	typedef void(_stdcall* glGetFramebufferAttachmentParameteriv) (GLenum target, GLenum attachment, GLenum pname, GLint* params);
	typedef GLenum(_stdcall* glCheckFramebufferStatus) (GLenum target);
	typedef GLboolean(_stdcall* glIsFramebuffer) (GLuint framebuffer);
	typedef GLboolean(_stdcall* glIsRenderbuffer) (GLuint renderbuffer);
	typedef void (_stdcall* glFlushMappedBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length);
	typedef void* (_stdcall* glMapBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
	typedef void (_stdcall* glBindBufferBase) (GLenum target, GLuint index, GLuint buffer);
	typedef void (_stdcall* glBindBufferRange) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	typedef void (_stdcall* glBindImageTextures) (GLuint first, GLsizei count, const GLuint* textures);
	typedef void (_stdcall* glBindSamplers) (GLuint first, GLsizei count, const GLuint* samplers);
	typedef void (_stdcall* glBindTextures) (GLuint first, GLsizei count, const GLuint* textures);
	typedef void (_stdcall* glBindVertexBuffers) (GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
	typedef void (_stdcall* glBindVertexArray) (GLuint array);
	typedef void (_stdcall* glDeleteVertexArrays) (GLsizei n, const GLuint* arrays);
	typedef void (_stdcall* glGenVertexArrays) (GLsizei n, GLuint* arrays);
	typedef GLboolean(_stdcall* glIsVertexArray) (GLuint array);
public:
	glBeginConditionalRender BeginConditionalRender = nullptr;
	glBeginTransformFeedback BeginTransformFeedback = nullptr;
	glBindFragDataLocation BindFragDataLocation = nullptr;
	glClampColor ClampColor = nullptr;
	glClearBufferfi ClearBufferfi = nullptr;
	glClearBufferfv ClearBufferfv = nullptr;
	glClearBufferiv ClearBufferiv = nullptr;
	glClearBufferuiv ClearBufferuiv = nullptr;
	glColorMaski ColorMaski = nullptr;
	glDisablei Disablei = nullptr;
	glEnablei Enablei = nullptr;
	glEndConditionalRender EndConditionalRender = nullptr;
	glEndTransformFeedback EndTransformFeedback = nullptr;
	glGetBooleani_v GetBooleani_v = nullptr;
	glGetFragDataLocation GetFragDataLocation = nullptr;
	glGetStringi GetStringi = nullptr;
	glGetTexParameterIiv GetTexParameterIiv = nullptr;
	glGetTexParameterIuiv GetTexParameterIuiv = nullptr;
	glGetTransformFeedbackVarying GetTransformFeedbackVarying = nullptr;
	glGetUniformuiv GetUniformuiv = nullptr;
	glGetVertexAttribIiv GetVertexAttribIiv = nullptr;
	glGetVertexAttribIuiv GetVertexAttribIuiv = nullptr;
	glIsEnabledi IsEnabledi = nullptr;
	glTexParameterIiv TexParameterIiv = nullptr;
	glTexParameterIuiv TexParameterIuiv = nullptr;
	glTransformFeedbackVaryings TransformFeedbackVaryings = nullptr;
	glUniform1ui Uniform1ui = nullptr;
	glUniform1uiv Uniform1uiv = nullptr;
	glUniform2ui Uniform2ui = nullptr;
	glUniform2uiv Uniform2uiv = nullptr;
	glUniform3ui Uniform3ui = nullptr;
	glUniform3uiv Uniform3uiv = nullptr;
	glUniform4ui Uniform4ui = nullptr;
	glUniform4uiv Uniform4uiv = nullptr;
	glVertexAttribI1i VertexAttribI1i = nullptr;
	glVertexAttribI1iv VertexAttribI1iv = nullptr;
	glVertexAttribI1ui VertexAttribI1ui = nullptr;
	glVertexAttribI1uiv VertexAttribI1uiv = nullptr;
	glVertexAttribI2i VertexAttribI2i = nullptr;
	glVertexAttribI2iv VertexAttribI2iv = nullptr;
	glVertexAttribI2ui VertexAttribI2ui = nullptr;
	glVertexAttribI2uiv VertexAttribI2uiv = nullptr;
	glVertexAttribI3i VertexAttribI3i = nullptr;
	glVertexAttribI3iv VertexAttribI3iv = nullptr;
	glVertexAttribI3ui VertexAttribI3ui = nullptr;
	glVertexAttribI3uiv VertexAttribI3uiv = nullptr;
	glVertexAttribI4bv VertexAttribI4bv = nullptr;
	glVertexAttribI4i VertexAttribI4i = nullptr;
	glVertexAttribI4iv VertexAttribI4iv = nullptr;
	glVertexAttribI4sv VertexAttribI4sv = nullptr;
	glVertexAttribI4ubv VertexAttribI4ubv = nullptr;
	glVertexAttribI4ui VertexAttribI4ui = nullptr;
	glVertexAttribI4uiv VertexAttribI4uiv = nullptr;
	glVertexAttribI4usv VertexAttribI4usv = nullptr;
	glVertexAttribIPointer VertexAttribIPointer = nullptr;
	glGenerateMipmap GenerateMipmap = nullptr;
	glGenFramebuffers GenFramebuffers = nullptr;
	glGenRenderbuffers GenRenderbuffers = nullptr;
	glDeleteFramebuffers DeleteFramebuffers = nullptr;
	glDeleteRenderbuffers DeleteRenderbuffers = nullptr;
	glBindFramebuffer BindFramebuffer = nullptr;
	glBindRenderbuffer BindRenderbuffer = nullptr;
	glRenderbufferStorage RenderbufferStorage = nullptr;
	glRenderbufferStorageMultisample RenderbufferStorageMultisample = nullptr;
	glFramebufferRenderbuffer FramebufferRenderbuffer = nullptr;
	glFramebufferTexture1D FramebufferTexture1D = nullptr;
	glFramebufferTexture2D FramebufferTexture2D = nullptr;
	glFramebufferTexture3D FramebufferTexture3D = nullptr;
	glBlitFramebuffer BlitFramebuffer = nullptr;
	glFramebufferTextureLayer FramebufferTextureLayer = nullptr;
	glGetRenderbufferParameteriv GetRenderbufferParameteriv = nullptr;
	glGetFramebufferAttachmentParameteriv GetFramebufferAttachmentParameteriv = nullptr;
	glCheckFramebufferStatus CheckFramebufferStatus = nullptr;
	glIsFramebuffer IsFramebuffer = nullptr;
	glIsRenderbuffer IsRenderbuffer = nullptr;
	glFlushMappedBufferRange FlushMappedBufferRange = nullptr;
	glMapBufferRange MapBufferRange = nullptr;
	glBindBufferBase BindBufferBase = nullptr;
	glBindBufferRange BindBufferRange = nullptr;
	glBindImageTextures BindImageTextures = nullptr;
	glBindSamplers BindSamplers = nullptr;
	glBindTextures BindTextures = nullptr;
	glBindVertexBuffers BindVertexBuffers = nullptr;
	glBindVertexArray BindVertexArray = nullptr;
	glDeleteVertexArrays DeleteVertexArrays = nullptr;
	glGenVertexArrays GenVertexArrays = nullptr;
	glIsVertexArray IsVertexArray = nullptr;
	GLcontext300() = default;
	explicit GLcontext300(HDC device) : GLcontext210(device) {
		this->BeginConditionalRender = reinterpret_cast<glBeginConditionalRender>(wglGetProcAddress("glBeginConditionalRender"));
		this->BeginTransformFeedback = reinterpret_cast<glBeginTransformFeedback>(wglGetProcAddress("glBeginTransformFeedback"));
		this->BindFragDataLocation = reinterpret_cast<glBindFragDataLocation>(wglGetProcAddress("glBindFragDataLocation"));
		this->ClampColor = reinterpret_cast<glClampColor>(wglGetProcAddress("glClampColor"));
		this->ClearBufferfi = reinterpret_cast<glClearBufferfi>(wglGetProcAddress("glClearBufferfi"));
		this->ClearBufferfv = reinterpret_cast<glClearBufferfv>(wglGetProcAddress("glClearBufferfv"));
		this->ClearBufferiv = reinterpret_cast<glClearBufferiv>(wglGetProcAddress("glClearBufferiv"));
		this->ClearBufferuiv = reinterpret_cast<glClearBufferuiv>(wglGetProcAddress("glClearBufferuiv"));
		this->ColorMaski = reinterpret_cast<glColorMaski>(wglGetProcAddress("glColorMaski"));
		this->Disablei = reinterpret_cast<glDisablei>(wglGetProcAddress("glDisablei"));
		this->Enablei = reinterpret_cast<glEnablei>(wglGetProcAddress("glEnablei"));
		this->EndConditionalRender = reinterpret_cast<glEndConditionalRender>(wglGetProcAddress("glEndConditionalRender"));
		this->EndTransformFeedback = reinterpret_cast<glEndTransformFeedback>(wglGetProcAddress("glEndTransformFeedback"));
		this->GetBooleani_v = reinterpret_cast<glGetBooleani_v>(wglGetProcAddress("glGetBooleani_v"));
		this->GetFragDataLocation = reinterpret_cast<glGetFragDataLocation>(wglGetProcAddress("glGetFragDataLocation"));
		this->GetStringi = reinterpret_cast<glGetStringi>(wglGetProcAddress("glGetStringi"));
		this->GetTexParameterIiv = reinterpret_cast<glGetTexParameterIiv>(wglGetProcAddress("glGetTexParameterIiv"));
		this->GetTexParameterIuiv = reinterpret_cast<glGetTexParameterIuiv>(wglGetProcAddress("glGetTexParameterIuiv"));
		this->GetTransformFeedbackVarying = reinterpret_cast<glGetTransformFeedbackVarying>(wglGetProcAddress("glGetTransformFeedbackVarying"));
		this->GetUniformuiv = reinterpret_cast<glGetUniformuiv>(wglGetProcAddress("glGetUniformuiv"));
		this->GetVertexAttribIiv = reinterpret_cast<glGetVertexAttribIiv>(wglGetProcAddress("glGetVertexAttribIiv"));
		this->GetVertexAttribIuiv = reinterpret_cast<glGetVertexAttribIuiv>(wglGetProcAddress("glGetVertexAttribIuiv"));
		this->IsEnabledi = reinterpret_cast<glIsEnabledi>(wglGetProcAddress("glIsEnabledi"));
		this->TexParameterIiv = reinterpret_cast<glTexParameterIiv>(wglGetProcAddress("glTexParameterIiv"));
		this->TexParameterIuiv = reinterpret_cast<glTexParameterIuiv>(wglGetProcAddress("glTexParameterIuiv"));
		this->TransformFeedbackVaryings = reinterpret_cast<glTransformFeedbackVaryings>(wglGetProcAddress("glTransformFeedbackVaryings"));
		this->Uniform1ui = reinterpret_cast<glUniform1ui>(wglGetProcAddress("glUniform1ui"));
		this->Uniform1uiv = reinterpret_cast<glUniform1uiv>(wglGetProcAddress("glUniform1uiv"));
		this->Uniform2ui = reinterpret_cast<glUniform2ui>(wglGetProcAddress("glUniform2ui"));
		this->Uniform2uiv = reinterpret_cast<glUniform2uiv>(wglGetProcAddress("glUniform2uiv"));
		this->Uniform3ui = reinterpret_cast<glUniform3ui>(wglGetProcAddress("glUniform3ui"));
		this->Uniform3uiv = reinterpret_cast<glUniform3uiv>(wglGetProcAddress("glUniform3uiv"));
		this->Uniform4ui = reinterpret_cast<glUniform4ui>(wglGetProcAddress("glUniform4ui"));
		this->Uniform4uiv = reinterpret_cast<glUniform4uiv>(wglGetProcAddress("glUniform4uiv"));
		this->VertexAttribI1i = reinterpret_cast<glVertexAttribI1i>(wglGetProcAddress("glVertexAttribI1i"));
		this->VertexAttribI1iv = reinterpret_cast<glVertexAttribI1iv>(wglGetProcAddress("glVertexAttribI1iv"));
		this->VertexAttribI1ui = reinterpret_cast<glVertexAttribI1ui>(wglGetProcAddress("glVertexAttribI1ui"));
		this->VertexAttribI1uiv = reinterpret_cast<glVertexAttribI1uiv>(wglGetProcAddress("glVertexAttribI1uiv"));
		this->VertexAttribI2i = reinterpret_cast<glVertexAttribI2i>(wglGetProcAddress("glVertexAttribI2i"));
		this->VertexAttribI2iv = reinterpret_cast<glVertexAttribI2iv>(wglGetProcAddress("glVertexAttribI2iv"));
		this->VertexAttribI2ui = reinterpret_cast<glVertexAttribI2ui>(wglGetProcAddress("glVertexAttribI2ui"));
		this->VertexAttribI2uiv = reinterpret_cast<glVertexAttribI2uiv>(wglGetProcAddress("glVertexAttribI2uiv"));
		this->VertexAttribI3i = reinterpret_cast<glVertexAttribI3i>(wglGetProcAddress("glVertexAttribI3i"));
		this->VertexAttribI3iv = reinterpret_cast<glVertexAttribI3iv>(wglGetProcAddress("glVertexAttribI3iv"));
		this->VertexAttribI3ui = reinterpret_cast<glVertexAttribI3ui>(wglGetProcAddress("glVertexAttribI3ui"));
		this->VertexAttribI3uiv = reinterpret_cast<glVertexAttribI3uiv>(wglGetProcAddress("glVertexAttribI3uiv"));
		this->VertexAttribI4bv = reinterpret_cast<glVertexAttribI4bv>(wglGetProcAddress("glVertexAttribI4bv"));
		this->VertexAttribI4i = reinterpret_cast<glVertexAttribI4i>(wglGetProcAddress("glVertexAttribI4i"));
		this->VertexAttribI4iv = reinterpret_cast<glVertexAttribI4iv>(wglGetProcAddress("glVertexAttribI4iv"));
		this->VertexAttribI4sv = reinterpret_cast<glVertexAttribI4sv>(wglGetProcAddress("glVertexAttribI4sv"));
		this->VertexAttribI4ubv = reinterpret_cast<glVertexAttribI4ubv>(wglGetProcAddress("glVertexAttribI4ubv"));
		this->VertexAttribI4ui = reinterpret_cast<glVertexAttribI4ui>(wglGetProcAddress("glVertexAttribI4ui"));
		this->VertexAttribI4uiv = reinterpret_cast<glVertexAttribI4uiv>(wglGetProcAddress("glVertexAttribI4uiv"));
		this->VertexAttribI4usv = reinterpret_cast<glVertexAttribI4usv>(wglGetProcAddress("glVertexAttribI4usv"));
		this->VertexAttribIPointer = reinterpret_cast<glVertexAttribIPointer>(wglGetProcAddress("glVertexAttribIPointer"));
		this->GenerateMipmap = reinterpret_cast<glGenerateMipmap>(wglGetProcAddress("glGenerateMipmap"));
		this->GenFramebuffers = reinterpret_cast<glGenFramebuffers>(wglGetProcAddress("glGenFramebuffers"));
		this->GenRenderbuffers = reinterpret_cast<glGenRenderbuffers>(wglGetProcAddress("glGenRenderbuffers"));
		this->DeleteFramebuffers = reinterpret_cast<glDeleteFramebuffers>(wglGetProcAddress("glDeleteFramebuffers"));
		this->DeleteRenderbuffers = reinterpret_cast<glDeleteRenderbuffers>(wglGetProcAddress("glDeleteRenderbuffers"));
		this->BindFramebuffer = reinterpret_cast<glBindFramebuffer>(wglGetProcAddress("glBindFramebuffer"));
		this->BindRenderbuffer = reinterpret_cast<glBindRenderbuffer>(wglGetProcAddress("glBindRenderbuffer"));
		this->RenderbufferStorage = reinterpret_cast<glRenderbufferStorage>(wglGetProcAddress("glRenderbufferStorage"));
		this->RenderbufferStorageMultisample = reinterpret_cast<glRenderbufferStorageMultisample>(wglGetProcAddress("glRenderbufferStorageMultisample"));
		this->FramebufferRenderbuffer = reinterpret_cast<glFramebufferRenderbuffer>(wglGetProcAddress("glFramebufferRenderbuffer"));
		this->FramebufferTexture1D = reinterpret_cast<glFramebufferTexture1D>(wglGetProcAddress("glFramebufferTexture1D"));
		this->FramebufferTexture2D = reinterpret_cast<glFramebufferTexture2D>(wglGetProcAddress("glFramebufferTexture2D"));
		this->FramebufferTexture3D = reinterpret_cast<glFramebufferTexture3D>(wglGetProcAddress("glFramebufferTexture3D"));
		this->BlitFramebuffer = reinterpret_cast<glBlitFramebuffer>(wglGetProcAddress("glBlitFramebuffer"));
		this->FramebufferTextureLayer = reinterpret_cast<glFramebufferTextureLayer>(wglGetProcAddress("glFramebufferTextureLayer"));
		this->GetRenderbufferParameteriv = reinterpret_cast<glGetRenderbufferParameteriv>(wglGetProcAddress("glGetRenderbufferParameteriv"));
		this->GetFramebufferAttachmentParameteriv = reinterpret_cast<glGetFramebufferAttachmentParameteriv>(wglGetProcAddress("glGetFramebufferAttachmentParameteriv"));
		this->CheckFramebufferStatus = reinterpret_cast<glCheckFramebufferStatus>(wglGetProcAddress("glCheckFramebufferStatus"));
		this->IsFramebuffer = reinterpret_cast<glIsFramebuffer>(wglGetProcAddress("glIsFramebuffer"));
		this->IsRenderbuffer = reinterpret_cast<glIsRenderbuffer>(wglGetProcAddress("glIsRenderbuffer"));
		this->FlushMappedBufferRange = reinterpret_cast<glFlushMappedBufferRange>(wglGetProcAddress("glFlushMappedBufferRange"));
		this->MapBufferRange = reinterpret_cast<glMapBufferRange>(wglGetProcAddress("glMapBufferRange"));
		this->BindBufferBase = reinterpret_cast<glBindBufferBase>(wglGetProcAddress("glBindBufferBase"));
		this->BindBufferRange = reinterpret_cast<glBindBufferRange>(wglGetProcAddress("glBindBufferRange"));
		this->BindImageTextures = reinterpret_cast<glBindImageTextures>(wglGetProcAddress("glBindImageTextures"));
		this->BindSamplers = reinterpret_cast<glBindSamplers>(wglGetProcAddress("glBindSamplers"));
		this->BindTextures = reinterpret_cast<glBindTextures>(wglGetProcAddress("glBindTextures"));
		this->BindVertexBuffers = reinterpret_cast<glBindVertexBuffers>(wglGetProcAddress("glBindVertexBuffers"));
		this->BindVertexArray = reinterpret_cast<glBindVertexArray>(wglGetProcAddress("glBindVertexArray"));
		this->DeleteVertexArrays = reinterpret_cast<glDeleteVertexArrays>(wglGetProcAddress("glDeleteVertexArrays"));
		this->GenVertexArrays = reinterpret_cast<glGenVertexArrays>(wglGetProcAddress("glGenVertexArrays"));
		this->IsVertexArray = reinterpret_cast<glIsVertexArray>(wglGetProcAddress("glIsVertexArray"));
	}
};

// { #version 310 }
class GLcontext310 : public GLcontext300 {
	/* TextureBuffer... */
	#define GL_TEXTURE_BUFFER 0x8C2A
	#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
	#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
	#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
	#define GL_TEXTURE_BUFFER_FORMAT 0x8C2E
	#define GL_SAMPLER_BUFFER 0x8DC2
	#define GL_INT_SAMPLER_2D_RECT 0x8DCD
	#define GL_INT_SAMPLER_BUFFER 0x8DD0
	#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
	#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
	/* UniformbufferParameterName */
	#define GL_UNIFORM_BUFFER_START 0x8A29
	#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
	#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
	#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
	#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
	#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
	#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
	#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
	#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
	#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
	#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
	#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
	#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
	#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
	#define GL_UNIFORM_TYPE 0x8A37
	#define GL_UNIFORM_SIZE 0x8A38
	#define GL_UNIFORM_NAME_LENGTH 0x8A39
	#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
	#define GL_UNIFORM_OFFSET 0x8A3B
	#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
	#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
	#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
	#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
	#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
	#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
	#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
	#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
	#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
	#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
	#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
	/* Unknown */
	#define GL_SIGNED_NORMALIZED 0x8F9C
	#define GL_PRIMITIVE_RESTART 0x8F9D
	#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
	typedef void (_stdcall* glDrawArraysInstanced) (GLenum mode, GLint first, GLsizei count, GLsizei primcount);
	typedef void (_stdcall* glDrawElementsInstanced) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount);
	typedef void (_stdcall* glPrimitiveRestartIndex) (GLuint buffer);
	typedef void (_stdcall* glTexBuffer) (GLenum target, GLenum internalFormat, GLuint buffer);
	typedef void (_stdcall* glGetActiveUniformBlockName) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
	typedef void (_stdcall* glGetActiveUniformBlockiv) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
	typedef void (_stdcall* glGetActiveUniformName) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
	typedef void (_stdcall* glGetActiveUniformsiv) (GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
	typedef void (_stdcall* glGetIntegeri_v) (GLenum target, GLuint index, GLint* data);
	typedef GLuint(_stdcall* glGetUniformBlockIndex) (GLuint program, const GLchar* uniformBlockName);
	typedef void (_stdcall* glGetUniformIndices) (GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
	typedef void (_stdcall* glUniformBlockBinding) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
public:
	glDrawArraysInstanced DrawArraysInstanced = nullptr;
	glDrawElementsInstanced DrawElementsInstanced = nullptr;
	glPrimitiveRestartIndex PrimitiveRestartIndex = nullptr;
	glTexBuffer TexBuffer = nullptr;
	glGetActiveUniformBlockName GetActiveUniformBlockName = nullptr;
	glGetActiveUniformBlockiv GetActiveUniformBlockiv = nullptr;
	glGetActiveUniformName GetActiveUniformName = nullptr;
	glGetActiveUniformsiv GetActiveUniformsiv = nullptr;
	glGetIntegeri_v GetIntegeri_v = nullptr;
	glGetUniformBlockIndex GetUniformBlockIndex = nullptr;
	glGetUniformIndices GetUniformIndices = nullptr;
	glUniformBlockBinding UniformBlockBinding = nullptr;
	GLcontext310() = default;
	explicit GLcontext310(HDC device) : GLcontext300(device) {
		this->DrawArraysInstanced = reinterpret_cast<glDrawArraysInstanced>(wglGetProcAddress("glDrawArraysInstanced"));
		this->DrawElementsInstanced = reinterpret_cast<glDrawElementsInstanced>(wglGetProcAddress("glDrawElementsInstanced"));
		this->PrimitiveRestartIndex = reinterpret_cast<glPrimitiveRestartIndex>(wglGetProcAddress("glPrimitiveRestartIndex"));
		this->TexBuffer = reinterpret_cast<glTexBuffer>(wglGetProcAddress("glTexBuffer"));
		this->GetActiveUniformBlockName = reinterpret_cast<glGetActiveUniformBlockName>(wglGetProcAddress("glGetActiveUniformBlockName"));
		this->GetActiveUniformBlockiv = reinterpret_cast<glGetActiveUniformBlockiv>(wglGetProcAddress("glGetActiveUniformBlockiv"));
		this->GetActiveUniformName = reinterpret_cast<glGetActiveUniformName>(wglGetProcAddress("glGetActiveUniformName"));
		this->GetActiveUniformsiv = reinterpret_cast<glGetActiveUniformsiv>(wglGetProcAddress("glGetActiveUniformsiv"));
		this->GetIntegeri_v = reinterpret_cast<glGetIntegeri_v>(wglGetProcAddress("glGetIntegeri_v"));
		this->GetUniformBlockIndex = reinterpret_cast<glGetUniformBlockIndex>(wglGetProcAddress("glGetUniformBlockIndex"));
		this->GetUniformIndices = reinterpret_cast<glGetUniformIndices>(wglGetProcAddress("glGetUniformIndices"));
		this->UniformBlockBinding = reinterpret_cast<glUniformBlockBinding>(wglGetProcAddress("glUniformBlockBinding"));
	}
};

// { #version 320 }
class GLcontext320 : public GLcontext310 {
	/* GlobalParameterName */
	#define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
	#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
	#define GL_LINES_ADJACENCY 0x000A
	#define GL_LINE_STRIP_ADJACENCY 0x000B
	#define GL_TRIANGLES_ADJACENCY 0x000C
	#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
	#define GL_PROGRAM_POINT_SIZE 0x8642
	#define GL_GEOMETRY_VERTICES_OUT 0x8916
	#define GL_GEOMETRY_INPUT_TYPE 0x8917
	#define GL_GEOMETRY_OUTPUT_TYPE 0x8918
	#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
	#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
	#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
	#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
	#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
	#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
	#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
	#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
	#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
	#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
	#define GL_CONTEXT_PROFILE_MASK 0x9126
	/* GlobalParameterName */
	#define GL_SAMPLER_BINDING 0x8919
	/* Sync ARB */
	#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
	#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
	#define GL_OBJECT_TYPE 0x9112
	#define GL_SYNC_CONDITION 0x9113
	#define GL_SYNC_STATUS 0x9114
	#define GL_SYNC_FLAGS 0x9115
	#define GL_SYNC_FENCE 0x9116
	#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
	#define GL_UNSIGNALED 0x9118
	#define GL_SIGNALED 0x9119
	#define GL_ALREADY_SIGNALED 0x911A
	#define GL_TIMEOUT_EXPIRED 0x911B
	#define GL_CONDITION_SATISFIED 0x911C
	#define GL_WAIT_FAILED 0x911D
	#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFFull
	/* QueryTarget */
	#define GL_TIME_ELAPSED 0x88BF
	#define GL_TIMESTAMP 0x8E28
	typedef void (_stdcall* glFramebufferTexture) (GLenum target, GLenum attachment, GLuint texture, GLint level);
	typedef void (_stdcall* glGetBufferParameteri64v) (GLenum target, GLenum value, GLint64* data);
	typedef void (_stdcall* glGetInteger64i_v) (GLenum pname, GLuint index, GLint64* data);
	typedef void (_stdcall* glDrawElementsBaseVertex) (GLenum mode, GLsizei count, GLenum type, void* indices, GLint basevertex);
	typedef void (_stdcall* glDrawElementsInstancedBaseVertex) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount, GLint basevertex);
	typedef void (_stdcall* glDrawRangeElementsBaseVertex) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, void* indices, GLint basevertex);
	typedef void (_stdcall* glMultiDrawElementsBaseVertex) (GLenum mode, GLsizei* count, GLenum type, void** indices, GLsizei primcount, GLint* basevertex);
	typedef void (_stdcall* glBindSampler) (GLuint unit, GLuint sampler);
	typedef void (_stdcall* glDeleteSamplers) (GLsizei count, const GLuint* samplers);
	typedef void (_stdcall* glGenSamplers) (GLsizei count, GLuint* samplers);
	typedef void (_stdcall* glGetSamplerParameterIiv) (GLuint sampler, GLenum pname, GLint* params);
	typedef void (_stdcall* glGetSamplerParameterIuiv) (GLuint sampler, GLenum pname, GLuint* params);
	typedef void (_stdcall* glGetSamplerParameterfv) (GLuint sampler, GLenum pname, GLfloat* params);
	typedef void (_stdcall* glGetSamplerParameteriv) (GLuint sampler, GLenum pname, GLint* params);
	typedef GLboolean(_stdcall* glIsSampler) (GLuint sampler);
	typedef void (_stdcall* glSamplerParameterIiv) (GLuint sampler, GLenum pname, const GLint* params);
	typedef void (_stdcall* glSamplerParameterIuiv) (GLuint sampler, GLenum pname, const GLuint* params);
	typedef void (_stdcall* glSamplerParameterf) (GLuint sampler, GLenum pname, GLfloat param);
	typedef void (_stdcall* glSamplerParameterfv) (GLuint sampler, GLenum pname, const GLfloat* params);
	typedef void (_stdcall* glSamplerParameteri) (GLuint sampler, GLenum pname, GLint param);
	typedef void (_stdcall* glSamplerParameteriv) (GLuint sampler, GLenum pname, const GLint* params);
	typedef GLenum(_stdcall* glClientWaitSync) (GLsync GLsync, GLbitfield flags, GLuint64 timeout);
	typedef void (_stdcall* glDeleteSync) (GLsync GLsync);
	typedef GLsync(_stdcall* glFenceSync) (GLenum condition, GLbitfield flags);
	typedef void (_stdcall* glGetInteger64v) (GLenum pname, GLint64* params);
	typedef void (_stdcall* glGetSynciv) (GLsync GLsync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values);
	typedef GLboolean(_stdcall* glIsSync) (GLsync GLsync);
	typedef void (_stdcall* glWaitSync) (GLsync GLsync, GLbitfield flags, GLuint64 timeout);
	typedef void (_stdcall* glGetQueryObjecti64v) (GLuint id, GLenum pname, GLint64* params);
	typedef void (_stdcall* glGetQueryObjectui64v) (GLuint id, GLenum pname, GLuint64* params);
	typedef void (_stdcall* glQueryCounter) (GLuint id, GLenum target);
public:
	glFramebufferTexture FramebufferTexture;
	glGetBufferParameteri64v GetBufferParameteri64v;
	glGetInteger64i_v GetInteger64i_v;
	glDrawElementsBaseVertex DrawElementsBaseVertex = nullptr;
	glDrawElementsInstancedBaseVertex DrawElementsInstancedBaseVertex = nullptr;
	glDrawRangeElementsBaseVertex DrawRangeElementsBaseVertex = nullptr;
	glMultiDrawElementsBaseVertex MultiDrawElementsBaseVertex = nullptr;
	glBindSampler BindSampler = nullptr;
	glDeleteSamplers DeleteSamplers = nullptr;
	glGenSamplers GenSamplers = nullptr;
	glGetSamplerParameterIiv GetSamplerParameterIiv = nullptr;
	glGetSamplerParameterIuiv GetSamplerParameterIuiv = nullptr;
	glGetSamplerParameterfv GetSamplerParameterfv = nullptr;
	glGetSamplerParameteriv GetSamplerParameteriv = nullptr;
	glIsSampler IsSampler = nullptr;
	glSamplerParameterIiv SamplerParameterIiv = nullptr;
	glSamplerParameterIuiv SamplerParameterIuiv = nullptr;
	glSamplerParameterf SamplerParameterf = nullptr;
	glSamplerParameterfv SamplerParameterfv = nullptr;
	glSamplerParameteri SamplerParameteri = nullptr;
	glSamplerParameteriv SamplerParameteriv = nullptr;
	glClientWaitSync ClientWaitSync = nullptr;
	glDeleteSync DeleteSync = nullptr;
	glFenceSync FenceSync = nullptr;
	glGetInteger64v GetInteger64v = nullptr;
	glGetSynciv GetSynciv = nullptr;
	glIsSync IsSync = nullptr;
	glWaitSync WaitSync = nullptr;
	glGetQueryObjecti64v GetQueryObjecti64v = nullptr;
	glGetQueryObjectui64v GetQueryObjectui64v = nullptr;
	glQueryCounter QueryCounter = nullptr;
	GLcontext320() = default;
	explicit GLcontext320(HDC device) : GLcontext310(device) {
		this->FramebufferTexture = reinterpret_cast<glFramebufferTexture>(wglGetProcAddress("glFramebufferTexture"));
		this->GetBufferParameteri64v = reinterpret_cast<glGetBufferParameteri64v>(wglGetProcAddress("glGetBufferParameteri64v"));
		this->GetInteger64i_v = reinterpret_cast<glGetInteger64i_v>(wglGetProcAddress("glGetInteger64i_v"));
		this->DrawElementsBaseVertex = reinterpret_cast<glDrawElementsBaseVertex>(wglGetProcAddress("glDrawElementsBaseVertex"));
		this->DrawElementsInstancedBaseVertex = reinterpret_cast<glDrawElementsInstancedBaseVertex>(wglGetProcAddress("glDrawElementsInstancedBaseVertex"));
		this->DrawRangeElementsBaseVertex = reinterpret_cast<glDrawRangeElementsBaseVertex>(wglGetProcAddress("glDrawRangeElementsBaseVertex"));
		this->MultiDrawElementsBaseVertex = reinterpret_cast<glMultiDrawElementsBaseVertex>(wglGetProcAddress("glMultiDrawElementsBaseVertex"));
		this->BindSampler = reinterpret_cast<glBindSampler>(wglGetProcAddress("glBindSampler"));
		this->DeleteSamplers = reinterpret_cast<glDeleteSamplers>(wglGetProcAddress("glDeleteSamplers"));
		this->GenSamplers = reinterpret_cast<glGenSamplers>(wglGetProcAddress("glGenSamplers"));
		this->GetSamplerParameterIiv = reinterpret_cast<glGetSamplerParameterIiv>(wglGetProcAddress("glGetSamplerParameterIiv"));
		this->GetSamplerParameterIuiv = reinterpret_cast<glGetSamplerParameterIuiv>(wglGetProcAddress("glGetSamplerParameterIuiv"));
		this->GetSamplerParameterfv = reinterpret_cast<glGetSamplerParameterfv>(wglGetProcAddress("glGetSamplerParameterfv"));
		this->GetSamplerParameteriv = reinterpret_cast<glGetSamplerParameteriv>(wglGetProcAddress("glGetSamplerParameteriv"));
		this->IsSampler = reinterpret_cast<glIsSampler>(wglGetProcAddress("glIsSampler"));
		this->SamplerParameterIiv = reinterpret_cast<glSamplerParameterIiv>(wglGetProcAddress("glSamplerParameterIiv"));
		this->SamplerParameterIuiv = reinterpret_cast<glSamplerParameterIuiv>(wglGetProcAddress("glSamplerParameterIuiv"));
		this->SamplerParameterf = reinterpret_cast<glSamplerParameterf>(wglGetProcAddress("glSamplerParameterf"));
		this->SamplerParameterfv = reinterpret_cast<glSamplerParameterfv>(wglGetProcAddress("glSamplerParameterfv"));
		this->SamplerParameteri = reinterpret_cast<glSamplerParameteri>(wglGetProcAddress("glSamplerParameteri"));
		this->SamplerParameteriv = reinterpret_cast<glSamplerParameteriv>(wglGetProcAddress("glSamplerParameteriv"));
		this->ClientWaitSync = reinterpret_cast<glClientWaitSync>(wglGetProcAddress("glClientWaitSync"));
		this->DeleteSync = reinterpret_cast<glDeleteSync>(wglGetProcAddress("glDeleteSync"));
		this->FenceSync = reinterpret_cast<glFenceSync>(wglGetProcAddress("glFenceSync"));
		this->GetInteger64v = reinterpret_cast<glGetInteger64v>(wglGetProcAddress("glGetInteger64v"));
		this->GetSynciv = reinterpret_cast<glGetSynciv>(wglGetProcAddress("glGetSynciv"));
		this->IsSync = reinterpret_cast<glIsSync>(wglGetProcAddress("glIsSync"));
		this->WaitSync = reinterpret_cast<glWaitSync>(wglGetProcAddress("glWaitSync"));
		this->GetQueryObjecti64v = reinterpret_cast<glGetQueryObjecti64v>(wglGetProcAddress("glGetQueryObjecti64v"));
		this->GetQueryObjectui64v = reinterpret_cast<glGetQueryObjectui64v>(wglGetProcAddress("glGetQueryObjectui64v"));
		this->QueryCounter = reinterpret_cast<glQueryCounter>(wglGetProcAddress("glQueryCounter"));
	}
};

// { #version 330 }
class GLcontext330 : public GLcontext320 {
	#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
	typedef void (_stdcall* glVertexAttribDivisor) (GLuint index, GLuint divisor);
public:
	glVertexAttribDivisor VertexAttribDivisor;
	GLcontext330() = default;
	explicit GLcontext330(HDC device) : GLcontext320(device) {
		this->VertexAttribDivisor = reinterpret_cast<glVertexAttribDivisor>(wglGetProcAddress("glVertexAttribDivisor"));
	}
};

// { #version 400 }
class GLcontext400 : public GLcontext330 {
	/* GetParameter */
	#define GL_SAMPLE_SHADING 0x8C36
	#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
	#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
	#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
	#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS 0x8F9F
	/* SubroutineParameter */
	#define GL_ACTIVE_SUBROUTINES 0x8DE5
	#define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
	#define GL_MAX_SUBROUTINES 0x8DE7
	#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
	#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
	#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
	#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
	#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
	#define GL_COMPATIBLE_SUBROUTINES 0x8E4B
	/* TessShader */
	#define GL_PATCHES 0xE
	#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
	#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
	#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
	#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
	#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
	#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
	#define GL_PATCH_VERTICES 0x8E72
	#define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
	#define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
	#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
	#define GL_TESS_GEN_MODE 0x8E76
	#define GL_TESS_GEN_SPACING 0x8E77
	#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
	#define GL_TESS_GEN_POINT_MODE 0x8E79
	#define GL_ISOLINES 0x8E7A
	#define GL_FRACTIONAL_ODD 0x8E7B
	#define GL_FRACTIONAL_EVEN 0x8E7C
	#define GL_MAX_PATCH_VERTICES 0x8E7D
	#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
	#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
	#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
	#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
	#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
	#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
	#define GL_MAX_TESS_PATCH_COMPONENTS          0x8E84
	#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
	#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
	#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS    0x8E89
	#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
	/* TransformFeedbackBuffer2 */
	#define GL_TRANSFORM_FEEDBACK               0x8E22
	#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
	#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
	#define GL_TRANSFORM_FEEDBACK_BINDING       0x8E25
	/* TransformFeedbackBuffer3 */
	#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
	#define GL_MAX_VERTEX_STREAMS             0x8E71
	typedef void (_stdcall* glBlendEquationSeparatei) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
	typedef void (_stdcall* glBlendEquationi) (GLuint buf, GLenum mode);
	typedef void (_stdcall* glBlendFuncSeparatei) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
	typedef void (_stdcall* glBlendFunci) (GLuint buf, GLenum src, GLenum dst);
	typedef void (_stdcall* glMinSampleShading) (GLclampf value);
	typedef void (_stdcall* glGetUniformdv) (GLuint program, GLint location, GLdouble* params);
	typedef void (_stdcall* glUniform1d) (GLint location, GLdouble x);
	typedef void (_stdcall* glUniform1dv) (GLint location, GLsizei count, const GLdouble* value);
	typedef void (_stdcall* glUniform2d) (GLint location, GLdouble x, GLdouble y);
	typedef void (_stdcall* glUniform2dv) (GLint location, GLsizei count, const GLdouble* value);
	typedef void (_stdcall* glUniform3d) (GLint location, GLdouble x, GLdouble y, GLdouble z);
	typedef void (_stdcall* glUniform3dv) (GLint location, GLsizei count, const GLdouble* value);
	typedef void (_stdcall* glUniform4d) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	typedef void (_stdcall* glUniform4dv) (GLint location, GLsizei count, const GLdouble* value);
	typedef void (_stdcall* glUniformMatrix2dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	typedef void (_stdcall* glUniformMatrix2x3dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	typedef void (_stdcall* glUniformMatrix2x4dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	typedef void (_stdcall* glUniformMatrix3dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	typedef void (_stdcall* glUniformMatrix3x2dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	typedef void (_stdcall* glUniformMatrix3x4dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	typedef void (_stdcall* glUniformMatrix4dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	typedef void (_stdcall* glUniformMatrix4x2dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	typedef void (_stdcall* glUniformMatrix4x3dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	typedef void (_stdcall* glGetActiveSubroutineName) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
	typedef void (_stdcall* glGetActiveSubroutineUniformName) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
	typedef void (_stdcall* glGetActiveSubroutineUniformiv) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
	typedef void (_stdcall* glGetProgramStageiv) (GLuint program, GLenum shadertype, GLenum pname, GLint* values);
	typedef GLuint(_stdcall* glGetSubroutineIndex) (GLuint program, GLenum shadertype, const GLchar* name);
	typedef GLint(_stdcall* glGetSubroutineUniformLocation) (GLuint program, GLenum shadertype, const GLchar* name);
	typedef void (_stdcall* glGetUniformSubroutineuiv) (GLenum shadertype, GLint location, GLuint* params);
	typedef void (_stdcall* glUniformSubroutinesuiv) (GLenum shadertype, GLsizei count, const GLuint* indices);
	typedef void (_stdcall* glPatchParameterfv) (GLenum pname, const GLfloat* values);
	typedef void (_stdcall* glPatchParameteri) (GLenum pname, GLint value);
	typedef void (_stdcall* glBindTransformFeedback) (GLenum target, GLuint id);
	typedef void (_stdcall* glDeleteTransformFeedbacks) (GLsizei n, const GLuint* ids);
	typedef void (_stdcall* glDrawTransformFeedback) (GLenum mode, GLuint id);
	typedef void (_stdcall* glGenTransformFeedbacks) (GLsizei n, GLuint* ids);
	typedef GLboolean(_stdcall* glIsTransformFeedback) (GLuint id);
	typedef void (_stdcall* glPauseTransformFeedback) (void);
	typedef void (_stdcall* glResumeTransformFeedback) (void);
	typedef void (_stdcall* glBeginQueryIndexed) (GLenum target, GLuint index, GLuint id);
	typedef void (_stdcall* glDrawTransformFeedbackStream) (GLenum mode, GLuint id, GLuint stream);
	typedef void (_stdcall* glEndQueryIndexed) (GLenum target, GLuint index);
	typedef void (_stdcall* glGetQueryIndexediv) (GLenum target, GLuint index, GLenum pname, GLint* params);
public:
	glBlendEquationSeparatei BlendEquationSeparatei = nullptr;
	glBlendEquationi       BlendEquationi       = nullptr;
	glBlendFuncSeparatei BlendFuncSeparatei   = nullptr;
	glBlendFunci        BlendFunci         = nullptr;
	glMinSampleShading MinSampleShading = nullptr;
	glGetUniformdv GetUniformdv = nullptr;
	glUniform1d  Uniform1d = nullptr;
	glUniform1dv Uniform1dv = nullptr;
	glUniform2d  Uniform2d = nullptr;
	glUniform2dv Uniform2dv = nullptr;
	glUniform3d  Uniform3d = nullptr;
	glUniform3dv Uniform3dv = nullptr;
	glUniform4d  Uniform4d = nullptr;
	glUniform4dv Uniform4dv = nullptr;
	glUniformMatrix2dv   UniformMatrix2dv = nullptr;
	glUniformMatrix2x3dv UniformMatrix2x3dv = nullptr;
	glUniformMatrix2x4dv UniformMatrix2x4dv = nullptr;
	glUniformMatrix3dv   UniformMatrix3dv = nullptr;
	glUniformMatrix3x2dv UniformMatrix3x2dv = nullptr;
	glUniformMatrix3x4dv UniformMatrix3x4dv = nullptr;
	glUniformMatrix4dv   UniformMatrix4dv = nullptr;
	glUniformMatrix4x2dv UniformMatrix4x2dv = nullptr;
	glUniformMatrix4x3dv UniformMatrix4x3dv = nullptr;
	glGetActiveSubroutineName GetActiveSubroutineName = nullptr;
	glGetActiveSubroutineUniformName GetActiveSubroutineUniformName = nullptr;
	glGetActiveSubroutineUniformiv GetActiveSubroutineUniformiv = nullptr;
	glGetProgramStageiv GetProgramStageiv = nullptr;
	glGetSubroutineIndex GetSubroutineIndex = nullptr;
	glGetSubroutineUniformLocation GetSubroutineUniformLocation = nullptr;
	glGetUniformSubroutineuiv GetUniformSubroutineuiv = nullptr;
	glUniformSubroutinesuiv UniformSubroutinesuiv = nullptr;
	glPatchParameterfv PatchParameterfv = nullptr;
	glPatchParameteri PatchParameteri = nullptr;
	glBindTransformFeedback BindTransformFeedback = nullptr;
	glDeleteTransformFeedbacks DeleteTransformFeedbacks = nullptr;
	glDrawTransformFeedback DrawTransformFeedback = nullptr;
	glGenTransformFeedbacks GenTransformFeedbacks = nullptr;
	glIsTransformFeedback IsTransformFeedback = nullptr;
	glPauseTransformFeedback PauseTransformFeedback = nullptr;
	glResumeTransformFeedback ResumeTransformFeedback = nullptr;
	glBeginQueryIndexed BeginQueryIndexed = nullptr;
	glDrawTransformFeedbackStream DrawTransformFeedbackStream = nullptr;
	glEndQueryIndexed EndQueryIndexed = nullptr;
	glGetQueryIndexediv GetQueryIndexediv = nullptr;
	GLcontext400() = default;
	explicit GLcontext400(HDC device) : GLcontext330(device) {
		this->BlendEquationSeparatei = reinterpret_cast<glBlendEquationSeparatei>(wglGetProcAddress("glBlendEquationSeparatei"));
		this->BlendEquationi       = reinterpret_cast<glBlendEquationi>(wglGetProcAddress("glBlendEquationi"));
		this->BlendFuncSeparatei = reinterpret_cast<glBlendFuncSeparatei>(wglGetProcAddress("glBlendFuncSeparatei"));
		this->BlendFunci        = reinterpret_cast<glBlendFunci>(wglGetProcAddress("glBlendFunci"));
		this->MinSampleShading = reinterpret_cast<glMinSampleShading>(wglGetProcAddress("glMinSampleShading"));
		this->GetUniformdv = reinterpret_cast<glGetUniformdv>(wglGetProcAddress("glGetUniformdv"));
		this->Uniform1d = reinterpret_cast<glUniform1d>(wglGetProcAddress("glUniform1d"));
		this->Uniform1dv = reinterpret_cast<glUniform1dv>(wglGetProcAddress("glUniform1dv"));
		this->Uniform2d = reinterpret_cast<glUniform2d>(wglGetProcAddress("glUniform2d"));
		this->Uniform2dv = reinterpret_cast<glUniform2dv>(wglGetProcAddress("glUniform2dv"));
		this->Uniform3d = reinterpret_cast<glUniform3d>(wglGetProcAddress("glUniform3d"));
		this->Uniform3dv = reinterpret_cast<glUniform3dv>(wglGetProcAddress("glUniform3dv"));
		this->Uniform4d = reinterpret_cast<glUniform4d>(wglGetProcAddress("glUniform4d"));
		this->Uniform4dv = reinterpret_cast<glUniform4dv>(wglGetProcAddress("glUniform4dv"));
		this->UniformMatrix2dv = reinterpret_cast<glUniformMatrix2dv>(wglGetProcAddress("glUniformMatrix2dv"));
		this->UniformMatrix2x3dv = reinterpret_cast<glUniformMatrix2x3dv>(wglGetProcAddress("glUniformMatrix2x3dv"));
		this->UniformMatrix2x4dv = reinterpret_cast<glUniformMatrix2x4dv>(wglGetProcAddress("glUniformMatrix2x4dv"));
		this->UniformMatrix3dv = reinterpret_cast<glUniformMatrix3dv>(wglGetProcAddress("glUniformMatrix3dv"));
		this->UniformMatrix3x2dv = reinterpret_cast<glUniformMatrix3x2dv>(wglGetProcAddress("glUniformMatrix3x2dv"));
		this->UniformMatrix3x4dv = reinterpret_cast<glUniformMatrix3x4dv>(wglGetProcAddress("glUniformMatrix3x4dv"));
		this->UniformMatrix4dv = reinterpret_cast<glUniformMatrix4dv>(wglGetProcAddress("glUniformMatrix4dv"));
		this->UniformMatrix4x2dv = reinterpret_cast<glUniformMatrix4x2dv>(wglGetProcAddress("glUniformMatrix4x2dv"));
		this->UniformMatrix4x3dv = reinterpret_cast<glUniformMatrix4x3dv>(wglGetProcAddress("glUniformMatrix4x3dv"));
		this->GetActiveSubroutineName = reinterpret_cast<glGetActiveSubroutineName>(wglGetProcAddress("glGetActiveSubroutineName"));
		this->GetActiveSubroutineUniformName = reinterpret_cast<glGetActiveSubroutineUniformName>(wglGetProcAddress("glGetActiveSubroutineUniformName"));
		this->GetActiveSubroutineUniformiv = reinterpret_cast<glGetActiveSubroutineUniformiv>(wglGetProcAddress("glGetActiveSubroutineUniformiv"));
		this->GetProgramStageiv = reinterpret_cast<glGetProgramStageiv>(wglGetProcAddress("glGetProgramStageiv"));
		this->GetSubroutineIndex = reinterpret_cast<glGetSubroutineIndex>(wglGetProcAddress("glGetSubroutineIndex"));
		this->GetSubroutineUniformLocation = reinterpret_cast<glGetSubroutineUniformLocation>(wglGetProcAddress("glGetSubroutineUniformLocation"));
		this->GetUniformSubroutineuiv = reinterpret_cast<glGetUniformSubroutineuiv>(wglGetProcAddress("glGetUniformSubroutineuiv"));
		this->UniformSubroutinesuiv = reinterpret_cast<glUniformSubroutinesuiv>(wglGetProcAddress("glUniformSubroutinesuiv"));
		this->PatchParameterfv = reinterpret_cast<glPatchParameterfv>(wglGetProcAddress("glPatchParameterfv"));
		this->PatchParameteri = reinterpret_cast<glPatchParameteri>(wglGetProcAddress("glPatchParameteri"));
		this->BindTransformFeedback = reinterpret_cast<glBindTransformFeedback>(wglGetProcAddress("glBindTransformFeedback"));
		this->DeleteTransformFeedbacks = reinterpret_cast<glDeleteTransformFeedbacks>(wglGetProcAddress("glDeleteTransformFeedbacks"));
		this->DrawTransformFeedback = reinterpret_cast<glDrawTransformFeedback>(wglGetProcAddress("glDrawTransformFeedback"));
		this->GenTransformFeedbacks = reinterpret_cast<glGenTransformFeedbacks>(wglGetProcAddress("glGenTransformFeedbacks"));
		this->IsTransformFeedback = reinterpret_cast<glIsTransformFeedback>(wglGetProcAddress("glIsTransformFeedback"));
		this->PauseTransformFeedback = reinterpret_cast<glPauseTransformFeedback>(wglGetProcAddress("glPauseTransformFeedback"));
		this->ResumeTransformFeedback = reinterpret_cast<glResumeTransformFeedback>(wglGetProcAddress("glResumeTransformFeedback"));
		this->BeginQueryIndexed = reinterpret_cast<glBeginQueryIndexed>(wglGetProcAddress("glBeginQueryIndexed"));
		this->DrawTransformFeedbackStream = reinterpret_cast<glDrawTransformFeedbackStream>(wglGetProcAddress("glDrawTransformFeedbackStream"));
		this->EndQueryIndexed = reinterpret_cast<glEndQueryIndexed>(wglGetProcAddress("glEndQueryIndexed"));
		this->GetQueryIndexediv = reinterpret_cast<glGetQueryIndexediv>(wglGetProcAddress("glGetQueryIndexediv"));
	}
};

// { #version 410 }
class GLcontext410 : public GLcontext400 {
	#define GL_FIXED 0x140C
	#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
	#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
	#define GL_RGB565 0x8D62
	#define GL_LOW_FLOAT 0x8DF0
	#define GL_MEDIUM_FLOAT 0x8DF1
	#define GL_HIGH_FLOAT 0x8DF2
	#define GL_LOW_INT 0x8DF3
	#define GL_MEDIUM_INT 0x8DF4
	#define GL_HIGH_INT 0x8DF5
	#define GL_SHADER_BINARY_FORMATS 0x8DF8
	#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
	#define GL_SHADER_COMPILER 0x8DFA
	#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
	#define GL_MAX_VARYING_VECTORS 0x8DFC
	#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
	/* ProgramBinary */
	#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
	#define GL_PROGRAM_BINARY_LENGTH           0x8741
	#define GL_NUM_PROGRAM_BINARY_FORMATS      0x87FE
	#define GL_PROGRAM_BINARY_FORMATS          0x87FF
	typedef void (_stdcall* glClearDepthf) (GLfloat d);
	typedef void (_stdcall* glDepthRangef) (GLfloat n, GLfloat f);
	typedef void (_stdcall* glGetShaderPrecisionFormat) (GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
	typedef void (_stdcall* glReleaseShaderCompiler) (void);
	typedef void (_stdcall* glShaderBinary) (GLsizei count, const GLuint* shaders, GLenum binaryformat, const void* binary, GLsizei length);
	typedef void (_stdcall* glGetProgramBinary) (GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary);
	typedef void (_stdcall* glProgramBinary) (GLuint program, GLenum binaryFormat, const void* binary, GLsizei length);
	typedef void (_stdcall* glProgramParameteri) (GLuint program, GLenum pname, GLint value);
	typedef void (_stdcall* glGetVertexAttribLdv) (GLuint index, GLenum pname, GLdouble* params);
	typedef void (_stdcall* glVertexAttribL1d) (GLuint index, GLdouble x);
	typedef void (_stdcall* glVertexAttribL1dv) (GLuint index, const GLdouble* v);
	typedef void (_stdcall* glVertexAttribL2d) (GLuint index, GLdouble x, GLdouble y);
	typedef void (_stdcall* glVertexAttribL2dv) (GLuint index, const GLdouble* v);
	typedef void (_stdcall* glVertexAttribL3d) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
	typedef void (_stdcall* glVertexAttribL3dv) (GLuint index, const GLdouble* v);
	typedef void (_stdcall* glVertexAttribL4d) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	typedef void (_stdcall* glVertexAttribL4dv) (GLuint index, const GLdouble* v);
	typedef void (_stdcall* glVertexAttribLPointer) (GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
public:
	glClearDepthf ClearDepthf = nullptr;
	glDepthRangef DepthRangef = nullptr;
	glGetShaderPrecisionFormat GetShaderPrecisionFormat = nullptr;
	glReleaseShaderCompiler ReleaseShaderCompiler = nullptr;
	glShaderBinary ShaderBinary = nullptr;
	glGetProgramBinary GetProgramBinary = nullptr;
	glProgramBinary ProgramBinary = nullptr;
	glProgramParameteri ProgramParameteri = nullptr;
	glGetVertexAttribLdv GetVertexAttribLdv = nullptr;
	glVertexAttribL1d VertexAttribL1d = nullptr;
	glVertexAttribL1dv VertexAttribL1dv = nullptr;
	glVertexAttribL2d VertexAttribL2d = nullptr;
	glVertexAttribL2dv VertexAttribL2dv = nullptr;
	glVertexAttribL3d VertexAttribL3d = nullptr;
	glVertexAttribL3dv VertexAttribL3dv = nullptr;
	glVertexAttribL4d VertexAttribL4d = nullptr;
	glVertexAttribL4dv VertexAttribL4dv = nullptr;
	glVertexAttribLPointer VertexAttribLPointer = nullptr;
	GLcontext410() = default;
	explicit GLcontext410(HDC device) : GLcontext400(device) {
		this->ClearDepthf = reinterpret_cast<glClearDepthf>(wglGetProcAddress("glClearDepthf"));
		this->DepthRangef = reinterpret_cast<glDepthRangef>(wglGetProcAddress("glDepthRangef"));
		this->GetShaderPrecisionFormat = reinterpret_cast<glGetShaderPrecisionFormat>(wglGetProcAddress("glGetShaderPrecisionFormat"));
		this->ReleaseShaderCompiler = reinterpret_cast<glReleaseShaderCompiler>(wglGetProcAddress("glReleaseShaderCompiler"));
		this->ShaderBinary = reinterpret_cast<glShaderBinary>(wglGetProcAddress("glShaderBinary"));
		this->GetProgramBinary = reinterpret_cast<glGetProgramBinary>(wglGetProcAddress("glGetProgramBinary"));
		this->ProgramBinary = reinterpret_cast<glProgramBinary>(wglGetProcAddress("glProgramBinary"));
		this->ProgramParameteri = reinterpret_cast<glProgramParameteri>(wglGetProcAddress("glProgramParameteri"));
		this->GetVertexAttribLdv = reinterpret_cast<glGetVertexAttribLdv>(wglGetProcAddress("glGetVertexAttribLdv"));
		this->VertexAttribL1d = reinterpret_cast<glVertexAttribL1d>(wglGetProcAddress("glVertexAttribL1d"));
		this->VertexAttribL1dv = reinterpret_cast<glVertexAttribL1dv>(wglGetProcAddress("glVertexAttribL1dv"));
		this->VertexAttribL2d = reinterpret_cast<glVertexAttribL2d>(wglGetProcAddress("glVertexAttribL2d"));
		this->VertexAttribL2dv = reinterpret_cast<glVertexAttribL2dv>(wglGetProcAddress("glVertexAttribL2dv"));
		this->VertexAttribL3d = reinterpret_cast<glVertexAttribL3d>(wglGetProcAddress("glVertexAttribL3d"));
		this->VertexAttribL3dv = reinterpret_cast<glVertexAttribL3dv>(wglGetProcAddress("glVertexAttribL3dv"));
		this->VertexAttribL4d = reinterpret_cast<glVertexAttribL4d>(wglGetProcAddress("glVertexAttribL4d"));
		this->VertexAttribL4dv = reinterpret_cast<glVertexAttribL4dv>(wglGetProcAddress("glVertexAttribL4dv"));
		this->VertexAttribLPointer = reinterpret_cast<glVertexAttribLPointer>(wglGetProcAddress("glVertexAttribLPointer"));
	}
};

// { #version 420 }
class GLcontext420 : public GLcontext410 {
	/* GetParameter with transformfeedbackbuffer */
	#define GL_TRANSFORM_FEEDBACK_PAUSED 0x8E23
	#define GL_TRANSFORM_FEEDBACK_ACTIVE 0x8E24
	/* TypeBPTCCompression */
	#define GL_COMPRESSED_RGBA_BPTC_UNORM 0x8E8C
	#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
	#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
	#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
	/* CopybufferTarget */
	#define GL_COPY_READ_BUFFER 0x8F36
	#define GL_COPY_WRITE_BUFFER 0x8F37
	#define GL_COPY_READ_BUFFER_BINDING 0x8F36
	#define GL_COPY_WRITE_BUFFER_BINDING 0x8F37
	/* GetAtomicParameter */
	#define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
	#define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
	#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
	#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
	#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
	#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
	#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
	#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
	#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
	#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
	#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
	#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
	#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
	#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
	#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
	#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
	#define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
	#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
	#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
	#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
	#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
	#define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
	#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
	#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
	#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
	#define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB
	#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
	/* ... */
	#define GL_MAX_IMAGE_UNITS 0x8F38
	#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
	#define GL_IMAGE_BINDING_NAME 0x8F3A
	#define GL_IMAGE_BINDING_LEVEL 0x8F3B
	#define GL_IMAGE_BINDING_LAYERED 0x8F3C
	#define GL_IMAGE_BINDING_LAYER 0x8F3D
	#define GL_IMAGE_BINDING_ACCESS 0x8F3E
	#define GL_IMAGE_1D 0x904C
	#define GL_IMAGE_2D 0x904D
	#define GL_IMAGE_3D 0x904E
	#define GL_IMAGE_2D_RECT 0x904F
	#define GL_IMAGE_CUBE 0x9050
	#define GL_IMAGE_BUFFER 0x9051
	#define GL_IMAGE_1D_ARRAY 0x9052
	#define GL_IMAGE_2D_ARRAY 0x9053
	#define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
	#define GL_IMAGE_2D_MULTISAMPLE 0x9055
	#define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056
	#define GL_INT_IMAGE_1D 0x9057
	#define GL_INT_IMAGE_2D 0x9058
	#define GL_INT_IMAGE_3D 0x9059
	#define GL_INT_IMAGE_2D_RECT 0x905A
	#define GL_INT_IMAGE_CUBE 0x905B
	#define GL_INT_IMAGE_BUFFER 0x905C
	#define GL_INT_IMAGE_1D_ARRAY 0x905D
	#define GL_INT_IMAGE_2D_ARRAY 0x905E
	#define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
	#define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060
	#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
	#define GL_UNSIGNED_INT_IMAGE_1D 0x9062
	#define GL_UNSIGNED_INT_IMAGE_2D 0x9063
	#define GL_UNSIGNED_INT_IMAGE_3D 0x9064
	#define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065
	#define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
	#define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
	#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068
	#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
	#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
	#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
	#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
	#define GL_MAX_IMAGE_SAMPLES 0x906D
	#define GL_IMAGE_BINDING_FORMAT 0x906E
	#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
	#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
	#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
	#define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
	#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
	#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
	#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
	#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
	#define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
	typedef void(_stdcall* glDrawElementsInstancedBaseVertexBaseInstance) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount, GLint basevertex, GLuint baseinstance);
	typedef void(_stdcall* glDrawElementsInstancedBaseInstance) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount, GLuint baseinstance);
	typedef void(_stdcall* glDrawArraysInstancedBaseInstance) (GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLuint baseinstance);
	typedef void(_stdcall* glCopyBufferSubData) (GLenum readtarget, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size);
	typedef void(_stdcall* glCopyImageSubData) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
	typedef void(_stdcall* glGetActiveAtomicCounterBufferiv) (GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);
	typedef void(_stdcall* glBindImageTexture) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
	typedef void(_stdcall* glMemoryBarrier) (GLbitfield barriers);
	typedef void(_stdcall* glTexStorage1D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
	typedef void(_stdcall* glTexStorage2D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
	typedef void(_stdcall* glTexStorage3D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
	typedef void(_stdcall* glDrawTransformFeedbackInstanced) (GLenum mode, GLuint id, GLsizei primcount);
	typedef void(_stdcall* glDrawTransformFeedbackStreamInstanced) (GLenum mode, GLuint id, GLuint stream, GLsizei primcount);
public:
	glDrawElementsInstancedBaseVertexBaseInstance DrawElementsInstancedBaseVertexBaseInstance = nullptr;
	glDrawElementsInstancedBaseInstance DrawElementsInstancedBaseInstance = nullptr;
	glDrawArraysInstancedBaseInstance DrawArraysInstancedBaseInstance = nullptr;
	glCopyBufferSubData CopyBufferSubData = nullptr;
	glCopyImageSubData CopyImageSubData = nullptr;
	glGetActiveAtomicCounterBufferiv GetActiveAtomicCounterBufferiv = nullptr;
	glBindImageTexture BindImageTexture = nullptr;
	glMemoryBarrier MemoryBarrier = nullptr;
	glTexStorage1D TexStorage1D = nullptr;
	glTexStorage2D TexStorage2D = nullptr;
	glTexStorage3D TexStorage3D = nullptr;
	glDrawTransformFeedbackInstanced DrawTransformFeedbackInstanced = nullptr;
	glDrawTransformFeedbackStreamInstanced DrawTransformFeedbackStreamInstanced = nullptr;
	GLcontext420() = default;
	explicit GLcontext420(HDC device) : GLcontext410(device) {
		this->DrawElementsInstancedBaseVertexBaseInstance = reinterpret_cast<glDrawElementsInstancedBaseVertexBaseInstance>(wglGetProcAddress("glDrawElementsInstancedBaseVertexBaseInstance"));
		this->DrawElementsInstancedBaseInstance = reinterpret_cast<glDrawElementsInstancedBaseInstance>(wglGetProcAddress("glDrawElementsInstancedBaseInstance"));
		this->DrawArraysInstancedBaseInstance = reinterpret_cast<glDrawArraysInstancedBaseInstance>(wglGetProcAddress("glDrawArraysInstancedBaseInstance"));
		this->CopyBufferSubData = reinterpret_cast<glCopyBufferSubData>(wglGetProcAddress("glCopyBufferSubData"));
		this->CopyImageSubData = reinterpret_cast<glCopyImageSubData>(wglGetProcAddress("glCopyImageSubData"));
		this->GetActiveAtomicCounterBufferiv = reinterpret_cast<glGetActiveAtomicCounterBufferiv>(wglGetProcAddress("glGetActiveAtomicCounterBufferiv"));
		this->BindImageTexture = reinterpret_cast<glBindImageTexture>(wglGetProcAddress("glBindImageTexture"));
		this->MemoryBarrier = reinterpret_cast<glMemoryBarrier>(wglGetProcAddress("glMemoryBarrier"));
		this->TexStorage1D = reinterpret_cast<glTexStorage1D>(wglGetProcAddress("glTexStorage1D"));
		this->TexStorage2D = reinterpret_cast<glTexStorage2D>(wglGetProcAddress("glTexStorage2D"));
		this->TexStorage3D = reinterpret_cast<glTexStorage3D>(wglGetProcAddress("glTexStorage3D"));
		this->DrawTransformFeedbackInstanced = reinterpret_cast<glDrawTransformFeedbackInstanced>(wglGetProcAddress("glDrawTransformFeedbackInstanced"));
		this->DrawTransformFeedbackStreamInstanced = reinterpret_cast<glDrawTransformFeedbackStreamInstanced>(wglGetProcAddress("glDrawTransformFeedbackStreamInstanced"));
	}
};

// { #version 430 }
class GLcontext430 : public GLcontext420 {
	#define GL_NUM_SHADING_LANGUAGE_VERSIONS 0x82E9
	#define GL_VERTEX_ATTRIB_ARRAY_LONG 0x874E
	#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
	#define GL_SHADER_STORAGE_BUFFER 0x90D2
	#define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3
	#define GL_SHADER_STORAGE_BUFFER_START 0x90D4
	#define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5
	#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
	#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
	#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
	#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
	#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
	#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
	#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
	#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
	#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
	#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
	typedef void(_stdcall* glClearBufferData) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data);
	typedef void(_stdcall* glClearBufferSubData) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
	typedef void(_stdcall* glFramebufferParameteri) (GLenum target, GLenum pname, GLint param);
	typedef void(_stdcall* glGetFramebufferParameteriv) (GLenum target, GLenum pname, GLint* params);
	typedef void(_stdcall* glShaderStorageBlockBinding) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
	typedef void(_stdcall* glTexStorage2DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	typedef void(_stdcall* glTexStorage3DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
public:
	glClearBufferData ClearBufferData;
	glClearBufferSubData ClearBufferSubData;
	glFramebufferParameteri FramebufferParameteri;
	glGetFramebufferParameteriv GetFramebufferParameteriv;
	glShaderStorageBlockBinding ShaderStorageBlockBinding;
	glTexStorage2DMultisample TexStorage2DMultisample;
	glTexStorage3DMultisample TexStorage3DMultisample;
	GLcontext430() = default;
	explicit GLcontext430(HDC device) : GLcontext420(device) {
		this->ClearBufferData = reinterpret_cast<glClearBufferData>(wglGetProcAddress("glClearBufferData"));
		this->ClearBufferSubData = reinterpret_cast<glClearBufferSubData>(wglGetProcAddress("glClearBufferSubData"));
		this->FramebufferParameteri = reinterpret_cast<glFramebufferParameteri>(wglGetProcAddress("glFramebufferParameteri"));
		this->GetFramebufferParameteriv = reinterpret_cast<glGetFramebufferParameteriv>(wglGetProcAddress("glGetFramebufferParameteriv"));
		this->ShaderStorageBlockBinding = reinterpret_cast<glShaderStorageBlockBinding>(wglGetProcAddress("glShaderStorageBlockBinding"));
		this->TexStorage2DMultisample = reinterpret_cast<glTexStorage2DMultisample>(wglGetProcAddress("glTexStorage2DMultisample"));
		this->TexStorage3DMultisample = reinterpret_cast<glTexStorage3DMultisample>(wglGetProcAddress("glTexStorage3DMultisample"));
	}
};

// { #version 440 }
class GLcontext440 : public GLcontext430 {
	#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
	#define GL_MAX_VERTEX_ATTRIB_STRIDE 0x82E5
	#define GL_TEXTURE_BUFFER_BINDING 0x8C2A
	typedef void(_stdcall* glClearTexImage) (GLuint texture, GLint level, GLenum format, GLenum type, const void* data);
	typedef void(_stdcall* glClearTexSubImage) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data);
	typedef void(_stdcall* glBindBuffersBase) (GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
	typedef void(_stdcall* glBindBuffersRange) (GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes);
public:
	glClearTexImage ClearTexImage = nullptr;
	glClearTexSubImage ClearTexSubImage = nullptr;
	glBindBuffersBase BindBuffersBase = nullptr;
	glBindBuffersRange BindBuffersRange = nullptr;
	GLcontext440() = default;
	explicit GLcontext440(HDC device) : GLcontext430(device) {
		this->ClearTexImage = reinterpret_cast<glClearTexImage>(wglGetProcAddress("glClearTexImage"));
		this->ClearTexSubImage = reinterpret_cast<glClearTexSubImage>(wglGetProcAddress("glClearTexSubImage"));
		this->BindBuffersBase = reinterpret_cast<glBindBuffersBase>(wglGetProcAddress("glBindBuffersBase"));
		this->BindBuffersRange = reinterpret_cast<glBindBuffersRange>(wglGetProcAddress("glBindBuffersRange"));
	}
};

// { #version 450 }
class GLcontext450 : public GLcontext440 {
	#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
	/* ClipControlOrigin ARB */
	#define GL_LOWER_LEFT 0x8CA1
	#define GL_UPPER_LEFT 0x8CA2
	/* ClipControlDepth ARB */
	#define GL_NEGATIVE_ONE_TO_ONE 0x935E
	#define GL_ZERO_TO_ONE 0x935F
	/* GetClipControlParameter ARB */
	#define GL_CLIP_ORIGIN 0x935C
	#define GL_CLIP_DEPTH_MODE 0x935D
	typedef GLenum(_stdcall* glGetGraphicsResetStatus) (void);
	typedef void (_stdcall* glGetnCompressedTexImage) (GLenum target, GLint lod, GLsizei bufSize, GLvoid* pixels);
	typedef void (_stdcall* glGetnUniformdv) (GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
	typedef void (_stdcall* glGetnTexImage) (GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
	typedef void (_stdcall* glClipControl) (GLenum origin, GLenum depth);
	typedef void (_stdcall* glGetNamedFramebufferParameterivEXT) (GLuint framebuffer, GLenum pname, GLint* params);
	typedef void (_stdcall* glNamedFramebufferParameteriEXT) (GLuint framebuffer, GLenum pname, GLint param);
	typedef void (_stdcall* glClearNamedBufferSubDataEXT) (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
	typedef void (_stdcall* glClearNamedBufferDataEXT) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
	typedef void (_stdcall* glMemoryBarrierByRegion) (GLbitfield barriers);
	typedef void (_stdcall* glTextureBarrier) (void);
public:
	glGetGraphicsResetStatus GetGraphicsResetStatus = nullptr;
	glGetnCompressedTexImage GetnCompressedTexImage = nullptr;
	glGetnUniformdv GetnUniformdv = nullptr;
	glGetnTexImage GetnTexImage = nullptr;
	glClipControl ClipControl = nullptr;
	glGetNamedFramebufferParameterivEXT GetNamedFramebufferParameterivEXT = nullptr;
	glNamedFramebufferParameteriEXT NamedFramebufferParameteriEXT = nullptr;
	glClearNamedBufferSubDataEXT ClearNamedBufferSubDataEXT = nullptr;
	glClearNamedBufferDataEXT ClearNamedBufferDataEXT = nullptr;
	glMemoryBarrierByRegion MemoryBarrierByRegion = nullptr;
	glTextureBarrier TextureBarrier = nullptr;
	GLcontext450() = default;
	explicit GLcontext450(HDC device) : GLcontext440(device) {
		this->GetGraphicsResetStatus = reinterpret_cast<glGetGraphicsResetStatus>(wglGetProcAddress("glGetGraphicsResetStatus"));
		this->GetnCompressedTexImage = reinterpret_cast<glGetnCompressedTexImage>(wglGetProcAddress("glGetnCompressedTexImage"));
		this->GetnUniformdv = reinterpret_cast<glGetnUniformdv>(wglGetProcAddress("glGetnUniformdv"));
		this->GetnTexImage = reinterpret_cast<glGetnTexImage>(wglGetProcAddress("glGetnTexImage"));
		this->ClipControl = reinterpret_cast<glClipControl>(wglGetProcAddress("glClipControl"));
		this->GetNamedFramebufferParameterivEXT = reinterpret_cast<glGetNamedFramebufferParameterivEXT>(wglGetProcAddress("glGetNamedFramebufferParameterivEXT"));
		this->NamedFramebufferParameteriEXT = reinterpret_cast<glNamedFramebufferParameteriEXT>(wglGetProcAddress("glNamedFramebufferParameteriEXT"));
		this->ClearNamedBufferSubDataEXT = reinterpret_cast<glClearNamedBufferSubDataEXT>(wglGetProcAddress("glClearNamedBufferSubDataEXT"));
		this->ClearNamedBufferDataEXT = reinterpret_cast<glClearNamedBufferDataEXT>(wglGetProcAddress("glClearNamedBufferDataEXT"));
		this->MemoryBarrierByRegion = reinterpret_cast<glMemoryBarrierByRegion>(wglGetProcAddress("glMemoryBarrierByRegion"));
		this->TextureBarrier = reinterpret_cast<glTextureBarrier>(wglGetProcAddress("glTextureBarrier"));
	}
};

// { #version 460 }
class GLcontext460 : public GLcontext450 {
	#define GL_CONTEXT_FLAG_NO_ERROR_BIT 0x00000008
	/* ParameterbufferTarget */
	#define GL_PARAMETER_BUFFER 0x80EE
	#define GL_PARAMETER_BUFFER_BINDING 0x80EF
	/* TransformFeedbackErrorCode */
	#define GL_TRANSFORM_FEEDBACK_OVERFLOW 0x82EC
	#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW 0x82ED
	#define GL_VERTICES_SUBMITTED 0x82EE
	#define GL_PRIMITIVES_SUBMITTED 0x82EF
	#define GL_VERTEX_SHADER_INVOCATIONS 0x82F0
	#define GL_TESS_CONTROL_SHADER_PATCHES 0x82F1
	#define GL_TESS_EVALUATION_SHADER_INVOCATIONS 0x82F2
	#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED 0x82F3
	#define GL_FRAGMENT_SHADER_INVOCATIONS 0x82F4
	#define GL_COMPUTE_SHADER_INVOCATIONS 0x82F5
	#define GL_CLIPPING_INPUT_PRIMITIVES 0x82F6
	#define GL_CLIPPING_OUTPUT_PRIMITIVES 0x82F7
	#define GL_TEXTURE_MAX_ANISOTROPY 0x84FE
	#define GL_MAX_TEXTURE_MAX_ANISOTROPY 0x84FF
	#define GL_POLYGON_OFFSET_CLAMP 0x8E1B
	#define GL_SHADER_BINARY_FORMAT_SPIR_V 0x9551
	#define GL_SPIR_V_BINARY 0x9552
	#define GL_SPIR_V_EXTENSIONS 0x9553
	#define GL_NUM_SPIR_V_EXTENSIONS 0x9554
	typedef void (_stdcall* glMultiDrawArraysIndirectCount) (GLenum mode, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
	typedef void (_stdcall* glMultiDrawElementsIndirectCount) (GLenum mode, GLenum type, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
	typedef void (_stdcall* glSpecializeShader) (GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue);
public:
	glMultiDrawArraysIndirectCount MultiDrawArraysIndirectCount;
	glMultiDrawElementsIndirectCount MultiDrawElementsIndirectCount;
	glSpecializeShader SpecializeShader;
	GLcontext460() = default;
	explicit GLcontext460(HDC device) : GLcontext450(device) {
		this->MultiDrawArraysIndirectCount = reinterpret_cast<glMultiDrawArraysIndirectCount>(wglGetProcAddress("glMultiDrawArraysIndirectCount"));
		this->MultiDrawElementsIndirectCount = reinterpret_cast<glMultiDrawElementsIndirectCount>(wglGetProcAddress("glMultiDrawElementsIndirectCount"));
		this->SpecializeShader = reinterpret_cast<glSpecializeShader>(wglGetProcAddress("glSpecializeShader"));
	}
};

// { compute shader }
class GLcontextCompute : public GLcontextBase {
	#define GL_COMPUTE_SHADER_BIT 0x00000020
	#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
	#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
	#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
	#define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265
	#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
	#define GL_COMPUTE_WORK_GROUP_SIZE 0x8267
	#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
	#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
	#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
	#define GL_DISPATCH_INDIRECT_BUFFER 0x90EE
	#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
	#define GL_COMPUTE_SHADER 0x91B9
	#define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB // ARB...
	#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
	#define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
	#define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE
	#define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF
	#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
	#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
	#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
	#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345
	typedef void (_stdcall* glDispatchCompute) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
	typedef void (_stdcall* glDispatchComputeIndirect) (GLintptr indirect);
	typedef void (_stdcall* glDispatchComputeGroupSizeARB) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
public:
	glDispatchCompute DispatchCompute = nullptr;
	glDispatchComputeIndirect DispatchComputeIndirect = nullptr;
	glDispatchComputeGroupSizeARB DispatchComputeGroupSizeARB = nullptr;
	GLcontextCompute() = default;
	explicit GLcontextCompute(HDC device) : GLcontextBase(device) {
		this->DispatchCompute = reinterpret_cast<glDispatchCompute>(wglGetProcAddress("glDispatchCompute"));
		this->DispatchComputeIndirect = reinterpret_cast<glDispatchComputeIndirect>(wglGetProcAddress("glDispatchComputeIndirect"));
		this->DispatchComputeGroupSizeARB = reinterpret_cast<glDispatchComputeGroupSizeARB>(wglGetProcAddress("glDispatchComputeGroupSizeARB"));
	}
};


// farward definition
class GLbuffer;
class GLtexture;
class GLshader;
class GLprogram;
class GLhighlevelCommandInterface {
public:
	virtual void DeleteBuffer(GLbuffer&) = 0;
	virtual void DeleteTexture(GLtexture&) = 0;
	virtual void DeleteShader(GLshader&) = 0;
	virtual void DeleteProgram(GLprogram&) = 0;
};