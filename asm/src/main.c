/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "my_project.h"
#include "asm.h"

int main(int const argc, char *argv[])
{
    if (my_str_cmp(argv[1], "-h") == 0)
        return display_help();
    return OK;
}
