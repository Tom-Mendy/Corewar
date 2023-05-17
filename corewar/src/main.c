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
    if (argc < 5) {
        if (write(2, "Not enough argument.\n", 22) == -1)
            return KO;
        return KO;
    }
    return start_vm(argv);
}
