/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** free_end
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

void free_end(elt_t *list_of_bites, char ** file_in_array,
char *output_filename, header_t *header_file)
{
    my_free_char_map(file_in_array);
    delete_first_element_list(&list_of_bites);
    free(list_of_bites);
    free(output_filename);
    free(header_file);
}
