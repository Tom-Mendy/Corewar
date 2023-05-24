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

int fill_int_array_with_cmd_sub(char **split_line, int j, asm_t *asm_n, int h)
{
    int len_instruction = 2;

    if (!split_line)
        return KO;
    if ((my_char_map_len(split_line) - h) != op_tab[j].nbr_args + 1)
        return KO;
    for (int k = 1; split_line[k] != NULL; k += 1) {
        add_len_by_type_of_param(split_line[k], &len_instruction, asm_n);
    }
    asm_n->tab_int[asm_n->index_int_tab] = malloc(sizeof(int) *
    (len_instruction + 1));

    asm_n->tab_int[asm_n->index_int_tab][0] = op_tab[j].code;
    for (int i = 1; i < len_instruction; i += 1) {
        asm_n->tab_int[asm_n->index_int_tab][i] = 0;
    }
    asm_n->tab_int[asm_n->index_int_tab][len_instruction] = -1;
    asm_n->index_int_tab += 1;
    return len_instruction;
}
