#include "./matrice.h"

int main()
{
	nombre_t nb_sommet=0;
	nombre_t ** sommet = NULL;
	FILE * fichier = fopen("donnee.txt","r");
	
	if(fichier){
		sommet=creationMatrice3(fichier,&nb_sommet);
  return 0;

}
