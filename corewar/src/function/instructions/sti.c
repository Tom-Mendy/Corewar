/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sti
*/

#include <unistd.h>
#include "corewar.h"

int sti_instruction(champion_t *champion, my_vm_t *my_vm)
{
    champion->program_counter +=
    jump_instruction_with_index(my_vm->memory[champion->program_counter + 1]);
    write(1, "sti\n", 4);
    return OK;
}
