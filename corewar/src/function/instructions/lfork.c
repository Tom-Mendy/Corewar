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
    champion->program_counter += 3;
    write(1, "lfork\n", 6);
    return OK;
}
