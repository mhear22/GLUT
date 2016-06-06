#pragma once

#include "header.h"

class Camera {
public:
	Camera(GLuint,float);
	~Camera();

	void moveCamera(float, float);

	void draw();
private:
	GLuint Program;
	glm::vec3 position;
	glm::vec3 getTarget();
	glm::vec3 target;
	glm::vec3 up;

};