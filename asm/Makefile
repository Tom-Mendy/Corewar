##
## EPITECH PROJECT, 2023
## antman
## File description:
## Makefile
##

SRC			=	display_help.c												\
				error_handling.c											\
				../../op.c													\
				asm_function/asm.c											\
				asm_function/generate_output_filename.c						\
				asm_function/find_name_comment.c							\
				asm_function/big_endian_number.c							\
				asm_function/free_end.c										\
				asm_function/get_header_information.c						\
				asm_function/initialise_asm_n.c								\
				asm_function/get_len_body.c									\
				asm_function/write_to_file.c								\
				fill_int_array/is_register.c								\
				fill_int_array/is_direct.c									\
				fill_int_array/ld_function.c								\
				fill_int_array/add_len_by_type_of_param.c					\
				fill_int_array/add_value_in_array.c							\
				fill_int_array/fill_int_array_with_cmd.c					\
				fill_int_array/fill_int_array_with_cmd_sub.c				\
				fill_int_array/fill_int_array.c								\
				my_load_clear_file_in_array/my_load_clear_file_in_array.c	\
				my_load_clear_file_in_array/check_instruction_validity.c	\
				my_load_clear_file_in_array/check_mn_per_line.c				\
				my_load_clear_file_in_array/clear_commente_in_file.c		\

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

NAME	= asm

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDLIBS) $(CFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf unit_tests

re:		fclean all

unit_tests: re
	mkdir unit_tests
	gcc -o unit_tests/unit_tests $(DIR_SRC) $(DIR_TESTS) $(LDLIBS)\
	--coverage -lcriterion

tests_run:	unit_tests
	./unit_tests/unit_tests

.PHONY: all clean fclean tests_run
