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

int *nb_to_hexa_tab(unsigned int nbr)
{
    unsigned int save_nbr = nbr;
    int *result = malloc(sizeof(int) * 9);
    for (int i = 0; i < 9; i += 1){
        result[i] = 0;
    }
    for (int i = 0; save_nbr > 0 ; i += 1) {
        result[i] = save_nbr % 16;
        save_nbr = save_nbr / 16;
    }
    result[8] = -1;
    return result;
}

void init_magic(header_t *header_file)
{
    header_file->magic = 0;
    int *hexa_nb = nb_to_hexa_tab(COREWAR_EXEC_MAGIC);

    for (int i = 0; hexa_nb[i] != -1; i += 2) {
        int tmp = hexa_nb[i];
        hexa_nb[i] = hexa_nb[i + 1];
        hexa_nb[i + 1] = tmp;
    }
    for (int i = 0; hexa_nb[i] != -1; i += 1) {
        header_file->magic += (hexa_nb[i] * my_compute_power_rec(16, 7 - i));
    }
}

int init_header_file(header_t *header_file, char *name, char *comment)
{
    if (header_file == NULL || name == NULL || comment == NULL)
        return KO;
    init_magic(header_file);
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
    return OK;
}

int asm_function(char *filename)
{
    char *name = "Jon Snow";
    char *comment = "Winter is coming";
    char *output_filename = generate_output_filename(filename);
    if (output_filename == NULL)
        return 84;
    header_t *header_file = malloc(sizeof(header_t));
    if (header_file == NULL)
        return 84;
    if (init_header_file(header_file, name, comment) == KO)
        return KO;
    int output_fd = open(output_filename, O_CREAT | O_WRONLY, S_IRWXU);
    if (output_fd == -1)
        return KO;
    write(output_fd, header_file, sizeof(header_t));
    close(output_fd);
    return OK;
}
