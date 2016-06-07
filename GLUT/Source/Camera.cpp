#include "Camera.h"
#include "Shader.h"

float MaxVerticalAngle = 90.0f;

Camera::Camera(GLuint program, float aspect)
{
	Program = program;

	_position = glm::vec3(0, 0, 0);
	_fov = 90.0f;
	_aspect = aspect;
	_nearPlane = 0.01f;
	_farPlane = 100.0f;
	_sensitivity = 0.1f;
}

void Camera::draw()
{
	Shader::SetUniform("camera", Matrix(), Program);
}

void Camera::OffsetOrientation(float x, float y)
{
	_horizontalAngle += x * _sensitivity;
	_verticalAngle += y * _sensitivity;
	NormaliseAngles();
}

glm::mat4 Camera::Projection()
{
	return glm::perspective(glm::radians(_fov), _aspect, _nearPlane, _farPlane);
}

glm::mat4 Camera::View()
{
	return Orientation() * glm::translate(glm::mat4(), -_position);
}

glm::mat4 Camera::Orientation()
{
	glm::mat4 orientation;
	orientation = glm::rotate(orientation, glm::radians(_verticalAngle), glm::vec3(1, 0, 0));
	orientation = glm::rotate(orientation, glm::radians(_horizontalAngle), glm::vec3(0, 1, 0));
	return orientation;
}

glm::mat4 Camera::Matrix()
{
	return Projection() * View();
}

void Camera::NormaliseAngles()
{
	_horizontalAngle = fmodf(_horizontalAngle, 360.0f);

	if (_horizontalAngle < 0.0f) 
	{
		_horizontalAngle += 360.0f;
	}

	if (_verticalAngle > MaxVerticalAngle) 
	{
		_verticalAngle = MaxVerticalAngle;
	}
	else if (_verticalAngle < -MaxVerticalAngle) 
	{
		_verticalAngle = -MaxVerticalAngle;
	}
}

Camera::~Camera()
{

}

