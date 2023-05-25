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
    champion->program_counter += 5;
    write(1, "live\n", 5);
    return OK;
}
