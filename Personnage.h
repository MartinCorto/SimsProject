#include <stdio.h>
#include <stdlib.h>
#define TAILLE_NOM 20
#define TAILLE_POSITION 50
#define TAILLE_SEXE /*ENORME MDRRRRRRRRRRRRRRRRRRRRRRRRRR*/7
#define INTIT_CARACT 100
typedef struct
{
	char nom[TAILLE_NOM];
	char prenom[TAILLE_NOM];
	CARACT caracteristiques;
	char position[TAILLE_POSITION]; 
	char sexe[TAILLE_SEXE];
} PERSONNAGE;

typedef struct
{
	int sante = INTIT_CARACT;
	int argent = INTIT_CARACT;
	int sommeil = INTIT_CARACT;
	int moral = INTIT_CARACT;
	int faim = INTIT_CARACT;
	int hygiene = INTIT_CARACT;	 
} CARACT;


void supprimerPersonnage(FILE* fichier);
void lister(FILE *fichier);
void affiche(FILE *fichier);
void afficherpersonnage(PERSONNAGE*personnage);
void fermer(FILE*fichier_ouvert);
void ajout(FILE *fichier);
FILE*ouvrir(char*nom_fichier);
