/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#include "my_project.h"
#include "corewar.h"

int main(int const argc, char const *argv[])
{
    if (my_str_cmp(argv[1], "-h") == 0 && argc == 2)
        return display_help();
    if (argc < 3) {
        if (write(2, "Not enough argument.\n", 21) == -1)
            return KO;
        return KO;
    }
    return start_vm(argv);
}
