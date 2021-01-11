##
## EPITECH PROJECT, 2020
## my_runner
## File description:
## Makefile
##

SRC			=	Draw/draw_window.c\
				Draw/draw_parallax.c\
				Draw/draw_window_bis.c\
				Engine/main.c\
				Engine/generator.c\
				Engine/manager_event.c\
				Engine/manager_sound.c\
				Engine/manager_texts.c\
				Engine/manager_coins.c\
				Engine/manager_player.c\
				Engine/manager_obstacle.c\
				Engine/manager_event_bis.c\
				Engine/manager_texts_bis.c\
				Load/load_settings.c\
				Load/load_settings_bis.c\
				Load/load_textures.c\
				Load/reinitialisation.c\
				Utils/maths.c\
				Utils/my_get.c\
				Utils/my_click.c\
				Utils/my_collision.c\
				Utils/my_create_window.c\

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-I../include -lm $(EFLAGS)

DEBUG		=	@

NAME		=	my_runner

EFLAGS		=	-Werror -Wall  -Wextra -Wpedantic

CSFMLFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

DEBUG_FLAG	=	--no-print-directory

all: do

do:	$(OBJ)
	$(DEBUG) gcc -o $(NAME) $(OBJ) $(CSFMLFLAGS) $(CFLAGS) -g3
	$(DEBUG) make $(DEBUG_FLAG) clean
	$(DEBUG) mv $(NAME) ../

clean:
	$(DEBUG) rm -rf $(OBJ)
	$(DEBUG) rm -rf *.vgcore*
	$(DEBUG) rm -rf ../$(NAME)

fclean:	clean
	$(DEBUG) rm -rf $(NAME)

re:	fclean all
