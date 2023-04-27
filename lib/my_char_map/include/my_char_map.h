/*
** EPITECH PROJECT, 2023
** my
** File description:
** my
*/

#ifndef MY_CHAR_MAP_H_
    #define MY_CHAR_MAP_H_
    #include <stdlib.h>
    #include <unistd.h>
    #include "my_macro.h"
    #include "my_str.h"
    char ** my_create_char_map(int const height, int const width,\
    char const c);
    int my_display_char_map(char const * const * map);
    int my_free_char_map(char **map);
    int my_count_char_in_char_map(char const * const * const map,\
    char const c);
    int my_char_map_len(char const * const * const map);
#endif /* MY_CHAR_MAP_H_ */
