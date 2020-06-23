#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "BmpLib.h"
#include "Personnage.h"
#include "GestionEvenements.h"



int main(int argc, char **argv)
{
	double start = clock();
	
	LIEU * cuisine = malloc(sizeof(LIEU));
	cuisine = initialisationCuisine(cuisine);
	afficheLIEU(cuisine);
	
	LIEU * chambre = malloc(sizeof(LIEU));
	chambre = initialisationChambre(chambre);
	afficheLIEU(chambre);
	
	LIEU * cellier = malloc(sizeof(LIEU));
	chambre = initialisationCellier(cellier);
	afficheLIEU(cellier);
	
	LIEU * salleDeBain = malloc(sizeof(LIEU));
	chambre = initialisationSalleDeBain(salleDeBain);
	afficheLIEU(salleDeBain);
	
	LIEU * jardin = malloc(sizeof(LIEU));
	jardin = initialisationJardin(jardin);
	afficheLIEU(jardin);
	
	LIEU * exterieur = malloc(sizeof(LIEU));
	exterieur = initialisationExterieur(exterieur);
	afficheLIEU(exterieur);
	
	LIEU * salon = malloc(sizeof(LIEU));
	salon = initialisationSalon(salon);
	afficheLIEU(salon);
	
	
	//~ double start = clock(); début cpt temps
	double stop = clock(); 
	//~ fin cpt temps   
	printf("Tps %lf en ms\n",(stop-start)* 1000/CLOCKS_PER_SEC);
	//~ stop-start = tps écoulé

	
	return 0;
}


