#include "Personnage.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


PERSONNAGE*saisirElement(void)
{
	PERSONNAGE*new=malloc(sizeof(PERSONNAGE));
	if( new == NULL )
	{
		printf("Erreur allocation memoire dans saisirElement()\n");
		return NULL;
	}
	printf("Saisir element\n");
	printf("nom : ");
	scanf("%s",new->nom);
	printf("sexe (H=1,F=2)  : ");
	scanf("%d",&new->sexe);
	printf("affichage de l'element saisi\n");
	attribuerCaracteristiquesAlea(new);
	afficherpersonnage(new);
	return new;
}

PERSONNAGE*ajoutFin(PERSONNAGE *liste , PERSONNAGE *nouvelElement )
{
	
	
	if (liste == NULL)
	{	/* cas d'une liste vide */
		
		nouvelElement->suiv = NULL;
		liste = nouvelElement;
	}
	else
	{	/* cas normal */
		PERSONNAGE *courant=liste;
/* contrairement a l'affichage on ne doit pas aller jusqu'a courant == NULL */
/* mais juste un cran avant car on veut avoir acces au contenu de courant  */
		while( courant->suiv != NULL ) 
		{
			/* on avance vers l'element suivant */
			courant = courant->suiv;
		}
		/* ici on est au bon endroit au dernier element */
		courant->suiv=nouvelElement;
		nouvelElement->suiv=NULL;
		
	}
	return liste;
}

		
	
	
	//~ printf("Ajout d'un nouveau personnage à la base de données\n");
	//~ /*memset memory set , force la valeur d'un champs de donnees */
	//~ memset(&new_perso,0,sizeof(new_perso));
	

	
	//~ printf("saisir le nom du personnage: ");
	//~ scanf("%s",new_perso.nom);
	
	//~ getchar();
	
	//~ printf("saisir le sexe du personnage ( H/F ) : ");
	//~ scanf("%c",&choix_sexe);getchar();
	//~ if( (choix_sexe == 'f') || (choix_sexe == 'F'))
	//~ {		
		//~ new_perso.sexe = 2;
		//~ printf("le personnage est une femme\n");
	//~ }else if( (choix_sexe = 'h') || (choix_sexe == 'H'))
	//~ {
		//~ new_perso.sexe = 1;
		//~ printf("le personnage est un homme\n");
	//~ }
	//~ attribuerCaracteristiquesAlea(&new_perso);
	//~ afficherpersonnage(&new_perso);
	//~ fwrite(&new_perso,sizeof(PERSONNAGE),1,fichier);
	//~ printf("personnage cree\n");	
//~ }

/* Fonction permettant d'ouvrir un fichier pour le modifier */
FILE*ouvrir(char*nom_fichier)
{
	FILE*f=NULL;
	//~ printf("ouverture du fichier [%s]\n",nom_fichier);
/* fopen mode a = append = "ajouter a la fin" ouvre le fichier s'il */
/* existe et place le pointeur a la fin si le fichier n'existe pas  */
/* le fichier est cree */
	f=fopen(nom_fichier,"a");
	fclose(f);
	f=fopen(nom_fichier,"r+");
	return f;	
}


/* Fonction permettant de fermer un fichier */
void fermer(FILE*fichier_ouvert)
{
	//~ printf("fermeture du fichier\n");
	fclose (fichier_ouvert);
}

void attribuerCaracteristiquesAlea(PERSONNAGE*personnage)
{
	if(personnage==NULL)return;
	personnage->caracteristiques.sante = randPers();
	personnage->caracteristiques.argent = randPers();
	personnage->caracteristiques.sommeil = randPers();
	personnage->caracteristiques.moral = randPers();
	personnage->caracteristiques.faim = randPers();
	personnage->caracteristiques.hygiene = randPers();
}

int randPers(void)
{
   static int first = 0;
   int min = 97;
   int max = 101;
   if (first == 0)
   {
      srand (time (NULL));
      first = 1;
   }
   return (rand()% (max-min)+min);
}

/* Fonction permettant d'afficher les coordonées d'un personnage */
void afficherpersonnage(PERSONNAGE*pers)
{
	if(pers==NULL)return;
	printf("Nom du personnage: %s\n",pers->nom);
	printf("santé du personnage: %d\n",pers->caracteristiques.sante);
	printf("argent du personnage: %d\n",pers->caracteristiques.argent);
	printf("sommeil du personnage: %d\n",pers->caracteristiques.sommeil);
	printf("moral du personnage: %d\n",pers->caracteristiques.moral);
	printf("faim du personnage: %d\n",pers->caracteristiques.faim);
	printf("hygiene du personnage: %d\n",pers->caracteristiques.hygiene);
}

PERSONNAGE*rechercherParNom(PERSONNAGE*liste,char*nom)
{
	if( liste == NULL )
	{
		printf("rechercherParNom impossible sur liste vide\n");
		return NULL;
	}
	
	PERSONNAGE*courant = liste;
	while( courant != NULL )
	{
		if( strcmp(courant->nom,nom) == 0 )
			return courant;
		courant = courant -> suiv ;
	}
	/* si o narrive ici c'est qu'on a pas trouver  */
	printf("Nom [%s] introuvable dans la liste\n",nom);
	return NULL;
}

/* Fonction permettant d'afficher les coordonées d'un personnage de la base en recherchant son nom ou son prénom */
void affiche(PERSONNAGE * liste)
{ 
	PERSONNAGE*elem=malloc(sizeof(PERSONNAGE));
	char nom_recherche[TAILLE_NOM];

	printf("saisi du nom du personnage à rechercher dans la BDD: ");
	scanf("%s",elem->nom);	
	elem = rechercherParNom(liste,elem);
	afficherpersonnage(elem);
}

/* Fonction permettant de lister tous les personnage de la base en affichant leurs informations */
void lister(PERSONNAGE *liste)
{
PERSONNAGE *courant = liste;
	if( liste == NULL )
	{
		printf("afficheListe impossible sur liste vide\n");
		return ;
	}
	while( courant != NULL ) /* tant qu'il reste des elements */
	{
		afficherpersonnage(courant);
		
		/* on avance vers l'element suivant */
		courant = courant->suiv;
	}
}

void supprimerPersonnage(PERSONNAGE* liste)
{
	PERSONNAGE*elem=malloc(sizeof(PERSONNAGE));
	char nom_recherche[TAILLE_NOM];
	//~ char const *old_FileName = "personnage.bin";
    //~ char *new_FileName = "personnage2.bin";
	//~ FILE *new_FilePersonnage=NULL;
	//~ new_FilePersonnage = ouvrir(new_FileName);

	printf("Supprimer un personnage de la base de données\n");
	
	
	
	printf("saisi du nom à supprimer : ");
	scanf("%s",elem->nom);
	getchar();
	
	elem = rechercherParNom(liste,elem);
	if( liste == NULL ){
		printf("suppression impossible dans liste vide");
		return NULL;}
	if( elem == NULL ){
		printf("suppression impossible d'element vide");
		return liste;}

	PERSONNAGE*tmp=NULL;
	if( elem == liste )
	{/* on essai de supprimer le premier element */
		tmp=liste;
		liste=elem->suiv;
		free(tmp);
		tmp=NULL;
		return liste;
	}
	
	

	/* on va parcourire la liste en regardanr les adresse */
	PERSONNAGE*courant=liste;
	PERSONNAGE*precedent=NULL;
	while(courant!=NULL)
	{	/* on a trouver la bonne adresse */
		if(courant == elem)
		{
			precedent->suiv=courant->suiv;
			free(courant);
			courant=NULL;
			return liste;
		}
		
		precedent=courant;
		courant=courant->suiv;
	}
	
	return ;
	
	
//~ /*positionnement du curseur au debut du ficher */
	//~ fseek(fichier ,0,SEEK_SET);
//~ /* on va lire des personnage du fichier un par un jusqu'à la fin du fichier*/
	//~ while(fread(&personnage,sizeof(PERSONNAGE),1,fichier)!=0)
	//~ {	
//~ /* pour chaque mode de recherche on va appliquer la bonne comparaison*/
		
			//~ if((strcmp(nom_recherche,personnage.nom)==0))
			//~ {
				//~ printf("personnage trouvees donc on ne fait rien\n");
			//~ }
		
		//~ else
		//~ {
			//~ fwrite(&personnage,sizeof(PERSONNAGE),1,new_FilePersonnage);
		//~ }	
	//~ }
	//~ fermer(fichier);
	//~ fermer(new_FilePersonnage);
	//~ remove(old_FileName);
    //~ rename(new_FileName, old_FileName);
    //~ ouvrir("personnage.bin");
//~ /* si on est arrive ici on n'a donc pas trouver le personnage */	
	//~ printf("Personnage introuvable \n");
}
