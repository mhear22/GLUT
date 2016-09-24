#pragma once
#ifndef Shader_h
#define Shader_h

#include "header.h"

static std::string DefaultVertexShader =
#include "VertexShader.glsl"


static std::string DefaultFragmentShader =
#include "FragmentShader.glsl"

class Shader
{
public:
	Shader(std::string &sourceCode, GLenum shaderType);
	GLuint object();

	static GLuint SetUniform(const GLchar* uniformName, glm::mat4& vec, GLuint Program);
private:
	GLuint _object;
	unsigned* _refCount;
};


#endif /* Shader_h */