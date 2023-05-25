/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** lldi
*/

#include <unistd.h>
#include "corewar.h"

int lldi_instruction(champion_t *champion, my_vm_t *my_vm)
{
    champion->program_counter +=
    jump_instruction_with_index(my_vm->memory[champion->program_counter + 1]);
    write(1, "lldi\n", 5);
    return OK;
}
