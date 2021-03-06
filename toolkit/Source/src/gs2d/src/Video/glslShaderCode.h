/* This file has been generated by the ShaderToCHeader tool. Do not edit! */

#ifndef GS2D_GLSL_DEFAULT_SHADER_H_
#define GS2D_GLSL_DEFAULT_SHADER_H_

#include <string>

/* Shaders included in this file:
GLSL/default/add1.ps            ->     GLSL_default_add1_ps
GLSL/default/default.ps         ->     GLSL_default_default_ps
GLSL/default/default.vs         ->     GLSL_default_default_vs
GLSL/default/fastRender.vs      ->     GLSL_default_fastRender_vs
GLSL/default/modulate1.ps       ->     GLSL_default_modulate1_ps
GLSL/default/optimal.vs         ->     GLSL_default_optimal_vs
*/

namespace gs2dshaders {

const std::string GLSL_default_add1_ps = 
"precision lowp float;\n" \
"uniform sampler2D diffuse;\n" \
"uniform sampler2D t1;\n" \
"\n" \
"varying vec4 v_color;\n" \
"varying vec2 v_texCoord;\n" \
"void main()\n" \
"{\n" \
"	gl_FragColor = v_color * texture2D(diffuse, v_texCoord) + vec4(texture2D(t1, v_texCoord).xyz, 0.0);\n" \
"}\n" \
"\n";

const std::string GLSL_default_default_ps = 
"precision lowp float;\n" \
"uniform sampler2D diffuse;\n" \
"\n" \
"varying vec4 v_color;\n" \
"varying vec2 v_texCoord;\n" \
"void main()\n" \
"{\n" \
"	gl_FragColor = v_color * texture2D(diffuse, v_texCoord);\n" \
"}\n" \
"\n";

const std::string GLSL_default_default_vs = 
"attribute vec4 vPosition;\n" \
"attribute vec2 vTexCoord;\n" \
"\n" \
"varying vec4 v_color;\n" \
"varying vec2 v_texCoord;\n" \
"\n" \
"uniform vec2 rectPos;\n" \
"uniform vec2 rectSize;\n" \
"uniform vec2 bitmapSize;\n" \
"\n" \
"uniform mat4 viewMatrix;\n" \
"uniform mat4 rotationMatrix;\n" \
"uniform vec2 screenSize;\n" \
"uniform vec2 size;\n" \
"uniform vec2 entityPos;\n" \
"uniform vec2 center;\n" \
"uniform vec2 cameraPos;\n" \
"\n" \
"uniform vec2 flipMul;\n" \
"uniform vec2 flipAdd;\n" \
"\n" \
"uniform vec4 color0;\n" \
"uniform vec4 color1;\n" \
"uniform vec4 color2;\n" \
"uniform vec4 color3;\n" \
"\n" \
"uniform float depth;\n" \
"\n" \
"vec4 transformSprite(vec3 position)\n" \
"{\n" \
"	vec4 newPos = vec4(position, 1.0) * vec4(flipMul, 1.0, 1.0) + vec4(flipAdd, 0.0, 0.0);\n" \
"	newPos = newPos * vec4(size, 1.0, 1.0) - vec4(center, 0.0, 0.0);\n" \
"\n" \
"	newPos = vec4(newPos.x * rotationMatrix[0][0] + newPos.y * rotationMatrix[1][0],\n" \
"				 -newPos.x * rotationMatrix[1][0] + newPos.y * rotationMatrix[0][0],\n" \
"				  newPos.z,\n" \
"				  newPos.w);\n" \
"\n" \
"	vec2 halfScreenSize = screenSize / 2.0;\n" \
"\n" \
"	newPos += vec4(entityPos.x, entityPos.y, 0.0, 0.0);\n" \
"	newPos -= vec4(halfScreenSize.x, halfScreenSize.y, 0.0, 0.0);\n" \
"	newPos -= vec4(cameraPos.x, cameraPos.y, 0.0, 0.0);\n" \
"\n" \
"	newPos *= vec4(1.0, -1.0, 1.0, 1.0);\n" \
"	return (viewMatrix * newPos);\n" \
"}\n" \
"\n" \
"vec2 transformCoord(vec2 texCoord)\n" \
"{\n" \
"	vec2 newCoord = texCoord * (rectSize/bitmapSize);\n" \
"	return newCoord + (rectPos/bitmapSize);\n" \
"}\n" \
"\n" \
"vec4 getVertexColor(vec4 position)\n" \
"{\n" \
"	vec4 vertex0 = color0 * (1.0-position.x) * (1.0-position.y);\n" \
"	vec4 vertex1 = color1 * (position.x) * (1.0-position.y);\n" \
"	vec4 vertex2 = color2 * (1.0-position.x) * (position.y);\n" \
"	vec4 vertex3 = color3 * (position.x) * (position.y);\n" \
"	return vertex0 + vertex1 + vertex2 + vertex3;\n" \
"}\n" \
"\n" \
"void main()\n" \
"{\n" \
"	gl_Position = transformSprite(vec3(vPosition.x, vPosition.y, depth)); \n" \
"	v_color = getVertexColor(vPosition);\n" \
"	v_texCoord = transformCoord(vTexCoord);\n" \
"}\n" \
"\n";

const std::string GLSL_default_fastRender_vs = 
"attribute vec4 vPosition;\n" \
"attribute vec2 vTexCoord;\n" \
"\n" \
"varying vec4 v_color;\n" \
"varying vec2 v_texCoord;\n" \
"\n" \
"uniform mat4 viewMatrix;\n" \
"\n" \
"uniform vec2 params[8];\n" \
"\n" \
"#define rectPos params[0]\n" \
"#define rectSize params[1]\n" \
"#define size params[2]\n" \
"#define entityPos params[3]\n" \
"#define bitmapSize params[4]\n" \
"#define screenSize params[5]\n" \
"#define colorRG params[6]\n" \
"#define colorBA params[7]\n" \
"\n" \
"vec4 transformSprite(vec3 position)\n" \
"{\n" \
"	vec4 newPos = vec4(position, 1.0) * vec4(size, 1.0, 1.0);\n" \
"	newPos += vec4(entityPos, 0.0, 0.0)-vec4(screenSize/2.0, 0.0, 0.0);\n" \
"	newPos *= vec4(1.0, -1.0, 1.0, 1.0);\n" \
"	return (viewMatrix * newPos);\n" \
"}\n" \
"\n" \
"vec2 transformCoord(vec2 texCoord)\n" \
"{\n" \
"	vec2 newCoord = texCoord * (rectSize/bitmapSize);\n" \
"	return newCoord + (rectPos/bitmapSize);\n" \
"}\n" \
"\n" \
"void main()\n" \
"{\n" \
"	gl_Position = transformSprite(vec3(vPosition.x, vPosition.y, vPosition.z));\n" \
"	v_color = vec4(colorRG.x, colorRG.y, colorBA.x, colorBA.y);\n" \
"	v_texCoord = transformCoord(vTexCoord);\n" \
"}\n" \
"\n";

const std::string GLSL_default_modulate1_ps = 
"precision lowp float;\n" \
"uniform sampler2D diffuse;\n" \
"uniform sampler2D t1;\n" \
"\n" \
"varying vec4 v_color;\n" \
"varying vec2 v_texCoord;\n" \
"void main()\n" \
"{\n" \
"	gl_FragColor = v_color * texture2D(diffuse, v_texCoord) * texture2D(t1, v_texCoord);\n" \
"}\n" \
"\n";

const std::string GLSL_default_optimal_vs = 
"attribute vec4 vPosition;\n" \
"attribute vec2 vTexCoord;\n" \
"\n" \
"varying vec4 v_color;\n" \
"varying vec2 v_texCoord;\n" \
"\n" \
"uniform mat4 viewMatrix;\n" \
"uniform mat4 rotationMatrix;\n" \
"\n" \
"uniform vec2 params[13];\n" \
"\n" \
"#define rectPos params[0]\n" \
"#define rectSize params[1]\n" \
"#define center params[2]\n" \
"#define size params[3]\n" \
"#define entityPos params[4]\n" \
"#define cameraPos params[5]\n" \
"#define bitmapSize params[6]\n" \
"#define colorRG params[7]\n" \
"#define colorBA params[8]\n" \
"#define depth params[9]\n" \
"#define screenSize params[10]\n" \
"#define flipAdd params[11]\n" \
"#define flipMul params[12]\n" \
"\n" \
"vec4 transformSprite(vec3 position)\n" \
"{\n" \
"	vec4 newPos = vec4(position, 1.0) * vec4(flipMul, 1.0, 1.0) + vec4(flipAdd, 0.0, 0.0);\n" \
"	newPos = newPos * vec4(size, 1.0, 1.0) - vec4(center, 0.0, 0.0);\n" \
"\n" \
"	newPos = vec4(newPos.x * rotationMatrix[0][0] + newPos.y * rotationMatrix[1][0],\n" \
"				 -newPos.x * rotationMatrix[1][0] + newPos.y * rotationMatrix[0][0],\n" \
"				  newPos.z,\n" \
"				  newPos.w);\n" \
"\n" \
"	vec2 halfScreenSize = screenSize / 2.0;\n" \
"\n" \
"	newPos += vec4(entityPos.x, entityPos.y, 0.0, 0.0);\n" \
"	newPos -= vec4(halfScreenSize.x, halfScreenSize.y, 0.0, 0.0);\n" \
"	newPos -= vec4(cameraPos.x, cameraPos.y, 0.0, 0.0);\n" \
"	newPos *= vec4(1.0, -1.0, 1.0, 1.0);\n" \
"	return (viewMatrix * newPos);\n" \
"}\n" \
"\n" \
"vec2 transformCoord(vec2 texCoord)\n" \
"{\n" \
"	vec2 newCoord = texCoord * (rectSize/bitmapSize);\n" \
"	return newCoord + (rectPos/bitmapSize);\n" \
"}\n" \
"\n" \
"void main()\n" \
"{\n" \
"	gl_Position = transformSprite(vec3(vPosition.x, vPosition.y, depth.x)); \n" \
"	v_color = vec4(colorRG, colorBA);\n" \
"	v_texCoord = transformCoord(vTexCoord);\n" \
"}\n" \
"\n";


}

#endif
