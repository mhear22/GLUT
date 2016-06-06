#include "Camera.h"
#include "Shader.h"

Camera::Camera(GLuint program)
{
	Program = program;

	position = glm::vec3(1, 1, 3);
	target = glm::vec3(0,0,0);
	up = glm::vec3(0, 1, 0);
}

Camera::~Camera()
{
}
float f = 0.0f;

void Camera::draw()
{
	if (f <= 3.0f) 
	{
		f = f + 0.1f;
	}
	else 
	{
		f = -3.0f;
	}
	target = glm::vec3(0,f,0);

	glm::mat4 camera = glm::lookAt(position, target, up);
	Shader::SetUniform("camera", camera, Program);
}
