/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** asm
*/

#include "../../include/my_project.h"
#include "asm.h"
#include "op.h"

int asm_function(char *filename)
{
    asm_t asm_n;
    asm_function_t function_declaration_usage_place;

    if (initialise_asm_n(&asm_n, filename) == KO)
        return KO;
    if (get_header_information(&asm_n) == KO)
        return KO;
    fill_int_array(&asm_n, &function_declaration_usage_place);
    if (get_len_body(&asm_n) == KO)
        return OK;
    if (write_to_file(&asm_n) == KO)
        return KO;
    free_end(&asm_n);
    return OK;
}
