/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** read_instruction
*/

#include "corewar.h"

int read_instruction(champion_t *champion, my_vm_t *my_vm)
{
    int instruction_type = my_vm->memory[champion->program_counter % MEM_SIZE];

    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (instruction_type == op_tab[i].code) {
            champion->cycle = op_tab[i].nbr_cycles;
            return OK;
        }
    }
    champion->program_counter++;
    return OK;
}
