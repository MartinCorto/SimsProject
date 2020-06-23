#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GestionEvenements.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>




LIEU * initialisationCuisine(LIEU * cuisine)
{
	cuisine->event =  malloc(4*sizeof(EVT*));
	strcpy(cuisine->nom_lieu,"Cuisine");
	cuisine->nb_evt = 4;
	
	EVT * evtCuisine1 =malloc(sizeof(EVT));
	EVT * evtCuisine2 =malloc(sizeof(EVT));
	EVT * evtCuisine3 =malloc(sizeof(EVT));
	EVT * evtCuisine4 =malloc(sizeof(EVT));
	
	strcpy(evtCuisine1->nom_evt, "Faire à manger");
	evtCuisine1->duree_evt = 1;
	evtCuisine1->sante = 5;
	evtCuisine1->prix = 0;
	evtCuisine1->sommeil = 0;
	evtCuisine1->moral = 0;
	evtCuisine1->faim = 5;
	evtCuisine1->hygiene = 1;
	cuisine->event[0] = *evtCuisine1;
	
	strcpy(evtCuisine2->nom_evt, "Manger");
	evtCuisine2->duree_evt = 1;
	evtCuisine2->sante = 1;
	evtCuisine2->prix = 0;
	evtCuisine2->sommeil = 3;
	evtCuisine2->moral = -5;
	evtCuisine2->faim = 2;
	evtCuisine2->hygiene = 2;
	cuisine->event[1] = *evtCuisine2;
	
	strcpy(evtCuisine3->nom_evt, "Boire un verre d'eau");
	evtCuisine3->duree_evt = 0;
	evtCuisine3->sante = 1;
	evtCuisine3->prix = 0;
	evtCuisine3->sommeil = -3;
	evtCuisine3->moral = 0;
	evtCuisine3->faim = -2;
	evtCuisine3->hygiene = 2;
	cuisine->event[2] = *evtCuisine3;
	
	strcpy(evtCuisine4->nom_evt, "Faire la vaisselle");
	evtCuisine4->duree_evt = 1;
	evtCuisine4->sante = 1;
	evtCuisine4->prix = 0;
	evtCuisine4->sommeil = 3;
	evtCuisine4->moral = -5;
	evtCuisine4->faim = 2;
	evtCuisine4->hygiene = 2;
	cuisine->event[3] = *evtCuisine4;

	return cuisine;
}

LIEU * initialisationChambre(LIEU * chambre)
{
	chambre->event =  malloc(4*sizeof(EVT*));
	strcpy(chambre->nom_lieu,"Chambre");
	chambre->nb_evt = 4;
	
	EVT * evtChambre1 =malloc(sizeof(EVT));
	EVT * evtChambre2 =malloc(sizeof(EVT));
	EVT * evtChambre3 =malloc(sizeof(EVT));
	EVT * evtChambre4 =malloc(sizeof(EVT));
	
	strcpy(evtChambre1->nom_evt, "Ranger la chambre");
	evtChambre1->duree_evt = 1;
	evtChambre1->sante = 1;
	evtChambre1->prix = 1;
	evtChambre1->sommeil = -1;
	evtChambre1->moral = 0;
	evtChambre1->faim = 1;
	evtChambre1->hygiene = -1;
	chambre->event[0] = *evtChambre1;
	
	strcpy(evtChambre2->nom_evt, "Dormir");
	evtChambre2->duree_evt = 8;
	evtChambre2->sante = 4;
	evtChambre2->prix = 3;
	evtChambre2->sommeil = 0;
	evtChambre2->moral = 0;
	evtChambre2->faim = -3;
	evtChambre2->hygiene = 10;
	chambre->event[1] = *evtChambre2;
	
	strcpy(evtChambre3->nom_evt, "Jouer à la play");
	evtChambre3->duree_evt = 2;
	evtChambre3->sante = 1;
	evtChambre3->prix = 1;
	evtChambre3->sommeil = 1;
	evtChambre3->moral = 0;
	evtChambre3->faim = 1;
	evtChambre3->hygiene = -1;
	chambre->event[2] = *evtChambre3;
	
	strcpy(evtChambre4->nom_evt, "Faire du sport");
	evtChambre4->duree_evt = 2;
	evtChambre4->sante = -2;
	evtChambre4->prix = -5;
	evtChambre4->sommeil = 2;
	evtChambre4->moral = 0;
	evtChambre4->faim = 5;
	evtChambre4->hygiene = -5;
	chambre->event[3] = *evtChambre4;
	
	return chambre;
}

LIEU * initialisationSalleDeBain(LIEU * salleDeBain)
{
	salleDeBain->nb_evt = 5;
	salleDeBain->event =  malloc(salleDeBain->nb_evt*sizeof(EVT*));
	strcpy(salleDeBain->nom_lieu,"Salle De Bain");
	
	EVT * evtSalleDeBain1 =malloc(sizeof(EVT));
	EVT * evtSalleDeBain2 =malloc(sizeof(EVT));
	EVT * evtSalleDeBain3 =malloc(sizeof(EVT));
	EVT * evtSalleDeBain4 =malloc(sizeof(EVT));
	EVT * evtSalleDeBain5 =malloc(sizeof(EVT));
	
	strcpy(evtSalleDeBain1->nom_evt, "Se laver");
	evtSalleDeBain1->duree_evt = 1;
	evtSalleDeBain1->sante = 0;
	evtSalleDeBain1->prix = 10;
	evtSalleDeBain1->sommeil = 2;
	evtSalleDeBain1->moral = -1;
	evtSalleDeBain1->faim = 1;
	evtSalleDeBain1->hygiene = -1;
	salleDeBain->event[0] = *evtSalleDeBain1;
	
	strcpy(evtSalleDeBain2->nom_evt, "Brosser les dents");
	evtSalleDeBain2->duree_evt = 1;
	evtSalleDeBain2->sante = 0;
	evtSalleDeBain2->prix = 3;
	evtSalleDeBain2->sommeil = 1;
	evtSalleDeBain2->moral = 0;
	evtSalleDeBain2->faim = 1;
	evtSalleDeBain2->hygiene = 0;
	salleDeBain->event[1] = *evtSalleDeBain2;
	
	strcpy(evtSalleDeBain3->nom_evt, "Aller aux toilettes");
	evtSalleDeBain3->duree_evt = 1;
	evtSalleDeBain3->sante = 0;
	evtSalleDeBain3->prix = 2;
	evtSalleDeBain3->sommeil = 1;
	evtSalleDeBain3->moral = 0;
	evtSalleDeBain3->faim = 1;
	evtSalleDeBain3->hygiene = 1;
	salleDeBain->event[2] = *evtSalleDeBain3;
	
	strcpy(evtSalleDeBain4->nom_evt, "Se raser");
	evtSalleDeBain4->duree_evt = 2;
	evtSalleDeBain4->sante = -2;
	evtSalleDeBain4->prix = -5;
	evtSalleDeBain4->sommeil = 2;
	evtSalleDeBain4->moral = 0;
	evtSalleDeBain4->faim = 5;
	evtSalleDeBain4->hygiene = -5;
	salleDeBain->event[3] = *evtSalleDeBain4;
	
	strcpy(evtSalleDeBain5->nom_evt, "Se coiffer");
	evtSalleDeBain5->duree_evt = 1;
	evtSalleDeBain5->sante = 1;
	evtSalleDeBain5->prix = 1;
	evtSalleDeBain5->sommeil = 2;
	evtSalleDeBain5->moral = -1;
	evtSalleDeBain5->faim = 1;
	evtSalleDeBain5->hygiene = 0;
	salleDeBain->event[4] = *evtSalleDeBain5;
	
	return salleDeBain;
}



LIEU * initialisationCellier(LIEU * cellier)
{
	cellier->event =  malloc(3*sizeof(EVT*));
	strcpy(cellier->nom_lieu,"Cellier");
	cellier->nb_evt = 3;
	
	EVT * evtCellier1 =malloc(sizeof(EVT));
	EVT * evtCellier2 =malloc(sizeof(EVT));
	EVT * evtCellier3 =malloc(sizeof(EVT));
	
	strcpy(evtCellier1->nom_evt, "Ranger ses chaussures");
	evtCellier1->duree_evt = 1;
	evtCellier1->sante = 1;
	evtCellier1->prix = -2;
	evtCellier1->sommeil = -2;
	evtCellier1->moral = 0;
	evtCellier1->faim = 1;
	evtCellier1->hygiene = 3;
	cellier->event[0] = *evtCellier1;
	
	strcpy(evtCellier2->nom_evt, "Lancer Machine à laver");
	evtCellier2->duree_evt = 1;
	evtCellier2->sante = 0;
	evtCellier2->prix = 0;
	evtCellier2->sommeil = 0;
	evtCellier2->moral = -1;
	evtCellier2->faim = 0;
	evtCellier2->hygiene = -1;
	cellier->event[1] = *evtCellier2;
	
	strcpy(evtCellier3->nom_evt, "Etandre le linge");
	evtCellier3->duree_evt = 1;
	evtCellier3->sante = 1;
	evtCellier3->prix = 0;
	evtCellier3->sommeil = 2;
	evtCellier3->moral = 0;
	evtCellier3->faim = 0;
	evtCellier3->hygiene = -1;
	cellier->event[2] = *evtCellier3;
	
	return cellier;
}


LIEU * initialisationJardin(LIEU * jardin)
{
	jardin->event =  malloc(3*sizeof(EVT*));
	strcpy(jardin->nom_lieu,"Jardin");
	jardin->nb_evt = 3;
	
	EVT * evtJardin1 =malloc(sizeof(EVT));
	EVT * evtJardin2 =malloc(sizeof(EVT));
	EVT * evtJardin3 =malloc(sizeof(EVT));
	
	strcpy(evtJardin1->nom_evt, "Planter des fleurs");
	evtJardin1->duree_evt = 3;
	evtJardin1->sante = -2;
	evtJardin1->prix = -2;
	evtJardin1->sommeil = -5;
	evtJardin1->moral = 4;
	evtJardin1->faim = -3;
	evtJardin1->hygiene = -3;
	jardin->event[0] = *evtJardin1;
		
	strcpy(evtJardin2->nom_evt, "Observer le ciel");
	evtJardin2->duree_evt = 1;
	evtJardin2->sante = 0;
	evtJardin2->prix = 0;
	evtJardin2->sommeil = 0;
	evtJardin2->moral = 3;
	evtJardin2->faim = 0;
	evtJardin2->hygiene = -1;
	jardin->event[1] = *evtJardin2;
	
	strcpy(evtJardin3->nom_evt, "Construire une cabane à oiseaux");
	evtJardin3->duree_evt = 1;
	evtJardin3->sante = 1;
	evtJardin3->prix = 0;
	evtJardin3->sommeil = 2;
	evtJardin3->moral = 0;
	evtJardin3->faim = 0;
	evtJardin3->hygiene = -1;
	jardin->event[2] = *evtJardin3;
	
	return jardin;
}

LIEU * initialisationExterieur(LIEU * exterieur)
{
	exterieur->event =  malloc(7*sizeof(EVT*));
	strcpy(exterieur->nom_lieu,"Exterieur");
	exterieur->nb_evt = 7;
	
	EVT * evtExterieur1 =malloc(sizeof(EVT));
	EVT * evtExterieur2 =malloc(sizeof(EVT));
	EVT * evtExterieur3 =malloc(sizeof(EVT));
	EVT * evtExterieur4 =malloc(sizeof(EVT));
	EVT * evtExterieur5 =malloc(sizeof(EVT));
	EVT * evtExterieur6 =malloc(sizeof(EVT));
	EVT * evtExterieur7 =malloc(sizeof(EVT));
	
	strcpy(evtExterieur1->nom_evt, "Voir ses amis");
	evtExterieur1->duree_evt = 4;
	evtExterieur1->sante = -3;
	evtExterieur1->prix = -2;
	evtExterieur1->sommeil = -10;
	evtExterieur1->moral = 10;
	evtExterieur1->faim = -5;
	evtExterieur1->hygiene = 0;
	exterieur->event[0] = *evtExterieur1;
		
	strcpy(evtExterieur2->nom_evt, "Aller au cinéma");
	evtExterieur2->duree_evt = 3;
	evtExterieur2->sante = 0;
	evtExterieur2->prix = -10;
	evtExterieur2->sommeil = 0;
	evtExterieur2->moral = 3;
	evtExterieur2->faim = -2;
	evtExterieur2->hygiene = 0;
	exterieur->event[1] = *evtExterieur2;
	
	strcpy(evtExterieur3->nom_evt, "Faire les courses");
	evtExterieur3->duree_evt = 2;
	evtExterieur3->sante = 1;
	evtExterieur3->prix = -15;
	evtExterieur3->sommeil = -2;
	evtExterieur3->moral = -1;
	evtExterieur3->faim = 0;
	evtExterieur3->hygiene = -1;
	exterieur->event[2] = *evtExterieur3;
	
	strcpy(evtExterieur4->nom_evt, "Se promener");
	evtExterieur4->duree_evt = 2;
	evtExterieur4->sante = 1;
	evtExterieur4->prix = 0;
	evtExterieur4->sommeil = -2;
	evtExterieur4->moral = 3;
	evtExterieur4->faim = -2;
	evtExterieur4->hygiene = -1;
	exterieur->event[3] = *evtExterieur4;
	
	strcpy(evtExterieur5->nom_evt, "Aller dans un bar");
	evtExterieur5->duree_evt = 3;
	evtExterieur5->sante = -5;
	evtExterieur5->prix = -20;
	evtExterieur5->sommeil = -3;
	evtExterieur5->moral = 3;
	evtExterieur5->faim = 0;
	evtExterieur5->hygiene = -1;
	exterieur->event[4] = *evtExterieur5;
	
	strcpy(evtExterieur6->nom_evt, "Courrir");
	evtExterieur6->duree_evt = 1;
	evtExterieur6->sante = 2;
	evtExterieur6->prix = 0;
	evtExterieur6->sommeil = -5;
	evtExterieur6->moral = 3;
	evtExterieur6->faim = -3;
	evtExterieur6->hygiene = -1;
	exterieur->event[5] = *evtExterieur6;
	
	strcpy(evtExterieur7->nom_evt, "Aller travailler");
	evtExterieur7->duree_evt = 8;
	evtExterieur7->sante = -2;
	evtExterieur7->prix = 100;
	evtExterieur7->sommeil = -8;
	evtExterieur7->moral = -2;
	evtExterieur7->faim = -3;
	evtExterieur7->hygiene = 0;
	exterieur->event[6] = *evtExterieur7;
	
	return exterieur;
}


LIEU * initialisationSalon(LIEU * salon)
{
	salon->event =  malloc(3*sizeof(EVT*));
	strcpy(salon->nom_lieu,"Salon");
	salon->nb_evt = 3;
	
	EVT * evtSalon1 =malloc(sizeof(EVT));
	EVT * evtSalon2 =malloc(sizeof(EVT));
	EVT * evtSalon3 =malloc(sizeof(EVT));
	
	strcpy(evtSalon1->nom_evt, "Lire un livre");
	evtSalon1->duree_evt = 2;
	evtSalon1->sante = 0;
	evtSalon1->prix = 0;
	evtSalon1->sommeil = -1;
	evtSalon1->moral = 4;
	evtSalon1->faim = 0;
	evtSalon1->hygiene = 0;
	salon->event[0] = *evtSalon1;
		
	strcpy(evtSalon2->nom_evt, "Regarder la télé");
	evtSalon2->duree_evt = 1;
	evtSalon2->sante = -1;
	evtSalon2->prix = 0;
	evtSalon2->sommeil = -1;
	evtSalon2->moral = 0;
	evtSalon2->faim = -1;
	evtSalon2->hygiene = 0;
	salon->event[1] = *evtSalon2;
	
	strcpy(evtSalon3->nom_evt, "Faire le ménage");
	evtSalon3->duree_evt = 3;
	evtSalon3->sante = 1;
	evtSalon3->prix = 0;
	evtSalon3->sommeil = -2;
	evtSalon3->moral = 3;
	evtSalon3->faim = -2;
	evtSalon3->hygiene = -1;
	salon->event[2] = *evtSalon3;
	
	return salon;
}


void attribuerCaracteristiquesEvt(LIEU * lieu, char * p_nomAction, int p_duree_evt, int p_faim, int p_hygiene, int p_moral, int p_prix, int p_sante, int p_sommeil)
{

	printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",p_nomAction,p_duree_evt,p_faim,p_hygiene,p_moral,p_prix,p_sante,p_sommeil);
	strcpy(lieu->event->nom_evt, p_nomAction);
	lieu->event->duree_evt = p_duree_evt;
	lieu->event->sante = p_sante;
	lieu->event->prix = p_prix;
	lieu->event->sommeil = p_sommeil;
	lieu->event->moral = p_moral;
	lieu->event->faim = p_faim;
	lieu->event->hygiene = p_hygiene;
	//return evt;
}

//~ EVT * insertionNewEvt(EVT * listeEvt, EVT *nouvelEvt )
//~ {
	//~ if (listeEvt == NULL)
	//~ {	/* cas d'une lsite vide */
		//~ nouvelEvt->event_suiv = NULL;
		//~ listeEvt = nouvelEvt;
		//~ return listeEvt;
	//~ }
	
	//~ if(nouvelEvt == NULL)
	//~ {
		//~ printf("Rien a insert\n");
		//~ return listeEvt;
	//~ }
	
	//~ EVT*courant = listeEvt;
	//~ EVT*precedent = NULL;
	//~ while( courant != NULL )
	//~ {
//~ /* parcour de la liste pour trouver le bon endroit ou insert */
		//~ if( strcasecmp(courant->nom_evt,nouvelEvt->nom_evt)>0)
		//~ { /* on a trouver le bon endroit */
			//~ if(courant==listeEvt)
			//~ { /* ajout debut */
				//~ nouvelEvt->event_suiv = listeEvt;
				//~ listeEvt = nouvelEvt;
				//~ return listeEvt;
			//~ }
			//~ else
			//~ {
				//~ precedent->event_suiv=nouvelEvt;
				//~ nouvelEvt->event_suiv=courant;
				//~ return listeEvt;
			//~ }
		//~ }
		//~ else
		//~ { /* on continue d'avancer */
			//~ precedent=courant;
			//~ courant=courant->event_suiv;
		//~ }
	//~ }
//~ /* ici on est sortie de la boucle => fin de la liste courant == NULL */
	//~ precedent->event_suiv=nouvelEvt;
	//~ nouvelEvt->event_suiv=NULL;

	//~ return listeEvt;
//~ }

//~ EVT * insertionNewEvt(EVT * listeEvt, EVT *nouvelEvt )
//~ {
	//~ if (listeEvt == NULL)
	//~ {	/* cas d'une lsite vide */
		//~ nouvelEvt->event_suiv = NULL;
		//~ listeEvt = nouvelEvt;
		//~ return listeEvt;
	//~ }
	
	//~ if(nouvelEvt == NULL)
	//~ {
		//~ printf("Rien a insert\n");
		//~ return listeEvt;
	//~ }
	
	//~ EVT*courant = listeEvt;
	//~ EVT*precedent = NULL;
	//~ while( courant != NULL )
	//~ {
//~ /* parcour de la liste pour trouver le bon endroit ou insert */
		//~ if( strcasecmp(courant->nom_evt,nouvelEvt->nom_evt)>0)
		//~ { /* on a trouver le bon endroit */
			//~ if(courant==listeEvt)
			//~ { /* ajout debut */
				//~ nouvelEvt->event_suiv = listeEvt;
				//~ listeEvt = nouvelEvt;
				//~ return listeEvt;
			//~ }
			//~ else
			//~ {
				//~ precedent->event_suiv=nouvelEvt;
				//~ nouvelEvt->event_suiv=courant;
				//~ return listeEvt;
			//~ }
		//~ }
		//~ else
		//~ { /* on continue d'avancer */
			//~ precedent=courant;
			//~ courant=courant->event_suiv;
		//~ }
	//~ }
//~ /* ici on est sortie de la boucle => fin de la liste courant == NULL */
	//~ precedent->event_suiv=nouvelEvt;
	//~ nouvelEvt->event_suiv=NULL;

	//~ return listeEvt;
//~ }


//~ void afficheLIEU(LIEU lieu)
//~ {
	//~ if( lieu.event == NULL )
	//~ {
		//~ printf("afficheLIEU impossible sur lieu vide\n");
		//~ return;
	//~ }
	//~ printf("|■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■|\n");
	//~ printf("|nom lieu: %20s|\n",lieu.nom_lieu);
	//~ afficheListeEvent(lieu.event);
//~ }
//~ void afficheLIEU(LIEU * lieu)
//~ {
	//~ if( lieu->event == NULL )
	//~ {
		//~ printf("afficheLIEU impossible sur lieu vide\n");
		//~ return;
	//~ }
	//~ printf("|■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■|\n");
	//~ printf("|nom lieu: %20s|\n",lieu->nom_lieu);
	//~ afficheListeEvent(lieu->event);
//~ }
void afficheLIEU(LIEU * lieu)
{
	if( lieu->event == NULL )
	{
		printf("afficheLIEU impossible sur lieu vide\n");
		return;
	}
	printf("|■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■|\n");
	printf("|nom lieu: %20s|\n",lieu->nom_lieu);
	printf("|nb actions du lieu: %10d|\n",lieu->nb_evt);
	for(int i=0; i<lieu->nb_evt;i++)
	{
		printf("|--------------------------|\n");
		printf("|nb nom evt: %10s|\n",lieu->event[i].nom_evt);
		printf("|nb durée evt: %10d|\n",lieu->event[i].duree_evt);
		printf("|nb faim evt: %10d|\n",lieu->event[i].faim);
		printf("|nb hygiene evt: %10d|\n",lieu->event[i].hygiene);
		printf("|nb moral evt: %10d|\n",lieu->event[i].moral);
		printf("|nb prix evt: %10d|\n",lieu->event[i].prix);
		printf("|nb sante evt: %10d|\n",lieu->event[i].sante);
		printf("|nb sommeil evt: %10d|\n",lieu->event[i].sommeil);
	}
	
	
	//afficheListeEvent(lieu->event);
}


void afficheEvent(EVT *event)
{
	if( event == NULL )
	{
		printf("afficheEvent impossible sur Event vide\n");
		return;
	}
	printf("|--------------------------|\n");
	printf("|nb nom evt: %10s|\n",event->nom_evt);
	printf("|nb durée evt: %10d|\n",event->duree_evt);
	printf("|nb faim evt: %10d|\n",event->faim);
	printf("|nb hygiene evt: %10d|\n",event->hygiene);
	printf("|nb moral evt: %10d|\n",event->moral);
	printf("|nb prix evt: %10d|\n",event->prix);
	printf("|nb sante evt: %10d|\n",event->sante);
	printf("|nb sommeil evt: %10d|\n",event->sommeil);
}


