/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** my_count_nb_in_int_map
*/

#include "my_int_map.h"

static void my_count_nb_in_int_map_sub(int const * const * const map,
int const i, int *count_c, int const c)
{
    for (int j = 0; map[i][j] != -1; j += 1) {
        if (map[i][j] == c)
            count_c += 1;
    }
}

int my_count_nb_in_int_map(int const * const * const map, int const c)
{
    int count_c = 0;

    for (int i = 0; map[i] != NULL; i += 1) {
        my_count_nb_in_int_map_sub(map, i, &count_c, c);
    }
    return count_c;
}
