#include "common.h"

void doInput(int * direction)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
			break;
            case SDL_KEYDOWN :
                switch (event.key.keysym.sym) {
                    case SDLK_RIGHT :
                        printf("RIGHT\n");
                        *direction = 1;
                    break;
                    case SDLK_UP :
                        printf("UP\n");
                        *direction = 2;
                    break;
                    case SDLK_LEFT :
                        printf("LEFT\n");
                        *direction = 3;
                    break;
                    case SDLK_DOWN :
                        printf("DOWN\n");
                        *direction = 4;
                    break;
                }
            break;

			default:
				break;
		}
	}
}