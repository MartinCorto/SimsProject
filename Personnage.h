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
	CARACT caracteristiques;
	char position[TAILLE_POSITION][TAILLE_POSITION]; 
	unsigned int sexe;
	struct personnage *suiv;
} PERSONNAGE;


PERSONNAGE*rechercherParNom(PERSONNAGE*liste,char*nom);
PERSONNAGE*saisirElement(void);
void supprimerPersonnage(PERSONNAGE *liste);
void lister(PERSONNAGE *liste);
void affiche(PERSONNAGE *liste);
void afficherpersonnage(PERSONNAGE*liste);
void fermer(FILE*fichier_ouvert);
//~ void ajout(FILE *fichier);
PERSONNAGE*ajoutFin(PERSONNAGE *liste , PERSONNAGE *nouvelElement );
FILE*ouvrir(char*nom_fichier);
int randPers(void);
void attribuerCaracteristiquesAlea(PERSONNAGE*liste);
