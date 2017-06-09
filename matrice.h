/*------------------------------------------------------------------------------------------------------*/
/*                                                                                                      */
/*                                                matrice.h                                             */
/*                                                                                                      */
/* Role  :     Déclaration des diretives de compilations, des constantes symboliques, de types et       */
/*             des prototypes.                                                                          */
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/


#ifndef GESTION_ENTREPOT_MATRICE_H
#define GESTION_ENTREPOT_MATRICE_H







#include "./tableau.h"






enum bool{faux, vrai};





nombre_t ** AllocationMatrice(int, int);

void SeparateurLigne(int, int);

void LireMatrice(nombre_t **, int, int);

void FlireMatrice(nombre_t **, int, int, FILE *, enum bool *);

void AfficherMatrice(nombre_t **, int, int);

void AfficherMatrice2(nombre_t **, int, int);

void LiberationMatrice(nombre_t ***, int);
















#endif
