/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** launch_instruction
*/

#include "corewar.h"
#include "op.h"

int (*tab_instruction[])(champion_t *champion, my_vm_t *my_vm) = {&live, &ld,
&st, &add, &sub, &and, &or, &xor, &zjmp, &ldi, &sti, &fork, &lld, &lldi, &lfork
, &aff};

int lauch_instruction(champion_t *champion, my_vm_t *my_vm)
{
    int instruction_type = my_vm->memory[champion->program_counter];

    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (instruction_type == op_tab[i].code) {
            return tab_instruction[i - 1];
        }
    }
}
