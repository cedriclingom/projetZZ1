#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./matrice_distance.h"


/*alloaction matrice de distance*/
nombre_t ** AllocationMatriceDistances(int NbSommet, int NbPointArret)
{

  int TailleMatrice = NbSommet + NbPointArret;

  nombre_t ** matrice = AllocationMatrice(TailleMatrice, TailleMatrice);
  
  return matrice;

}


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
	      
	      distance[i][j] = 0;

	    }

	}

    }

}


/*recherche de sommet de grille*/

void RechercheSommet(int * x, nombre_t ** sommet, int NbSommet, enum bool * ptrouver)
{

  int i = 0;

  *ptrouver = faux;
  
  while((i < (NbSommet-1)) && (sommet[i][0] != *x))
    {
      
      ++i;

    }

  if(i < (NbSommet -1))
    {

      *ptrouver = vrai;

    }

}



/*recherche d'arretes*/

void RechercheArrete(int a, nombre_t ** arrete, int NbArretes, enum bool *ptrouver, int * x, int * y)
{

  int i = 0;

  *ptrouver = faux;
  
  while ((i < NbArretes) && (arrete[i][0] != a))
    {
      
      ++i;
      
    }
  
  if(i < NbArretes)
    {
      
      *x = arrete[i][1];
      
      *y = arrete[i][2];
      
      *ptrouver = vrai;
      
    }
  
}


/*calcule de distance entre 2 sommets*/

double CalculDistance(int a, int b, int c, int d)
{

  return sqrt(pow((a - c) * 1.0, 2.0) + pow((b - d) * 1.0, 2.0));

}


void RechercheCouple(int a, int b, nombre_t ** arrete, int NbArretes, enum bool * ptrouver)
{

  int i = 0;

  enum bool trouver = (((arrete[i][1] == a) && (arrete[i][2] == b)) || ((arrete[i][1] == b) && (arrete[i][2] == a)));
  
  *ptrouver = faux;

  
  
  while((i < NbArretes) && !trouver)
    {

      trouver = (((arrete[i][1] == a) && (arrete[i][2] == b)) || ((arrete[i][1] == b) && (arrete[i][2] == a)));
           
      ++i;
 
    }

  if(i < NbArretes)
    {

      *ptrouver = vrai;

    }

}






/*création de matrice de distance*/

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



void RemplirMatriceDistance(nombre_t *** distance,nombre_t ** sommet, int NbSommet, nombre_t ** PointArret, int NbPointArret, nombre_t ** arrete, int NbArrete)
{

  *distance = AllocationMatriceDistances(NbSommet, NbPointArret);

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




/*Algorithme de Floyd*/
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




/*création de la matrice de distance juste entre les points d'arrets et le debut*/

nombre_t **  ExtraireMatriceDistancePA(nombre_t ** distance, int NbSommet, int NbPointArret)
{

  int i, j, dimension;

  nombre_t ** DistancePA = AllocationMatrice(NbPointArret, NbPointArret);

  if(DistancePA)
    {

      dimension = NbSommet + NbPointArret;

      for(i = NbSommet; i < dimension; ++i)
	{

	  for(j = i + 1; j < dimension; ++j)
	    {
	      
	      DistancePA[i - NbSommet][j - NbSommet] = distance[i][j];

	      DistancePA[j - NbSommet][i - NbSommet] = DistancePA[i - NbSommet][j - NbSommet];

	    }

	}

    }
  else
    {

      printf("Erreur d'alloctation de la matrice de distance des pouints d'arrets!\n");

    }

  return DistancePA;

}



