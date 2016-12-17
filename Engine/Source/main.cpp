#include "header.h"
#include "Game.h"
#include "Configuration.h"

int main()
{
	auto config = new Configuration();
	config->Fullscreen = true;
	config->ScreenNumber = 0;
	Game g = Game(config);
	g.Run();
	return 0;
}