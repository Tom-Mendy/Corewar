/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** and
*/

#include <unistd.h>
#include "corewar.h"

int and_instruction(champion_t *champion, my_vm_t *my_vm)
{
    champion->program_counter +=
    jump_instruction(my_vm->memory[champion->program_counter + 1]);
    write(1, "and\n", 4);
    return OK;
}
