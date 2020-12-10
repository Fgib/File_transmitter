##
## EPITECH PROJECT, 2020
## my_runner
## File description:
## Makefile
##

SRC			=	obstacle_manager.c\
				player_manager.c\
				load_settings.c\
				load_textures.c\
				event_manager.c\
				draw_parallax.c\
				draw_window.c\
				my_get.c\
				maths.c\
				main.c\

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Iinclude -lm $(EFLAGS)

DEBUG		=	@

NAME		=	my_runner

EFLAGS		=	-Werror -Wall  -Wextra -Wpedantic

CSFMLFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

DEBUG_FLAG	=	--no-print-directory

all: do

do:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFMLFLAGS) $(CFLAGS) -g3
	$(DEBUG) make $(DEBUG_FLAG) clean
	$(DEBUG) printf "\nCompilation success\n"

clean:
	$(DEBUG) rm -rf $(OBJ)
	$(DEBUG) rm -rf *.vgcore*

fclean:	clean
	$(DEBUG) rm -rf $(NAME)

re:	fclean all