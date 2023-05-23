/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** write_to_file
*/

#include <sys/stat.h>
#include "my_project.h"
#include "asm.h"
#include "op.h"

int write_to_file(asm_t *asm_n)
{
    int output_fd = 1;

    if (asm_n->output_filename == NULL || asm_n->header_file == NULL)
        return KO;
    output_fd = open(asm_n->output_filename, O_CREAT | O_WRONLY, S_IRWXU);
    if (output_fd == -1)
        return KO;
    write(output_fd, asm_n->header_file, sizeof(header_t));
    for (int i = 0; asm_n->tab_int[i] != NULL; i += 1){
        for (int j = 0; asm_n->tab_int[i][j] != -1; j += 1){
            write(output_fd, &(asm_n->tab_int[i][j]), 1);
        }
    }
    close(output_fd);
    return OK;
}
