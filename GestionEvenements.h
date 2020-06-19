#include <stdio.h>
#include <stdlib.h>



typedef struct evt
{
	char nom_;
	int duree_evt;
	int prix;
} EVT;



typedef struct
{
	char nom_lieu[];
	EVT * action;
	int nb_evt;
} LIEU;

//~ void afficheListeEvent(EVT *liste);
//~ void afficheElementEvent(EVT *event);

//~ void ajouterEvenement(FILE *fichier_evenement);
//~ EVT*insertionAlphaEvent(EVT *liste, EVT *nouvelElement);

//~ FILE*ouvrirEvenements(char*nom_fichier);
//~ void fermerEvenements(FILE*fichier_ouvert);
