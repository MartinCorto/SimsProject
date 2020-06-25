#include <stdio.h>
#include <stdlib.h>

#define TAILLE_NOM_EVT 30
#define TAILLE_NOM_LIEU 20

typedef struct evt
{
	char nom_evt[TAILLE_NOM_EVT];
	int duree_evt;
	int prix;
	int sante;
	int sommeil;
	int moral;
	int faim;
	int hygiene;
} EVT;



typedef struct
{
	char nom_lieu[TAILLE_NOM_LIEU];
	EVT event[10];
	int nb_evt;
} LIEU;

LIEU initialisationCuisine(void);
LIEU * initialisationChambre(LIEU * chambre);
LIEU * initialisationSalleDeBain(LIEU * salleDeBain);
LIEU * initialisationCellier(LIEU * cellier);
LIEU * initialisationExterieur(LIEU * exterieur);
LIEU * initialisationJardin(LIEU * jardin);
LIEU * initialisationSalon(LIEU * salon);
void initialisationLieux(LIEU place[7]);

void afficheLIEU(LIEU lieu);

EVT*insertionNewEvt(EVT *listeEvt, EVT *nouvelEvt);


void afficheListeEvent(EVT *liste);
void afficheEvent(EVT *event);

void attribuerCaracteristiquesEvt(LIEU * lieu, char * p_nomAction, int p_duree_evt, int p_faim, int p_hygiene, int p_moral, int p_prix, int p_sante, int p_sommeil);
