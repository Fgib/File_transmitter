##
## EPITECH PROJECT, 2020
## bs_screensaver
## File description:
## Makefile
##

SRC			=		1080p/refresh_rate_manager.c\
					1080p/spritesheet_manager.c\
					1080p/events_manager_bis.c\
					1080p/textures_manager.c\
					1080p/initialisation.c\
					1080p/screen_printer.c\
					1080p/events_manager.c\
					1080p/lego_manager.c\
					1080p/score_drawer.c\
					1080p/window_god.c\
					720p/refresh_rate_manager2.c\
					720p/spritesheet_manager2.c\
					720p/textures_manager2.c\
					720p/initialisation2.c\
					720p/screen_printer2.c\
					720p/events_manager2.c\
					720p/lego_manager2.c\
					720p/window_god2.c\
					480p/refresh_rate_manager3.c\
					480p/spritesheet_manager3.c\
					480p/textures_manager3.c\
					480p/initialisation3.c\
					480p/screen_printer3.c\
					480p/events_manager3.c\
					480p/lego_manager3.c\
					480p/window_god3.c\
					utils.c\
					maths.c\
					main.c \

OBJ	=			$(SRC:.c=.o)

SOURCE	=		sources

NAME	=		my_hunter

DEBUG	=		@

CSFMLFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-system

#COLORS
WHITE	=		\e[0m
RED		=		\e[1;31m
GREEN	=		\e[1;32m
YELLOW	=		\e[1;33m
BLUE	=		\e[1;34m

all:			$(NAME)

$(NAME):
				$(DEBUG) printf "$(BLUE)Begining of compilation\n$(WHITE)"
				$(DEBUG) make start
				$(DEBUG) printf "$(GREEN)Successfully created objs\n\n$(WHITE)"
				$(DEBUG) printf "$(BLUE)Binary compilation\n$(WHITE)"
				$(DEBUG) make loading
				$(DEBUG) gcc -o $(NAME) $(OBJ) $(CSFMLFLAGS) -g3 -lm
				$(DEBUG) printf "$(GREEN)Binary succesfully created\n\n$(WHITE)"
				$(DEBUG) rm -rf $(OBJ)
				$(DEBUG) mv $(NAME) ..
				$(DEBUG) make play

start:	$(OBJ)

clean:
				$(DEBUG) rm -rf $(OBJ)

fclean:	clean
				$(DEBUG) rm -rf ../$(NAME)
				$(DEBUG) rm -rf *.vgcore*
				$(DEBUG) printf "$(RED)    -removed object files\n$(WHITE)"
				$(DEBUG) printf "$(RED)    -removed valgrind files\n$(WHITE)"
				$(DEBUG) printf "$(RED)    -removed emacs temporary files\n$(WHITE)"


re:	fclean all

loading:
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).$(WHITE)"
				$(DEBUG) sleep 0.055
				$(DEBUG) printf "$(YELLOW).\n$(WHITE)"
				$(DEBUG) sleep 0.055


play:
				$(DEBUG) printf "$(RED) ___  ___  ____    ____     __       _______   _______   ______        ______    ______       ______   ______    ______  \n$(WHITE)"
				$(DEBUG) printf "$(RED)|   \/   | \   \  /   /    |  |     |   ____| /  _____| /  __  \      /  ____|  /  __  \     |   _  \ |   _  \  |   _  \ \n$(WHITE)"
				$(DEBUG) printf "$(RED)|  \  /  |  \   \/   /     |  |     |  |__   |  |  __  |  |  |  |    |  |  __  |  |  |  |    |  |_) | |  |_)  | |  |_)  |\n$(WHITE)"
				$(DEBUG) printf "$(RED)|  |\/|  |   \_    _/      |  |     |   __|  |  | |_ | |  |  |  |    |  | |_ | |  |  |  |    |   _ <  |      /  |      / \n$(WHITE)"
				$(DEBUG) printf "$(RED)|  |  |  |     |  |        |  |____ |  |____ |  |__| | |  |__|  |    |  |__| | |  |__|  |    |  |_) | |  |\  \  |  |\  \ \n$(WHITE)"
				$(DEBUG) printf "$(RED)|__|  |__|     |__|        |_______||_______| \______|  \______/      \______|  \______/     |______/ |__| \__| |__| \__|\n\n$(WHITE)"