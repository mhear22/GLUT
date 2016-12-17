#include "Input.h"



Input::Input(GLFWwindow* window,Camera* cam)
{
	this->camera = cam;
	glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);
	glfwGetCursorPos(window, &mouseX, &mouseY);
}

double Input::mouseX = 0.0f;
double Input::mouseY = 0.0f;

double Input::posX = 0.0f;
double Input::posY = 0.0f;
double Input::posZ = 0.0f;

void Input::Draw()
{
	float modifier = 2.0f;
	camera->SetOrientation(mouseX, mouseY);

	//Workout where you are looking
	camera->SetPosition(modifier * posX, modifier * posZ, modifier * posY);
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

float Adjust(float value, int action)
{
	if(action == GLFW_PRESS)
		return value;
	else if(action == GLFW_RELEASE)
		return 0;
	return 0;
}

void Input::KeyPress(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(key == GLFW_KEY_ESCAPE)
		exit(0);
	else if (key == GLFW_KEY_W)
		posX = Adjust(0.01, action);
	else if (key == GLFW_KEY_A)
		posY = Adjust(-0.01, action);
	else if (key == GLFW_KEY_S)
		posX = Adjust(-0.01, action);
	else if (key == GLFW_KEY_D)
		posY = Adjust(0.01, action);
}
