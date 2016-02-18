#include "linkfive.h"

/*
	Fonction qui verifie les scanf pour les entiers
*/

int verifScanInt(void) {
	int choix, len;
	char *tmp = (char *) malloc(sizeof(char) * 1024);
	scanf("%s", tmp);
	len = strlen(tmp);
	if (len < 3 && (isdigit(tmp[0]) || isdigit(tmp[1])))
		choix = atoi(tmp);
	else
		choix = -1;
	free(tmp);
	return (choix);
}

/*
	Fonction qui vérifie les scanf des chaines de caractères
*/

char *verifScanString(void) {
	char *str;
	char *tmp = (char *) malloc(sizeof(char) * 1024);
	scanf("%s", tmp);
	str = strdup(tmp);
	free(tmp);
	return (str);
}