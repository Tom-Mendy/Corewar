/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** my_map_len
*/

#include "my_int_map.h"

int my_int_map_len(int const * const * const map)
{
    int i = 0;

    if (*map == NULL)
        return -1;
    for (; map[i] != NULL; i += 1);
    return i;
}
