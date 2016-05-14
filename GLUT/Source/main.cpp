#include <iostream>
#include <thread>

#include "header.h"

int main()
{
	if(!glfwInit())
	{
		exit(0);
	}
	
	GLFWwindow* w = glfwCreateWindow(400, 400, "", NULL, NULL);
	glfwMakeContextCurrent(w);
	while (!glfwWindowShouldClose(w))
	{
		glClear(GL_DEPTH_BUFFER_BIT);
		
		glBegin(GL_TRIANGLES);
		
		glVertex3f(1,-1,0);
		glVertex3f(0,1,0);
		glVertex3f(-1,-1,0);
		
		glEnd();
		
		glfwSwapBuffers(w);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
