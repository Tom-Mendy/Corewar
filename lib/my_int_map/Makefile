##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC     	=	my_create_int_map.c			\
				my_display_int_map.c		\
				my_free_int_map.c			\
				my_int_line_len.c			\
				my_int_map_len.c			\
				my_count_nb_in_int_map.c	\

EXT			=	../my_str/src/my_put_str.c	\
				../my_str/src/my_put_char.c	\
				../my_int/src/my_put_nbr.c	\
				../my_str/src/my_str_len.c	\

DIR_SRC		=	$(addprefix src/, $(SRC))

TEST		=	\

DIR_TESTS	=	$(addprefix tests/, $(TEST))

OBJ			=	$(DIR_SRC:.c=.o)

OBJ_EXT		=	$(EXT:.c=.o)

OBJ_TESTS	=	$(DIR_TESTS:.c=.o)

CPPFLAGS	=	-I include\
				-I ../my_str/include\
				-I ../my_int/include\
				-I ../../include\
				-Wextra\
				-Wall\
				-ggdb3\

NAME		=	../libmy_int_map.a

$(NAME):		$(OBJ) ${OBJ_EXT}
	ar rcs $(NAME) $(OBJ) ${OBJ_EXT}

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf unit_tests
	rm -rf *.gcov
	rm -f $(NAME)

re: fclean all

unit_tests: re
	mkdir unit_tests
		gcc -o unit_tests/unit_tests $(DIR_SRC) $(DIR_TESTS) -I include/\
		--coverage -lcriterion

tests_run:	unit_tests
	./unit_tests/unit_tests

.PHONY: all clean fclean re tests_run
