#include "Game.h"

Game::Game()
{
	int argc = 0;
	char** argv = { };
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400,400);
	glutCreateWindow("window");
	glutDisplayFunc(Draw);
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glutMainLoop();
}

static clock_t lastFrame = clock();

static float FPS = 0.0f;

void Game::Draw()
{
	float change = clock() - lastFrame; 
	FPS = CLOCKS_PER_SEC/change;
	printf("fps: %f \n", FPS);
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		
		glVertex2i(-1, -1);
		glVertex2i(1, -1);
		glVertex2i(1, 1);
		
		glVertex2i(1, 1);
		glVertex2i(-1, 1);
		glVertex2i(-1, -1);
		
	glEnd();
	glutSwapBuffers();
}