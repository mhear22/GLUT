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
	void static CheckFPS();

	class Mouse
	{
	public:
	};

	class Keyboard
	{
	public:
		void static KeyPress(unsigned char key, int x, int y);
	private:
		unsigned char key[255];
	};
};