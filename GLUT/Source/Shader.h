#ifndef Shader_hpp
#define Shader_hpp

#include "header.h"




class Shader
{
public:
	Shader(std::string& sourceCode, GLenum shaderType);
	static Shader ShaderFromFile(const std::string& filePath, GLenum shaderType);
private:
	GLuint _object;
	unsigned* _refCount;
};


#endif /* Shader_hpp */