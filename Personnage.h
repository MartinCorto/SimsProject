#include <stdio.h>
#include <stdlib.h>
#define TAILLE_NOM 20
#define TAILLE_POSITION 50
#define TAILLE_SEXE 7
#define INTIT_CARACT 100


typedef struct caracteristiques
{
	int sante ;
	int argent;
	int sommeil;
	int moral;
	int faim;
	int hygiene;	 
} CARACT;


typedef struct personnage
{
	char nom[TAILLE_NOM];
	char prenom[TAILLE_NOM];
	CARACT caracteristiques;
	char position[TAILLE_POSITION]; 
	unsigned int sexe;
} PERSONNAGE;



void supprimerPersonnage(FILE* fichier);
void lister(FILE *fichier);
void affiche(FILE *fichier);
void afficherpersonnage(PERSONNAGE*personnage);
void fermer(FILE*fichier_ouvert);
void ajout(FILE *fichier);
FILE*ouvrir(char*nom_fichier);
int randPers(void);
void attribuerCaracteristiquesAlea(PERSONNAGE*personnage);
