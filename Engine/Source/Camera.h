#pragma once
#include "header.h"

using namespace glm;


class Camera {
public:
	Camera(GLuint,float);
	~Camera();

	void SetOrientation(float x, float y);
	mat4 Orientation();
	mat4 Matrix();
	mat4 Projection();
	mat4 View();

	void draw();
private:

	void NormaliseAngles();
	GLuint Program;
	vec3 _position;
	float _verticalAngle;
	float _horizontalAngle;
	float _fov;
	float _aspect;
	float _nearPlane;
	float _farPlane;
	float _sensitivity;
};
