/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** launch_instruction
*/

#include "corewar.h"
#include "instruction.h"
#include "op.h"

int (*tab_instruction[])(champion_t *champion, my_vm_t *my_vm) =
{&live_instruction, &ld_instruction, &st_instruction, &add_instruction,
&sub_instruction, &and_instruction, &or_instruction, &xor_instruction,
&zjmp_instruction, &ldi_instruction, &sti_instruction, &fork_instruction,
&lld_instruction, &lldi_instruction, &lfork_instruction, &aff_instruction};

int launch_instruction(champion_t *champion, my_vm_t *my_vm)
{
    int instruction_type = my_vm->memory[champion->program_counter] % MEM_SIZE;

    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (instruction_type == op_tab[i].code) {
            return tab_instruction[i](champion, my_vm);
        }
    }
    return OK;
}
