##
## EPITECH PROJECT, 2023
## antman
## File description:
## Makefile
##

SRC			=	linked_list/add_node.c	\
				linked_list/create_node.c	\
				linked_list/free_list.c	\
				function/display_help.c	\
				function/init_champion_list.c	\
				function/my_str_to_int.c	\
				function/free_champion.c	\
				function/vm.c

DIR_SRC		=	$(addprefix src/, $(SRC))

MAIN		=	src/main.c

TESTS		=	test_display_help.c\

DIR_TESTS	=	$(addprefix tests/, $(TESTS))

OBJ_MAIN	=	$(MAIN:.c=.o)

OBJ_DIR_SRC	=	$(DIR_SRC:.c=.o)

OBJ			=	$(OBJ_DIR_SRC) $(OBJ_MAIN)

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

NAME		=	corewar

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDLIBS) $(CPPFLAGS) $(CFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf unit_tests

re:		fclean all

unit_tests: re
	mkdir unit_tests
	gcc -o unit_tests/unit_tests $(DIR_SRC) $(DIR_TESTS) $(CPPFLAGS)\
	$(LDLIBS) --coverage -lcriterion

tests_run:	unit_tests
	./unit_tests/unit_tests

.PHONY: all clean fclean tests_run
