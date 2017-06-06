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







/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* echange                 Fait l'échange de 2 valeurs.                                            */
/*                                                                                                 */
/* En entrée             : a   - Pointeur sur un entier (valeur 1).                                */
/*                         b   - Pointeur sur un entier (valeur 2).                                */
/*                                                                                                 */
/* En sortie             : a   - Pointeur sur un entier (valeur 1).                                */
/*                         b   - Pointeur sur un entier (valeur 2).                                */
/*                                                                                                 */
/* Variable(s) locale(s) : aux - Variable temporaire permetant d'effectuer l'échange.              */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


void echange(int * a, int * b)
{

  int aux;

  aux = *a;

  *a = *b;

  *b = aux;

}


/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* SequenceDistanceMin     Procure la séquence de points d'arrets de distance minimal.             */
/*                                                                                                 */
/* En entrée             : DistancePA   - Pointeur sur la matrice des points d'arrets des distances*/
/*                         PointArret   - Pointeur sur la matrice des points d'arrets.             */
/*                         ListPA       - Pointeur sur list des points d'arrets.                   */
/*                         NbPointArret - Nombre de points d'arrets.                               */
/*                                                                                                 */
/* En sortie             : ListPA       - Pointeur sur list des points d'arrets.                   */
/*                                                                                                 */
/* Variable(s) locale(s) : i, j         - Variable de boucle.                                      */
/*                         indice       - Variable contenant l'indice du point d'arret le plus     */
/*                                        proche du point arret précédent.                         */
/*                         min          - Contient la distance minimum courante.                   */
/*                         dist         - Contient la calcule de distance entre 2 points d'arrets. */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


void SequenceDistanceMin(nombre_t ** DistancePA, nombre_t ** PointArret, nombre_t * ListPA, int NbPointArret)
{

  int i, j, indice;
  
  double min, dist;

  min = CalculDistance(0, 0, PointArret[0][2], PointArret[0][3]);       /*Initialise la distance minimal*/
  
  indice = 0;
  
  for(i = 1; i < NbPointArret; ++i)                                    /*Cherche le point arret le plus proche du début*/
    {
      
      dist = CalculDistance(0, 0, PointArret[i][2], PointArret[i][3]);
      
      if(dist < min)
	{
	  
	  min = dist;
	  
	  indice = i;
	  
	}
      
    }
  
  echange(&(ListPA[0]), &(ListPA[indice]));                           /*Place le point d'arret le plus proche du début en tete*/
  
  for(i = 0; i < NbPointArret - 1; ++i)                              /* Détermine la séquence de distance minimal*/
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


/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* AfficheSequence         Affiche une séquence de points d'arrets.                                */
/*                                                                                                 */
/* En entrée             : pgrille      - Pointeur sur une grille.                                 */
/*                         DistancePA   - Pointeur sur la matrice de distance entre les points     */
/*                                        d'arrets.                                                */
/*                         NbPointArret - Nombre de points d'arrets.                               */
/*                                                                                                 */
/* En sortie             :                Rien en sortie.                                          */
/*                                                                                                 */
/* Variable(s) locale(s) : i            - Variable de boucle.                                      */
/*                         som          - Contient la distance début jusqu'au dernier point d'arret*/
/*                                        de la séquence.                                          */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


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

