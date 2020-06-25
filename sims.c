#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <time.h>
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()
#include "Personnage.h"
#include "GestionEvenements.h"
#include "graph.h"


// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1000
#define HauteurFenetre 800

// Fonction de trace de cercle
//void cercle(float centreX, float centreY, float rayon);
/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);



int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	
	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);
	
	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */
	lanceBoucleEvenements();
	
	return 0;
}




/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB **fond = NULL; // L'image a afficher au centre de l'ecran
	static int etat;
	static PERSONNAGE*liste;
	static PERSONNAGE* PersoCourant;
	static LIEU lieuCourant;
	static LIEU *place;
	static clock_t prev_millis;
	static clock_t prev_millisCondPerso;
	switch (evenement)
	{
		case Initialisation:
			etat=0;//0: menu, 1 sims, 2 creation;
			place=malloc(7*sizeof(LIEU));
			fond = malloc(4*sizeof(DonneesImageRGB *));
			fond[0]=lisBMPRGB("menu.bmp");
			fond[1]=lisBMPRGB("sim.bmp");
			fond[2]=lisBMPRGB("cree.bmp");
			fond[3]=lisBMPRGB("supp.bmp");
			initialisationLieux(place);
			lieuCourant=place[0];
			prev_millis=clock();
			prev_millisCondPerso=clock();
			//image = lisBMPRGB("menu.bmp");
			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);
			break;
		
		case Temporisation:

			if ((clock() - prev_millis)/CLOCKS_PER_SEC > 1)
			{
				prev_millis=clock();
				timePerso(liste);
				
			}
			if ((clock() - prev_millisCondPerso)/CLOCKS_PER_SEC > 6)
			{
				prev_millisCondPerso=clock();
				printConditionPerso(liste);
			}
			// il faut redessiner la fenetre :
			rafraichisFenetre();
			
			//~ printConditionPerso(liste);
			
			if (etat==2)
			{
				liste=ajoutFin(liste , saisirElement());
				etat=0;
			}
			break;
			
		case Affichage:

			// On part d'un fond d'ecran blanc

				effaceFenetre(255,255,255);
				// Affichage d'une image 
				if (fond != NULL) // Si l'image a pu etre lue
				{
					// On affiche l'image
					ecrisImage(0, 0, fond[etat]->largeurImage, fond[etat]->hauteurImage, fond[etat]->donneesRGB);
				}
				if (etat==0 || etat==3)
				{
					listeSims(liste);

				}
				if(etat==1){
					gestion(PersoCourant, lieuCourant, place);
				}

			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				//case 'Q': /* Pour sortir quelque peu proprement du programme */
				//case 'q':
				//	libereDonneesImageRGB(fond); /* On libere la structure image,
				//	c'est plus propre, meme si on va sortir du programme juste apres */
				//	termineBoucleEvenements();
				//	break;

				case 'F':
				case 'f':
					pleinEcran = !pleinEcran; // Changement de mode plein ecran
					if (pleinEcran)
						modePleinEcran();
					else
						redimensionneFenetre(LargeurFenetre, HauteurFenetre);
					break;

				case 'L':
				case 'l':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 100 millisecondes (lent)
					demandeTemporisation(100);
					break;

				case 'S':
				case 's':
					// Configure le systeme pour ne plus generer de message Temporisation
					demandeTemporisation(-1);
					break;
			}
			break;
			
		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:					// On affiche l'image

			if (etatBoutonSouris() == GaucheAppuye)
			{
				
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
				
			}
			else if (etatBoutonSouris() == GaucheRelache)
			{
				printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
				etat=bouton1(etat, abscisseSouris(), ordonneeSouris());
				etat=bouton2(etat, abscisseSouris(), ordonneeSouris());
				if (etat==0 || etat==3)
				{
					PersoCourant=boutonSims(liste, abscisseSouris(),  ordonneeSouris());
					if (PersoCourant != NULL )
					{
						if (etat==0)
						{
							etat=1;
						}
						if(etat==3){
							liste=supprimerPersonnage(liste, PersoCourant);
						}
					}
				}
				if (etat==1)
				{
					lieuCourant=gestionLieu(place, lieuCourant, abscisseSouris(), ordonneeSouris());
					if (PersoCourant->caracteristiques.occup == 0)
					{
						PersoCourant=gestionPerso(lieuCourant, PersoCourant,abscisseSouris() , ordonneeSouris() );
					}
					
				}

			}
			break;
		
		case Souris: // Si la souris est deplacee
			break;
		
		case Inactivite: // Quand aucun message n'est disponible
			break;
		
		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
			// Donc le systeme nous en informe
			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}

