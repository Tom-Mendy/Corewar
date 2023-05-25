/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** aff
*/

#include <unistd.h>
#include "corewar.h"

int aff_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "aff\n", 5);
    return OK;
}
