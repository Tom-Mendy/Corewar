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
    champion->program_counter +=
    jump_instruction(my_vm->memory[champion->program_counter + 1]);
    champion->carry = 1;
    return OK;
}
