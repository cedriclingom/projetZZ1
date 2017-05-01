/*------------------------------------------------------------------------------------------------------*/
/*                                                                                                      */
/*                                              tableau.h                                               */
/*                                                                                                      */
/* Role  :     Déclaration des diretives de compilations, des constantes symboliques, de types et       */
/*             des prototypes.                                                                          */
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/




#ifndef GESTION_ENTREPOT_TABLEAU_H
#define GESTION_ENTREPOT_TABLEAU_H





#include <stdio.h>
#include <stdlib.h>






typedef union nombre
{

  int entier;

  float reel;

}nombre_t;




nombre_t * AllocationTableau(int);

void AfficherTableau(nombre_t *, int);







#endif
