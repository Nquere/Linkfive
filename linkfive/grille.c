#include "linkfive.h"

/*
	Fonction permettant d'afficher une ligne encadré de 2 retours chariot pour 
	la présentation de la grille
*/

void printLine(int taille)
{
	int i;
	printf("\n");
	for (i = 0; i < taille+2; ++i)
		printf("_____");
	printf("\n");
}

/*
	Fonction qui affiche les différents éléments qui composent le plateau de jeu.
*/

void afficheGrille(int taille, int **tab)
{
	int nb = 1, i, j;
	printf("    ");
	for (i = 0; i < taille; i++)
		printf("   %d  ", i+1);
	for (i = 0; i < taille; ++i)
	{
		printLine(taille);
		printf(" %d ", nb++);
		for (j = 0; j < taille; ++j)
		{
			if (tab[i][j] == 0)
				printf("|   | ");
			else if (tab[i][j] == 1)
				printf("| X | ");
			else
				printf("| O | ");
		}

	}
	printf("\n");
}