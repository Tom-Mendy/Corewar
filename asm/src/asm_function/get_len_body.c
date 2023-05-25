/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_len_body
*/

#include "../../include/my_project.h"
#include "asm.h"
#include "op.h"

int get_len_body(asm_t *asm_n)
{
    int result = 0;

    if (!asm_n)
        return KO;
    for (int i = 0; asm_n->tab_int[i] != NULL; i += 1){
        for (int j = 0; asm_n->tab_int[i][j] != -1; j += 1, result += 1);
    }
    asm_n->header_file->prog_size = big_endian_number(result);
    return OK;
}
