#include "Camera.h"
#include "Shader.h"

Camera::Camera(GLuint program, float aspect)
{
	Program = program;

	position = glm::vec3(1, 1, 3);
	target = glm::vec3(0,0,1);
	up = glm::vec3(0, 1, 0);

	glm::mat4 projection = glm::perspective(glm::radians(90.0f), aspect, 0.1f, 10.0f);
	Shader::SetUniform("projection", projection, Program);
}

void Camera::draw()
{
	auto x = getTarget();
	glm::mat4 camera = glm::lookAt(position, x, up);
	Shader::SetUniform("camera", camera, Program);
}

glm::vec3 Camera::getTarget()
{
	float x = position.x - target.x;
	float y = position.y - target.y;
	float z = position.z - target.z;
	return glm::vec3(x,y,z);
}

Camera::~Camera()
{

}
