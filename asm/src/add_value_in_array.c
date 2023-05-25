/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** add_value_in_array
*/

#include "../../include/my_project.h"
#include "asm.h"
#include "op.h"

static int put_coding_byte_in_array(asm_t *asm_n, int tab_coding_byte[8])
{
    int coding_byte = 0;
    for (int i = 0; i < 8; i += 1){
        coding_byte += tab_coding_byte[i] * my_compute_power_rec(2, 8 - 1 - i);
    }
    asm_n->tab_int[asm_n->index_int_tab][1] = coding_byte;
    return OK;
}

static int add_value_in_array_sub_switch(int tab_coding_byte[8], int k,
int this_instruction)
{
    switch (this_instruction) {
    case T_DIR:
        tab_coding_byte[(k - 1) * 2 + 0] = 1;
        break;
    case T_IND:
        tab_coding_byte[(k - 1) * 2 + 0] = 1;
        tab_coding_byte[(k - 1) * 2 + 1] = 1;
        break;
    default:
        return KO;
    }
    return OK;
}

static int add_value_in_array_sub(char *split_line_elem, asm_t *asm_n,
asm_coding_bytes_t *asm_coding_bytes_n)
{
    int this_instruction = asm_coding_bytes_n->len_instruction;
    if (add_len_by_type_of_param(split_line_elem,
    &(asm_coding_bytes_n->len_instruction)) == KO)
        return KO;
    this_instruction = asm_coding_bytes_n->len_instruction - this_instruction;
    switch (this_instruction) {
    case T_REG:
        asm_n->tab_int[asm_n->index_int_tab][asm_coding_bytes_n->
        len_instruction - 1] = my_get_nbr(&(split_line_elem[1]));
        asm_coding_bytes_n->tab_coding_byte[(asm_coding_bytes_n->
        k - 1) * 2 + 1] = 1;
        break;
    default:
        if (add_value_in_array_sub_switch(asm_coding_bytes_n->tab_coding_byte,
        asm_coding_bytes_n->k,
        this_instruction) == KO)
            return KO;
    }
    return OK;
}

int add_value_in_array(char **split_line, asm_t *asm_n, int h)
{
    asm_coding_bytes_t asm_coding_bytes_n = {.len_instruction = 2,
    .tab_coding_byte = {0}, .k = 1 + h};

    for (; split_line[asm_coding_bytes_n.k] != NULL; asm_coding_bytes_n.k
    += 1) {
        if (add_value_in_array_sub(split_line[asm_coding_bytes_n.k],
        asm_n, &asm_coding_bytes_n) == KO)
            return KO;
    }
    if (put_coding_byte_in_array(asm_n, asm_coding_bytes_n.tab_coding_byte)
    == KO)
        return KO;
    return OK;
}
