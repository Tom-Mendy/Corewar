/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** my_count_char_in_char_map
*/

#include "my_char_map.h"

static void my_count_char_in_char_map_sub(char const * const * const map,
int const i, int *count_c, char const c)
{
    for (int j = 0; map[i][j] != '\0'; j += 1) {
        if (map[i][j] == c)
            count_c += 1;
    }
}

int my_count_char_in_char_map(char const * const * const map, char const c)
{
    int count_c = 0;

    if (map == NULL)
        return -1;
    if (*map == NULL)
        return -1;
    for (int i = 0; map[i] != NULL; i += 1) {
        my_count_char_in_char_map_sub(map, i, &count_c, c);
    }
    return count_c;
}
