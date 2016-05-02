#define FREEGLUT_STATIC
#include <GL/glut.h>
#include <cstdio>
#include <time.h>

class Game
{
public:
	Game();
private:
	void static Draw();
};