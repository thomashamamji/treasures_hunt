#include "common.h"

void prepareScene(App * app)
{
	SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
	SDL_RenderClear(app->renderer);
}

void presentScene(App * app)
{
	SDL_RenderPresent(app->renderer);
}

void blit(App app, SDL_Texture *texture, int x, int y)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}

void blitPlaces (App * app, Map * map) {
	SDL_Texture * sand = loadTexture(*app, "sand.png");
	SDL_Texture * three = loadTexture(*app, "three.png");
	SDL_Texture * montain = loadTexture(*app, "montain.png");
	SDL_Texture * terre = loadTexture(*app, "terre.png");
	SDL_Texture * tresure = loadTexture(*app, "tresure.png");
	SDL_Texture * water = loadTexture(*app, "water.png");
	SDL_Texture * perso = loadTexture(*app, "perso.png");
	SDL_Texture * bridge = loadTexture(*app, "bridge.png");

	for (int i = map->xo; i < map->xo + map->sizex+1; i++) {
		for (int j = map->yo; j < map->yo + map->sizey; j++) {
			switch (map->mat[j][i])
            {
                case 0 :
                    blit(*app, tresure, map->scale*(i - map->xo), map->scale*(j - map->yo));
                break;
                case 1 :
                    blit(*app, terre, map->scale *(i - map->xo), map->scale*(j - map->yo)); // Terre
                break;
                case 2 :
                    blit(*app, three, map->scale*(i - map->xo), map->scale*(j - map->yo)); // Three
                break;
                case 3 :
                    blit(*app, montain, map->scale*(i - map->xo), map->scale*(j - map->yo)); // Mountain
                break;
                case 4 :
                    blit(*app, water, map->scale*(i - map->xo), map->scale*(j - map->yo)); // Water
                break;
                case 5 :
                    blit(*app, bridge, map->scale*(i - map->xo), map->scale*(j - map->yo)); // Bridge
                break;
                case 6:
                    blit(*app, sand, map->scale*(i - map->xo), map->scale*(j - map->yo)); // Sand
                break;
                case 7 :
                    blit(*app, perso, map->scale*(i - map->xo), map->scale*(j - map->yo)); // Personnage
                break;
            }
		}
	}
}
