#include "linkfive.h"

/*
	Fonction permettant d'initialiser un joueur
*/

struct player initPlayer(struct player p, int *player)
{
	printf("\nChoisissez votre pseudonyme (pas d'espace): ");
	p.nom = verifScanString();
	if (*player == 1)
		p.numero = 2;
	else
	{
		p.numero = 1;
		*player = *player + 1;
	}
	return (p);
}

/*
	Fonction permettant d'initialisation une grille
*/

int **initGrille(int **tab, int taille)
{
	int i, j;

	tab = (int **) malloc(sizeof(int *) * taille);
	for (i = 0; i < taille; ++i)
		tab[i] = (int *) malloc(sizeof(int) * taille);
	for (i = 0; i < taille; i++)
	{
		for (j = 0; j < taille; j++)
			tab[i][j] = 0;
	}
	return (tab);
}

/*
	Fonction qui libére la grille allouée par la fonction initGrille
*/

void freeGrille(int **tab, int taille, struct player *p1, struct player *p2)
{
	int i;
	free(p1->nom);
	free(p2->nom);
	for (i = 0; i < taille; ++i)
		free(tab[i]);
	free(tab);
	// printf("Grille libérée\n");
}