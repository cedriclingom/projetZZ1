/*------------------------------------------------------------------------------------------------------*/
/*                                                                                                      */
/*                                                  grille.h                                            */
/*                                                                                                      */
/* Role  :     Déclaration des diretives de compilations, des constantes symboliques, de types et       */
/*             des prototypes.                                                                          */
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/


#ifndef GESTION_ENTREPOT_GRILLE_H
#define GESTION_ENTREPOT_GRILLE_H






#include "./tableau.h"
#include "./matrice.h"






#define NBCOL 3
#define NBCOLPA 4








typedef struct grille
{

  nombre_t * SommetEntrepot;

  nombre_t * arrete;

  nombre_t * PointArret;

}grille_t;







nombre_t ** CreationEntrepot(FILE *, int *, enum bool *);

nombre_t ** CreationArrete(FILE *, int *, enum bool *);

nombre_t ** CreationPointArret(FILE *, int *, enum bool *);

void LectureFichier(char *, nombre_t ***, nombre_t ***, nombre_t ***, int *, int *, int *,enum bool *);

nombre_t * CreationListe(nombre_t **, int);

grille_t * CreationGrille(nombre_t **, nombre_t **, nombre_t **, int, int, int, enum bool *);

void LibererGrille(grille_t **);







#endif
