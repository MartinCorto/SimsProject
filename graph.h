int bouton1(int etat, int x, int y);
int bouton2(int etat, int x, int y);
void creation();
void listeSims(PERSONNAGE * liste);
PERSONNAGE * boutonSims(PERSONNAGE * liste,int x,int y);
int cliqueCarre(int x1, int y1, int x2, int y2, int x, int y);
void gestion(PERSONNAGE * sims, LIEU lieuCourant, LIEU place[7]);
LIEU gestionLieu(LIEU place[7], LIEU courant, int x, int y);
PERSONNAGE * gestionPerso(LIEU courant, PERSONNAGE *perso, int x ,int y);
void timePerso(PERSONNAGE * liste);