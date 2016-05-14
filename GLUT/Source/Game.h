
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
		void static Clicked(int button, int state, int x, int y);
		void static Moved(int x, int y);
		void static Entering(int state);
	};

	class Keyboard
	{
	public:
		void static KeyPress(GLFWwindow*,int,int, int, int);
	private:
		unsigned char key[255];
	};
};