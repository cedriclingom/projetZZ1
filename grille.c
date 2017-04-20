#include "./grille.h"


nombre_t ** creationEntrepot(FILE * f, nombre_t * nb)
{
	int * CodeLecture;

	int ** matrice = NULL;
	
	int i,j;
	
	fscanf(fichier,"%d",nb);
	
	matrice = AllocationMatrice(nb, NBCOL);
	
	if(matrice)
		
	{
	
		FlireMatrice(matrice, nb, NBCOL, f, CodeLecture);
		
		AfficherMatrice(matrice, nb, NBCOL);
		
	}
		
	return matrice;
}

nombre_t ** creationArrete(FILE * f, nombre_t * nb)
{
  
  int i,j;

  int CodeLecture;
  
  int ** matrice =  AllocationMatrice(*nb, NBCOL);
	
  if(matrice)
    {

      fscanf(fichier,"%d",nb);
      
      FlireMatrice(matrice, *nb, NBCOL, f, &CodeLecture);
      
      AfficherMatrice(matrice, *nb, NBCOL);
	
    }
  
  return matrice;

}

nombre_t ** creationPointArret(FILE * f, nombre_t * nb)
{
	int * CodeLecture;

	int ** matrice = NULL;

	int i,j;

	fscanf(fichier,"%d",nb);

	matrice = AllocationMatrice(nb, NBCOLPA);

	if(matrice)
		
	{
	
		FlireMatrice(matrice, nb, NBCOLPA, f, CodeLecture);
		
		AfficherMatrice(matrice, nb, NBCOLPA);
		
	}

	return matrice;
}


/*creation de la liste des sommets de l'entrepot*/
/*création de la liste des arretes*/
/*création de la liste des points d'arrets*/
