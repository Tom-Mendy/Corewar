/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_len_instruction
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

static int add_len_by_type_of_param(char *str, int *len_instruction,
asm_t *asm_n)
{
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

int get_len_instruction(char **split_line, int j, asm_t *asm_n)
{
    int len_instruction = 0;

    if (!split_line)
        return -1;
    if (op_tab[j].code == 1) {
        asm_n->tab_int[asm_n->index_int_tab] = malloc(sizeof(int) * (5));
        for (int i = 0; i < 5; i += 1) {
            asm_n->tab_int[asm_n->index_int_tab][i] = 0;
        }
        asm_n->tab_int[asm_n->index_int_tab][0] = 1;
        asm_n->index_int_tab += 1;
        asm_n->tab_int[asm_n->index_int_tab][4] = my_get_nbr(&(split_line[1][1]));
        asm_n->index_int_tab += 1;
        return 5;
    }
    if (op_tab[j].code == 2){
        return 7;
    }
    if (op_tab[j].code == 9)
        return 3;
    len_instruction = 2;
    for (int k = 1; split_line[k] != NULL; k += 1) {
        add_len_by_type_of_param(split_line[k], &len_instruction, asm_n);
    }
    return len_instruction;
}
