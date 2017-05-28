/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/*                                 grille.c                                                        */
/*                                                                                                 */
/* Role : Définitions des fonctions et procédures permettant la création de                        */
/*        l'entrepot et des point d'arrets.                                                        */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/






#include "./grille.h"





/*--------------------------------------------------------------------------------------------------*/
/*                                                                                                  */
/* CreationEntrepot           Premet la grille qui représente le skelete de l'entrepot.             */
/*                                                                                                  */
/* En entrée             : f             - Pointeur sur un fichier.                                 */
/*                         nb            - Pointeur sur la case mémoire contenant de le nombre de   */
/*                                         ligne de la matrice entrepot.                            */
/*                         PcodeCreation - Pointeur sur la case mémoire contenant vrai si la        */
/*                                         création c'est bien passé et faux sinon.                 */
/*                                                                                                  */
/* En sortie             : nb            - Pointeur sur la case mémoire contenant de le nombre de   */
/*                                         ligne de la matrice entrepot.                            */
/*                         PcodeCreation - Pointeur sur la case mémoire contenant vrai si la        */
/*                                         création c'est bien passé et faux sinon.                 */
/*                         matrice       - Retourne le pointeur de pointeur sur un entier.          */
/*                                                                                                  */
/* Variable(s) locale(s) : matrice       - Pointeur de pointeur sur un entier.                      */
/*                                                                                                  */
/*--------------------------------------------------------------------------------------------------*/


nombre_t ** CreationEntrepot(FILE * f, int * nb, enum bool * PcodeCreation)
{
  nombre_t ** matrice = NULL;
  
  *PcodeCreation = fscanf(f, "%d", nb);
  
  matrice = AllocationMatrice(*nb, NBCOL);
  
  if(matrice && *PcodeCreation)	                           /*si l'allocation et la lecture c'est bien passé*/	
    {
      
      FlireMatrice(matrice, *nb, NBCOL, f, PcodeCreation);
      
      if(*PcodeCreation)                                     /*si la lecture dans le fichier c'est bien passé*/
	{
	  
	  *PcodeCreation = vrai;

	}
      else
	{
	  
	  *PcodeCreation = faux;

	  printf("Erreur de lecture pour la matrice!\n");
	  
	}
      
    }
  
  return matrice;

}



/*--------------------------------------------------------------------------------------------------*/
/*                                                                                                  */
/* CreationArrete           Premet la création de la matrice contenant les arretes.                 */
/*                                                                                                  */
/* En entrée             : f             - Pointeur sur un fichier.                                 */
/*                         nb            - Pointeur sur la case mémoire contenant de le nombre de   */
/*                                         ligne de la matrice entrepot.                            */
/*                         PcodeCreation - Pointeur sur la case mémoire contenant vrai si la        */
/*                                         création c'est bien passé et faux sinon.                 */
/*                                                                                                  */
/* En sortie             : nb            - Pointeur sur la case mémoire contenant de le nombre de   */
/*                                         ligne de la matrice entrepot.                            */
/*                         PcodeCreation - Pointeur sur la case mémoire contenant vrai si la        */
/*                                         création c'est bien passé et faux sinon.                 */
/*                         matrice       - Retourne le pointeur de pointeur sur un entier.          */
/*                                                                                                  */
/* Variable(s) locale(s) : matrice       - Pointeur de pointeur sur un entier.                      */
/*                                                                                                  */
/*--------------------------------------------------------------------------------------------------*/



nombre_t ** CreationArrete(FILE * f, int * nb, enum bool *PcodeCreation)
{
  
  nombre_t ** matrice =  NULL;
	
  *PcodeCreation = fscanf(f,"%d", nb);
	
  matrice = AllocationMatrice(*nb, NBCOL);
	
  if(matrice && *PcodeCreation)                            /*si l'allocation et la lecture c'est bien passé*/
    {

      FlireMatrice(matrice, *nb, NBCOL, f, PcodeCreation);

       if(*PcodeCreation)                                     /*si la lecture dans le fichier c'est bien passé*/
	{
	  
	  *PcodeCreation = vrai;
	  
	}
      else
	{
	  
	  *PcodeCreation = faux;

	  printf("Erreur de lecture pour la matrice!\n");
	  
	}
	
    }
  
  return matrice;

}


/*--------------------------------------------------------------------------------------------------*/
/*                                                                                                  */
/* CreationArrete           Premet la création de la matrice contenant les arretes.                 */
/*                                                                                                  */
/* En entrée             : f             - Pointeur sur un fichier.                                 */
/*                         nb            - Pointeur sur la case mémoire contenant de le nombre de   */
/*                                         ligne de la matrice entrepot.                            */
/*                         PcodeCreation - Pointeur sur la case mémoire contenant vrai si la        */
/*                                         création c'est bien passé et faux sinon.                 */
/*                                                                                                  */
/* En sortie             : nb            - Pointeur sur la case mémoire contenant de le nombre de   */
/*                                         ligne de la matrice entrepot.                            */
/*                         PcodeCreation - Pointeur sur la case mémoire contenant vrai si la        */
/*                                         création c'est bien passé et faux sinon.                 */
/*                         matrice       - Retourne le pointeur de pointeur sur un entier.          */
/*                                                                                                  */
/* Variable(s) locale(s) : matrice       - Pointeur de pointeur sur un entier.                      */
/*                                                                                                  */
/*--------------------------------------------------------------------------------------------------*/


nombre_t ** CreationPointArret(FILE * f, int * nb, enum bool * PcodeCreation)
{

  nombre_t ** matrice = NULL;
  
  *PcodeCreation = fscanf(f, "%d", nb);
  
  matrice = AllocationMatrice(*nb, NBCOLPA);
  
  if(matrice && *PcodeCreation)
    
    {
      
      FlireMatrice(matrice, *nb, NBCOLPA, f, PcodeCreation);

       if(*PcodeCreation)                                     /*si la lecture dans le fichier c'est bien passé*/
	{
	  
	  *PcodeCreation = vrai;
	  
	}
      else
	{
	  
	  *PcodeCreation = faux;

	  printf("Erreur de lecture pour la matrice!\n");
	  
	}
      
    }
  
  return matrice;
  
}


void LectureFichier(char * NomFichier, nombre_t *** sommet, nombre_t *** arrete, nombre_t *** PointArret, int * NbSommet, int * NbArretes, int * NbPointArret, enum bool * PcodeLecture)
{

  FILE * f = fopen(NomFichier,"r");
  
  *PcodeLecture = vrai;                                            /*On suppose que la lecture se passera bien*/

  if(f != NULL)
    {
      
      *sommet = CreationEntrepot(f, NbSommet, PcodeLecture);
      
      if(*PcodeLecture)                                            /*si matrice entrepot est créer*/
	{

	  printf("Ceci est la matrice de l'entrepot!\n");
	  
	  AfficherMatrice(*sommet, *NbSommet, NBCOL);
	  
	  *arrete = CreationArrete(f, NbArretes, PcodeLecture);
	  
	  if(*PcodeLecture)                                        /*si la matrice des arretes est créer*/
	    {
	      
	       printf("Ceci est la matrice des arretes!\n");
	       
	       AfficherMatrice(*arrete, *NbArretes, NBCOL);
	      
	       *PointArret = CreationPointArret(f, NbPointArret, PcodeLecture);
	       
	       printf("Ceci est la matrice des points d'arrets!\n");
	       
	       AfficherMatrice(*PointArret, *NbPointArret, NBCOLPA);	  
	      
	    }
	  else
	    {
	     
	      *PcodeLecture = faux;
 
	      printf("Erreur de création de la matrice des arretes!\n");

	    }

	}
      else
	{

	  *PcodeLecture = faux;
	  
	  printf("Erreur de création de la matrice Entrepot!\n");
	  
	}

        fclose(f);
      
    }

}



/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* CreationListe           Crée une liste contigue.                                                */
/*                                                                                                 */
/* En entrée             : matrice - Pointeur de tete de liste contigue de pointeurs de tete de    */
/*                                   liste contigues.                                              */
/*                         taille  - Taille d'une liste contigue.                                  */
/*                                                                                                 */
/* En sortie             : pliste  - Retourne l'adresse de tete de liste contigue.                 */
/*                                                                                                 */
/* Variable(s) locale(s) : i       - Variable de boucle.                                           */
/*                         pliste  - Pointeur de tete de liste contigue.                           */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/



nombre_t * CreationListe(nombre_t ** matrice, int taille)
{

  int i;
  
  nombre_t * pliste = AllocationTableau(taille);

  if(pliste)
    {

      for(i = 0; i < taille; ++i)
	{

	  pliste[i].entier = matrice[i][0].entier;

	}

    }

  return pliste;

}





/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* CreationGrille          Crée la grille sous forme de liste.                                     */
/*                                                                                                 */
/* En entrée             : m1,m2,m3      - Pointeur de tete de liste contigue de pointeurs de tetes*/
/*                                         de liste contigues.                                     */
/*                         nb1,nb2,nb3   - Nombre de lignes de respectivement m1, m2 et m3.        */
/*                         PcodeCreation - Pointeur sur une case mémoire contenant vrai si la      */
/*                                         création c'est bien passée et faux sinon.               */
/*                                                                                                 */
/* En sortie             : PcodeCreation - Pointeur sur une case mémoire contenant vrai si la      */
/*                                         création c'est bien passée et faux sinon.               */
/*                         pgrille       - Retourne l'adresse de la structure grille.              */
/*                                                                                                 */
/* Variable(s) locale(s) : pgrille       - Pointeur sur une structure qui représente la grille.    */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/


grille_t * CreationGrille(nombre_t ** m1, nombre_t ** m2, nombre_t ** m3, int nb1, int nb2, int nb3, enum bool * PcodeCreation)
{

  grille_t * pgrille = (grille_t *)malloc(sizeof(grille_t));

  *PcodeCreation = vrai;                                             /*on suppose que le création se passera bien*/

  if(pgrille)
    {

      pgrille->SommetEntrepot = CreationListe(m1, nb1);              /*crée la liste des sommet de l'entrepot*/    

      if(pgrille->SommetEntrepot)         
	{
	  
	  pgrille->arrete = CreationListe(m2, nb2);                 /*crée la liste des arretes*/

	  if(pgrille->arrete)
	    {

	      pgrille->PointArret = CreationListe(m3, nb3);         /*crée la liste des points d'arrets*/

	    }
	  else
	    {

	      *PcodeCreation = faux;

	      free(pgrille->SommetEntrepot);

	      free(pgrille->arrete);

	    }

	}
      else
	{

	  *PcodeCreation = faux;

	  free(pgrille->SommetEntrepot);

	}

    }
  else
    {

      *PcodeCreation = faux;

    }

  return pgrille;

}
	  

/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* LibererGrille            Permet de liberer la grille.                                           */
/*                                                                                                 */
/* En entrée             : ppgrille - Pointeur de pointeur de grille.                              */
/*                                                                                                 */
/* En sortie             : ppgrille - Pointeur de pointeur de grille.                              */
/*                                                                                                 */
/* Variable(s) locale(s) :            Rien en variable locale.                                     */
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/
  

void LibererGrille(grille_t ** ppgrille)
{

  free((*ppgrille)->SommetEntrepot);

  free((*ppgrille)->arrete);

  free((*ppgrille)->PointArret);

  free(*ppgrille);

  *ppgrille = NULL;

}




/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/**/
/*                                                                                                 */
/* En entrée             : */
/*                                                                                                 */
/* En sortie             :*/
/*                                                                                                 */
/* Variable(s) locale(s) :*/
/*                                                                                                 */
/*-------------------------------------------------------------------------------------------------*/
