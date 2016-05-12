//
//  main.cpp
//  OpenGL-Mac
//
//  Created by Rosanne Heares on 12/05/2016.
//  Copyright © 2016 Rosanne Heares. All rights reserved.
//

#include <iostream>
#include <thread>

#ifdef __APPLE__
#include <GLFW/glfw3.h>
#else
#include <GL/glfw.h>
#endif

int main()
{
	glfwInit();
	
	GLFWwindow* w = glfwCreateWindow(400, 400, "", NULL, NULL);
	glfwMakeContextCurrent(w);
	while (!glfwWindowShouldClose(w))
	{
		
		
		glBegin(GL_TRIANGLES);
		
		glVertex3f(1,1,0);
		glVertex3f(0,1,0);
		glVertex3f(-1,0,0);
		
		glEnd();
		
		glfwSwapBuffers(w);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
