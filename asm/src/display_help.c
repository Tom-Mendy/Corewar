/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** display_help
*/

#include "my_project.h"

int display_help(bool h_option_specified)
{
    if (h_option_specified){
        if (printf("USAGE\n") < 0)
            return KO;
        if (printf("./asm file_name[.s]\n") < 0)
            return KO;
        if (printf("DESCRIPTION\n") < 0)
            return KO;
        if (printf("file_name file in assembly language to be") < 0)
            return KO;
        if (printf(" converted into file_name.cor,\n") < 0)
            return KO;
        if (printf("an executable in the Virtual Machine.\n") < 0)
            return KO;
        return OK;
    }
    return 1;
}
