/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_
    #include "op.h"
    int asm_function(char *filename);
    int display_help(void);
    int check_input(char *av[]);
    char *generate_output_filename(char *filename);
    int find_name_comment(char **file_in_array, char **name, char **comment);
    int big_endian_number(int nb);
    int clear_commente_in_file(char **file);
    void free_end(elt_t *list_of_bites, char ** file_in_array,
    char *output_filename, header_t *header_file);
    int get_header_information(header_t **header_file, char **file_in_array);
    char ** my_load_clear_file_in_array(char *filename);
    char **simplify_array(char **file_in_array);
#endif /* !ASM_H_ */
