#include "Personnage.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
void ajout(FILE *fichier)
{
	PERSONNAGE new_perso;
	char choix;
	char choix_sexe;
	
	printf("Ajout d'un nouveau personnage à la base de données\n");
	/*memset memory set , force la valeur d'un champs de donnees */
	memset(&new_perso,0,sizeof(new_perso));
	
	/* pour ajouter un nouveau personnage on le place a la fin*/
	fseek(fichier,0,SEEK_END);
	
	printf("saisir le nom du personnage: ");
	scanf("%s",new_perso.nom);
	printf("saisir le prenom du personnage: ");
	scanf("%s",new_perso.prenom);
	
	getchar();
	
	printf("saisir le sexe du personnage ( H/F ) : ");
	scanf("%c",&choix_sexe);getchar();
	if( choix_sexe == 'f' || choix_sexe == 'F')
	{		
		new_perso.sexe = 'femme';
		printf("le personnage est une femme\n");
	}else if( choix_sexe = 'h' || choix_sexe == 'H')
	{
		new_perso.sexe = 'homme';
		printf("le personnage est un homme\n");
	}
	afficherpersonnage(&new_perso);
	if( DEMANDE_CONFIRMATION == 1)
	{
		printf("Confirmer l'ajout du personnage à la base? ( Y/n ) : ");
		scanf("%c",&choix);getchar();
		if( choix == 'n' || choix == 'N')
		{
			printf("Abandon de l'ajout du personnage à la base de données \n");
			return;
		}
	}
	fwrite(&new_perso,sizeof(PERSONNAGE),1,fichier);
	printf("personnage cree\n");	
}

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

/* Fonction permettant d'afficher les coordonées d'un personnage */
void afficherpersonnage(PERSONNAGE*personnage)
{
	if(personnage==NULL)return;
	printf("Nom du personnage: %s\n",personnage->nom);
	printf("Prenom du personnage: %s\n",personnage->prenom);
	printf("santé du personnage: %d\n",personnage->caracteristique.sante);
	printf("argent du personnage: %d\n",personnage->caracteristique.argent);
	printf("sommeil du personnage: %d\n",personnage->caracteristique.sommeil);
	printf("moral du personnage: %d\n",personnage->caracteristique.moral);
	printf("faim du personnage: %d\n",personnage->caracteristique.faim);
	printf("hygiene du personnage: %d\n",personnage->caracteristique.hygiene);
}

/* Fonction permettant d'afficher les coordonées d'un personnage de la base en recherchant son nom ou son prénom */
void affiche(FILE *fichier)
{
	PERSONNAGE personnage;
	char nom_recherche[TAILLE_NOM];
	char prenom_recherche[TAILLE_NOM];
	char choix;
	printf("Affiche les informations d'un personnage en fonction d'un critère de recherche\n");
	
	printf("Choix du critere de recherche d'un personnage :\n");
	printf("1 : nom | 2 prenom \n");
	scanf("%c",&choix);getchar();
	switch(choix)
	{
		case '1':
			printf("saisi du nom du personnage à rechercher dans la BDD: ");
			scanf("%s",nom_recherche);getchar();
			break;
			
		case '2':
			printf("saisi du prenom du personnage à rechercher dans la BDD : ");
			scanf("%s",prenom_recherche);getchar();
			break;
			
		default :
			printf("Critere de recherche inconnu : abandon \n");
			return;
	}
	
/*positionnement du curseur au debut du ficher */
	fseek(fichier ,0,SEEK_SET);
/* on va lire des personnage du fichier un par un jusqua la fin du fichier*/
	while(fread(&personnage,sizeof(PERSONNAGE),1,fichier)!=0)
	{	
/* pour chaque mode de recherche on va appliquer la bonne comparaison*/
		if(choix == '1')
		{
			if(strcmp(nom_recherche,personnage.nom)==0)
			{
				afficherpersonnage(&personnage);
				return;
			}
		}
		else if ( choix == '2')
		{
			if(strcmp(prenom_recherche,personnage.prenom)==0)
			{
				afficherpersonnage(&personnage);
				return;
			}
		}
	}
/* si on est arrive ici on n'a donc pas trouver le personnage */	
	printf("Personnage introuvable dans la base de données\n");
	
}

/* Fonction permettant de lister tous les personnage de la base en affichant leurs informations */
void lister(FILE *fichier)
{
	PERSONNAGE personnage;
	int nombre_personnage=0;
	printf("lister les caractéristiques des personnages de la base de données\n");
	/*positionnement du curseur au debut du ficher */
	fseek(fichier ,0,SEEK_SET);
/* on va lire des personnage du fichier un par un jusqua la fin du fichier*/
	while(fread(&personnage,sizeof(PERSONNAGE),1,fichier)!=0)
	{	
		afficherpersonnage(&personnage);
		nombre_personnage++;
	}
	printf("il y a %d personnages\n",nombre_personnage);
}

void supprimerPersonnage(FILE* fichier){
	PERSONNAGE personnage;
	char nom_recherche[TAILLE_NOM];
	char prenom_recherche[TAILLE_NOM];
	char choix;
	char const *old_FileName = "personnage.bin";
    char *new_FileName = "personnage2.bin";
	FILE *new_FilePersonnage=NULL;
	new_FilePersonnage = ouvrir(new_FileName);

	printf("Supprimer un personnage de la base de données\n");
	
	printf("choix du critere de recherche pour supprimer un personnage :\n");
	printf("1 : nom | 2 prenom \n");
	scanf("%c",&choix);getchar();
	switch(choix)
	{
		case '1':
			printf("saisi du nom à supprimer : ");
			scanf("%s",nom_recherche);
			getchar();
			break;
			
		case '2':
			printf("saisi du prenom a supprimer : ");
			scanf("%s",prenom_recherche);
			getchar();
			break;
			
		default :
			printf("critere inconnu : abandon \n");
			return;
	}
	
/*positionnement du curseur au debut du ficher */
	fseek(fichier ,0,SEEK_SET);
/* on va lire des personnage du fichier un par un jusqu'à la fin du fichier*/
	while(fread(&personnage,sizeof(PERSONNAGE),1,fichier)!=0)
	{	
/* pour chaque mode de recherche on va appliquer la bonne comparaison*/
		if(choix == '1')
		{
			if((strcmp(nom_recherche,personnage.nom)==0) || (strcmp(prenom_recherche,personnage.prenom)==0))
			{
				printf("personnage trouvees donc on ne fait rien\n");
			}
		}
		else
		{
			fwrite(&personnage,sizeof(PERSONNAGE),1,new_FilePersonnage);
		}	
	}
	fermer(fichier);
	fermer(new_FilePersonnage);
	remove(old_FileName);
    rename(new_FileName, old_FileName);
    ouvrir("personnage.bin");
/* si on est arrive ici on n'a donc pas trouver le personnage */	
	printf("Personnage introuvable \n");
}
