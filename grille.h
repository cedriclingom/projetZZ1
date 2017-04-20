#ifndef GESTION_ENTREPOT_GRILLE_H
#define GESTION_ENTREPOT_GRILLE_H





#include "./matrice.h"
#define NBCOL 3
#define NBCOLPA 4





typedef struct grille
{

  nombre_t * SommetEntrepot;

  nombre_t * arrete;

  nombre_t * PointArret;

}grille_t;


nombre_t ** creationEntrepot(FILE * f, nombre_t * nb);

nombre_t ** creationArrete(FILE * f, nombre_t * nb);

nombre_t ** creationPointArret(FILE * f, nombre_t * nb);







#endif
