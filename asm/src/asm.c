/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** asm
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

int fill_int_array_ter(asm_t *asm_n, int h,
asm_function_t *function_declaration_usage_place, char **split_line)
{
    for (int j = 0; op_tab[j].mnemonique != NULL; j += 1) {
        if (my_str_cmp(op_tab[j].mnemonique, split_line[h]) == OK) {
            fill_int_array_with_cmd(split_line, j, asm_n);
            return OK;
        }
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
    if (!asm_n || !function_declaration_usage_place || !split_line)
        return KO;
    for (int h = 0; split_line[h] != NULL; h += 1) {
        if (fill_int_array_ter(asm_n, h, function_declaration_usage_place,
        split_line) == OK)
            return OK;
    }
    return OK;
}

int fill_int_array(asm_t *asm_n,
asm_function_t *function_declaration_usage_place)
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

int get_len_body(asm_t *asm_n)
{
    int result = 0;

    if (!asm_n)
        return KO;
    for (int i = 0; asm_n->tab_int[i] != NULL; i += 1){
        for (int j = 0; asm_n->tab_int[i][j] != -1; j += 1){
            result += 1;
        }
    }
    asm_n->header_file->prog_size = big_endian_number(result);
    return OK;
}

int asm_function(char *filename)
{
    asm_t asm_n;
    asm_function_t function_declaration_usage_place;

    if (initialise_asm_n(&asm_n, filename) == KO)
        return KO;
    if (asm_n.file_in_array == NULL)
        return KO;
    if (asm_n.output_filename == NULL)
        return KO;
    if (get_header_information(&asm_n.header_file, asm_n.file_in_array) == KO)
        return KO;
    asm_n.tab_int = my_create_int_map(my_char_map_len(asm_n.file_in_array),
    0, 0);
    fill_int_array(&asm_n, &function_declaration_usage_place);
    if (get_len_body(&asm_n) == KO)
        return OK;
    if (write_to_file(&asm_n) == KO)
        return KO;
    free_end(asm_n.file_in_array, asm_n.output_filename, asm_n.header_file);
    return OK;
}
