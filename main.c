#include "./matrice.h"
#include "./grille.h"

int main()
{
  int NbSommet, NbArretes, NbPointArret;
  
  enum bool CodeLecture;
  
  nombre_t ** sommet = NULL, ** arrete = NULL, ** PointArret = NULL;
  
  LectureFichier("./entrepot.txt", sommet, arrete, PointArret, &NbSommet, &NbArretes, &NbPointArret, &CodeLecture);
  
  LiberationMatrice(&sommet, NbSommet);
  
  LiberationMatrice(&arrete, NbArretes);
  
  LiberationMatrice(PointArret, NbPointArret);  
  
  return 0;
  
}
