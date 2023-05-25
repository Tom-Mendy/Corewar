##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC     	=	my_create_char_map.c		\
				my_free_char_map.c			\
				my_display_char_map.c		\
				my_count_char_in_char_map.c	\
				my_char_map_len.c			\

DIR_SRC		=	$(addprefix src/, $(SRC))

EXT			=	../my_str/src/my_str_len.c	\

TEST		=	test_my_create_char_map.c\
				test_my_char_map_len.c\

DIR_TESTS	=	$(addprefix tests/, $(TEST))

OBJ_EXT		=	$(EXT:.c=.o)

OBJ_DIR_SRC	=	$(DIR_SRC:.c=.o)

OBJ			=	$(OBJ_DIR_SRC) $(OBJ_EXT)

CPPFLAGS	=	-I include				\
				-I ../my_str/include	\
				-I ../../include		\

NAME		=	../libmy_char_map.a

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf unit_tests
	rm -rf *.gcov
	rm -f $(NAME)

re: fclean all

unit_tests: re
	mkdir -p unit_tests
	gcc -o unit_tests/unit_tests $(DIR_SRC) $(EXT) $(DIR_TESTS) $(CPPFLAGS) \
	--coverage -lcriterion

tests_run:	unit_tests
	./unit_tests/unit_tests

.PHONY: all clean fclean re tests_run
