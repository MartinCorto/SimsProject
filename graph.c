#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GfxLib.h"
#include "Personnage.h"
#include "GestionEvenements.h"
#include "graph.h"


int bouton1(int etat, int x, int y){
	if (x > 65 && x < 235 && y < 105 && y> 50)
	{
		if (etat==0)
		{
			return 2;
		}
		if (etat==1)
		{
			return 0;
		}
		if (etat==2)
		{
			return 0;
		}
		if (etat==3)
		{
			return 0;
		}
	}
	return etat;
}

int bouton2(int etat, int x, int y){
	if (x > 775 && x < 935 && y < 105 && y> 50)
	{
		if (etat == 0)
		{
			return 3;
		}
		if (etat == 2)
		{
			return 0;
		}

	}
	return etat;

}

void creation(){
	couleurCourante(34,95, 125);
	rectangle(295, 645, 780, 680);
	char nom[12];

	couleurCourante(255,255, 255);
	epaisseurDeTrait(3);
	scanf("%s", nom);
	afficheChaine(nom, 25, 300, 650);
}

void listeSims(PERSONNAGE * liste){
	if (liste == NULL)
	{
		return;
	}
	couleurCourante(224,151, 61);
	PERSONNAGE * courant;
	courant=liste;
	rectangle(225, 580, 775, 680);

	couleurCourante(255,255, 255);
	epaisseurDeTrait(4);
	afficheChaine(courant->nom, 40, 230 + (550-tailleChaine(courant->nom, 40))/2, 615);
	int i=0;
	while(courant->suiv != NULL && i<3){
		i++;
		courant=courant->suiv;
		couleurCourante(224,151, 61);
		rectangle(225, 580-150*i, 775, 680-150*i);
		

		couleurCourante(255,255, 255);
		epaisseurDeTrait(4);
		afficheChaine(courant->nom, 40, 230 + (550-tailleChaine(courant->nom, 40))/2, 615-150*i);
		

	}
}

PERSONNAGE * boutonSims(PERSONNAGE * liste, int x, int y){
	if (liste == NULL)
	{
		return NULL;
	}

	PERSONNAGE * courant;
	courant=liste;
	int i=0;

	if (cliqueCarre(225, 580, 775, 680, x, y)==1)
	{
		return courant;
	}

	while(courant->suiv != NULL && i<3){
		i++;
		courant=courant->suiv;

		if (cliqueCarre(225, 580-150*i, 775, 680-150*i, x, y)==1)
		{
			return courant;
		}
	}

	return NULL;

}

int cliqueCarre(int x1, int y1, int x2, int y2, int x, int y){

	if (x>x1 && x<x2 && y>y1 && y<y2)
	{
		return 1;
	}
	return 0;
}

void gestion(PERSONNAGE * sims, LIEU lieuCourant, LIEU place[7]){
	char str[25];
	couleurCourante(255,255, 255);
	epaisseurDeTrait(3);
	afficheChaine(sims->nom, 25, 675 + (325-tailleChaine(sims->nom, 25))/2, 650);

	//sante
	sprintf(str, "Sante : %d", sims->caracteristiques.sante);
	afficheChaine(str, 25, 675 + (325-tailleChaine(str, 25))/2, 550);

	//Moral
	sprintf(str, "Moral : %d", sims->caracteristiques.moral);
	afficheChaine(str, 25, 675 + (325-tailleChaine(str, 25))/2, 500);

	//Sommeil
	sprintf(str, "Sommeil : %d", sims->caracteristiques.sommeil);
	afficheChaine(str, 25, 675 + (325-tailleChaine(str, 25))/2, 450);

	//Faim
	sprintf(str, "Faim : %d", sims->caracteristiques.faim);
	afficheChaine(str, 25, 675 + (325-tailleChaine(str, 25))/2, 400);

	//Hygiene
	sprintf(str, "Hygienne : %d", sims->caracteristiques.hygiene);
	afficheChaine(str, 25, 675 + (325-tailleChaine(str, 25))/2, 350);

	//Occup
	sprintf(str, "Occupation : %d", sims->caracteristiques.occup);
	afficheChaine(str, 25, 675 + (325-tailleChaine(str, 25))/2, 300);

	//Argent
	sprintf(str, "Argent : %d", sims->caracteristiques.argent);
	afficheChaine(str, 25, 675 + (325-tailleChaine(str, 25))/2, 250);

	for (int i = 0; i < 7; ++i)
	{
		couleurCourante(224,151, 61);
		rectangle(30, 600-70*i, 290, 660-70*i);

		couleurCourante(255,255, 255);
		epaisseurDeTrait(3);
		afficheChaine(place[i].nom_lieu, 25, 30 + (260-tailleChaine(place[i].nom_lieu, 25))/2, 620-70*i);
	}

	for (int i = 0; i < lieuCourant.nb_evt; ++i)
	{
		couleurCourante(224,151, 61);
		rectangle(360, 600-70*i, 640, 660-70*i);

		couleurCourante(255,255, 255);
		epaisseurDeTrait(3);
		afficheChaine(lieuCourant.event[i].nom_evt, 25, 360 + (260-tailleChaine(lieuCourant.event[i].nom_evt, 25))/2, 620-70*i);
	}
}

LIEU gestionLieu(LIEU place[7], LIEU courant, int x, int y){
	for (int i = 0; i < 7; ++i)
	{
		if (cliqueCarre(30, 600-70*i, 290, 660-70*i, x, y)==1)
		{
			return place[i];
		}
	}

	return courant;

}

PERSONNAGE *gestionPerso(LIEU courant, PERSONNAGE *perso, int x ,int y){

	for (int i = 0; i < courant.nb_evt; ++i)
	{
		if (cliqueCarre(360, 600-70*i, 640, 660-70*i, x, y)==1)
		{
			perso->caracteristiques.sante+=courant.event[i].sante;
			perso->caracteristiques.sante= perso->caracteristiques.sante >100 ? 100 : perso->caracteristiques.sante;

			perso->caracteristiques.argent+=courant.event[i].prix;
			

			perso->caracteristiques.sommeil+=courant.event[i].sommeil;
			perso->caracteristiques.sommeil= perso->caracteristiques.sommeil >100 ? 100 : perso->caracteristiques.sommeil;

			perso->caracteristiques.moral+=courant.event[i].moral;
			perso->caracteristiques.moral= perso->caracteristiques.moral >100 ? 100 : perso->caracteristiques.moral;

			perso->caracteristiques.faim+=courant.event[i].faim;
			perso->caracteristiques.faim= perso->caracteristiques.faim >100 ? 100 : perso->caracteristiques.faim;

			perso->caracteristiques.hygiene+=courant.event[i].hygiene;
			perso->caracteristiques.hygiene= perso->caracteristiques.hygiene >100 ? 100 : perso->caracteristiques.hygiene;

			perso->caracteristiques.occup+=courant.event[i].duree_evt;
			
			return perso;

		}
	}

	return perso;
}

void timePerso(PERSONNAGE * liste){
	if (liste == NULL)
	{
		return;
	}
	PERSONNAGE * courant;
	courant=liste;
	courant->caracteristiques.occup-=1;
	courant->caracteristiques.occup= courant->caracteristiques.occup < 0 ? 0 : courant->caracteristiques.occup;
	
	
	while(courant->suiv != NULL){

		courant=courant->suiv;
		
		courant->caracteristiques.occup-=1;
		courant->caracteristiques.occup= courant->caracteristiques.occup < 0 ? 0 : courant->caracteristiques.occup;
		
		
		

	}
}