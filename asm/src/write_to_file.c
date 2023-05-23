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

int write_to_file(char *output_filename, header_t *header_file)
{
    int output_fd = 1;

    if (output_filename == NULL || header_file == NULL)
        return KO;
    output_fd = open(output_filename, O_CREAT | O_WRONLY, S_IRWXU);
    if (output_fd == -1)
        return KO;
    write(output_fd, header_file, sizeof(header_t));
    close(output_fd);
    return OK;
}
