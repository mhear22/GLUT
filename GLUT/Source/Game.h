#include <GL/glut.h>
#include <cstdio>
#include <chrono>
#include <time.h>
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

	void static DrawHex(float x, float y, float scale);
	void static DrawSquare(float x, float y, float height, float width);

	void static KeyPress(unsigned char key, int x, int y);
	void static Mouse(int button, int state, int x, int y);
	void static CheckFPS();
};