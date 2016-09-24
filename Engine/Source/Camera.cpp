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
	mat4 matrix = Matrix();
	Shader::SetUniform("camera", matrix, Program);
}

void Camera::OffsetOrientation(float x, float y)
{
	_horizontalAngle += x * _sensitivity;
	_verticalAngle += y * _sensitivity;
	NormaliseAngles();
}

mat4 Camera::Projection()
{
	return perspective(radians(_fov), _aspect, _nearPlane, _farPlane);
}

mat4 Camera::View()
{
	return Orientation() * translate(mat4(), -_position);
}

mat4 Camera::Orientation()
{
	mat4 orientation;
	orientation = rotate(orientation, radians(_verticalAngle), vec3(1, 0, 0));
	orientation = rotate(orientation, radians(_horizontalAngle), vec3(0, 1, 0));
	return orientation;
}

mat4 Camera::Matrix()
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

