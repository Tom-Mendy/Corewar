/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** initialise_asm_n
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

int initialise_asm_n(asm_t *asm_n, char *filename)
{
    if (!asm_n || !filename)
        return KO;
    asm_n->file_in_array = my_load_clear_file_in_array(filename);
    asm_n->header_file = NULL;
    asm_n->index_int_tab = 0;
    asm_n->output_filename = generate_output_filename(filename);
    asm_n->tab_int = NULL;
    return OK;
}
