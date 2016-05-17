#include "Game.h"

Game::Game()
{
	if(!glfwInit())
	{
		exit(0);
	}

	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


	auto x = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(x);
	int count;
	GLFWmonitor** monitors = glfwGetMonitors(&count);
	
	GLFWwindow* w = glfwCreateWindow(mode->width, mode->height, "", monitors[0], NULL);
	
	glfwMakeContextCurrent(w);

	std::vector<Shader> shaders;

	shaders.push_back(Shader::ShaderFromFile("Source\\GLSL\\VertexShader.glsl", GL_VERTEX_SHADER));


	glfwSetKeyCallback(w, Game::Keyboard::KeyPress);
	glfwSetInputMode(w, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetMouseButtonCallback(w, Game::Mouse::Clicked);
	glfwSetCursorPosCallback(w, Game::Mouse::Moved);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

	glHint(GL_POINT_SMOOTH_HINT, GL_FASTEST);
	glPointSize(10);


	while (!glfwWindowShouldClose(w))
	{
		Game::Draw();
		glfwSwapBuffers(w);
		glfwPollEvents();
	}

	glfwTerminate();
}

void Game::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Draw::DebugWall3D();
	Draw::Camera();
	// = 0 * 0 * 0;
	//Draw::TriangleWall(100);
}

void Game::Mouse::Clicked(GLFWwindow* window,int button, int action, int mods)
{
	printf("clicked");
}

void Game::Mouse::Moved(GLFWwindow* window, double x, double y)
{
	if(x == 0 && y == 0)
	{
		return;
	}
	printf("moved %f, %f\n", x,y);
	glfwSetCursorPos(window, 0,0);
}


void Game::Keyboard::KeyPress(GLFWwindow* window, int key, int scancode, int actions, int mods)
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