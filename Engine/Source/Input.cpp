#include "Input.h"



Input::Input(GLFWwindow* window,Camera* cam)
{
	this->camera = cam;
	glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);
	glfwGetCursorPos(window, &mouseX, &mouseY);
}

double Input::mouseX = 0.0f;
double Input::mouseY = 0.0f;

void Input::Draw()
{
	camera->SetOrientation(mouseX, mouseY);
}
void Input::Click(GLFWwindow* window, int button, int action, int mods)
{
	printf("clicked");
}

void Input::Move(GLFWwindow* window, double x, double y)
{
	printf("moved %f, %f\n", x,y);
	if(x == 0 && y == 0)
	{
		return;
	}
	mouseX = x;
	mouseY = y;
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
