/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** is_direct
*/

#include "../../include/my_project.h"
#include "asm.h"
#include "op.h"

int is_direct(char *str)
{
    if (!str)
        return false;
    return (str[0] == DIRECT_CHAR);
}
