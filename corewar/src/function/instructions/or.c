/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** or
*/

#include <unistd.h>
#include "corewar.h"

int or_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "or\n", 4);
    return OK;
}
