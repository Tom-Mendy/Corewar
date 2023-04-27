/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** my_map_len
*/

#include "my_char_map.h"

int my_char_map_len(char const * const * const map)
{
    int map_len = 0;

    if (map == NULL)
        return -1;
    for (; map[map_len] != NULL; map_len += 1);
    return map_len;
}
