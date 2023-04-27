/*
** EPITECH PROJECT, 2023
** create map
** File description:
** create_map
*/

#include "my_int_map.h"

int **my_create_int_map(int const height, int const width, int const c)
{
    int **map = malloc(sizeof(int *) * (height + 1));

    if (map == NULL)
        return NULL;
    for (int i = 0; i < height; i += 1){
        map[i] = malloc(sizeof(int) * (width + 1));
        if (map[i] == NULL)
            return NULL;
        for (int j = 0; j < width; j += 1){
            map[i][j] = c;
        }
        map[i][width] = -1;
    }
    map[height] = NULL;
    return map;
}
