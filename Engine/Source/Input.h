#ifndef input_hpp
#define input_hpp

#include "header.h"
#include "Camera.h"


class Input
{
public:
	Input(GLFWwindow* window, Camera* cam);
	
	void Draw();
	
	void static Click(GLFWwindow* window, int button, int action, int mods);
	void static Move(GLFWwindow* window, double x, double y);
	void static KeyPress(GLFWwindow* window, int key, int scancode, int action, int mods);
	
	double static mouseX;
	double static mouseY;

	double static posX;
	double static posY;
	double static posZ;
private:
	Camera* camera;
};

#endif
