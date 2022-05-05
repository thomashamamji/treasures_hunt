#include "tresor.h"
#ifndef abs
# define abs(x) ((x < 0) ? (-x) : (x))
#endif

void draw_map (Map * map) {
    for (unsigned int x = map->xo; x < map->sizex + map->xo; x++) {
        for (unsigned int y = map->yo; y < map->sizey + map->yo; y++) {
            switch (map->mat[x][y])
            {
                case 0 :
                    printf(" T "); // Treasure
                break;
                case 1 :
                    printf(" . "); // Terre
                break;
                case 2 :
                    printf(" | "); // Three
                break;
                case 3 :
                    printf(" X "); // Mountain
                break;
                case 4 :
                    printf(" O "); // Water
                break;
                case 5 :
                    printf("| |"); // Bridge
                break;
                case 6:
                    printf(" _ "); // Sand
                break;
                case 7 :
                    printf(" * "); // Personnage
                break;
                case 8 :
                    printf(" c "); // Move
                break;
            }
        }
        printf("\n\n");
    }

    printf("\n");

    for (unsigned int x = map->xo; x < map->sizex + map->xo; x++) {
        for (unsigned int y = map->yo; y < map->sizey + map->yo; y++) {
            switch (map->currentMat[x][y])
            {
                case 0 :
                    printf(" T "); // Treasure
                break;
                case 1 :
                    printf(" . "); // Terre
                break;
                case 2 :
                    printf(" | "); // Three
                break;
                case 3 :
                    printf(" X "); // Mountain
                break;
                case 4 :
                    printf(" O "); // Water
                break;
                case 5 :
                    printf("| |"); // Bridge
                break;
                case 6:
                    printf(" _ "); // S&&
                break;
                case 7 :
                    printf(" * "); // Personnage
                break;
                case 8 :
                    printf(" c "); // Move
                break;
            }
        }
        printf("\n\n");
    }
}

int matValidation (int val) {
    if (val >= 2 && val <= 4) return 0;
    return 1;
}

int findLastIndex (int Mvs[12][100][2], int i) {
    int j = 0;

    while (Mvs[i][j][0] || Mvs[i][j++][1]);

    return j;
}

Moves * initMap (Map * map, Perso * perso) {
    map->xo = 0;
    map->yo = 0;
    map->sizex = 25;
    map->sizey = 26;
    map->scale = SCALE; // !!!
    map->mat = (int**) calloc(map->sizex, sizeof(int*));
    map->currentMat = (int**) calloc(map->sizex, sizeof(int*));

    Move mv;
    printf("Chosissez les localisations des 4 trésors :\n");
    Moves * tresors = malloc(sizeof(Moves*));
    tresors = NULL;

    int valid, validLocationDomain, validLocation;

    // Filling both mat and currentMat matrixes

    for (int i = 0; i < map->sizey; i++) {
        map->mat[i] = calloc(map->sizey, sizeof(int));
        map->currentMat[i] = calloc(map->sizey, sizeof(int));
        
        for (int j = 0; j < map->sizey; j++) {
            // Affectation
            map->mat[i][j] = MAP[i][j];
            map->currentMat[i][j] = MAP[i][j];
        }
    }

    // Placing other points

    for (int i = 0; i < 4; i++) {
        do {
            printf("Trésor %d : (x y)\n", i+1);
            validLocationDomain = validLocation = 0;
            valid = scanf("%d %d", &mv.x, &mv.y) == 2;
            if (valid) validLocationDomain = mv.x > map->xo && mv.x < map->sizex-1 && mv.y > map->yo && mv.y < map->sizey-1;
            if (validLocationDomain) validLocation = matValidation(map->currentMat[mv.x][mv.y]);
            if (!valid || !validLocationDomain || !validLocation) printf("Saisie invalide des coordonées du trésor %d\n", i+1);
        } while (!valid || !validLocationDomain || !validLocation);

        tresors = addqueue(tresors, mv);
    }

    // Perso
    perso->x = 23;
    perso->y = 22;
    map->mat[perso->y][perso->x] = 7;
    map->currentMat[perso->y][perso->x] = 7;

    return tresors;
}

void refresh_map (Map * map, Moves * tresors) {
    srand(time(NULL));
    int rd_n = rand() % 4;

    for (int i = 0; i < rd_n; i++, tresors = tresors->next);

    printf("(%d, %d)\n\n\n", tresors->val.x, tresors->val.y);

    map->mat[tresors->val.y][tresors->val.x] = 0;
    map->currentMat[tresors->val.y][tresors->val.x] = 0;
}

void freeMap (Map * map) {
    for (unsigned int i = 0; i < map->sizex; i++) {
        free(map->mat[i]);
        map->mat[i] = NULL;
    }

    free(map->mat);
    map->mat = NULL;
}

int movePerso (Map * map, Perso * perso, int y, int x) {
    int X = perso->x, Y = perso->y;
    perso->x = perso->x + x;
    perso->y = perso->y + y;

    int mapLims = (X == 25 && x > 0) || (Y == 26 && y > 0) || (X == 0 && x < 0) || (Y == 0 && y < 0); // bool
    printf("%d\n", mapLims);

    if ((map->mat[perso->x][perso->y] >= 2 && map->mat[perso->x][perso->y] <= 4) || mapLims) {
        // Undo
        perso->x = X;
        perso->y = Y;

        printf("\nErreur : %d\n", (- map->mat[perso->x][perso->y]) + 1);
        return (- map->mat[perso->x][perso->y]) + 1; // Error code
    }

    map->mat[X][Y] = MAP[X][Y];
    map->mat[perso->x][perso->y] = 7; // Point personnage

    return 0; // No error
}

Moves * addqueue (Moves * mvs, Move mv) {
    Moves * Q;
    Moves * head;

    Moves * P = malloc(sizeof(Moves)*10);
    P->next = NULL;

    P->val = mv;

    if (mvs == NULL) {
        return P;
    }

    else {
        Q = mvs;
        head = mvs;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
        return head;
    }
}

Nodes * addqueue_n (Nodes * nodes, Node node) {
    Nodes * Q;
    Nodes * head;

    Nodes * P = malloc(sizeof(Nodes));
    P->next = NULL;

    P->val = node;

    if (nodes == NULL) {
        return P;
    }

    else {
        Q = nodes;
        head = nodes;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
        return head;
    }
}

void displayMoves (Moves * mvs) {
    if (mvs != NULL) {
        printf("(%d,%d)\n", mvs->val.x, mvs->val.y);
        displayMoves (mvs->next);
    }
}

void displayMovesTab(int Mvs[12][100][2]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 2; k++) {
                printf("%d ", Mvs[i][j][k]);
            }
            printf("\n");
        }
    }
}

int dist (Node a, Node b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int comp2nodes (Node * a, Node * b) {
    if (a->heuristique < b->heuristique) {
        return 1;
    }

    else if (a->heuristique == b->heuristique) {
        return 0;
    }

    else {
        return -1;
    }
}

int findCl (Nodes * nodes, Node nd) {
    while (nodes != NULL) {
       if (nodes->val.x == nd.x && nodes->val.y == nd.y) {
           return 1;
       }

       nodes = nodes->next;
    }

    return 0;
}

void sortList(Nodes * path, Nodes ** sorted) {
    Nodes * marqued = malloc(sizeof(Nodes));

    while (path != NULL) {
        if (!findCl(marqued, path->val)) {
            *sorted = addqueue_n(*sorted, path->val);
            marqued = addqueue_n(marqued, path->val);
        }

        path = path->next;
    }

    free(marqued);
}

void draw_path_solution (Map * map, Nodes * path) {
    for (int i = 0; path != NULL; i++) {
        map->mat[path->val.x][path->val.y] = 8;
        path = path->next;
    }
}
