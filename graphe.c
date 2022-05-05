#include "graphe.h"

Graph * initGraph (Map * map) {
    Graph * g = malloc(sizeof(Graph));
    g->arretes = malloc(sizeof(Graph));
    g->mat = calloc(map->sizex, sizeof(int*));
    g->x = map->sizex;
    g->y = map->sizey;
    
    for (int i = 0; i < map->sizex; i++) {
        g->mat[i] = calloc(map->sizey, sizeof(int));
    }

    for (int x = map->xo; x < map->xo + map->sizex; x++) {
        for (int y = map->yo; y < map->yo + map->sizey; y++) {
            if (map->mat[x][y] == 1 || map->mat[x][y] == 5) g->mat[x][y] = 1;
            else if (map->mat[x][y] == 6) g->mat[x][y] = 2;
        }
    }

    return g;
}

void displayGraph (Graph * g) {
    for (int x = 0; x < g->x; x++) {
        for (int y = 0; y < g->y; y++) {
            printf("%d ", g->mat[x][y]);
        }
        printf("\n");
    }
}

void free_graph(Graph * g) {
    free(g->arretes);
    g->arretes = NULL;
    free(g);
    g = NULL;
}
