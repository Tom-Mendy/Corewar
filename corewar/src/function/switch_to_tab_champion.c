/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** switch_to_tab_champion
*/

#include<stdlib.h>
#include "my_champion_list.h"
#include "corewar.h"
#include "my_vm.h"

static int load_champion_in_memory_with_load_address(champion_list_t *list_tmp,
my_vm_t *my_vm)
{
    int index = 0;

    if (list_tmp->champion->load_address == -1)
        return OK;
    if (list_tmp->champion->load_address >= MEM_SIZE)
        return KO;
    for (int i = list_tmp->champion->load_address; i < list_tmp->
    champion->load_address + list_tmp->champion->header.prog_size; i++) {
        if (my_vm->memory[i % MEM_SIZE] != -1)
            return KO;
        if (list_tmp->champion->prog_script[index] < 0)
            my_vm->memory[i % MEM_SIZE] = (int)(list_tmp->champion->
            prog_script[index]) + 256;
        else
            my_vm->memory[i % MEM_SIZE] = (int)(list_tmp->champion->
            prog_script[index]);
        index++;
    }
    return OK;
}

my_vm_t *switch_to_tab_champion(my_vm_t *my_vm)
{
    champion_list_t *list_tmp = my_vm->champion_list;

    my_vm->memory = malloc(sizeof(int) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        my_vm->memory[i] = -1;
    while (list_tmp != NULL) {
        if (load_champion_in_memory_with_load_address(list_tmp, my_vm) == KO) {
            free_vm(my_vm);
            return NULL;
        }
        list_tmp = list_tmp->next;
    }
    return my_vm;
}
