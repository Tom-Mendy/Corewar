/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** display_help
*/

#include "my_project.h"
#include "asm.h"

int display_help(void)
{
    if (my_put_str("USAGE\n") == -1)
        return KO;
    if (my_put_str("./asm file_name[.s]\n") == -1)
        return KO;
    if (my_put_str("DESCRIPTION\n") == -1)
        return KO;
    if (my_put_str("file_name file in assembly language to be") == -1)
        return KO;
    if (my_put_str(" converted into file_name.cor,\n") == -1)
        return KO;
    if (my_put_str("an executable in the Virtual Machine.\n") == -1)
        return KO;
    return OK;
}
