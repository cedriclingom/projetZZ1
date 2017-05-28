#include "./sequence.h"

int main(int argc, char ** argv)
{

  int NbSommet, NbArrete, NbPointArret;
  
  enum bool CodeLecture, CodeCreation;

  grille_t * pgrille = NULL;
  
  nombre_t ** sommet = NULL, ** arrete = NULL, ** PointArret = NULL, ** distance = NULL, ** DistancePA = NULL;
  
  if(argc == 2)
    {
  
      LectureFichier(argv[1], &sommet, &arrete, &PointArret, &NbSommet, &NbArrete, &NbPointArret, &CodeLecture);

      if(CodeLecture)
	{

	  pgrille = CreationGrille(sommet, arrete, PointArret, NbSommet, NbArrete, NbPointArret, &CodeCreation);

	  if(CodeCreation)
	    {

	      printf("Les sommets de l'entropot!\n");

	      AfficherTableau(pgrille->SommetEntrepot, NbSommet);

	      printf("Les arretes!\n");

	      AfficherTableau(pgrille->arrete, NbArrete);

	      printf("Les Points d'arrets!\n");

	      AfficherTableau(pgrille->PointArret, NbPointArret);

	      RemplirMatriceDistance(&distance, sommet, NbSommet, PointArret, NbPointArret, arrete, NbArrete);

	      AfficherMatrice2(distance, NbSommet + NbPointArret, NbSommet + NbPointArret);

	      floyd(distance, NbSommet, NbPointArret);

	      AfficherMatrice2(distance, NbSommet + NbPointArret, NbSommet + NbPointArret);

	      DistancePA = ExtraireMatriceDistancePA(distance, NbSommet, NbPointArret);

	      AfficherMatrice2(DistancePA, NbPointArret, NbPointArret);

	      SequenceDistanceMin(DistancePA, PointArret, pgrille->PointArret, NbPointArret);

	      AfficheSequence(pgrille, DistancePA, NbPointArret);

	      LibererGrille(&pgrille);

	    }
  
	  LiberationMatrice(&sommet, NbSommet);
      
	  LiberationMatrice(&arrete, NbArrete);
      
	  LiberationMatrice(&PointArret, NbPointArret);

	  LiberationMatrice(&distance, NbSommet + NbPointArret);

	}
      else
	{

	  printf("Erreur de lecture à partir d'un fichier!\n");

	}

    }
  else
    {

      printf("Erreur vous avez qu'à deux arguments!\n");

    }
  
  return 0;
  
}
