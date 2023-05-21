/*
** EPITECH PROJECT, 2023
** check_champion
** File description:
** check_champion_vm
*/

#include "corewar.h"

int check_champion_vm(champion_list_t *list)
{
    champion_list_t *list_tmp = list;

    if (list == NULL)
        return KO;
    while (list_tmp->next != NULL) {
        if (list_tmp->champion->load_address ==
            list_tmp->next->champion->load_address) {
            return KO;
        }
        if (list_tmp->champion->prog_number ==
            list_tmp->next->champion->prog_number) {
            return KO;
        }
        list_tmp = list_tmp->next;
    }
    print_champion_list(list_tmp);
    return OK;
}
