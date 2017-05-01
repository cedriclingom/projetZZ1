/*------------------------------------------------------------------------------------------------------*/
/*                                                                                                      */
/*                                              tableau.c                                               */
/*                                                                                                      */
/* Role  :        Définitions des procédures et fonctions liées à la manipulation des tableaux.         */
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/





#include "./tableau.h"






/*------------------------------------------------------------------------------------------------------*/
/* AllocationTableau            Alloue un tableau.                                                      */
/*                                                                                                      */
/* En entrée             : taille - La taille du tableau.                                               */
/*                                                                                                      */
/* En sortie             : tab    - Pointeur sur un tableau alloué.                                     */
/*                                                                                                      */
/* Variable(s) locale(s) : tab    - Pointeur sur un tableau alloué.                                     */              
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/



nombre_t * AllocationTableau(int taille)
{

  nombre_t * tab = (nombre_t *)malloc(taille * sizeof(nombre_t));

  return tab;

}


/*------------------------------------------------------------------------------------------------------*/
/* AfficherTableau            Affiche le contenu d'un tableau.                                          */
/*                                                                                                      */
/* En entrée             : taille - La taille du tableau.                                               */
/*                         tab    - Pointeur sur le tableau à afficher.                                 */
/*                                                                                                      */
/* En sortie             :          Rien en sortie.                                                     */
/*                                                                                                      */
/* Variable(s) locale(s) : i      - Variable de boucle.                                                 */              
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/


void AfficherTableau(nombre_t * tab, int taille)
{

  int i;

  printf("Le contenu de mon tableau est:\n");

  printf("[ ");

  for(i = 0; i < taille - 1; ++i)
    {

      printf("%d, ", tab[i].entier);

    }

  printf("%d ]\n", tab[i].entier);

}
