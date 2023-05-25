/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** add
*/

#include <unistd.h>
#include "corewar.h"

int add_instruction(champion_t *champion, my_vm_t *my_vm)
{
    champion->program_counter +=
    jump_instruction(my_vm->memory[champion->program_counter + 1]);
    write(1, "add\n", 4);
    return OK;
}
