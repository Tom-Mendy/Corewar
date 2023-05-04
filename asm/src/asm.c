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

int init_header_file(header_t *header_file, char *name, char *comment)
{
    header_file->magic = COREWAR_EXEC_MAGIC;
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
}

int asm_function(char *filename)
{
    char *name = "Jon Snow";
    char *comment = "Winter is coming";
    header_t *header_file = malloc(sizeof(header_t));
    if (header_file == NULL)
        return 84;
    init_header_file(header_file, name, comment);
    int output_fd = open("test.txt", O_CREAT | O_WRONLY, S_IRWXU);
    if (output_fd == -1)
        return KO;
    write(output_fd, header_file, sizeof(header_t));
    close(output_fd);
    return OK;
}
