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
	struct EVT * event_suiv;
} EVT;



typedef struct
{
	char nom_lieu[TAILLE_NOM_LIEU];
	//~ struct EVT * event_suiv;
	EVT * event;
	int nb_evt;//allocation dynamique du nombre d'event
} LIEU;

void initialisationEvenements(void);
void afficheLIEU(LIEU lieu);

EVT*insertionNewEvt(EVT *listeEvt, EVT *nouvelEvt);


void afficheListeEvent(EVT *liste);
void afficheEvent(EVT *event);

EVT attribuerCaracteristiquesEvt(EVT evt, char * p_nomAction, int p_duree_evt, int p_faim, int p_hygiene, int p_moral, int p_prix, int p_sante, int p_sommeil);
//~ void afficheElementEvent(EVT *event);

//~ void ajouterEvenement(FILE *fichier_evenement);
//~ EVT*insertionAlphaEvent(EVT *liste, EVT *nouvelElement);

//~ FILE*ouvrirEvenements(char*nom_fichier);
//~ void fermerEvenements(FILE*fichier_ouvert);
