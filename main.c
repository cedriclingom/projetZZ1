/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/*                                             main.c                                              */
/*                                                                                                 */
/* Role : Contient une fonction la fonction principal faisant appelle à d'autres fonctions et      */
/*        procédures permettant traitement dans le cadre de la détermination de la meilleur        */
/*        séquence de point d'arrets de distance minimal.                                          */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include "./sequence.h"



/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* main                    Permet determiner la meilleur séquence de points d'arrets à partir      */
/*                         données d'entrepot contenu dans un fichier.                             */
/*                                                                                                 */
/* En entrée             : argc         - Le nombre d'arguments passé en ligne de commande.        */
/*                         argv         - Pointeur de pointeur de chaine de caractères (arguments).*/
/*                                                                                                 */
/* En sortie             :                Retourne 0 si tout c'est bien passé bien.                */
/*                                                                                                 */
/* Variable(s) locale(s) : NbSommet     - Le nombre de sommets.                                    */
/*                         NbArrete     - Le nombre d'arretes.                                     */
/*                         NbPointArret - Le nombre de points d'arrets.                            */
/*                         CodeLecture  - Contient vrai si la lecture à partir du fichier c'est    */
/*                                        passé et faux sinon.                                     */
/*                         CodeCreation - Contient vrai si la creation les listes de somets de la  */
/*                                        grille, d'arretes et de points d'arrets à été crée et    */
/*                                        faux sinon.                                              */
/*                         pgrille      - Pointeur sur une structure de grille composé d'un        */
/*                                        ensemble de sommets de base, d'arretes et de point       */
/*                                        d'arrets.                                                */
/*                         sommet       - Pointeur sur une matrice de sommet.                      */
/*                         arrete       - Pointeur sur une matrice d'arretes.                      */
/*                         PointArret   - Pointeur sur une matrice de points d'arrets.             */
/*                         distance     - Pointeur sur une matrice de disatnce.                    */
/*                         DistancePA   - Pointeur sur une matrice de distance entre points        */
/*                                        d'arrets.                                                */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


int main(int argc, char ** argv)
{

  int NbSommet, NbArrete, NbPointArret;
  
  enum bool CodeLecture, CodeCreation;

  grille_t * pgrille = NULL;
  
  nombre_t ** sommet = NULL, ** arrete = NULL, ** PointArret = NULL, ** distance = NULL, ** DistancePA = NULL;
  
  if(argc == 2)              /*si le nombre d'argument égale à 2*/
    {
  
      LectureFichier(argv[1], &sommet, &arrete, &PointArret, &NbSommet, &NbArrete, &NbPointArret, &CodeLecture);

      if(CodeLecture)        /*si la lecture c'est bien passé*/ 
	{

	  pgrille = CreationGrille(sommet, arrete, PointArret, NbSommet, NbArrete, NbPointArret, &CodeCreation);

	  if(CodeCreation)   /*si la création des listes c'est bien passé*/
	    {

	      printf("Les sommets de l'entropot sont:\n");

	      AfficherTableau(pgrille->SommetEntrepot, NbSommet);

	      printf("Les arretes sont:\n");

	      AfficherTableau(pgrille->arrete, NbArrete);

	      printf("Les Points d'arrets sont:\n");

	      AfficherTableau(pgrille->PointArret, NbPointArret);

	      RemplirMatriceDistance(&distance, sommet, NbSommet, PointArret, NbPointArret, arrete, NbArrete);

	      printf("Le contenu de la matrice de distance:\n");

	      AfficherMatrice(distance, NbSommet + NbPointArret, NbSommet + NbPointArret);

	      floyd(distance, NbSommet, NbPointArret);

	      printf("Le contenu de la matrice de distance après utilisation de floyd:\n");

	      AfficherMatrice(distance, NbSommet + NbPointArret, NbSommet + NbPointArret);

	      DistancePA = ExtraireMatriceDistancePA(distance, NbSommet, NbPointArret);

	      printf("Le contenu de la matrice de distance entre les points d'arrets:\n");

	      AfficherMatrice(DistancePA, NbPointArret, NbPointArret);

	      SequenceDistanceMin(DistancePA, PointArret, pgrille->PointArret, NbPointArret);

	      AfficheSequence(pgrille, DistancePA, NbPointArret);

	      LibererGrille(&pgrille);

	    }
  
	  LiberationMatrice(&sommet, NbSommet);
      
	  LiberationMatrice(&arrete, NbArrete);
      
	  LiberationMatrice(&PointArret, NbPointArret);

	  LiberationMatrice(&distance, NbSommet + NbPointArret);

	  LiberationMatrice(&DistancePA, NbPointArret);

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
