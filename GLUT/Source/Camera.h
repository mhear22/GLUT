#pragma once

#include "header.h"

class Camera {
public:
	Camera(GLuint);
	~Camera();

	void draw();
private:
	GLuint Program;
	glm::vec3 position;
	glm::vec3 target;
	glm::vec3 up;

};