/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "../../include/my_project.h"
#include "asm.h"
#include "op.h"

int main(int const argc, char *argv[])
{
    if (argc < 2) {
        if (write(2, "Error: Incorrect no. of arguments.\n", 36) == -1)
            return KO;
        return KO;
    }
    if (my_str_cmp(argv[1], "-h") == 0)
        return display_help();
    if (check_input(argv) == KO)
        return KO;
    return asm_function(argv[1]);
}
