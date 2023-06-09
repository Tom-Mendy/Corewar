/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_
    #include "../../include/op.h"
    typedef struct asm_s{
        int **tab_int;
        int index_int_tab;
        header_t *header_file;
        char *output_filename;
        char **file_in_array;
    } asm_t;
    typedef struct asm_function_s{
        char *name;
        int declaration;
        int call[];
    } asm_function_t;
    typedef struct asm_coding_bytes_s{
        int len_instruction;
        int tab_coding_byte[8];
        int k;
    }asm_coding_bytes_t;
    int asm_function(char *filename);
    int display_help(void);
    int check_input(char *av[]);
    char *generate_output_filename(char *filename);
    int find_name_comment(char **file_in_array, char **name, char **comment);
    int big_endian_number(int nb);
    int clear_commente_in_file(char **file);
    void free_end(asm_t *asm_n);
    int get_header_information(asm_t *asm_n);
    char ** my_load_clear_file_in_array(char *filename);
    int initialise_asm_n(asm_t *asm_n, char *filename);
    int is_register(char *str);
    int is_direct(char *str);
    int write_to_file(asm_t *asm_n);
    int fill_int_array_with_cmd(char **split_line, int j, asm_t *asm_n, int h);
    int fill_int_array_with_cmd_sub(char **split_line, int j, asm_t *asm_n,
    int h);
    int check_info(char **arr);
    int fill_int_array(asm_t *asm_n, asm_function_t *
    function_declaration_usage_place);
    int get_len_body(asm_t *asm_n);
    int check_mn_per_line(char **line);
    int add_len_by_type_of_param(char *str, int *len_instruction);
    int add_value_in_array(char **split_line, asm_t *asm_n, int h);
    int ld_function(asm_t *asm_n, char **split_line, int h);
#endif /* !ASM_H_ */
