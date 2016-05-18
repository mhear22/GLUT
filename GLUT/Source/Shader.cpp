#include "Shader.h"

Shader::Shader(std::string & sourceCode, GLenum shaderType) 
//: 
//	_object(0),
//	_refCount(NULL)
{
	//_object = glCreateShader(shaderType);
	//if (_object == 0)
	//{
	//	throw std::runtime_error("Could not into shader");
	//}
	//
	//const char* code = sourceCode.c_str();
	//
	//glShaderSource(_object, 1, (const GLchar**)&code, NULL);
	//
	//glCompileShader(_object);
	//
	//GLint status;
	//glGetShaderiv(_object, GL_COMPILE_STATUS, &status);
	//if (status == GL_FALSE)
	//{
	//	std::string msg("Compile failure in shader:\n");
	//
	//	GLint infoLogLength;
	//	glGetShaderiv(_object, GL_INFO_LOG_LENGTH, &infoLogLength);
	//	char* strInfoLog = new char[infoLogLength + 1];
	//	glGetShaderInfoLog(_object, infoLogLength, NULL, strInfoLog);
	//	msg += strInfoLog;
	//	delete[] strInfoLog;
	//
	//	glDeleteShader(_object); _object = 0;
	//	throw std::runtime_error(msg);
	//}
	//
	//_refCount = new unsigned;
	//*_refCount = 1;
}

Shader Shader::ShaderFromFile(const std::string & filePath, GLenum shaderType)
{
	std::ifstream f;
	f.open(filePath, std::ios::in | std::ios::binary);

	if (!(f.is_open()))
	{
		throw std::runtime_error(std::string("Failed to open file: ") + filePath);
	}

	std::stringstream buffer;

	buffer << f.rdbuf();

	std::string s(buffer.str());
	
	Shader shader = Shader(s, shaderType);
	
	return shader;
}






