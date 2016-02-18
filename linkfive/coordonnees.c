#include "linkfive.h"

/*
	Fonction permettant d'entrer les coordonnées des joueurs dans la grille
*/

void entreCoord(struct player *p, int taille, int **tab)
{
	printf("Player %s : C'est votre tour !!\n", p->nom);
	
	do {
		printf("Entrez le numéro de la ligne voulue ^.^. : ");
		p->coord.x = verifScanInt();
	} while (!(verifCoord(p->coord.x, taille)));

	do {
		printf("\nEntrez le numéro de la colonne voulu ^.^. : ");
		p->coord.y = verifScanInt();
	} while (!(verifCoord(p->coord.y, taille)));
	
	if (tab[p->coord.x - 1][p->coord.y - 1] == 0)
	{
		if (p->numero == 1)
			tab[p->coord.x - 1][p->coord.y - 1] = 1;
		else
			tab[p->coord.x - 1][p->coord.y - 1] = 2;
	}
	else
	{
		printf("Cette case est déjà prise, veuillez recommencer :\n");
		entreCoord(p, taille, tab);
	}
	afficheGrille(taille, tab);
}

/*
	Fonction qui retourne 1 si la coordonnée entrée est comprise entre 0 et la taille
*/

int verifCoord(int coord, int taille)
{
	return (coord > 0 && coord <= taille);
}