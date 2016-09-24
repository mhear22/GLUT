#pragma once
#include "header.h"

using namespace glm;


class Camera {
public:
	Camera(GLuint,float);
	~Camera();

	void OffsetOrientation(float x, float y);
	glm::mat4 Orientation();
	glm::mat4 Matrix();
	glm::mat4 Projection();
	glm::mat4 View();

	void draw();
private:

	void NormaliseAngles();
	GLuint Program;
	glm::vec3 _position;
	float _verticalAngle;
	float _horizontalAngle;
	float _fov;
	float _aspect;
	float _nearPlane;
	float _farPlane;
	float _sensitivity;
};
