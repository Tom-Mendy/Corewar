/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** loop_corewar
*/

#include "corewar.h"

int check_champion_instruction_sub(my_vm_t *my_vm, champion_t *champion)
{
    if (!my_vm || !champion)
        return KO;
    if (champion->is_alive == false)
        return KO;
    champion->cycle_to_die -= 1;
    if (champion->cycle_to_die <= 0) {
        champion->is_alive = false;
        my_vm->nb_champion_alive -= 1;
    }
    if (champion->cycle > 0) {
        champion->cycle -= 1;
        return OK;
    }
    return 1;
}

static int check_champion_instruction(my_vm_t *my_vm, champion_t *champion)
{
    int return_value = 0;
    if (!my_vm || !champion)
        return KO;
    return_value = check_champion_instruction_sub(my_vm, champion);
    if (return_value != 1)
        return return_value;
    if (champion->instruction_in_progress == true) {

    } else {
        read_instruction(champion, my_vm);
        if (champion->cycle > 0)
            champion->instruction_in_progress = true;
    }
    champion->cycle -= 1;
    return OK;
}

static int loop_check_champion_instruction(my_vm_t *my_vm)
{
    if (!my_vm)
        return KO;
    for (int i = 0; my_vm->tab_champion[i] != NULL; i++) {
        check_champion_instruction(my_vm, my_vm->tab_champion[i]);
    }
    return OK;
}

int loop_corewar(my_vm_t *my_vm)
{
    if (!my_vm)
        return KO;
    my_vm->nb_live = 0;
    my_vm->dump_cycle = 0;
    my_vm->cycle_to_die = CYCLE_TO_DIE;
    my_vm->nb_champion_alive = my_list_champion_len(my_vm->champion_list);
    if (my_vm->nb_champion_alive == -1)
        return KO;
    while (my_vm->nb_champion_alive > 1) {
        if (loop_check_champion_instruction(my_vm) == KO)
            return KO;
        my_vm->dump_cycle++;
        if (my_vm->dump_cycle == my_vm->dump)
            display_memory(my_vm->memory);
    }
    return OK;
}
