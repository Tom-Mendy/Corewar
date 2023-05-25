/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** lfork
*/

#include <unistd.h>
#include "corewar.h"

int lfork_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "lfork\n", 7);
    return OK;
}
