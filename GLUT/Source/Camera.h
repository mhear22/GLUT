#pragma once

#include "header.h"

class Camera {
public:
	Camera(GLuint,float);
	~Camera();

	void RotateCamera(float, float);

	void draw();
private:
	GLuint Program;
	glm::mat4 lookingAt;

};