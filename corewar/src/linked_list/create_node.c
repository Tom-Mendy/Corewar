/*
** EPITECH PROJECT, 2023
** create_node
** File description:
** create_node
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_champion_list.h"

champion_list_t *create_champion(champion_t *champion)
{
    champion_list_t *new_node = malloc(sizeof(champion_list_t));
    if (!new_node)
        return NULL;
    new_node->champion = champion;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
