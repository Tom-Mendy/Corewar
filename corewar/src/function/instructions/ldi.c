/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ldi
*/

#include <unistd.h>
#include "corewar.h"

int ldi_instruction(champion_t *champion, my_vm_t *my_vm)
{
    champion->carry = 1;
    champion->program_counter +=
    jump_instruction_with_index(my_vm->memory[champion->program_counter + 1]);
    return OK;
}
