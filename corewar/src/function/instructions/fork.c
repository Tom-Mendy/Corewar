/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** fork
*/

#include <unistd.h>
#include "corewar.h"

int fork_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "fork\n", 6);
    return OK;
}
