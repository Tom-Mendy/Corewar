/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** free_end
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

void free_end(asm_t *asm_n)
{
    my_free_int_map(asm_n->tab_int);
    my_free_char_map(asm_n->file_in_array);
    free(asm_n->output_filename);
    free(asm_n->header_file);
}
