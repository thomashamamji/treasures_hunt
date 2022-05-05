#ifndef __GRAPHE_H__
#define __GRAPHE_H__

#include <stdio.h>
#include <stdlib.h>

#include "objs.h"

Graph * create_graph (int nb_sommets, int nb_arrets);
int find(subset * subsets, int i);
void Union (subset * subsets, int x, int y);
void boruvkaMST(Graph* graph);
Graph * initGraph (Map * map);
void displayGraph (Graph * g);
void free_graph(Graph * g);
ListSuccessor * initLs (Graph * g);

#endif