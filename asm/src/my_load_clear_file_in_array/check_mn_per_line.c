/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** check_mn_per_line
*/

#include "../../include/my_project.h"
#include "asm.h"
#include "op.h"

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

int check_mn_per_line(char **line)
{
    int i = 1;
    char label_str[2] = { LABEL_CHAR, 0 };

    if (!line)
        return -1;
    if (my_str_cmp(my_str_str(line[0], label_str), label_str) == 0)
        i += 1;
    for (; line[i] != NULL; i++) {
        if (do_if(line, i) == -1)
            return -1;
    }
    return OK;
}
