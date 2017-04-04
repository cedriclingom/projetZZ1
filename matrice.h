#ifndef GESTION_ENTREPOT_MATRICE_H
#define GESTION_ENTREPOT_MATRICE_H







#include <stdio.h>
#include <stdlib.h>








typedef union
{

  int ValEntier;

  float ValReel;

}nombre_t;









void AllocationMatrice(nombre_t ***, int, int);

void SeparateurLigne(int, int);

void AfficherMatrice(nombre_t **, int, int);

void LiberationMatrice(nombre_t ***, int);
















#endif
