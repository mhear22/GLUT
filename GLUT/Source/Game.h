
#include "header.h"
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
		void static Clicked(int button, int state, int x, int y);
		void static Moved(int x, int y);
		void static Entering(int state);
	};

	class Keyboard
	{
	public:
		void static KeyPress(unsigned char key, int x, int y);
	private:
		unsigned char key[255];
	};
};