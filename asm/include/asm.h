/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_
    #include "op.h"
    typedef struct asm_s{
        int **tab_int;
        int index_int_tab;
        header_t *header_file;
        char *output_filename;
        char **file_in_array;
    }asm_t;
    typedef struct asm_function_s{
        char *name;
        int declaration;
        int call[];
    }asm_function_t;

    int asm_function(char *filename);
    int display_help(void);
    int check_input(char *av[]);
    char *generate_output_filename(char *filename);
    int find_name_comment(char **file_in_array, char **name, char **comment);
    int big_endian_number(int nb);
    int clear_commente_in_file(char **file);
    void free_end(char ** file_in_array, char *output_filename,
    header_t *header_file);
    int get_header_information(header_t **header_file, char **file_in_array);
    char ** my_load_clear_file_in_array(char *filename);
    char **simplify_array(char **file_in_array);
    char **my_new_char_array(char **file_in_array);
    int initialise_asm_n(asm_t *asm_n, char *filename);
    int is_register(char *str);
    int is_direct(char *str);
    int write_to_file(char *output_filename, header_t *header_file);
    int get_len_instruction(char **split_line, int j, asm_t *asm_n);
#endif /* !ASM_H_ */
