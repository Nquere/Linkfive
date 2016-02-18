#ifndef _LINK_FIVE_H_
# define _LINK_FIVE_H_


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>


struct coord {
	int x;
	int y;
};

struct player{
	char *nom;
	int numero;
	struct coord coord;
};

// Fonctions nécessaires à l'affichage de la grille (grille.c)

void printLine(int taille);
void afficheGrille(int taille, int **tab);

// Fonctions nécessaires pour allouer et libérer la grille (init.c)

int **initGrille(int **tab, int taille);
void freeGrille(int **tab, int taille, struct player *p1, struct player *p2);
struct player initPlayer(struct player p, int *player);

// Fonctions d'affichage des menus du jeu (menu.c)

void menuInit(void);
void menuSauvegarde(int **tab1, int taille, struct player *p1, struct player *p2);
void menuAide(void);

// Fonctions concernant les coordonnées (coordonnees.c)

void entreCoord(struct player *p, int taille, int **tab);
int verifCoord(int coord, int taille);

// Fonctions pour déterminer si l'un des joueurs gagne (gagneOuNon.c)

int pleineGrille(int taille,int **tab);
int nbAlignesFiveOuNon(int taille, int **tab, struct player p, int dirx, int diry);
int gagneGrille(int taille, int **tab, struct player p);

// Fonctions du jeu en lui même (jeu.c)

void jeu(int **tab, int taille, struct player *p1, struct player *p2);
int **lancementJeu(int *taille, struct player *p1, struct player *p2, int *player);

// Fonctions de sauvegarde et chargement (sauvegarde.c)
void sauvegardeJeu(int **tab, int taille, struct player p1, struct player p2);
int **chargementJeu(int *taille, struct player *p1, struct player *p2);

// Fonctions qui vérifient les scanf ( verifscan.c )

int verifScanInt(void);
char *verifScanString(void);

#endif