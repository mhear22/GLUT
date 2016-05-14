#include "Game.h"

Game::Game()
{
	if(!glfwInit())
	{
		exit(0);
	}
	auto x = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(x);
	
	
	GLFWwindow* w = glfwCreateWindow(mode->width, mode->height, "", NULL, NULL);
	
	glfwSetKeyCallback(w, Game::Keyboard::KeyPress);
	glfwSetInputMode(w, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	glfwSetMouseButtonCallback(w, Game::Mouse::Clicked);
	glfwSetCursorPosCallback(w, Game::Mouse::Moved);
	
	glfwMakeContextCurrent(w);
	
	while (!glfwWindowShouldClose(w))
	{
		Game::Draw();
		glfwSwapBuffers(w);
		glfwPollEvents();
	}
	glfwTerminate();
	
	
	
	//glutKeyboardUpFunc(Keyboard::KeyPress);
	//glutMouseFunc(Mouse::Clicked);
	//glutDisplayFunc(Draw);
	
	//implement
	//glutPassiveMotionFunc(Mouse::Moved);
	
	//glutEntryFunc(Mouse::Entering);
	
	//glutIdleFunc(Draw);
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//glutMainLoop();
}


float i = 0;
float i2 = 0;

void Game::Draw()
{
	//t1.detach();

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(i,i2,0.5);
	Draw::Square(-1,-1,2,2);

	Draw::TriangleWall();

	
	//glutSwapBuffers();
	//glutPostRedisplay();
}

void Game::Mouse::Clicked(GLFWwindow* window,int button, int action, int mods)
{
	
}

void Game::Mouse::Moved(GLFWwindow* window, double x, double y)
{
	
}

void Game::Mouse::Entering(int state)
{
	
}

void Game::Keyboard::KeyPress(GLFWwindow* window, int key, int scancode, int actions, int mods)
{
	//Game::Keyboard::keys[key] = actions;
	
	
	if(key == 256)
	{
		exit(0);
	}
}



















