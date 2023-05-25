/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** live
*/

#include <unistd.h>
#include "corewar.h"

int live_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "live\n", 6);
    return OK;
}
