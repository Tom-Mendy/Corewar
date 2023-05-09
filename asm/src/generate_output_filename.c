/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** generate_output_filename
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

int count_nb_char_before_point(char *filename)
{
    int result = 0;
    for (; filename[result] != '\0' && filename[result] != '.' ; result += 1);
    return result;
}

char *generate_output_filename(char *filename)
{
    int nb_char_before_point = count_nb_char_before_point(filename);
    char * output_filename = malloc(sizeof(char) *
    (nb_char_before_point + 4 + 1));
    if (output_filename == NULL)
        return NULL;
    my_str_n_cpy(output_filename, filename, nb_char_before_point);
    output_filename[nb_char_before_point] = '\0';
    my_str_cat(output_filename, ".cor");
    return output_filename;
}
