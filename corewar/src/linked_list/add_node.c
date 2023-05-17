/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-lemin-marc.mendia
** File description:
** add_node
*/

#include <unistd.h>
#include "my_champion_list.h"

champion_list_t *add_champion_in_list(champion_list_t *list,
                                        champion_t *champion)
{
    champion_list_t *node = create_champion(champion);
    champion_list_t *list_tmp = list;
    if (list_tmp == NULL)
        return node;
    while (list_tmp->next != NULL)
        list_tmp = list_tmp->next;
    list_tmp->next = node;
    node->prev = list_tmp;
    return list;
}
