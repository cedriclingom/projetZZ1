/*-----------------------------------------------------------------------------------*/
/*                                                                                   */
/*                                 grille.c                                          */
/*                                                                                   */
/* Role : Définitions des fonctions et procédures permettant la création de          */
/*        l'entrepot et des point d'arrets.                                          */
/*                                                                                   */
/*-----------------------------------------------------------------------------------*/






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


void LectureFichier(char * NomFichier, nombre_t ** sommet, nombre_t ** arrete, nombre_t ** PointArret, int * NbSommet, int * NbArretes, int * NbPointArret, enum bool * PcodeLecture)
{

  FILE * f = fopen(NomFichier,"r");
  
  *PcodeLecture = vrai;                                            /*On suppose que la lecture se passera bien*/

  if(f != NULL)
    {
      
      sommet = CreationEntrepot(f, NbSommet, PcodeLecture);
      
      if(*PcodeLecture)                                            /*si matrice entrepot est créer*/
	{

	  printf("Ceci est la matrice de l'entrepot!\n");
	  
	  AfficherMatrice(sommet, *NbSommet, NBCOL);
	  
	  arrete = CreationArrete(f, NbArretes, PcodeLecture);
	  
	  if(*PcodeLecture)                                        /*si la matrice des arretes est créer*/
	    {
	      
	       printf("Ceci est la matrice des arretes!\n");
	       
	       AfficherMatrice(arrete, *NbArretes, NBCOL);
	      
	       PointArret = CreationPointArret(f, NbPointArret, PcodeLecture);
	       
	       printf("Ceci est la matrice des points d'arrets!\n");
	       
	       AfficherMatrice(PointArret, *NbPointArret, NBCOLPA);	  
	      
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
/*creation de la liste des sommets de l'entrepot*/
/*création de la liste des arretes*/
/*création de la liste des points d'arrets*/
