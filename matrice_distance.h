#ifndef GESTION_ENTREPOT_MATRICE_DISTANCE_H
#define GESTION_ENTREPOT_MATRICE_DISTANCE_H





#include <math.h>
#include "./grille.h"




nombre_t ** AllocationMatriceDistances(int, int);

void RechercheSommet(int *, nombre_t **, int, enum bool *);

void RechercheArrete(int, nombre_t **, int, enum bool *, int *, int *);

void RechercheCouple(int, int, nombre_t **, int, enum bool *);

float CalculDistance(int, int, int, int);

void RemplirMatriceDistancePhase1(nombre_t **, nombre_t **, nombre_t **, int, int);

void RemplirMatriceDistancePhase2(nombre_t **, nombre_t **, nombre_t **, nombre_t **, int, int, int);

void RemplirMatriceDistance(nombre_t ***, nombre_t **, int, nombre_t **, int, nombre_t **, int);

void floyd(nombre_t **, int, int);

nombre_t **  ExtraireMatriceDistancePA(nombre_t **, int, int);












#endif
