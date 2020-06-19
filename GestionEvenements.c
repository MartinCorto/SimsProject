#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GestionEvenements.h"
//~ #include "BmpLib.h"


#include "Personnage.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>








































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
