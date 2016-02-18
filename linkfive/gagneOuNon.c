#include "linkfive.h"


/*
	Fonction qui permet de savoir le nombre de pions alignés selon une direction donnée 
	en coordonnées x et y appellés dirx et diry grâce à un compteur et une sortie de boucle
	dès que le nombre n'est pas celui du joueur.
*/

int nbAlignesFiveOuNon(int taille, int **tab, struct player p, int dirx, int diry)
{
	/*
		Partie après les coordonnées selon les directions dirx et diry
	*/

	int c = 1, i, j;

	for (i = (p.coord.x-1) + dirx, j = (p.coord.y-1) + diry;
			i >= 0 && j >= 0 && i < taille && j < taille;
			i += dirx, j += diry)
	{
		if (tab[i][j] == p.numero)
			++c;
		else
			break;
	}
	for (i = (p.coord.x-1) - dirx, j = (p.coord.y-1) - diry;
			i >= 0 && j >= 0 && i < taille && j < taille;
			i -= dirx, j -= diry)
	{
		if (tab[i][j] == p.numero)
			++c;
		else
			break;
	}
		return c >= 5;
}

/*
	Fonction qui vérifie si le joueur gagne en horizontale, en verticale,
	en diagonale et en diagonale inverse.Elle retourne 0 ou 1 selon si il perd ou il gagne.
*/

int gagneGrille(int taille, int **tab, struct player p)
{
	return (nbAlignesFiveOuNon(taille, tab, p, 1, 0)
		|| nbAlignesFiveOuNon(taille, tab, p, 0, 1)
		|| nbAlignesFiveOuNon(taille, tab, p, 1, 1)
		|| nbAlignesFiveOuNon(taille, tab, p, -1, 1));
}

/*
	Fonction qui vérifie si la grille est remplie ou non
*/

int pleineGrille(int taille,int **tab)
{
	int cmp = 0 ,i ,j;
	for (i = 0; i < taille; i++)
	{
		for (j = 0; j < taille; j++)
		{
			if (tab[i][j] == 0)
				cmp++;
			j++;
		}
		i++;
	}
	
	return (cmp == 0);
}