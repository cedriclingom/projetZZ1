/*------------------------------------------------------------------------------------------------------*/
/*                                                                                                      */
/*                                              matrice.c                                               */
/*                                                                                                      */
/* Role  :                                                                                              */
/*------------------------------------------------------------------------------------------------------*/









#include "./matrice.h"










/*------------------------------------------------------------------------------------------------------*/
/*                                                                                                      */
/* AllocationMatrice           Alloue une matrice d'un certain nombre de lignes et colonnes.            */
/*                                                                                                      */
/* En entrée             :     matrice   - Pointeur de pointeur de pointeur sur un nombre.              */
/*                             NbLigne   - Le nombre de ligne de la matrice.                            */
/*                             NbColonne - Le nombre de colonne de la matrice.                          */
/*                                                                                                      */
/* En sortie             :     matrice   - Pointeur de pointeur de pointeur sur un nombre.              */
/*                                                                                                      */
/* Variable(s) locale(s) :     i         - Variable de boucle.                                          */
/*                             j         - Variable de boucle.                                          */
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/


void AllocationMatrice(nombre_t *** matrice,int NbLigne, int NbColonne)
{
  
  int i, j;

  (*matrice) = (nombre_t **)malloc(NbLigne * sizeof(nombre_t *));

  if(*matrice)
    {
      
      for(i = 0; i < NbLigne; ++i)
	{

	  (*matrice)[i] = (nombre_t *)malloc(NbColonne * sizeof(nombre_t));
	  
	  if(!(*matrice)[i])
	    {

	      for(j = 0; j < i; ++j)
		{

		  free((*matrice)[j]);

		}

	      free(*matrice);

	      *matrice = NULL;

	      i = NbLigne;

	    }

	}

    }

}
/*lecture1 matrice*/
/*lecture2 matrice*/
/*affiche matrice*/
/*desallocation matrice*/
