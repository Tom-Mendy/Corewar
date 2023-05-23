/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** load_header_in_memory
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "corewar.h"
#include "my_str.h"

static int transform_big_to_little(int value)
{
    int new_value = 0;

    new_value |= (value & 0xFF000000) >> 24;
    new_value |= (value & 0x00FF0000) >> 8;
    new_value |= (value & 0x0000FF00) << 8;
    new_value |= (value & 0x000000FF) << 24;

    return new_value;
}

static int load_body_in_memory(int fd, champion_t *champion)
{
    char buffer[1];
    int nread = 0;

    if (champion->header.prog_size < 0) {
        close(fd);
        return KO;
    }
    champion->prog_script = malloc(sizeof(char) * champion->header.prog_size);
    nread = read(fd, champion->prog_script, champion->header.prog_size);
    if (nread < champion->header.prog_size) {
        close(fd);
        return KO;
    }
    if ((read(fd, buffer, 1)) != 0) {
        close(fd);
        return KO;
    }
    close(fd);
    return OK;
}

static int load_header_and_body_in_memory(champion_t *champion,
char const *filename)
{
    int nread = 0;
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        if (write(2, "failed to open file\n", 2) == -1)
            return KO;
        return KO;
    }
    nread = read(fd, &(champion->header), sizeof(header_t));
    if (nread < (int)sizeof(header_t)) {
        close(fd);
        return KO;
    }
    champion->header.magic = transform_big_to_little(champion->header.magic);
    champion->header.prog_size =
    transform_big_to_little(champion->header.prog_size);
    return load_body_in_memory(fd, champion);
}

int load_and_check_header_in_memory(champion_t *champion,
char const *filename)
{
    if (load_header_and_body_in_memory(champion, filename) == KO)
        return KO;
    if (champion->header.magic != COREWAR_EXEC_MAGIC) {
        return KO;
    }
    return OK;
}
