#include "Personnage.h"
#include <stdio.h>
#include <string.h>

void ajout(FILE *fichier)
{
	PERSONNAGE new_perso;
	char choix;
	char choix_sexe;
	
	printf("Ajout d'un nouveau client à la base de données\n");
	/*memset memory set , force la valeur d'un champs de donnees */
	memset(&new_perso,0,sizeof(new_perso));
	
	/* pour ajouter un nouveau client on le place a la fin*/
	fseek(fichier,0,SEEK_END);
	
	printf("saisir le nom du client: ");
	scanf("%s",new_perso.nom);
	printf("saisir le prenom du client: ");
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


/* Fonction permettant d'afficher les coordonées d'un client */
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
