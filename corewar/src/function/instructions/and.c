/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** and
*/

#include <unistd.h>
#include "corewar.h"

int and_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "and\n", 4);
    return OK;
}
