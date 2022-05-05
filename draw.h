#ifndef __DRAW_H__
#define __DRAW_H__

#include "tresor.h"

void prepareScene(App * app);
void presentScene(App * app);
void blit(App app, SDL_Texture *texture, int x, int y);
void blitPlaces (App * app, Map * map);

#endif