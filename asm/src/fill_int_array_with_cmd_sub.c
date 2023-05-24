/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** fill_int_array_with_cmd_sub
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

static int add_len_by_type_of_param(char *str, int *len_instruction,
asm_t *asm_n)
{
    if (!asm_n)
        return KO;
    if (is_register(str) == true) {
        *len_instruction += T_REG;
        return OK;
    }
    if (is_direct(str) == true) {
        *len_instruction += T_DIR;
        return OK;
    }
    *len_instruction += T_IND;
    return OK;
}

int fill_int_array_with_cmd_sub(char **split_line, asm_t *asm_n)
{
    int len_instruction = 2;
    for (int k = 1; split_line[k] != NULL; k += 1) {
        add_len_by_type_of_param(split_line[k], &len_instruction, asm_n);
    }
    asm_n->tab_int[asm_n->index_int_tab] = malloc(sizeof(int) * (len_instruction + 1));
    asm_n->tab_int[asm_n->index_int_tab][len_instruction] = -1;
    for (int i = 0; asm_n->tab_int[asm_n->index_int_tab][i] != -1; i += 1) {
        asm_n->tab_int[asm_n->index_int_tab][i] = 0;
    }
    asm_n->index_int_tab += 1;
    return len_instruction;
}
