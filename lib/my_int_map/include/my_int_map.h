/*
** EPITECH PROJECT, 2023
** my
** File description:
** my
*/

#ifndef MY_INT_MAP_H_
    #define MY_INT_MAP_H_
    #include <stdlib.h>
    #include <unistd.h>
    #include "my_macro.h"
    #include "my_str.h"
    #include "my_int.h"
    int **my_create_int_map(int const height, int const width, int const c);
    int my_display_int_map(int const * const * const map);
    int my_free_int_map(int **map);
    int my_int_line_len(int const * const int_line);
    int my_int_map_len(int const * const * const map);
    int my_count_nb_in_int_map(int const * const * const map, int const c);
#endif /* MY_INT_MAP_H_ */
