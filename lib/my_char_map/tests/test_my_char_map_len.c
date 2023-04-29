/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** test_my_create_char_map
*/

#include <criterion/criterion.h>
#include "my_char_map.h"

Test(my_char_map_len, null_map) {
    cr_assert_eq(my_char_map_len(NULL), -1);
}

Test(my_char_map_len, empty_map) {
    char **map = malloc(sizeof(char*));
    map[0] = NULL;
    cr_assert_eq(my_char_map_len(map), 0);
    free(map);
}

Test(my_char_map_len, one_row_map) {
    char **map = malloc(sizeof(char*) * 2);
    map[0] = "This is one row map.";
    map[1] = NULL;
    cr_assert_eq(my_char_map_len(map), 1);
    free(map);
}

Test(my_char_map_len, three_rows_map) {
    char **map = malloc(sizeof(char*) * 4);
    map[0] = "This is three rows map.";
    map[1] = "And this is the second row.";
    map[2] = "Finally the third.";
    map[3] = NULL;
    cr_assert_eq(my_char_map_len(map), 3);
    free(map);
}
