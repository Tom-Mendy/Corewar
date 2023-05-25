/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ld_function
*/

#include "../../include/my_project.h"
#include "asm.h"
#include "op.h"

static int get_coding_bytes_ld_function(char *str)
{
    int coding_byte = 16;
    int len_instruction = 0;

    if (!str)
        return -1;
    add_len_by_type_of_param(str, &len_instruction);
    switch (len_instruction){
    case T_DIR:
        coding_byte += 128;
        break;
    case T_IND:
        coding_byte += 192;
        break;
    default:
        return -1;
    }
    return coding_byte;
}

static int fill_array_ld_function(asm_t *asm_n, char **split_line, int h)
{
    int coding_byte = 0;

    if (!asm_n || !split_line || h < 0)
        return KO;
    asm_n->tab_int[asm_n->index_int_tab][0] = 2;
    for (int i = 2; i < 7; i += 1) {
        asm_n->tab_int[asm_n->index_int_tab][i] = 0;
    }
    coding_byte = get_coding_bytes_ld_function(split_line[h + 1]);
    if (coding_byte == -1)
        return KO;
    asm_n->tab_int[asm_n->index_int_tab][1] = coding_byte;
    asm_n->tab_int[asm_n->index_int_tab][7] = -1;
    asm_n->tab_int[asm_n->index_int_tab][6] =
    my_get_nbr(&(split_line[h + 2][1]));
    return OK;
}

int ld_function(asm_t *asm_n, char **split_line, int h)
{
    if (!asm_n || !split_line || h < 0)
        return KO;
    if ((my_char_map_len(split_line) - h) != 3)
        return KO;
    asm_n->tab_int[asm_n->index_int_tab] = malloc(sizeof(int) * (7 + 1));
    if (asm_n->tab_int[asm_n->index_int_tab] == NULL)
        return KO;
    if (fill_array_ld_function(asm_n, split_line, h) == KO)
        return KO;
    asm_n->index_int_tab += 1;
    return OK;
}
