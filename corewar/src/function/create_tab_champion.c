/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** create_tab_champion
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_champion_list.h"
#include "corewar.h"
#include "my_vm.h"

static void put_champion_list_in_tab_champion(my_vm_t *my_vm)
{
    int index = 0;
    champion_list_t *list_tmp = my_vm->champion_list;

    while (list_tmp != NULL) {
        my_vm->tab_champion[index] = list_tmp->champion;
        index++;
        list_tmp = list_tmp->next;
    }
}

my_vm_t *create_tab_champion(my_vm_t *my_vm)
{
    int len_tab = my_list_champion_len(my_vm->champion_list);
    if (len_tab < 2) {
        free_vm(my_vm);
        if (write(2, "try with more than one champion\n", 33) == -1)
            return NULL;
        return NULL;
    }
    my_vm->tab_champion = malloc(sizeof(champion_t) * (len_tab + 1));
    if (my_vm->tab_champion == NULL) {
        free_vm(my_vm);
        return NULL;
    }
    my_vm->tab_champion[len_tab] = NULL;
    put_champion_list_in_tab_champion(my_vm);
    return my_vm;
}
