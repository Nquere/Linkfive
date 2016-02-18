#include "linkfive.h"

/*
	Fonction permettant de mettre en place les différents éléments
	avant de lancer une nouvelle partie.
*/

int **lancementJeu(int *taille, struct player *p1, struct player *p2, int *player)
{
	int **tab = NULL;

	do {
		printf("Veuillez saisir la taille de votre grille de jeu (supérieure à 5 et inférieure à 20) : ");
		*taille = verifScanInt();
	} while (*taille < 5 || *taille > 20);

	// Allocation de la grille

	tab = initGrille(tab, *taille);

	// Initialisation des joueurs

	*p1 = initPlayer(*p1, player);
	*p2 = initPlayer(*p2, player);
	return tab;
}

/*
	Fonction qui lance le jeu que ce soit une partie chargée
	ou une nouvelle partie.
*/
void jeu(int **tab1, int taille, struct player *p1, struct player *p2)
{
	do
	{
		system("clear");
		afficheGrille(taille, tab1);
		entreCoord(p1, taille, tab1);
		menuSauvegarde(tab1, taille, p1, p2);
		
		if (!(gagneGrille(taille, tab1, *p1)) && (!pleineGrille(taille, tab1)))
		{
			system("clear");
			afficheGrille(taille, tab1);
			entreCoord(p2, taille, tab1);
			menuSauvegarde(tab1, taille, p1, p2);

			if (gagneGrille(taille, tab1, *p2))
			{
				printf("\n**************");
				printf("\nJoueur 2 gagne\n");
				printf("**************\n");
				break;
			}
		}
		else if (gagneGrille(taille, tab1, *p1))
		{
			printf("\n**************");
			printf("\nJoueur 1 gagne\n");
			printf("**************\n");
			break;
		}
	} while (pleineGrille(taille, tab1) == 0);

	if (pleineGrille(taille, tab1))
	{
		printf("\n***************");
		printf("\nMatch NUL !!!!!\n");
		printf("***************\n");
	}

	freeGrille(tab1, taille, p1, p2);
}