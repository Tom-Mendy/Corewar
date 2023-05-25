/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-lemin-marc.mendia
** File description:
** my_list_len
*/

#include <unistd.h>
#include "my_champion_list.h"

int my_list_champion_len(champion_list_t *list)
{
    int count = 0;

    if (!list)
        return -1;
    champion_list_t *list_tmp = list;
    while (list_tmp != NULL) {
        list_tmp = list_tmp->next;
        list = list_tmp;
        count ++;
    }
    return count;
}
