/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** my_load_clear_file_in_array
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

char ** my_load_clear_file_in_array(char *filename)
{
    char **file_in_array = NULL;

    if (!filename)
        return NULL;
    file_in_array = my_load_file_in_array(filename);
    if (file_in_array == NULL)
        return NULL;
    if (clear_commente_in_file(file_in_array) == KO){
        my_free_char_map(file_in_array);
        return NULL;
    }
    return file_in_array;
}
