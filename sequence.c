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
  
  float min, dist;

  min = CalculDistance(0, 0, PointArret[0][2].entier, PointArret[0][3].entier);
  
  indice = 0;
  
  for(i = 1; i < NbPointArret; ++i)
    {
      
      dist = CalculDistance(0, 0, PointArret[i][2].entier, PointArret[i][3].entier);
      
      if(dist < min)
	{
	  
	  min = dist;
	  
	  indice = i;
	  
	}
      
    }
  
  echange(&(ListPA[0].entier), &(ListPA[indice].entier));
  
  for(i = 0; i < NbPointArret; ++i)
    {
      
      for(j = i + 1; j < NbPointArret; ++j)
	{
	  
	  if(j - i == 1)
	    {
	      
	      min = DistancePA[ListPA[i].entier][ListPA[j].entier].reel;
	      
	      indice = j;
	      
	    }
	  else
	    {
	      
	      dist = DistancePA[ListPA[i].entier][ListPA[j].entier].reel;
	      
	      if(dist < min)
		{
		  
		  min = dist;
		  
		  indice = j;
		  
		}
	      
	    }
	  
	}
      
      echange(&(ListPA[i + 1].entier), &(ListPA[indice].entier));
      
    }

}

/*Affiche la séquence*/

void AfficheSequence(grille_t * pgrille, nombre_t ** DistancePA, int NbPointArret)
{

  int i;

  float som = 0;

  printf("La meilleur séquence est:\n");

  AfficherTableau(pgrille->PointArret, NbPointArret);

  for(i = 0; i < NbPointArret - 1; ++i)
    {

      som += DistancePA[pgrille->PointArret[i].entier][pgrille->PointArret[i + 1].entier].reel;

    }

  printf("La distance total minimal est de: %f\n", som);

}
  
