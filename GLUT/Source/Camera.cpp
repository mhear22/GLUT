#include "Camera.h"
#include "Shader.h"

Camera::Camera(GLuint program, float aspect)
{
	Program = program;

	glm::vec3 position = glm::vec3(0, 0, 3);
	glm::vec3 target = glm::vec3(0,0,1);
	glm::vec3 up = glm::vec3(0, 1, 0);

	glm::mat4 projection = glm::perspective(glm::radians(90.0f), aspect, 0.1f, 10.0f);
	Shader::SetUniform("projection", projection, Program);
	lookingAt = glm::lookAt(position, target, up);
}

void Camera::draw()
{
	Shader::SetUniform("camera", lookingAt, Program);
}

void Camera::RotateCamera(float x, float y)
{
	float sensitivity = 0.01f;
	
	lookingAt = glm::rotate(lookingAt, x * sensitivity , glm::vec3(1,0,0));
	lookingAt = glm::rotate(lookingAt, y * sensitivity , glm::vec3(0,1,0));
}

Camera::~Camera()
{

}

