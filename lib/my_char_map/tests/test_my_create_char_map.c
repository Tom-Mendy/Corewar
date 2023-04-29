/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** test_my_create_char_map
*/

#include <criterion/criterion.h>
#include "my_char_map.h"

Test(my_create_char_map, normal_case) {
    int height = 5;
    int width = 10;
    char c = 'X';
    char **map = my_create_char_map(height, width, c);

    cr_assert_not_null(map);
    for (int i = 0; i < height; i += 1) {
        cr_assert_not_null(map[i]);
        for (int j = 0; j < width; j += 1) {
            cr_assert_eq(map[i][j], c);
        }
        cr_assert_eq(map[i][width], '\0');
    }
    cr_assert_eq(map[height], NULL);
}
