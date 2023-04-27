/*
** EPITECH PROJECT, 2023
** create map
** File description:
** create_map
*/

#include "my_char_map.h"

int my_display_char_map(char const * const * map)
{
    if (map == NULL)
        return KO;
    for (int i = 0; map[i] != NULL; i += 1) {
        if (write(1, map[i], my_str_len(map[i])) == -1)
            return KO;
        if (write(1, "\n", 1) == -1)
            return KO;
    }
    return OK;
}
