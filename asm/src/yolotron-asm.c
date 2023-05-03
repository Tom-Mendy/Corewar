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

int rev_int(int nb)
{
    int result = 0;
    while (nb > 0){
        result *= 10;
        result += nb % 10;
        nb = nb / 10;
    }
    return result;
}

char *my_revstr(char *str)
{
    char temp = 'a';
    int count = my_str_len(str) + 1;
    int action = count / 2;
    for (int i = 0; i < action; i += 1) {
        temp = str[i];
        str[i] = str[count - i - 2];
        str[count - i - 2] = temp;
    }
    return str;
}

void my_put_nbr_in_file(int file_fd, int nb)
{
    int rev_nb = rev_int(nb);
    int tmp_nb = 0;
    for (int i = 0; rev_nb > 0; i += 1){
        tmp_nb = rev_nb % 10;
        write(file_fd, &tmp_nb, 1);
        rev_nb /= 10;
    }
    tmp_nb = '0';
    if (nb % 10 == 0)
        write(file_fd, &tmp_nb, 1);
}

int *nb_to_hexa_tab(unsigned int nbr)
{
    int count = 0;
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

int get_index_from_str(char *str, char c)
{
    int result = 0;
    for (; str[result] != '\0'; result += 1){
        if (str[result] == c){
            return result;
        }
    }
    return result;
}

int append_str_to_file(const char *source_file, const char *output_file)
{
    FILE *source_fd;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int nb_1 = 0;
    int nb_2 = 0;

    if (source_file == NULL)
        return -1;
    source_fd = fopen(source_file, "r");
    if (source_fd == NULL)
        return -1;
    int output_fd = open(output_file, O_CREAT | O_WRONLY, S_IRWXU);
    if (output_fd == -1)
        return -1;
    while ((nread = getline(&line, &len, source_fd)) != -1) {
        char **str_split = spliter(line, " ");
        my_display_char_map(str_split);
        if (my_str_cmp("put", str_split[0]) == 0){
            int tmp = 4;
            write(output_fd, &tmp, 1);
            int *tmp_tab_len_word = nb_to_hexa_tab(my_str_len(&line[4]));
            for (int i = 0; tmp_tab_len_word[i] != -1; i += 2){
                int tmp_nb = tmp_tab_len_word[i] + (tmp_tab_len_word[i + 1] * 16);
                write(output_fd, &tmp_nb, 1);
            }
            write(output_fd, &line[4], nread - 4);
        }
        else if (my_str_cmp("add", str_split[0]) == 0){
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
        }
        else if (my_str_cmp("sub", str_split[0]) == 0){
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
        }
        else
        my_free_char_map(str_split);
    }
    free(line);
    fclose(source_fd);
    close(output_fd);
    return 0;
}

int main(int argc, char **argv)
{
    return append_str_to_file(argv[1], argv[2]);
}