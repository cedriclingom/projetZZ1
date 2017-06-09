/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/*                                             sequence.c                                          */
/*                                                                                                 */
/* Role : Définition des fonctions et procédures permettant de calculer la matrice de distance     */
/*        tous les sommet de la grille ainsi que les points d'arrets.Ensuite une extraction de la  */
/*        matrice de distance entre les point d'arrets.                                            */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/








#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./matrice_distance.h"











/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* InitialiseMatriceDistance   Initialise la matrice de distance.                                  */
/*                                                                                                 */
/* En entrée             : distance  - Pointeur sur la matrice de distance.                        */
/*                         NbLigne   - Le nombre de ligne de la matrice.                           */
/*                         NbColonne - Le nombre de colonne de la matrice.                         */
/*                                                                                                 */
/* En sortie             : distance  - Pointeur sur la matrice de distance.                        */
/*                                                                                                 */
/* Variable(s) locale(s) : i, j      - Variable de boucle.                                         */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


void InitialiserMatriceDistance(nombre_t ** distance, int NbLigne, int NbColonne)
{

  int i, j;

  for(i = 0; i < NbLigne; ++i)
    {
      for(j = 0; j < NbColonne; ++j)
	{

	  if(i != j)
	    {

	      distance[i][j] = VALEUR_MAX;

	    }
	  else
	    {
	      
	      distance[i][j] = 0;              /*initialise les diagonale à zéro*/

	    }

	}

    }

}


/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* RechercheSommet         Recherche un sommet dans la grille des sommets de l'entrepot.           */
/*                                                                                                 */
/* En entrée             : x        - sommet à rechercher.                                         */
/*                         sommet   - Pointeur sur une matrice de sommets de l'entrepot.           */
/*                         NbSommet - Le nombre de sommets de la grille.                           */
/*                         ptrouver - Pointeur sur un case mémoire contenant vrai si on a trouver  */
/*                                    le sommet et faux sinon.                                     */
/*                                                                                                 */
/* En sortie             : ptrouver - Pointeur sur un case mémoire contenant vrai si on a trouver  */
/*                                    le sommet et faux sinon.                                     */
/*                                                                                                 */
/* Variable(s) locale(s) : i        - Variable de boucle.                                          */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


void RechercheSommet(int * x, nombre_t ** sommet, int NbSommet, enum bool * ptrouver)
{

  int i = 0;

  *ptrouver = faux;
  
  while((i < (NbSommet-1)) && (sommet[i][0] != *x))    /*tantque je suis dans la matrice et j'ai pas trouver le sommet*/
    {
      
      ++i;

    }

  if(i < (NbSommet -1))                               /*si le sommet existe*/ 
    {

      *ptrouver = vrai;

    }

}


/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* RechercheArrete         Recherche une arrete dans la matrice d'arrete.                          */
/*                                                                                                 */
/* En entrée             : a         - Arrete à rechercher.                                        */
/*                         arrete    - Pointeur sur une matrice d'arretes.                         */
/*                         Nbarretes - Le nombre d'arretes.                                        */
/*                         ptrouver  - Pointeur sur une case mémoire contenant vrai si on a trouvé */
/*                                     l'arrete et faux sinon.                                     */
/*                         x         - Pointeur sur case mémoire contenant le sommet 1 que relie   */
/*                                     l'arrete rechercher.                                        */
/*                         y         - Pointeur sur case mémoire contenant le sommet 1 que relie   */
/*                                     l'arrete rechercher.                                        */
/*                                                                                                 */
/* En sortie             : ptrouver  - Pointeur sur une case mémoire contenant vrai si on a trouvé */
/*                                     l'arrete et faux sinon.                                     */
/*                         x         - Pointeur sur case mémoire contenant le sommet 1 que relie   */
/*                                     l'arrete rechercher.                                        */
/*                         y         - Pointeur sur case mémoire contenant le sommet 1 que relie   */
/*                                     l'arrete rechercher.                                        */
/*                                                                                                 */
/* Variable(s) locale(s) : i         - Variable de boucle.                                         */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


void RechercheArrete(int a, nombre_t ** arrete, int NbArretes, enum bool *ptrouver, int * x, int * y)
{

  int i = 0;

  *ptrouver = faux;
  
  while ((i < NbArretes) && (arrete[i][0] != a))                   /*tantque je suis dans la matrice et j'ai pas trouver l'arrete*/
    {
      
      ++i;
      
    }
  
  if(i < NbArretes)                                                /*si j'ai trouver l'arrete*/
    {
      
      *x = arrete[i][1];
      
      *y = arrete[i][2];
      
      *ptrouver = vrai;
      
    }
  
}


/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* CalculDistance          Calcule la distance entre deus sommets.                                 */
/*                                                                                                 */
/* En entrée             : a - La coordonée en abscisse du premier sommet.                         */
/*                         b - La coordonée en ordonée  du premier sommet.                         */
/*                         c - La coordonée en abscisse du deuxième sommet.                        */
/*                         d - La coordonée en ordonée  du deuxième sommet.                        */
/*                                                                                                 */
/* En sortie             :     Retourne la distance calculer.                                      */
/*                                                                                                 */
/* Variable(s) locale(s) :     Rien en variable locale.                                            */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


double CalculDistance(int a, int b, int c, int d)
{

  return sqrt(pow((a - c) * 1.0, 2.0) + pow((b - d) * 1.0, 2.0));

}


/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* RechercheCouple         Recherche un couple de sommet dans la matrice d'arrete.                 */
/*                                                                                                 */
/* En entrée             : a         - Premier sommet.                                             */
/*                         b         - Deuxième sommet.                                            */
/*                         arrete    - Pointeur sur une matrice d'arretes.                         */
/*                         NbArretes - Le nombre d'arretes.                                        */
/*                         ptrouver  - Pointeur sur une case mémoire contenant vrai si on a trouvé */
/*                                     le couple de sommet et faux sinon.                          */
/*                                                                                                 */
/* En sortie             : ptrouver  - Pointeur sur une case mémoire contenant vrai si on a trouvé */
/*                                     le couple de sommet et faux sinon.                          */
/*                                                                                                 */
/* Variable(s) locale(s) : i         - Variable de boucle.                                         */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


void RechercheCouple(int a, int b, nombre_t ** arrete, int NbArretes, enum bool * ptrouver)
{

  int i = 0;

  *ptrouver = (((arrete[i][1] == a) && (arrete[i][2] == b)) || ((arrete[i][1] == b) && (arrete[i][2] == a)));  
  
  while((i < NbArretes) && !ptrouver)            /*tantque je suis dans la matrice et j'ai pas trouvé le couple de sommet*/
    {

      *ptrouver = (((arrete[i][1] == a) && (arrete[i][2] == b)) || ((arrete[i][1] == b) && (arrete[i][2] == a)));
           
      ++i;
 
    }

  if(i < NbArretes)                              /*si j'ai trouver*/
    {

      *ptrouver = vrai;

    }

}


/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* RemplirMatriceDaistancePhase1  Remplir la matrice de distance entre sommet de l'entrepot.       */
/*                                                                                                 */
/* En entrée             : distance - Pointeur sur la matrice de distance.                         */
/*                         sommet   - Pointeur sur la matrice des sommets de l'entrepot.           */
/*                         arrete   - Pointeur sur la matrice d'arretes.                           */
/*                         NbSommet - Le nombre de sommets.                                        */
/*                         NbArrete - Le nombre d'arretes.                                         */
/*                                                                                                 */
/* En sortie             : distance - Pointeur sur la matrice de distance.                         */
/*                                                                                                 */
/* Variable(s) locale(s) : i,j      - Variable de boucle.                                          */
/*                         trouver  - Pointeur sur une case mémoire contenant vrai si on a trouvé  */
/*                                    le couple de sommet et faux sinon.                           */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


void RemplirMatriceDistancePhase1(nombre_t ** distance , nombre_t ** sommet, nombre_t ** arrete, int NbSommet, int NbArrete)
{

  int i , j;
  
  enum bool trouver;
  
  for (i = 0; i < NbSommet; ++i)
    {
      
      for (j = i + 1; j < NbSommet; ++j)
	{
      
	  RechercheCouple(sommet[i][0], sommet[j][0], arrete, NbArrete, &trouver);
	  
	  if(trouver)
	    {
	      
	      distance[i][j] = CalculDistance(sommet[i][1], sommet[i][2], sommet[j][1], sommet[j][2]);
	      
	      distance[j][i] = distance[i][j];
	      
	    }
	  
	}
      
    }
  
}


/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* RemplirMatriceDistancePhase2   Remplie la matrice de distance entre les points d'arrets et entre*/
/*                                les points d'arrets et les sommets appartenant à la meme arrete. */
/*                                                                                                 */
/* En entrée             : distance     - Pointeur sur la matrice de distnace.                     */
/*                         PointArret   - Pointeur sur une matrice de points d'arrets.             */
/*                         sommet       - Pointeur sur une matrice de sommets.                     */
/*                         arrete       - Pointeur sur une matrice d'arretes.                      */
/*                         NbSommet     - Le nombrede sommets.                                     */
/*                         NbPointArret - Le nombre de Points d'arrets.                            */
/*                         NbArrete     - Le nombre d'arretes.                                     */
/*                                                                                                 */
/* En sortie             : distance     - Pointeur sur la matrice de distnace.                     */
/*                                                                                                 */
/* Variable(s) locale(s) : i            - Variable de boucle.                                      */
/*                         x            - Contient la sommet 1.                                    */
/*                         y            - Contient le sommet 2.                                    */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


void RemplirMatriceDistancePhase2(nombre_t ** distance , nombre_t ** PointArret, nombre_t ** sommet, nombre_t ** arrete, int NbSommet, int NbPointArret, int NbArrete)
{
  
  int i , x , y;
  
  enum bool trouver1, trouver2;
	
  for(i = NbSommet; i < (NbSommet + NbPointArret); ++i)
    {
      
      RechercheArrete(PointArret[i - NbSommet][1], arrete, NbArrete, &trouver1, &x, &y);
      
      if(trouver1)
	{
	  
	  RechercheSommet(&x, sommet , NbSommet , &trouver1);
	  
	  RechercheSommet(&y, sommet, NbSommet, &trouver2);
	  
	  if((trouver1) && (trouver2))
	    {
	      
	      distance[i][x] = CalculDistance(PointArret[i - NbSommet][2], PointArret[i - NbSommet][3], sommet[x][1], sommet[x][2]);

	      distance[i][y] = CalculDistance(PointArret[i - NbSommet][2], PointArret[i - NbSommet][3],sommet[y][1], sommet[y][2]);
	      
	      distance[x][i] = distance[i][x];
	      
	      distance[y][i] = distance[i][y];
	      
	    }
	  
	}
      
    }
  
}


/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* RemplirMatriceDistance  Permet de remplir la matrice de distance.                               */
/*                                                                                                 */
/* En entrée             : distance     - Pointeur de pointeur sur la mtrice de distance.          */
/*                         sommet       - Pointeur sur une de sommet de l'entrepot.                */
/*                         arrete       - Pointeur sur une matrice d'arretes.                      */
/*                         PointArret   - Pointeur sur une matrice de point d'arets.               */
/*                         NbSommet     - Nombre de sommet de l'entrepot.                          */
/*                         NbPointArret - Nombre de points d'arrets.                               */
/*                         NbArrete     - Nombre d'arretes.                                        */
/*                                                                                                 */
/* En sortie             : distance     - Pointeur de pointeur sur la mtrice de distance.          */
/*                                                                                                 */
/* Variable(s) locale(s) :                Rien EN variable locale.                                 */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


void RemplirMatriceDistance(nombre_t *** distance,nombre_t ** sommet, int NbSommet, nombre_t ** PointArret, int NbPointArret, nombre_t ** arrete, int NbArrete)
{

  *distance = AllocationMatrice(NbSommet + NbPointArret, NbSommet + NbPointArret);

  if(*distance)
    {

      InitialiserMatriceDistance(*distance, NbSommet + NbPointArret, NbSommet + NbPointArret);

      RemplirMatriceDistancePhase1(*distance, sommet, arrete, NbSommet, NbArrete);

      RemplirMatriceDistancePhase2(*distance , PointArret, sommet, arrete, NbSommet, NbPointArret, NbArrete);

    }
  else
    {

      printf("Erreur d'allocation de la matrice de distance!\n");

    }

}


/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* floyd                   Determine la distance minimal entre chaque pairs de sommets de la       */
/*                         matrice de distance.                                                    */
/*                                                                                                 */
/* En entrée             : distance     - Pointeur sur la mtrice de distance.                      */
/*                         NbSommet     - Nombre de sommet de l'entrepot.                          */
/*                         NbPointArret - Nombre de point d'arrets.                                */
/*                                                                                                 */
/* En sortie             : distance     - Pointeur sur la mtrice de distance.                      */
/*                                                                                                 */
/* Variable(s) locale(s) : i, j, k      - Variable de boucle.                                      */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


void floyd(nombre_t ** distance, int NbSommet, int NbPointArret)
{
  
  int i , j , k;
  
  for(k = 0; k < (NbSommet + NbPointArret); ++k)
    {
      
      for(i = 0; i < (NbSommet + NbPointArret); ++i)
	{
	  
	  for(j = 0; j < (NbSommet + NbPointArret); ++j)
	    {
	      
	      if(distance[i][j] > (distance[i][k] + distance[k][j]))
		{
		  
		  distance[i][j] = distance[i][k] + distance[k][j];
			
		}
	      
	    }
	  
	}
      
    }
	
}


/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* ExtraireMatriceDistancePA   Extrait la matrice distance juste entre les points d'arrets.        */
/*                                                                                                 */
/* En entrée             : distance     - Pointeur sur la mtrice de distance.                      */
/*                         NbSommet     - Nombre de sommet de l'entrepot.                          */
/*                         NbPointArret - Nombre de point d'arrets.                                */
/*                                                                                                 */
/* En sortie             : DistancePA   - Retourner un pointeur sur la matrice de distance entre   */
/*                                        les points d'arrets.                                     */
/*                                                                                                 */
/* Variable(s) locale(s) : i, j         - Variable de boucle.                                      */
/*                         DistancePA   - Retourner un pointeur sur la matrice de distance entre   */
/*                                        les points d'arrets.                                     */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


nombre_t **  ExtraireMatriceDistancePA(nombre_t ** distance, int NbSommet, int NbPointArret)
{

  int i, j;

  nombre_t ** DistancePA = AllocationMatrice(NbPointArret, NbPointArret);

  if(DistancePA)
    {

      InitialiserMatriceDistance(DistancePA, NbPointArret, NbPointArret);

      for(i = 0; i < NbPointArret; ++i)
	{

	  for(j = i + 1; j < NbPointArret; ++j)
	    {
	      
	      DistancePA[i][j] = distance[i + NbSommet][j + NbSommet];

	      DistancePA[j][i] = DistancePA[i][j];

	    }

	}

    }
  else
    {

      printf("Erreur d'alloctation de la matrice de distance des pouints d'arrets!\n");

    }

  return DistancePA;

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
