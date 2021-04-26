/*

Jeu du pendu
Ce fichier contient les prototypes des fonctions de pendu.c

*/

#ifndef DEF_PENDU
#define DEF_PENDU

int piocherMot(char *motPioche);
int nombreAleatoire(int nombreMax);

char lireCaractere();
int gagne(int lettreTrouvee[], long tailleMot);
int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[]);

#endif
