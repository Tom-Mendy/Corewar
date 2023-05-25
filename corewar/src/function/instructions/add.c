/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** add
*/

#include <unistd.h>
#include "corewar.h"

int add_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "add\n", 5);
    return OK;
}
