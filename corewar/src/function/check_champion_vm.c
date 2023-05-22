/*
** EPITECH PROJECT, 2023
** check_champion
** File description:
** check_champion_vm
*/

#include "corewar.h"

int check_champion_list_vm(champion_t *champion_in_list, champion_t *champion)
{
    if (champion->prog_number != -1) {
        if (champion_in_list->prog_number == champion->prog_number) {
            return KO;
        }
    }
    if (champion->load_address != -1) {
        if (champion_in_list->load_address == champion->load_address) {
            return KO;
        }
    }
    return OK;
}

int check_champion_vm(champion_list_t *champion_list, champion_t *champion)
{
    champion_list_t *list_tmp = champion_list;

    if (champion_list == NULL)
        return OK;
    while (list_tmp->next != NULL) {
        if (check_champion_list_vm(list_tmp->champion, champion) == KO)
            return KO;
        list_tmp = list_tmp->next;
    }
    return OK;
}

champion_list_t *check_and_add_champion_in_list(champion_list_t *champion_list,
    champion_t *champion)
{
    if (check_champion_vm(champion_list, champion) == KO) {
        free_champion_list(champion_list);
        return NULL;
    }
    champion_list = add_champion_in_list(champion_list, champion);
    if (champion_list == NULL)
        return NULL;
    return champion_list;
}
