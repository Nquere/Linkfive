#include "linkfive.h"


/*
	Fonction d'affichage du Menu principal
*/

void menuInit(void)
{
	system("clear");
	printf("\n****************************\n");
	printf("* BIENVENUE DANS LINK FIVE *");	
	printf("\n****************************\n");	
	printf("Menu :\n");
	printf("Veuillez choisir l'option que vous souhaitez :\n");
	printf("Lancer une nouvelle partie : \t\t0\n");
	printf("Charger une nouvelle partie : \t\t1\n");
	printf("Aide et Lancer une nouvelle partie : \t2\n");
	printf("Aide et Charger une nouvelle partie : \t3\n");
	printf("Quitter : \t\t\t\t4 ou autre\n");
}

/*
	Fonction qui affiche le menu de sauvegarde et appelle la fonction de sauvegarde
*/

void menuSauvegarde(int **tab1, int taille, struct player *p1, struct player *p2)
{
	int choix;
	printf("Sauvegarde de la partie ? Entrez 1 Non ? Entrez 2\n");
	choix = verifScanInt();
	if (choix == 1)
		sauvegardeJeu(tab1, taille, *p1, *p2);
	printf("Quitter la partie ? Entrez 0\n");
	choix = verifScanInt();
	if (choix == 0)
	{
		freeGrille(tab1, taille, p1, p2);
		exit(1);
	}
}

/*
	Fonction d'affichage de l'aide 
*/

void menuAide(void) {
	system("clear");
	printf("\n\t******************Aide*******************\n");
	printf("\tLe premier joueur a un avantage dès le début\n");
	printf("\tcar il est le premier à poser un pion.\n");
	printf("\tIl peut donc jouer de manière agressive.\n");
	printf("\tLe deuxième joueur lui doit avoir une bonne défense\n");
	printf("\tet créer des menaces.\n");
	printf("\n\tIl faut toujours faire attention aux noeuds de l'adversaire.\n");
	printf("\tLes noeuds sont les endroits où 2 lignes de pions se croisent.\n");
	printf("\n\tIl ne faut pas être focaliser uniquement sur ses pions,\
	\n\til faut faire attention au dernier coup de l'adversaire.\n");
	printf("\n\tGrouper ses pions est une stratégie forte\
	 \n\tmais il faut aussi occuper l'espace de jeu\n\n");
}