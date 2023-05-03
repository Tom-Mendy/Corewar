/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** error_handling
*/

#include "my_project.h"
#include "asm.h"

int check_input(char *av[])
{
    int fd = open(av[1], O_RDONLY);
    if (av == NULL) {
        if (write(2, "Error: Input is NULL\n", 22) == -1)
            return KO;
        return KO;
    }
    if (fd == -1) {
        write(2, "Error: File does not exist.\n", 29);
        return KO;
    }
    close(fd);
    return OK;
}
