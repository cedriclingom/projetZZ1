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






/*------------------------------------------------------------------------------------------------------*/
/*                                                                                                      */
/* SeparateurLigne            Sépare chaque ligne de la matrice lors de la saisie des valeurs.          */
/*                                                                                                      */
/* En entrée             :    NumeroLigne   - Numéro de ligne de la matrice.                            */
/*                                                                                                      */
/* En sortie             :    LongueurLigne - Longueur de la ligne servant de séparateur en ligne de    */
/*                                            commande.                                                 */
/*                                                                                                      */
/* Variable(s) locale(s) :    i             - Variable de boucle.                                       */
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/



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
  

/*------------------------------------------------------------------------------------------------------*/
/*                                                                                                      */
/* LireMatrice              Permet d'entrer les données dans la matrice à partir de l'entrée standard.  */
/*                                                                                                      */
/* En entrée             :  matrice   - Pointeur de pointeur sur un nombre.                             */
/*                          NbLigne   - Le nombre de ligne de la matrice.                               */
/*                          NbColonne - Le nombre de colonne de la matrice.                             */
/*                                                                                                      */
/* En sortie             :  matrice   - Pointeur de pointeur sur un nombre.                             */                                  /*                                                                                                      */
/* Variable(s) locale(s) :  i , j     - Variables de boucle.                                            */
/*                          continu   - Variable contenant une valeur signifiant la lecture c'est bien  */
/*                                      passée ou pas.                                                  */  
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/


void LireMatrice(nombre_t ** matrice, int NbLigne, int NbColonne)
{

  int i, j, continu = 1;

  for(i = 0; (i < NbLigne && continu); ++i)
    {

      SeparateurLigne(i+1, 100);

      for(j = 0; (j < NbColonne && continu) ; ++j)
	{

	  printf("Entrez l'élément %d: ", j + 1);

	  continu = scanf("%d", matrice[i] + j);

	}

    }

}



/*------------------------------------------------------------------------------------------------------*/
/*                                                                                                      */
/* FlireMatrice            Lecture de données pour une matrice à partir d'un fichier.                   */
/*                                                                                                      */
/* En entrée             : matrice     - Pointeur de pointeur sur un nombre.                            */
/*                         NbLigne     - Nombre de ligne de la matrice.                                 */
/*                         NbColonne   - Nombre de colonne de la matrice.                               */
/*                         f           - Pointeur de fichier.                                           */
/*                         CodeLecture - Pointeur sur la case mémoire contenant une valeur comme quoi   */
/*                                       la lecture c'est bien passé ou pas.                            */
/*                                                                                                      */
/* En sortie             : matrice     - Pointeur de pointeur sur un nombre.                            */
/*                         CodeLecture - Pointeur sur la case mémoire contenant une valeur comme quoi   */
/*                                       la lecture c'est bien passé ou pas.                            */
/*                                                                                                      */
/* Variable(s) locale(s) : i, j        - Variables de boucle.                                           */
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/


void FlireMatrice(nombre_t ** matrice, int NbLigne, int NbColonne, FILE * f, int * CodeLecture)
{

  int i, j;

  *CodeLecture = 1;

  for(i = 0; (i < NbLigne && *CodeLecture); ++i)           /*tantque je suis dans la matrice et que la lecture ce passe bien*/
    {

      for(j = 0; (j < NbColonne && *CodeLecture); ++j)
	{

	  *CodeLecture = fscanf(f, "%d", matrice[i] + j);

	}

    }

}



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
