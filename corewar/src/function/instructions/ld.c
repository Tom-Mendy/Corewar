/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ld
*/

#include <unistd.h>
#include "corewar.h"

int ld_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "ld\n", 4);
    return OK;
}
