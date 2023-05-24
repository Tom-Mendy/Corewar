/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** asm
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

int get_len_body(asm_t *asm_n)
{
    int result = 0;

    if (!asm_n)
        return KO;
    for (int i = 0; asm_n->tab_int[i] != NULL; i += 1){
        for (int j = 0; asm_n->tab_int[i][j] != -1; j += 1){
            result += 1;
        }
    }
    asm_n->header_file->prog_size = big_endian_number(result);
    return OK;
}

int asm_function(char *filename)
{
    asm_t asm_n;
    asm_function_t function_declaration_usage_place;

    if (initialise_asm_n(&asm_n, filename) == KO)
        return KO;
    if (get_header_information(&asm_n) == KO)
        return KO;
    fill_int_array(&asm_n, &function_declaration_usage_place);
    if (get_len_body(&asm_n) == KO)
        return OK;
    if (write_to_file(&asm_n) == KO)
        return KO;
    free_end(&asm_n);
    return OK;
}
