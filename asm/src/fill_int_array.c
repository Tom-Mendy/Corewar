/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** fill_int_array
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

int know_instruction(char **split_line, int j, asm_t *asm_n, int h)
{
    if (my_str_cmp(op_tab[j].mnemonique, split_line[h]) == OK) {
        if (fill_int_array_with_cmd(split_line, j, asm_n, h) == KO)
            return KO;
        return OK;
    }
    return 1;
}

int fill_int_array_ter(asm_t *asm_n, int h,
asm_function_t *function_declaration_usage_place, char **split_line)
{
    int return_value = 0;

    if (!asm_n || !function_declaration_usage_place || !split_line)
        return KO;
    for (int j = 0; op_tab[j].mnemonique != NULL; j += 1) {
        return_value = know_instruction(split_line, j, asm_n, h);
        if (return_value != 1)
            return return_value;
        if (split_line[h][my_str_len(split_line[h]) - 1] == LABEL_CHAR) {
            function_declaration_usage_place->declaration =
            asm_n->index_int_tab;
        }
    }
    return 1;
}

int fill_int_array_sub(asm_t *asm_n,
asm_function_t *function_declaration_usage_place, char **split_line)
{
    int return_value = 0;

    if (!asm_n || !function_declaration_usage_place || !split_line)
        return KO;
    for (int h = 0; split_line[h] != NULL; h += 1) {
        return_value = fill_int_array_ter(asm_n, h,
        function_declaration_usage_place, split_line);
        if (return_value != 1)
            return return_value;
    }
    return OK;
}

int fill_int_array(asm_t *asm_n, asm_function_t *
function_declaration_usage_place)
{
    asm_n->index_int_tab = 0;

    if (!asm_n || !function_declaration_usage_place)
        return KO;
    asm_n->tab_int = malloc(sizeof(int *) *
    (my_char_map_len(asm_n->file_in_array) - 2 + 1));
    asm_n->tab_int[my_char_map_len(asm_n->file_in_array) - 2] = NULL;
    for (int i = 2; asm_n->file_in_array[i] != NULL; i += 1) {
        char **split_line = spliter(asm_n->file_in_array[i], " ,");
        if (fill_int_array_sub(asm_n, function_declaration_usage_place,
        split_line) == KO)
            return KO;
        my_free_char_map(split_line);
    }
    return OK;
}
