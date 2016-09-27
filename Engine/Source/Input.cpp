#include "Input.h"

Input::Input(Camera* cam)
{
	this->camera = cam;
}

double Input::mouseX = 0.0;
double Input::mouseY = 0.0;

void Input::Draw()
{
	camera->OffsetOrientation((float)mouseX, (float)mouseY);
	mouseX = 0.0;
	mouseY = 0.0;
}
void Input::Click(GLFWwindow* window, int button, int action, int mods)
{
	printf("clicked");
}

void Input::Move(GLFWwindow* window, double x, double y)
{
	if(x == 0 && y == 0)
	{
		return;
	}
	printf("moved %f, %f\n", x,y);
	mouseX = mouseX + x;
	mouseY = mouseY + y;
	glfwSetCursorPos(window, 0,0);
}

void Input::KeyPress(GLFWwindow* window, int key, int scancode, int actions, int mods)
{
	if(key == 256)
	{
		exit(0);
	}
	else if (key == 96)
	{
		printf("Break");
	}
}
