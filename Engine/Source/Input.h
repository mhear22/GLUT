#ifndef input_hpp
#define input_hpp

#include "header.h"
#include "Camera.h"

class Input
{
public:
	Input(Camera* cam);
	
	void Draw();
	
	void static Click(GLFWwindow* window, int button, int action, int mods);
	void static Move(GLFWwindow* window, double x, double y);
	void static KeyPress(GLFWwindow* window, int key, int scancode, int actions, int mods);
	
	double static mouseX;
	double static mouseY;
private:
	Camera* camera;
};

#endif
