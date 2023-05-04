/*
** EPITECH PROJECT, 2023
** bs_corewar
** File description:
** write-some-text
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include "my_project.h"

int put(int output_fd)
{
    int tmp = 4;
    write(output_fd, &tmp, 1);
    int *tmp_tab_len_word = nb_to_hexa_tab(my_str_len(&line[4]));
    for (int i = 0; tmp_tab_len_word[i] != -1; i += 2){
        int tmp_nb = tmp_tab_len_word[i] + (tmp_tab_len_word[i + 1] * 16);
        write(output_fd, &tmp_nb, 1);
    }
    write(output_fd, &line[4], nread - 4);
    return 0;
}

int add(int output_fd)
{
    int nb_1 = 0;
    int nb_2 = 0;
    int tmp = 1;
    write(output_fd, &tmp, 1);
    nb_1 = my_get_nbr(str_split[1]);
    int *str_hex_nb_1 = nb_to_hexa_tab(nb_1);
    nb_2 = my_get_nbr(str_split[2]);
    int *str_hex_nb_2 = nb_to_hexa_tab(nb_2);
    for (int i = 0; str_hex_nb_1[i] != -1; i += 2){
        int tmp_nb = str_hex_nb_1[i] + (str_hex_nb_1[i + 1] * 16);
        write(output_fd, &tmp_nb, 1);
    }
    for (int i = 0; str_hex_nb_2[i] != -1; i += 2){
        int tmp_nb = str_hex_nb_2[i] + (str_hex_nb_2[i + 1] * 16);
        write(output_fd, &tmp_nb, 1);
    }
    return 0;
}

int sub(int output_fd)
{
    int nb_1 = 0;
    int nb_2 = 0;
    int tmp = 2;
    write(output_fd, &tmp, 1);
    nb_1 = my_get_nbr(str_split[1]);
    int *str_hex_nb_1 = nb_to_hexa_tab(nb_1);
    nb_2 = my_get_nbr(str_split[2]);
    int *str_hex_nb_2 = nb_to_hexa_tab(nb_2);
    for (int i = 0; str_hex_nb_1[i] != -1; i += 2){
        int tmp_nb = str_hex_nb_1[i] + (str_hex_nb_1[i + 1] * 16);
        write(output_fd, &tmp_nb, 1);
    }
    for (int i = 0; str_hex_nb_2[i] != -1; i += 2){
        int tmp_nb = str_hex_nb_2[i] + (str_hex_nb_2[i + 1] * 16);
        write(output_fd, &tmp_nb, 1);
    }
    return 0;
}

int loop(FILE *source_fd, int output_fd)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, source_fd)) != -1) {
        char **str_split = spliter(line, " ");
        my_display_char_map(str_split);
        if (my_str_cmp("put", str_split[0]) == 0)
            put(output_fd);
        if (my_str_cmp("add", str_split[0]) == 0)
            add(output_fd);
        if (my_str_cmp("sub", str_split[0]) == 0)
            sub(output_fd);
        my_free_char_map(str_split);
    }
    free(line);
}

int main(int argc, char **argv)
{
    FILE *source_fd;
    char *source_file = argv[1];
    char *output_file = argv[2];
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    if (source_file == NULL)
        return -1;
    source_fd = fopen(source_file, "r");
    if (source_fd == NULL)
        return -1;
    int output_fd = open(output_file, O_CREAT | O_WRONLY, S_IRWXU);
    if (output_fd == -1)
        return -1;
    loop(source_fd, output_fd);
    fclose(source_fd);
    close(output_fd);
    return 0;
}
