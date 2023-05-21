/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** asm
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
    write(output_fd, header_file, sizeof(header_t) - 1);
    close(output_fd);
    return OK;
}

int asm_function(char *filename)
{
    elt_t *list_of_bites = NULL;
    header_t *header_file = NULL;
    char *output_filename = generate_output_filename(filename);
    char **file_in_array = my_load_clear_file_in_array(filename);

    if (file_in_array == NULL)
        return KO;
    if (output_filename == NULL)
        return KO;
    if (get_header_information(&header_file, file_in_array) == KO)
        return KO;
    if (write_to_file(output_filename, header_file) == KO)
        return KO;
    put_end_list(&list_of_bites, 1);
    free_end(list_of_bites, file_in_array, output_filename, header_file);
    return OK;
}
