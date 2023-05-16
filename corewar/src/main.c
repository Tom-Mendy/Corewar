/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#include "my_project.h"
#include "corewar.h"

int main(int const argc, char *argv[])
{
    if (my_str_cmp(argv[1], "-h") == 0)
        return display_help();
    if (parcing_argv(argc, argv) == KO)
        return KO;
    return OK;
}
