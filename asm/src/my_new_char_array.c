/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** my_new_char_array
*/

#include "../../include/my_project.h"
#include "asm.h"
#include "op.h"

static int nb_element_in_map(char **file_in_array)
{
    int result = 0;
    char **tmp_tab = NULL;
    char separator[3] = {' ', SEPARATOR_CHAR, 0};

    if (!file_in_array)
        return -1;
    for (int i = 2; file_in_array[i] != NULL ; i++) {
        tmp_tab = spliter(file_in_array[i], separator);
        result += my_char_map_len(tmp_tab);
        my_free_char_map(tmp_tab);
    }
    return result;
}

static int fill_result(char **file_in_array, char **result)
{
    char **tmp_tab = NULL;
    int index_result = 0;
    char separator[3] = {' ', SEPARATOR_CHAR, 0};

    if (!file_in_array || !result)
        return KO;
    for (int i = 2; file_in_array[i] != NULL ; i++) {
        tmp_tab = spliter(file_in_array[i], separator);
        for (int j = 0; tmp_tab[j] != NULL ; j++) {
            result[index_result] = generate_malloc_str_from_str(tmp_tab[j]);
            index_result += 1;
        }
        my_free_char_map(tmp_tab);
    }
    return OK;
}

char **my_new_char_array(char **file_in_array)
{
    char **result = NULL;
    int map_len = 0;

    if (!file_in_array)
        return NULL;
    map_len = nb_element_in_map(file_in_array);
    result = malloc(sizeof(char *) * (map_len + 1));
    if (result == NULL)
        return NULL;
    result[map_len] = NULL;
    if (fill_result(file_in_array, result) == KO)
        return NULL;
    if (result == NULL)
        return NULL;
    return result;
}
