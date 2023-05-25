/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** add_len_by_type_of_param
*/

#include "../../include/my_project.h"
#include "asm.h"
#include "op.h"

int add_len_by_type_of_param(char *str, int *len_instruction)
{
    if (!str || !len_instruction)
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
