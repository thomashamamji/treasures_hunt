#ifndef __OBJS_H__
#define __OBJS_H__

#include "mods.h"

typedef struct
{
    int x;
    int y;
    SDL_Texture * texture;
} Perso;

typedef struct {
    int x;
    int y;
} Move;

typedef struct _Moves
{
    Move val;
    struct _Moves * next;
} Moves;

typedef struct _ListMoves
{
    Moves * val;
    struct _ListMoves * next;
} ListMoves;

typedef struct {
    Move src;
    Move dest;
    int weight;
} Arret;

typedef struct {
    int nb_arrets;
    int nb_sommets;
    Arret * arretes;
    int x, y; // Sizes
    int ** mat;
} Graph;

typedef struct {
    int n_vertices; // TAILLE ARRETES
    int * nb_vertex; // NB SOMMETS
    int ** ls; // LISTE DES SUCCESSEURS POUR CHAQUE SOMMETS
} ListSuccessor;

typedef struct
{
    int parent;
    int rank;
} subset;

typedef struct
{
    int x, y, weight, heuristique;
} Node;

typedef struct _Nodes
{
    Node val;
    struct _Nodes * next;
} Nodes;


typedef struct {
    int xo;
    int yo;
    unsigned int sizex;
    unsigned int sizey;
    unsigned int scale;
    int ** mat;
    int ** currentMat;
} Map;

struct route {
    /* route has only one direction! */
    int x; /* index of stop in array of all stops of src of this route */
    int y; /* intex of stop in array of all stops od dst of this route */
    double d;
};

struct stop {
    double col, row;
    int * n;
    int n_len;
    double f, g, h;
    int from;
};

#endif