/*
** EPITECH PROJECT, 2023
** free_int_map
** File description:
** free_int_map
*/

#include "my_int_map.h"

int my_free_int_map(int **map)
{
    if (map == NULL)
        return OK;
    for (int i = 0; map[i] != NULL; i += 1){
        free(map[i]);
    }
    free(map);
    return OK;
}
