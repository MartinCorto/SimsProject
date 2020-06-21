#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GestionEvenements.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


void initialisationEvenements(void)
{
	LIEU cuisine;
	memset(&cuisine,0,sizeof(cuisine));
	strcpy(cuisine.nom_lieu,"Cuisine");
	cuisine.nb_evt = 4;
	EVT * listeEvtCuisine = NULL;
	EVT evtCuisine1;
	evtCuisine1 = attribuerCaracteristiquesEvt(evtCuisine1,"Faire à manger",1,2,0,0,0,1,1);
	listeEvtCuisine = insertionNewEvt(listeEvtCuisine, &evtCuisine1);
	cuisine.event = listeEvtCuisine;
	
	EVT evtCuisine2;
	evtCuisine2 = attribuerCaracteristiquesEvt(evtCuisine2,"Manger",1,1,0,3,-5,2,2);
	listeEvtCuisine = insertionNewEvt(listeEvtCuisine, &evtCuisine2);
	cuisine.event = listeEvtCuisine;
	
	EVT evtCuisine3;
	evtCuisine3 = attribuerCaracteristiquesEvt(evtCuisine3,"Faire la vaisselle",1,1,0,(-3),0,-2,2);
	listeEvtCuisine = insertionNewEvt(listeEvtCuisine, &evtCuisine3);
	cuisine.event = listeEvtCuisine;
	
	EVT evtCuisine4;
	evtCuisine4 = attribuerCaracteristiquesEvt(evtCuisine4,"Boire un verre d'eau",0,1,0,(-3),0,-2,2);
	listeEvtCuisine = insertionNewEvt(listeEvtCuisine, &evtCuisine4);
	cuisine.event = listeEvtCuisine;
	
	afficheLIEU(cuisine);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------


	LIEU chambre;
	memset(&chambre,0,sizeof(chambre));
	strcpy(chambre.nom_lieu,"Chambre");
	chambre.nb_evt = 3;
	EVT * listeEvtChambre = NULL;
	EVT evtChambre1;
	evtChambre1 = attribuerCaracteristiquesEvt(evtChambre1,"Ranger la chambre",1,1,1,-1,0,1,-1);
	listeEvtChambre = insertionNewEvt(listeEvtChambre, &evtChambre1);
	chambre.event = listeEvtChambre;
	
	EVT evtChambre2;
	evtChambre2 = attribuerCaracteristiquesEvt(evtChambre2,"Dormir",8,4,3,0,0,3,10);
	listeEvtChambre = insertionNewEvt(listeEvtChambre, &evtChambre2);
	chambre.event = listeEvtChambre;
	
	EVT evtChambre3;
	evtChambre3 = attribuerCaracteristiquesEvt(evtChambre3,"Jouer",2,1,1,1,0,1,-1);
	listeEvtChambre = insertionNewEvt(listeEvtChambre, &evtChambre3);
	chambre.event = listeEvtChambre;
	
	EVT evtChambre4;
	//attribuerCaracteristiquesEvt(EVT evt, char * p_nomAction, int p_duree_evt, int p_faim, int p_hygiene, int p_moral, int p_prix, int p_sante, int p_sommeil)
	evtChambre4 = attribuerCaracteristiquesEvt(evtChambre4,"Faire du sport",2,-2,-5,2,0,5,-5);
	listeEvtChambre = insertionNewEvt(listeEvtChambre, &evtChambre4);
	chambre.event = listeEvtChambre;
	
	afficheLIEU(chambre);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	LIEU salleDeBain;
	memset(&salleDeBain,0,sizeof(salleDeBain));
	strcpy(salleDeBain.nom_lieu,"Salle De Bain");
	salleDeBain.nb_evt = 5;
	EVT * listeEvtsalleDeBain = NULL;
	EVT evtsalleDeBain1;
	evtsalleDeBain1 = attribuerCaracteristiquesEvt(evtsalleDeBain1,"Se laver",1,0,10,2,-1,1,1);
	listeEvtsalleDeBain = insertionNewEvt(listeEvtsalleDeBain, &evtsalleDeBain1);
	salleDeBain.event = listeEvtsalleDeBain;
	
	EVT evtsalleDeBain2;
	evtsalleDeBain2 = attribuerCaracteristiquesEvt(evtsalleDeBain2,"Brosser les dents",1,0,3,1,0,1,0);
	listeEvtsalleDeBain = insertionNewEvt(listeEvtsalleDeBain, &evtsalleDeBain2);
	salleDeBain.event = listeEvtsalleDeBain;
	
	EVT evtsalleDeBain3;
	evtsalleDeBain3 = attribuerCaracteristiquesEvt(evtsalleDeBain3,"Aller aux toilettes",1,0,2,1,0,1,1);
	listeEvtsalleDeBain = insertionNewEvt(listeEvtsalleDeBain, &evtsalleDeBain3);
	salleDeBain.event = listeEvtsalleDeBain;
	
	EVT evtsalleDeBain4;
	evtsalleDeBain4 = attribuerCaracteristiquesEvt(evtsalleDeBain4,"Se raser",1,1,1,2,-1,1,0);
	listeEvtsalleDeBain = insertionNewEvt(listeEvtsalleDeBain, &evtsalleDeBain4);
	salleDeBain.event = listeEvtsalleDeBain;
	
	EVT evtsalleDeBain5;
	evtsalleDeBain5 = attribuerCaracteristiquesEvt(evtsalleDeBain5,"Se coiffer",1,1,1,2,-1,1,0);
	listeEvtsalleDeBain = insertionNewEvt(listeEvtsalleDeBain, &evtsalleDeBain5);
	salleDeBain.event = listeEvtsalleDeBain;

	afficheLIEU(salleDeBain);
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	LIEU cellier;
	memset(&cellier,0,sizeof(cellier));
	strcpy(cellier.nom_lieu,"Cellier");
	cellier.nb_evt = 3;
	EVT * listeEvtCellier = NULL;
	EVT evtCellier1;
	//attribuerCaracteristiquesEvt(EVT evt, char * p_nomAction, int p_duree_evt, int p_faim, int p_hygiene, int p_moral, int p_prix, int p_sante, int p_sommeil)
	evtCellier1 = attribuerCaracteristiquesEvt(evtCellier1,"Ranger ses chaussures",1,1,-2,-2,0,1,3);
	listeEvtCellier = insertionNewEvt(listeEvtCellier, &evtCellier1);
	cellier.event = listeEvtCellier;
	
	EVT evtCellier2;
	evtCellier2 = attribuerCaracteristiquesEvt(evtCellier2,"Lancer Machine à laver",1,0,0,0,-1,0,-1);
	listeEvtCellier = insertionNewEvt(listeEvtCellier, &evtCellier2);
	cellier.event = listeEvtCellier;
	
	EVT evtCellier3;
	evtCellier3 = attribuerCaracteristiquesEvt(evtCellier3,"Etandre le linge",1,1,0,2,0,0,-1);
	listeEvtCellier = insertionNewEvt(listeEvtCellier, &evtCellier3);
	cellier.event = listeEvtCellier;
	
	afficheLIEU(cellier);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	LIEU jardin;
	memset(&cellier,0,sizeof(jardin));
	strcpy(jardin.nom_lieu,"Jardin");
	jardin.nb_evt = 3;
	EVT * listeEvtJardin = NULL;
	EVT evtJardin1;
	//attribuerCaracteristiquesEvt(EVT evt, char * p_nomAction, int p_duree_evt, int p_faim, int p_hygiene, int p_moral, int p_prix, int p_sante, int p_sommeil)
	evtJardin1 = attribuerCaracteristiquesEvt(evtJardin1,"Planter des fleurs",1,1,-2,-2,0,1,3);
	listeEvtJardin = insertionNewEvt(listeEvtJardin, &evtJardin1);
	jardin.event = listeEvtJardin;
	
	EVT evtJardin2;
	evtJardin2 = attribuerCaracteristiquesEvt(evtJardin2,"Observer le ciel",1,0,0,0,-1,0,-1);
	listeEvtJardin = insertionNewEvt(listeEvtJardin, &evtJardin2);
	jardin.event = listeEvtJardin;
	
	EVT evtJardin3;
	evtJardin3 = attribuerCaracteristiquesEvt(evtJardin3,"Construire une cabane à oiseaux",1,1,0,2,0,0,-1);
	listeEvtJardin = insertionNewEvt(listeEvtCellier, &evtJardin3);
	jardin.event = listeEvtJardin;
	
	afficheLIEU(jardin);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	LIEU exterieur;
	memset(&exterieur,0,sizeof(exterieur));
	strcpy(exterieur.nom_lieu,"Exterieur");
	exterieur.nb_evt = 3;
	EVT * listeEvtExterieur = NULL;
	EVT evtExterieur1;
	//attribuerCaracteristiquesEvt(EVT evt, char * p_nomAction, int p_duree_evt, int p_faim, int p_hygiene, int p_moral, int p_prix, int p_sante, int p_sommeil)
	evtExterieur1 = attribuerCaracteristiquesEvt(evtExterieur1,"Voir ses amis",4,-3,-2,10,-13,5,-10);
	listeEvtExterieur = insertionNewEvt(listeEvtExterieur, &evtExterieur1);
	exterieur.event = listeEvtExterieur;
	
	EVT evtExterieur2;
	evtExterieur2 = attribuerCaracteristiquesEvt(evtExterieur2,"Aller au cinéma",1,0,0,2,-10,1,-2);
	listeEvtExterieur = insertionNewEvt(listeEvtExterieur, &evtExterieur2);
	exterieur.event = listeEvtExterieur;
	
	EVT evtExterieur3;
	evtExterieur3 = attribuerCaracteristiquesEvt(evtExterieur3,"Faire les courses",2,-1,0,-2,-15,-1,-3);
	listeEvtExterieur = insertionNewEvt(listeEvtExterieur, &evtExterieur3);
	exterieur.event = listeEvtExterieur;
	
	EVT evtExterieur4;
	evtExterieur4 = attribuerCaracteristiquesEvt(evtExterieur4,"Se promener",1,1,0,2,0,5,-3);
	listeEvtExterieur = insertionNewEvt(listeEvtExterieur, &evtExterieur4);
	exterieur.event = listeEvtExterieur;
	
	EVT evtExterieur5;
	evtExterieur5 = attribuerCaracteristiquesEvt(evtExterieur5,"Aller dans un bar",3,0,-1,2,-20,-5,-3);
	listeEvtExterieur = insertionNewEvt(listeEvtExterieur, &evtExterieur5);
	exterieur.event = listeEvtExterieur;
	
	EVT evtExterieur6;
	evtExterieur6 = attribuerCaracteristiquesEvt(evtExterieur6,"Courrir",1,1,-5,2,0,5,-1);
	listeEvtExterieur = insertionNewEvt(listeEvtExterieur, &evtExterieur6);
	exterieur.event = listeEvtExterieur;
	
	EVT evtExterieur7;
	evtExterieur7 = attribuerCaracteristiquesEvt(evtExterieur7,"Aller travailler",8,-2,-3,-2,100,-5,-10);
	listeEvtExterieur = insertionNewEvt(listeEvtExterieur, &evtExterieur7);
	exterieur.event = listeEvtExterieur;
	
	afficheLIEU(exterieur);
	
	
	
}

EVT attribuerCaracteristiquesEvt(EVT evt, char * p_nomAction, int p_duree_evt, int p_faim, int p_hygiene, int p_moral, int p_prix, int p_sante, int p_sommeil)
{
	printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",p_nomAction,p_duree_evt,p_faim,p_hygiene,p_moral,p_prix,p_sante,p_sommeil);
	strcpy(evt.nom_evt, p_nomAction);
	evt.duree_evt = p_duree_evt;
	evt.sante = p_sante;
	evt.prix = p_prix;
	evt.sommeil = p_sommeil;
	evt.moral = p_moral;
	evt.faim = p_faim;
	evt.hygiene = p_hygiene;
	return evt;
}

EVT * insertionNewEvt(EVT * listeEvt, EVT *nouvelEvt )
{
	if (listeEvt == NULL)
	{	/* cas d'une lsite vide */
		nouvelEvt->event_suiv = NULL;
		listeEvt = nouvelEvt;
		return listeEvt;
	}
	
	if(nouvelEvt == NULL)
	{
		printf("Rien a insert\n");
		return listeEvt;
	}
	
	EVT*courant = listeEvt;
	EVT*precedent = NULL;
	while( courant != NULL )
	{
/* parcour de la liste pour trouver le bon endroit ou insert */
		if( strcasecmp(courant->nom_evt,nouvelEvt->nom_evt)>0)
		{ /* on a trouver le bon endroit */
			if(courant==listeEvt)
			{ /* ajout debut */
				nouvelEvt->event_suiv = listeEvt;
				listeEvt = nouvelEvt;
				return listeEvt;
			}
			else
			{
				precedent->event_suiv=nouvelEvt;
				nouvelEvt->event_suiv=courant;
				return listeEvt;
			}
		}
		else
		{ /* on continue d'avancer */
			precedent=courant;
			courant=courant->event_suiv;
		}
	}
/* ici on est sortie de la boucle => fin de la liste courant == NULL */
	precedent->event_suiv=nouvelEvt;
	nouvelEvt->event_suiv=NULL;

	return listeEvt;
}


void afficheLIEU(LIEU lieu)
{
	if( lieu.event == NULL )
	{
		printf("afficheLIEU impossible sur lieu vide\n");
		return;
	}
	printf("|■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■|\n");
	printf("|nom lieu: %20s|\n",lieu.nom_lieu);
	afficheListeEvent(lieu.event);
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

void afficheListeEvent(EVT *liste)
{
	EVT *courant=liste;
	if( liste == NULL )
	{
		printf("afficheListe impossible sur liste vide\n");
		return ;
	}
	while( courant != NULL ) /* tant qu'il reste des elements */
	{
		afficheEvent(courant);
		
		/* on avance vers l'element suivant */
		courant = courant->event_suiv;
	}
}


































//~ void ajouterEvenement(FILE *fichier_evenement)
//~ {
	//~ EVT new_event;
	//~ char choix;
	//~ char choix_sexe;
	
	//~ printf("Ajout d'un nouveau event à la base de données\n");
	//~ /*memset memory set , force la valeur d'un champs de donnees */
	//~ memset(&new_event,0,sizeof(new_perso));
	
	//~ /* pour ajouter un nouveau personnage on le place a la fin*/
	//~ fseek(fichier,0,SEEK_END);
	
	//~ printf("saisir le nom du personnage: ");
	//~ scanf("%s",new_perso.nom);
	//~ printf("saisir le prenom du personnage: ");
	//~ scanf("%s",new_perso.prenom);
	
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
	//~ attribuerCaracteristiquesAlea(&new_event);
	//~ afficheElementEvent(&new_event);
	//~ fwrite(&new_event,sizeof(EVT),1,fichier);
	//~ printf("personnage cree\n");	
//~ }

//~ /* Fonction permettant d'ouvrir un fichier pour le modifier */
//~ FILE*ouvrirEvenements(char*nom_fichier)
//~ {
	//~ FILE*f=NULL;
	//~ f=fopen(nom_fichier,"a");
	//~ fclose(f);
	//~ f=fopen(nom_fichier,"r+");
	//~ return f;	
//~ }


//~ /* Fonction permettant de fermer un fichier */
//~ void fermerEvenements(FILE*fichier_ouvert)
//~ {
	//~ printf("fermeture du fichier\n");
	//~ fclose (fichier_ouvert);
//~ }

//~ EVT*insertionAlphaEvent(EVT *liste, EVT *nouvelElement )
//~ {
	//~ if (liste == NULL)
	//~ {	/* cas d'une lsite vide */
		//~ nouvelElement->suiv = NULL;
		//~ liste = nouvelElement;
		//~ return liste;
	//~ }
	
	//~ if(nouvelElement == NULL)
	//~ {
		//~ printf("Rien a insert\n");
		//~ return liste;
	//~ }
	
	//~ EVT*courant = liste;
	//~ EVT*precedent = NULL;
	//~ while( courant != NULL )
	//~ {
//~ /* parcour de la liste pour trouver le bon endroit ou insert */
		//~ if( courant->t_evt < nouvelElement->t_evt)
		//~ { /* on a trouver le bon endroit */
			//~ if(courant==liste)
			//~ { /* ajout debut */
				//~ nouvelElement->suiv = liste;
				//~ liste = nouvelElement;
				//~ return liste;
			//~ }
			//~ else
			//~ {
				//~ precedent->suiv=nouvelElement;
				//~ nouvelElement->suiv=courant;
				//~ return liste;
			//~ }
		//~ }
		//~ else
		//~ { /* on continue d'avancer */
			//~ precedent=courant;
			//~ courant=courant->suiv;
		//~ }
	//~ }
//~ /* ici on est sortie de la boucle => fin de la liste courant == NULL */
	//~ precedent->suiv=nouvelElement;
	//~ nouvelElement->suiv=NULL;

	//~ return liste;
//~ }


//~ void afficheElementEvent(EVT *event)
//~ {
	//~ if( event == NULL )
	//~ {
		//~ printf("afficheElementEvent impossible sur Event vide\n");
		//~ return;
	//~ }
	//~ printf("|--------------------------|\n");
	//~ printf("|id emetteur : %d|\n",event->id_emet);
	//~ printf("|id destinataire : %d|\n",event->id_dest);
	//~ printf("|type action : %d|\n",event->type_act);
	//~ printf("|durée de l'action : %d|\n",event->t_evt);
//~ }

//~ void afficheListeEvent(EVT *liste)
//~ {
	//~ EVT *courant=liste;
	//~ if( liste == NULL )
	//~ {
		//~ printf("afficheListe impossible sur liste vide\n");
		//~ return ;
	//~ }
	//~ while( courant != NULL ) /* tant qu'il reste des elements */
	//~ {
		//~ afficheElement(courant);
		
		//~ /* on avance vers l'element suivant */
		//~ courant = courant->suiv;
	//~ }
//~ }


//~ //---------------- Echeancier
//~ int file_ech_vide(ECH* echeancier)
//~ {
	//~ // si res = 1 alors la file d'evenements de l'echeancier est nulle, plus d'evenement a traiter
	//~ // si res = 0 alors la file d'evenements de l'echeancier est PAS nulle, on continu de traiter les evenements
	//~ int res;
	//~ if(echeancier->debut == NULL)
	//~ {
		//~ res = 1;
	//~ }
	//~ else
	//~ {
		//~ res = 0;
	//~ }
	//~ return res;
//~ }

//~ void retirerEvtEch(ECH* echeancier, EVT* evt_a_traiter)
//~ {
	
//~ }
