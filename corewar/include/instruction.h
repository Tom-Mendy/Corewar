/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction
*/

#ifndef INSTRUCTION_H_
    #define INSTRUCTION_H_

    #include "my_vm.h"
    #include "my_champion_list.h"

int add_instruction(champion_t *champion, my_vm_t *my_vm);
int aff_instruction(champion_t *champion, my_vm_t *my_vm);
int and_instruction(champion_t *champion, my_vm_t *my_vm);
int fork_instruction(champion_t *champion, my_vm_t *my_vm);
int ld_instruction(champion_t *champion, my_vm_t *my_vm);
int ldi_instruction(champion_t *champion, my_vm_t *my_vm);
int lfork_instruction(champion_t *champion, my_vm_t *my_vm);
int live_instruction(champion_t *champion, my_vm_t *my_vm);
int lld_instruction(champion_t *champion, my_vm_t *my_vm);
int lldi_instruction(champion_t *champion, my_vm_t *my_vm);
int or_instruction(champion_t *champion, my_vm_t *my_vm);
int xor_instruction(champion_t *champion, my_vm_t *my_vm);
int st_instruction(champion_t *champion, my_vm_t *my_vm);
int sti_instruction(champion_t *champion, my_vm_t *my_vm);
int sub_instruction(champion_t *champion, my_vm_t *my_vm);
int zjmp_instruction(champion_t *champion, my_vm_t *my_vm);

#endif /* !INSTRUCTION_H_ */
