/*
** EPITECH PROJECT, 2023
** print_champion_list
** File description:
** print_champion_list
*/

#include <stdio.h>
#include "my_champion_list.h"

void print_champion_list(champion_list_t *list)
{
    champion_list_t *list_tmp = list;
    while (list_tmp != NULL) {
        printf("prog_name: %s\nprog_num: %d\nprog_address: %d\n\
        prog_script: %s\n", list_tmp->champion->name,\
        list_tmp->champion->prog_number, list_tmp->champion->load_address,\
        list_tmp->champion->champion_script);
        list_tmp = list_tmp->next;
    }
}
