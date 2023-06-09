/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** fill_int_array_with_cmd_sub
*/

#include "../../include/my_project.h"
#include "asm.h"
#include "op.h"

int add_default_value_in_array(asm_t *asm_n, int j, int len_instruction)
{
    asm_n->tab_int[asm_n->index_int_tab] = malloc(sizeof(int) *
    (len_instruction + 1));
    if (asm_n->tab_int[asm_n->index_int_tab] == NULL)
        return KO;
    asm_n->tab_int[asm_n->index_int_tab][0] = op_tab[j].code;
    for (int i = 1; i < len_instruction; i += 1) {
        asm_n->tab_int[asm_n->index_int_tab][i] = 0;
    }
    asm_n->tab_int[asm_n->index_int_tab][len_instruction] = -1;
    return OK;
}

int fill_int_array_with_cmd_sub(char **split_line, int j, asm_t *asm_n, int h)
{
    int len_instruction = 2;

    if (!asm_n || !split_line || !*split_line || j < 0 || h < 0)
        return KO;
    if ((my_char_map_len(split_line) - h) != op_tab[j].nbr_args + 1)
        return KO;
    for (int k = 1; split_line[k] != NULL; k += 1) {
        if (add_len_by_type_of_param(split_line[k], &len_instruction) == KO)
            return KO;
    }
    if (add_default_value_in_array(asm_n, j, len_instruction) == KO)
        return KO;
    if (add_value_in_array(split_line, asm_n, h) == KO)
        return KO;
    asm_n->index_int_tab += 1;
    return OK;
}
