#include <GL/glut.h>
#include <cstdio>
#include <chrono>
#include <thread>

using namespace std::chrono;

class Game
{
public:
	Game();
private:
	void static Draw();
	void static CheckFPS();
};