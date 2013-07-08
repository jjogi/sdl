#include "game.h"

void
game::OnEvent( SDL_Event *event )
{
	switch ( event->type )
	{
		case SDL_QUIT:
			running = false;
			break;
		case SDL_KEYDOWN:
			switch ( event->key.keysym.sym )
			{
				case SDLK_LEFT:
					printf( "left\n" );
					break;
				case SDLK_RIGHT:
					printf( "right\n" );
					break;
				case SDLK_q:
					if ( event->key.keysym.mod & KMOD_CTRL )
					{
						running = false;
					}
					break;
				default:
					break;
			}
			break;
		case SDL_KEYUP:
			break;
		default:
//			printf( "OMG! An event!\n" );
			break;
	}
}

