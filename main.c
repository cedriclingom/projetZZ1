#include "./matrice.h"
#include "./grille.h"

int main()
{
	nombre_t nb_sommet = 0;
	
	nombre_t nb_arretes = 0;
	
	nombre_t nb_pt_arret = 0;

	nombre_t ** sommet = NULL;

	nombre_t ** arrete = NULL;

	nombre_t ** pt_arret = NULL;

	FILE * fichier = fopen("entrepot.txt","r");
	
	if(fichier){

		sommet = creationEntrepot(fichier, &nb_sommet);
		
		arrete = creationArrete(fichier, &nb_arretes);

		pt_arret = creationPointArret(fichier, &nb_pt_arret);
		
		LiberationMatrice(&sommet, nb_sommet);

		LiberationMatrice(&arrete, nb_arretes);

		LiberationMatrice(&pt_arret, nb_pt_arret);

	}
	fclose(fichier);

  return 0;

}
