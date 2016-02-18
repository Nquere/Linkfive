
Link Five

Pour lancer l'application, il faut se placer dans le dossier du programme à l'aide du terminal et d’exécuter la commande make :
	make linkfive
puis la commande :
	./linkfive

Et le jeu se lance.


Si l’on veut supprimer les fichiers objets (type .o), il faut faire appel à la règle clean du Makefile :
	make clean

Si l’on veut supprimer les fichiers objets et l’exécutable, on fait appel à la règle fclean du Makefile :
	make fclean

Si l’on veut relancer une compilation en effaçant les fichiers objets précédents, il y a une règle re dans le Makefile :
	make re