#include "Shader.h"

Shader::Shader(std::string & sourceCode, GLenum shaderType) 
: 
	_object(0),
	_refCount(NULL)
{
	_object = glCreateShader(shaderType);
	if (_object == 0)
	{
		throw std::runtime_error("Could not into shader");
	}
	
	const char* code = sourceCode.c_str();
	
	glShaderSource(_object, 1, (const GLchar**)&code, NULL);
	
	glCompileShader(_object);
	
	GLint status;
	glGetShaderiv(_object, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		std::string msg("Compile failure in shader:\n");
	
		GLint infoLogLength;
		glGetShaderiv(_object, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* strInfoLog = new char[infoLogLength + 1];
		glGetShaderInfoLog(_object, infoLogLength, NULL, strInfoLog);
		msg += strInfoLog;
		delete[] strInfoLog;
	
		glDeleteShader(_object); _object = 0;
		throw std::runtime_error(msg);
	}
	
	_refCount = new unsigned;
	*_refCount = 1;
}

GLuint Shader::object()
{
	return _object;
}

GLuint Shader::SetUniform(const GLchar* uniformName, glm::mat4& vec, GLuint Program)
{
	GLint uniformLoc = glGetUniformLocation(Program, uniformName);
	if (uniformLoc == GLint(-1))
	{
		throw std::runtime_error("Shader is broken, could not find Uniform");
	}
	auto vecptr = glm::value_ptr(vec);

	glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, vecptr);
	return 0;
}