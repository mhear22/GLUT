
#include "header.h"
#include "Draw.h"

using namespace std::chrono;

class Game
{
public:
	Game();
private:
	void static Draw();

	class Mouse
	{
	public:
		void static Clicked(GLFWwindow* window,int button, int action, int mods);
		void static Moved(GLFWwindow* window, double x, double y);
		void static Entering(int state);
	};

	class Keyboard
	{
	public:
		void static KeyPress(GLFWwindow*,int,int, int, int);
	private:
		unsigned char static keys[256];
	};
};