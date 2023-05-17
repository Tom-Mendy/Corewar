/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-lemin-marc.mendia
** File description:
** free_list
*/

#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"
#include "my_champion_list.h"

void free_champion_list(champion_list_t *list)
{
    champion_list_t *list_tmp = list;
    while (list_tmp != NULL) {
        list_tmp = list_tmp->next;
        free_champion(list->champion);
        free(list);
        list = list_tmp;
    }
}
