/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** free_end
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

void free_end(char ** file_in_array, char *output_filename,
header_t *header_file)
{
    my_free_char_map(file_in_array);
    free(output_filename);
    free(header_file);
}
