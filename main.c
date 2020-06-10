#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "fourier.h"

void printMenu(void);

int main(void)
{

    
    int exit = 0;
	char choix;
	
	
	float l_periode_traceCarre1 = 0;
	float l_amplitude_traceCarre1 = 0;
	int l_nbPeriode_traceCarre1 = 0;

	float l_periode_traceCarre2 = 0;
	float l_amplitude_traceCarre2 = 0;
	int l_nbPeriode_traceCarre2 = 0;

	int l_boolenCouleur = 2;
	while( exit == 0 )
	{
		printMenu();
		scanf(" %c",&choix);
		switch(choix)
		{
			case '0':
			case 'O':
			case 'o':
				exit = 1;
				break;
			
			case '1':
				printf("Axes Simple taille fixe 1200*1200\n");
				Image *imgRepere = initialiseRepereCentre(1200,1200);
				sauveImage(imgRepere,"axes.bmp");
				libereImage(&imgRepere);
				break;
			
			case '2':
				l_boolenCouleur = saisirCouleurBooleen();
				printf("Couleur choisie %d\n", l_boolenCouleur);
				break;
				
			case '3':
				l_periode_traceCarre1 = saisirPeriode();
				l_amplitude_traceCarre1 = saisirAmplitude();
				l_nbPeriode_traceCarre1 = saisirNbPeriode();
				
				Image *ImageCarre1 = traceCarre1(l_amplitude_traceCarre1, l_periode_traceCarre1, l_nbPeriode_traceCarre1);
				sauveImage(ImageCarre1,"carre1.bmp");
				libereImage(&ImageCarre1);
				break;

			case '4':	
				l_periode_traceCarre2 = saisirPeriode();
				l_amplitude_traceCarre2 = saisirAmplitude();
				l_nbPeriode_traceCarre2 = saisirNbPeriode();
				l_boolenCouleur = saisirCouleurBooleen();
				
				Image *ImageCarre2 = traceCarre2(l_amplitude_traceCarre2, l_periode_traceCarre2, l_nbPeriode_traceCarre2, l_boolenCouleur);
				sauveImage(ImageCarre2,"carre2.bmp");
				libereImage(&ImageCarre2);
				break;

			default :
				printf("Commande inconnue\n");
				break;
		}
	}

return 0;
}

/*
Permet d'afficher un menu textuel
param : void
return : void
*/
void printMenu(void)
{
	printf("  -- Menu --\n");
	printf(" 0 - Exit\n");
	printf(" 1 - Creer axes\n");
	printf(" 2 - Test choix de la couleur\n");
	printf(" 3 - Trace carre1 \n");
	printf(" 4 - Trace carre2 \n");
}
