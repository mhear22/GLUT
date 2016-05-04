#include <GL/glut.h>
#include <cstdio>
#include <chrono>
#include <time.h>
#include <string>
#include <thread>
#include <tuple>

#include "Draw.h"

using namespace std::chrono;

class Game
{
public:
	Game();
private:
	void static Draw();

	void static KeyPress(unsigned char key, int x, int y);
	void static Mouse(int button, int state, int x, int y);
	void static CheckFPS();
};