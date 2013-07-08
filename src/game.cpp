#include "game.h"

game::game() {
	// initialize some basic settings
	surface = NULL;

	running = true;

	width = 640;
	height = 480;
}

int
game::OnExecute()
{
	if ( OnInit() == false )
	{
		return -1;
	}

	SDL_Event event;

	while ( running )
	{
		while ( SDL_PollEvent( &event ) )
		{
			OnEvent( &event );
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

int
main ( int argc, char *argv[] )
{
	game app;

	return app.OnExecute();
}

