##
## EPITECH PROJECT, 2023
## antman
## File description:
## Makefile
##

SRC			=	main.c\
				display_help.c\

DIR_SRC =       $(addprefix src/, $(SRC))

OBJ     =       $(DIR_SRC:.c=.o)

LDLIBS		=	-L ../lib/							\
				-l my_str							\
				-l my_linked_list					\
				-l my_int							\
				-l my_char_map						\
				-l my_int_map						\

CPPFLAGS	=	-I include/							\
				-I ../include/						\
				-I ../lib/my_str/include			\
				-I ../lib/my_linked_list/include	\
				-I ../lib/my_int/include			\
				-I ../lib/my_char_map/include		\
				-I ../lib/my_int_map/include		\

CFLAGS		=	-Wall -Wextra -ggdb3

NAME	= asm

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDLIBS) $(CPPFLAGS) $(CFLAGS)

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean
