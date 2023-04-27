/*
** EPITECH PROJECT, 2023
** create map
** File description:
** create_map
*/

#include "my_char_map.h"

int my_free_char_map(char **map)
{
    if (map == NULL)
        return OK;
    for (int i = 0; map[i] != NULL; i += 1){
        free(map[i]);
    }
    free(map);
    return OK;
}
