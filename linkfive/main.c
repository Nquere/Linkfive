#include "linkfive.h"

/*
	Fonction principale du programme
*/

int main(void)
{
	int taille, choix, player = 0; // La taille de la grille et un indicateur de joueur
	int **tab = NULL; // La grille
	struct player p1, p2; // Les 2 joueurs de la grille

	menuInit();
	choix = verifScanInt();
	switch(choix)
	{
		case 0: // Cas où il s'agit d'une nouvelle partie
			tab = lancementJeu(&taille, &p1, &p2, &player);
			jeu(tab, taille, &p1, &p2);
			break;
		case 1: // Cas où il s'agit de charger la partie sauvegardée
			tab = chargementJeu(&taille, &p1, &p2);
			jeu(tab, taille, &p1, &p2);
			break;
		case 2:
			menuAide();
			tab = lancementJeu(&taille, &p1, &p2, &player);
			jeu(tab, taille, &p1, &p2);
			break;
		case 3:
			menuAide();
			tab = chargementJeu(&taille, &p1, &p2);
			jeu(tab, taille, &p1, &p2);
			break;
		default:
			printf("Au revoir\n");
			break;
	}

	return 0;
}