##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## Makefile
##

CFLAGS	=	-Wall -Wextra -g3 -I./include

SRC	=	lib/match_flags.c\
		lib/my_addons.c\
		lib/my_getnbr.c\
		lib/my_printf.c\
		lib/my_put_base.c\
		lib/my_put_nbr_base.c\
		lib/my_put_nbr.c\
		lib/my_put_ptr.c\
		lib/my_put_str_x.c\
		lib/my_put_unsigned.c\
		lib/my_putsmth.c\
		lib/my_putstr_oct.c\
		lib/my_strlen.c\
		lib/redirect_print.c\
		source/coord_gestion.c\
		source/display.c\
		source/load_boats.c\
		source/navy.c\
		source/platform.c\
		source/game_start.c\
		source/my_file_put_nbr.c\
		source/shoot.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f $(NAME)
		rm -f source/*.o
		rm -f lib/*.o

fclean:	clean

re:	fclean all