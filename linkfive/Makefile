NAME = linkfive
OBJ = $(SRC:.c=.o)
SRC = main.c \
	  menu.c \
	  sauvegarde.c \
	  gagneOuNon.c \
	  coordonnees.c \
	  verifscan.c \
	  grille.c \
	  init.c \
	  jeu.c
CFLAGS = -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@($(CC) -o $(NAME) $(OBJ))
	@echo "\033[35m\"$(NAME)\" created !\033[0m"

%.o: %.c
	@($(CC) -c $(SRC) $(CFLAGS))

clean :
	@(rm -f $(OBJ))
	@echo "\033[31mObject files deleted\033[0m"

fclean : clean
	@(rm -f $(NAME))
	@echo "\033[31m\"$(NAME)\" deleted\033[0m"

re : fclean all