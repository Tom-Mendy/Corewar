/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** error_handling
*/

#include "my_project.h"
#include "asm.h"

int check_input(int const ac, char *av[])
{
    int fd = open(av[1], O_RDONLY);
    if (av == NULL) {
        if (write(2, "Error: Input is NULL\n", 22) == -1)
            return KO;
        return KO;
    }
    if (fd == -1) {
        write(2, "Error: Open file failed.\n", 26);
        return KO;
    }
    close(fd);
    return OK;
}
