/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

int main(int const argc, char *argv[])
{
    if (argc < 2) {
        write(2, "Error: Incorrect no. of arguments.\n", 36);
        return KO;
    }
    if (my_str_cmp(argv[1], "-h") == 0)
        return display_help();
    if (check_input(argv) == KO)
        return KO;

    header_t *header_file = malloc(sizeof(header_t));
    header_file->magic = COREWAR_EXEC_MAGIC;
    for (int i = 0; i < PROG_NAME_LENGTH; i += 1){
        header_file->prog_name[i] = 0;
    }
    for (int i = 0; i < COMMENT_LENGTH; i += 1){
        header_file->comment[i] = 0;
    }
    char *name = "Jon Snow";
    char *comment = "Winter is coming";
    for (int i = 0; name[i] != '\0'; i += 1){
        header_file->prog_name[i] = name[i];
    }
    for (int i = 0; comment[i] != '\0'; i += 1){
        header_file->comment[i] = comment[i];
    }
    printf("%s\n", header_file->prog_name);
    int output_fd = open("test.txt", O_CREAT | O_WRONLY, S_IRWXU);
    if (output_fd == -1)
        return KO;
    write(output_fd, header_file, sizeof(header_t));
    close(output_fd);
    return OK;
}
