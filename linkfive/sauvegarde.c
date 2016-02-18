#include "linkfive.h"

/*
	Fonction permettant la sauvegarde du jeu en cours
*/

void sauvegardeJeu(int **tab, int taille, struct player p1, struct player p2)
{
	FILE *fsave = NULL;
	int i, j;

	fsave = fopen("Save/save", "w");
	if (fsave == NULL)
	{
		printf("Erreur de fopen.\n");
		exit(-1);
	}
	fprintf(fsave, "Partie de %s et %s :\n", p1.nom, p2.nom);
	fprintf(fsave, "Taille de la grille : %d\n", taille);
	for (i = 0; i < taille; ++i)
	{
		for (j = 0; j < taille; ++j)
			fprintf(fsave, "tab = %d", tab[i][j]);
	}
	fprintf(fsave, "\nDernières coordonnées du joueur %s numéro %d : ligne %d colonne %d\n"
		, p1.nom, p1.numero, p1.coord.x, p1.coord.y);
	fprintf(fsave, "Dernières coordonnées du joueur %s numéro %d : ligne %d colonne %d\n"
		, p2.nom, p2.numero, p2.coord.x, p2.coord.y);

	fclose(fsave);

}




/*
	Fonction permettant le chargement de la partie demandée
*/

int **chargementJeu(int *taille, struct player *p1, struct player *p2)
{
	int **tab1 = NULL;
	int i, j, quit = 1;
	FILE *fsave = NULL;

	fsave = fopen("Save/save", "r");
	if (fsave == NULL)
	{
		printf("Erreur de fopen.\n");
		exit(-1);
	}
	while(quit)
	{
		char *tmp = (char *) malloc(sizeof(char) * 1024);
		char *tmp1 = (char *) malloc(sizeof(char) * 1024);
		fscanf(fsave, "Partie de %s et %s :\n", tmp, tmp1);
		p1->nom = strdup(tmp);
		p2->nom = strdup(tmp1);
		free(tmp);
		free(tmp1);
		fscanf(fsave, "Taille de la grille : %d\n", taille);
		tab1 = (int **) malloc(sizeof(int *) * (*taille));
		for (i = 0; i < *taille; ++i)
			tab1[i] = (int *) malloc(sizeof(int) * (*taille));
		for (i = 0; i < *taille; i++)
		{
			for (j = 0; j < *taille; j++)
			{
				tab1[i][j] = 0;
				fscanf(fsave, "tab = %d", &tab1[i][j]);
				// printf("tab[%d][%d] = %d\n", i, j, tab1[i][j]);
			}
		}
		fscanf(fsave, "\nDernières coordonnées du joueur %s numéro %d : ligne %d colonne %d\n"
		, p1->nom, &p1->numero, &p1->coord.x, &p1->coord.y);
		fscanf(fsave, "Dernières coordonnées du joueur %s numéro %d : ligne %d colonne %d\n"
		, p2->nom, &p2->numero, &p2->coord.x, &p2->coord.y);

		 printf("\nDernières coordonnées du joueur %s, numéro %d : ligne %d colonne %d\n"
		 	, p1->nom, p1->numero, p1->coord.x, p1->coord.y);
		 printf("Dernières coordonnées du joueur %s, numéro %d : ligne %d colonne %d\n"
		 	, p2->nom, p2->numero, p2->coord.x, p2->coord.y);
		 quit = 0;
	}
	fclose(fsave);
	return (tab1);
}