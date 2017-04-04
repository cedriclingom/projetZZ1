#ifndef GESTION_ENTREPOT_MATRICE_H
#define GESTION_ENTREPOT_MATRICE_H







#include <stdio.h>
#include <stdlib.h>








typedef int nombre_t;









void AllocationMatrice(nombre_t ***, int, int);

void SeparateurLigne(int, int);

void LireMatrice(nombre_t **, int, int);

void AfficherMatrice(nombre_t **, int, int);

void LiberationMatrice(nombre_t ***, int);
















#endif
