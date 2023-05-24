/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** fill_int_array_with_cmd
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

int live(asm_t *asm_n, char **split_line, int h)
{
    asm_n->tab_int[asm_n->index_int_tab] = malloc(sizeof(int) * (5 + 1));
    asm_n->tab_int[asm_n->index_int_tab][0] = 1;
    for (int i = 1; i < 5; i += 1) {
        asm_n->tab_int[asm_n->index_int_tab][i] = 0;
    }
    asm_n->tab_int[asm_n->index_int_tab][5] = -1;
    asm_n->tab_int[asm_n->index_int_tab][4] =
    my_get_nbr(&(split_line[h + 1][1]));
    asm_n->index_int_tab += 1;
    return 5;
}

int ld_function(asm_t *asm_n, char **split_line, int h)
{
    asm_n->tab_int[asm_n->index_int_tab] = malloc(sizeof(int) * (7 + 1));
    asm_n->tab_int[asm_n->index_int_tab][0] = 2;
    for (int i = 1; i < 7; i += 1) {
        asm_n->tab_int[asm_n->index_int_tab][i] = 0;
    }
    asm_n->tab_int[asm_n->index_int_tab][7] = -1;
    asm_n->tab_int[asm_n->index_int_tab][4] =
    my_get_nbr(&(split_line[h + 1][1]));
    asm_n->index_int_tab += 1;
    return 7;
}

int zjump(asm_t *asm_n)
{
    asm_n->tab_int[asm_n->index_int_tab] = malloc(sizeof(int) * (3 + 1));
    asm_n->tab_int[asm_n->index_int_tab][0] = 9;
    for (int i = 1; i < 3; i += 1) {
        asm_n->tab_int[asm_n->index_int_tab][i] = 0;
    }
    asm_n->tab_int[asm_n->index_int_tab][3] = -1;
    asm_n->index_int_tab += 1;
    return 3;
}

int fill_int_array_with_cmd(char **split_line, int j, asm_t *asm_n, int h)
{
    if (!asm_n || !split_line)
        return -1;
    if (op_tab[j].code == 1)
        return live(asm_n, split_line, h);
    if (op_tab[j].code == 2)
        return ld_function(asm_n, split_line, h);
    if (op_tab[j].code == 9)
        return zjump(asm_n);
    return fill_int_array_with_cmd_sub(op_tab[j].code, split_line, asm_n);
}
