#include "./matrice.h"
#include "./grille.h"

int main(int argc, char ** argv)
{
  int NbSommet, NbArretes, NbPointArret;
  
  enum bool CodeLecture, CodeCreation;

  grille_t * pgrille = NULL;
  
  nombre_t ** sommet = NULL, ** arrete = NULL, ** PointArret = NULL;
  
  if(argc == 2)
    {
  
      LectureFichier(argv[1], &sommet, &arrete, &PointArret, &NbSommet, &NbArretes, &NbPointArret, &CodeLecture);

      if(CodeLecture)
	{

	  pgrille = CreationGrille(sommet, arrete, PointArret, NbSommet, NbArretes, NbPointArret, &CodeCreation);

	  if(CodeCreation)
	    {

	      printf("Les sommets de l'entropot!\n");

	      AfficherTableau(pgrille->SommetEntrepot, NbSommet);

	      printf("Les arretes!\n");

	      AfficherTableau(pgrille->arrete, NbArretes);

	      printf("Les Points d'arrets!\n");

	      AfficherTableau(pgrille->PointArret, NbPointArret);

	      LibererGrille(&pgrille);

	    }
  
	  LiberationMatrice(&sommet, NbSommet);
      
	  LiberationMatrice(&arrete, NbArretes);
      
	  LiberationMatrice(&PointArret, NbPointArret);

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
