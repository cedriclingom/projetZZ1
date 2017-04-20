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


nombre_t ** creationEntrepot(FILE *, nombre_t *);

nombre_t ** creationArrete(FILE *, nombre_t);

nombre_t ** creationPointArret(FILE *, nombre_t *);







#endif
