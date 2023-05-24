/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** check_instruction_validity
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

extern op_t op_tab[];

static int do_if(char **line, int i)
{
    int j = 0;
    for (j = 0; j < 17; j++) {
        if (my_str_n_cmp(line[i], op_tab[j].mnemonique,
        my_str_len(op_tab[i].mnemonique)) == 0) {
            write(2, "Error: Multiple mnemonics found on same line.\n", 47);
            return -1;
        }
    }
    return 0;
}

static int check_mn_per_line(char **line)
{
    int i = 1;
    char label_str[2] = {LABEL_CHAR, 0};

    if (!line)
        return -1;
    if (my_str_cmp(my_str_str(line[0], label_str), label_str) == 0)
        i += 1;
    for (; line[i] != NULL; i++) {
        if (do_if(line, i) == -1)
            return -1;
    }
    return 0;
}

int get_len_op_tab(void)
{
    int i = 0;
    for (; op_tab[i].mnemonique != 0; i += 1);
    return i;
}

static int check_if_mn(char *str)
{
    int j = 0;
    int return_value = 0;
    char **line = spliter(str, " ");
    char label_str[2] = {LABEL_CHAR, 0};
    int len_op_tab = get_len_op_tab();

    if (my_str_cmp(my_str_str(line[0], label_str), label_str) == 0)
        j = 1;
    for (int i = 0; i < len_op_tab; i++) {
        if (my_str_n_cmp(line[j], op_tab[i].mnemonique,
        my_str_len(op_tab[i].mnemonique)) == 0)
            break;
        if ((i + 1) == len_op_tab) {
            write(2, "Error: Line without mnemonic, or LABEL error.\n", 47);
            my_free_char_map(line);
            return -1;
        }
    }
    return_value = check_mn_per_line(line);
    my_free_char_map(line);
    return return_value;
}

int check_info(char **arr)
{
    if (arr == NULL) {
        write(2, "Error: array is NULL.\n", 23);
        return -1;
    }
    for (int i = 2; arr[i] != NULL; i++) {
        if (check_if_mn(arr[i]) == -1)
            return -1;
    }
    return 0;
}
