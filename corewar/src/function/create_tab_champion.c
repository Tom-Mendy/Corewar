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
#include "my_project.h"
#include "my_vm.h"

static int prog_number_is_available(int prog_number,
champion_list_t *champion_list)
{
    champion_list_t *list_tmp = champion_list;
    while (list_tmp != NULL) {
        if (prog_number == list_tmp->champion->prog_number)
            return 1;
        list_tmp = list_tmp->next;
    }
    return OK;
}

static int check_and_set_prog_number(champion_list_t *champion_list,
champion_t *champion)
{
    if (champion->prog_number != -1 && (champion->prog_number < 1 ||
    champion->prog_number > MAX_ARGS_NUMBER)) {
        if (write(2, "-n invalid:\nEnter a number between 1 and ", 42) ==
        -1)
            return KO;
        if (my_put_nbr(MAX_ARGS_NUMBER) == -1)
            return KO;
        if (write(2, " included\n", 11) == -1)
            return KO;
        return KO;
    }
    if (champion->prog_number != -1)
        return OK;
    for (int i = 1; i <= MAX_ARGS_NUMBER; i++) {
        if (prog_number_is_available(i, champion_list) == OK) {
            champion->prog_number = i;
            return OK;
        }
    }
    return OK;
}

static int swittch_list_to_tab_champion_and_set_and_check_prog_nbr
(my_vm_t *my_vm)
{
    int index = 0;
    champion_list_t *list_tmp = my_vm->champion_list;

    while (list_tmp != NULL) {
        if (check_and_set_prog_number(my_vm->champion_list,
        list_tmp->champion) == KO) {
            free_vm(my_vm);
            return KO;
        }
        my_vm->tab_champion[index] = list_tmp->champion;
        index++;
        list_tmp = list_tmp->next;
    }
    return OK;
}

static my_vm_t *error_message(void)
{
    if (write(2, "try with less than ", 20) == -1)
        return NULL;
    if (my_put_nbr(MAX_ARGS_NUMBER + 1) == -1)
        return NULL;
    if (write(2, " champion\n", 11) == -1)
        return NULL;
    return NULL;
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
    if (len_tab > MAX_ARGS_NUMBER) {
        free_vm(my_vm);
        return error_message();
    }
    my_vm->tab_champion = malloc(sizeof(champion_t) * (len_tab + 1));
    if (my_vm->tab_champion == NULL) {
        free_vm(my_vm);
        return NULL;
    }
    my_vm->tab_champion[len_tab] = NULL;
    if (swittch_list_to_tab_champion_and_set_and_check_prog_nbr(my_vm) == KO)
        return NULL;
    return my_vm;
}
