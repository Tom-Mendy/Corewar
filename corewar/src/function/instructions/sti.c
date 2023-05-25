/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sti
*/

#include <unistd.h>
#include "corewar.h"

int sti_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "sti\n", 5);
    return OK;
}
