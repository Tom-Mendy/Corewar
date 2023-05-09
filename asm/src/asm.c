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

int put_name_and_comment_in_struct(header_t *header_file, char *name,
char *comment)
{
    if (header_file == NULL || name == NULL || comment == NULL)
        return KO;
    for (int i = 0; i < PROG_NAME_LENGTH; i += 1){
        header_file->prog_name[i] = 0;
    }
    for (int i = 0; i < COMMENT_LENGTH; i += 1){
        header_file->comment[i] = 0;
    }
    for (int i = 0; name[i] != '\0'; i += 1){
        header_file->prog_name[i] = name[i];
    }
    for (int i = 0; comment[i] != '\0'; i += 1){
        header_file->comment[i] = comment[i];
    }
    return 0;
}

int init_header_file(header_t *header_file, char *filename)
{
    char *name = NULL;
    char *comment = NULL;
    char **file_in_array = my_load_file_in_array(filename);

    if (file_in_array == NULL)
        return KO;
    for (int i = 0; file_in_array[i] != NULL; i++) {
        if (find_name_comment(file_in_array[i], &name, &comment) == KO)
            return KO;
    }
    if (header_file == NULL || name == NULL || comment == NULL)
        return KO;
    header_file->magic = big_endian_number(COREWAR_EXEC_MAGIC);
    header_file->prog_size = big_endian_number(22);
    if (put_name_and_comment_in_struct(header_file, name, comment) == KO)
        return KO;
    return OK;
}

int write_to_file(char *output_filename, header_t *header_file)
{
    int output_fd = open(output_filename, O_CREAT | O_WRONLY, S_IRWXU);

    if (output_fd == -1)
        return KO;
    write(output_fd, header_file, sizeof(header_t));
    close(output_fd);
    return OK;
}

int asm_function(char *filename)
{
    char *output_filename = generate_output_filename(filename);
    header_t *header_file = NULL;

    if (output_filename == NULL)
        return 84;
    header_file = malloc(sizeof(header_t));
    if (header_file == NULL)
        return 84;
    if (init_header_file(header_file, filename) == KO)
        return KO;
    if (write_to_file(output_filename, header_file) == KO)
        return KO;
    free(output_filename);
    free(header_file);
    return OK;
}
