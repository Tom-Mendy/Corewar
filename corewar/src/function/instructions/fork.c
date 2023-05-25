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
    champion->program_counter += 3;
    write(1, "fork\n", 5);
    return OK;
}
