#include "graphe.h"
#include "tresor.h"
#include "common.h"

App app;

int main (void) {
    Map * map = malloc(sizeof(Map));
    Perso perso;
    perso.texture = loadTexture(app, "perso.png");
    perso.x = 22;
    perso.y = 23;
    int direction = 0;
    Nodes * path = malloc(sizeof(Nodes));
    path = NULL;

    memset(&app, 0, sizeof(App));
    draw_map(map);
    initSDL(&app);

    Moves * tresors = initMap(map, &perso);
    Node start, end;
    start.x = 22;
    start.y = 23;

    refresh_map(map, tresors);

    end.x = tresors->val.x;
    end.y = tresors->val.y;
    
    draw_map(map);

    Graph * g = initGraph(map);

    draw_path_solution (map, path);

    while (path != NULL) {
        printf("[%d, %d]\n", path->val.x, path->val.y);
        path = path->next;
    }

    displayGraph(g);

    draw_map(map);

    while (1) {
        direction = 0;
        prepareScene(&app);

		doInput(&direction);

        if (direction) {
            switch (direction) {
                case 1 :
                    printf("RIGHT\n");
                    movePerso(map, &perso, 1, 0);
                break;
                case 2 :
                    printf("UP\n");
                    movePerso(map, &perso, 0, -1);
                break;
                case 3 :
                    printf("LEFT\n");
                    movePerso(map, &perso, -1, 0);
                break;
                case 4 :
                    printf("DOWN\n");
                    movePerso(map, &perso, 0, 1);
                break;
                default : break;
            }
        }

        blitPlaces(&app, map);

        presentScene(&app);

		SDL_Delay(16);
    }

    free_graph(g);
    freeMap(map);
    free(tresors);
    free(path);

    return 0;
}