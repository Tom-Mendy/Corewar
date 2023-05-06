/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_

    int asm_function(char *filename);
    int display_help(void);
    int check_input(char *av[]);
    char *generate_output_filename(char *filename);
    int find_name_comment(char *actual_line, char **name, char **comment);
    int big_endian_number(int nb);

#endif /* !ASM_H_ */
