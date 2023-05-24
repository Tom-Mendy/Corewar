/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** is_register
*/

#include "../../include/my_project.h"
#include "asm.h"
#include "op.h"

int is_register(char *str)
{
    if (!str)
        return false;
    return (str[0] == 'r' && my_is_num(str[1]) == true &&
    my_str_len(str) == 2);
}
