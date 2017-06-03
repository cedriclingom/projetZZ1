/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/*                                             sequence.c                                          */
/*                                                                                                 */
/* Role : Définition des fonctions et procédures liées à la détermination de la meilleur séquence  */
/*        de point d'arrets.                                                                       */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include "./sequence.h"






void echange(int * a, int * b)
{

  int aux;

  aux = *a;

  *a = *b;

  *b = aux;

}

/*création d'une séquence par défaut*/

/*Déterminer la meilleur séquence*/

void SequenceDistanceMin(nombre_t ** DistancePA, nombre_t ** PointArret, nombre_t * ListPA, int NbPointArret)
{

  int i, j, indice;
  
  double min, dist;

  min = CalculDistance(0, 0, PointArret[0][2], PointArret[0][3]);
  
  indice = 0;
  
  for(i = 1; i < NbPointArret; ++i)
    {
      
      dist = CalculDistance(0, 0, PointArret[i][2], PointArret[i][3]);
      
      if(dist < min)
	{
	  
	  min = dist;
	  
	  indice = i;
	  
	}
      
    }
  
  echange(&(ListPA[0]), &(ListPA[indice]));
  
  for(i = 0; i < NbPointArret - 1; ++i)
    {
      
      for(j = i + 1; j < NbPointArret; ++j)
	{
	  
	  if(j - i == 1)
	    {
	      
	      min = DistancePA[ListPA[i]][ListPA[j]];
	      
	      indice = j;
	      
	    }
	  else
	    {
	      
	      dist = DistancePA[ListPA[i]][ListPA[j]];
	      
	      if(dist < min)
		{
		  
		  min = dist;
		  
		  indice = j;
		  
		}
	      
	    }
	  
	}
      
      echange(&(ListPA[i + 1]), &(ListPA[indice]));
      
    }

}

/*Affiche la séquence*/

void AfficheSequence(grille_t * pgrille, nombre_t ** DistancePA, int NbPointArret)
{

  int i;

  double som = 0;

  printf("La meilleur séquence est:\n");

  AfficherTableau(pgrille->PointArret, NbPointArret);

  for(i = 0; i < NbPointArret - 1; ++i)
    {

      som += DistancePA[pgrille->PointArret[i]][pgrille->PointArret[i + 1]];

    }

  printf("La distance total minimal est de: %f\n", som);

}
  



/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/**/
/*                                                                                                 */
/* En entrée             : */
/*                                                                                                 */
/* En sortie             :*/
/*                                                                                                 */
/* Variable(s) locale(s) :*/
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/

