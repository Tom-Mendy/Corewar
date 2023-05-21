/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_header_information
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

static int put_name_and_comment_in_struct(header_t *header_file, char *name,
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

static int init_header_file(header_t *header_file, char **file_in_array)
{
    char *name = NULL;
    char *comment = NULL;

    if (file_in_array == NULL)
        return KO;
    if (find_name_comment(file_in_array, &name, &comment) == KO)
        return KO;
    if (header_file == NULL || name == NULL || comment == NULL)
        return KO;
    header_file->magic = big_endian_number(COREWAR_EXEC_MAGIC);
    header_file->prog_size = big_endian_number(22);
    if (put_name_and_comment_in_struct(header_file, name, comment) == KO)
        return KO;
    free(name);
    free(comment);
    return OK;
}

int get_header_information(header_t **header_file, char **file_in_array)
{
    if (!header_file || !file_in_array)
        return KO;
    *header_file = malloc(sizeof(header_t));
    if (*header_file == NULL)
        return KO;
    if (init_header_file(*header_file, file_in_array) == KO)
        return KO;
    return OK;
}
