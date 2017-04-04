/*------------------------------------------------------------------------------------------------------*/
/*                                                                                                      */
/*                                              matrice.c                                               */
/*                                                                                                      */
/* Role  :        Le fichier matrice.c contient les définitions liés au traitement à effectuer sur une  */
/*                matrice.                                                                              */
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/









#include "./matrice.h"










/*------------------------------------------------------------------------------------------------------*/
/*                                                                                                      */
/* AllocationMatrice           Alloue une matrice d'un certain nombre de lignes et colonnes.            */
/*                                                                                                      */
/* En entrée             :     matrice    - Pointeur de pointeur de pointeur sur un nombre.             */
/*                             NbLigne    - Le nombre de ligne de la matrice.                           */
/*                             NbColonne  - Le nombre de colonne de la matrice.                         */
/*                                                                                                      */
/* En sortie             :     pmatrice   - Pointeur de pointeur de pointeur sur un nombre.             */
/*                                                                                                      */
/* Variable(s) locale(s) :     i         - Variable de boucle.                                          */
/*                             j         - Variable de boucle.                                          */
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/


void AllocationMatrice(nombre_t *** pmatrice,int NbLigne, int NbColonne)
{
  
  int i, j;

  (*pmatrice) = (nombre_t **)malloc(NbLigne * sizeof(nombre_t *));

  if(*pmatrice)                                                               /*si l'allocation des lignes à marcher*/
    {
      
      for(i = 0; i < NbLigne; ++i)
	{

	  (*pmatrice)[i] = (nombre_t *)malloc(NbColonne * sizeof(nombre_t));  /*alloue les colonnes de chaque ligne*/
	  
	  if(!(*pmatrice)[i])                                                 /*si l'allocation n'a pas marcher*/
	    {

	      for(j = 0; j < i; ++j)
		{

		  free((*pmatrice)[j]);                                      

		}

	      free(*pmatrice);

	      *pmatrice = NULL;

	      i = NbLigne;

	    }

	}

    }

}





void SeparateurLigne(int NumeroLigne, int LongueurLigne)
{

  int i;
  
  printf("/");

  for(i = 0; i < LongueurLigne; ++i)
    {

      printf("*");

      if(i == ((LongueurLigne / 2) -1))
	{
	  
	  printf("LIGNE %d", NumeroLigne);

	}

    }

  printf("/\n");

}
  
/*void LireMatrice(nombre_t ** matrice, int NbLigne, int NbColonne)
{

  int i, j;

  for(i = 0; i < NbLigne; ++i)
    {

      printf("
*/




/*lecture2 matrice*/


/*------------------------------------------------------------------------------------------------------*/
/*                                                                                                      */
/* AfficherMatrice           Affiche le contenu de la matrce.                                           */
/*                                                                                                      */
/* En entrée             :   matrice   - Pointeur de pointeur sur un nombre.                            */
/*                           NbLigne   - Le nombre de lignes de la matrice.                             */
/*                           NbColonne - Le nombre de colonnes de la matrice.                           */ 
/*                                                                                                      */
/* En sortie             :   Rien en sortie.                                                            */
/*                                                                                                      */
/* Variable(s) locale(s) :   i         - Variable de boucle.                                            */
/*                           j         - Variable de boucle.                                            */
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/


void AfficherMatrice(nombre_t ** matrice, int NbLigne, int NbColonne)
{

  int i, j;
  
  for(i = 0; i < NbLigne; ++i)
    {

      printf("| ");

      for(j = 0; j < NbColonne; ++j)
	{
	  
	  printf("%d ", matrice[i][j]);

	}

      printf("|\n");

    }

}


/*------------------------------------------------------------------------------------------------------*/
/*                                                                                                      */
/* LiberationMatrice            Désalloue toute la matrice.                                             */
/*                                                                                                      */
/* En entrée             :      pmatrice - Pointeur de pointeur de pointeur sur un nombre.              */
/*                              NbLigne  - Le nombre de lignes de la matrice.                           */
/*                                                                                                      */    
/* En sortie             :      Rien en sortie.                                                         */
/*                                                                                                      */
/* Variable(s) locale(s) :      i        - Variable de boucle.                                          */
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/


void LiberationMatrice(nombre_t *** pmatrice, int NbLigne)
{

  int i;

  for(i = 0; i < NbLigne; ++i)
    {

      free((*pmatrice)[i]);

    }

  free(*pmatrice);

  *pmatrice = NULL;

}
