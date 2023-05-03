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

int get_number_from(char *str_file)
{
    int index_mul = 0;
    int result = 0;
    u_int8_t tmp = str_file[0];
    str_file[0] = str_file[1];
    str_file[1] = tmp;
    tmp = str_file[2];
    str_file[2] = str_file[3];
    str_file[3] = tmp;
    for (int i = 3; i >= 0; i -= 1){
        if (str_file[i] != 0){
            tmp = str_file[i];
            result += tmp * (my_compute_power_rec(16, index_mul));
            index_mul += 2;
        }
    }
    return result;
}

int append_str_to_file(const char *source_file)
{
    if (source_file == NULL)
        return -1;
    char *str_file = my_load_file_in_memory(source_file);
    if (str_file == NULL)
        return -1;
    int have_to_read = 0;
    for (int i = 0; str_file[i] != '\0'|| have_to_read > i; i += 1){
        u_int8_t tmp_int = str_file[i];
        if (str_file[i] == 1 || str_file[i] == 2){
            have_to_read = i + 9;
        }
        if (str_file[i] == 1){
            int nb_1 = get_number_from(&str_file[i + 1]);
            int nb_2 = get_number_from(&str_file[i + 5]);
            my_put_nbr(nb_1 + nb_2);
            write(1, "\n", 1);
            i += 8;
        }
        if (str_file[i] == 2){
            int nb_1 = get_number_from(&str_file[i + 1]);
            int nb_2 = get_number_from(&str_file[i + 5]);
            my_put_nbr(nb_1 - nb_2);
            write(1, "\n", 1);
            i += 8;
        }
        if (str_file[i] == 4){
            int len_word = get_number_from(&str_file[i + 1]);
            i += 4;
            for (int j = 0; j < len_word; j += 1){
                write(1, &str_file[i + j], 1);
            }
            write(1, "\n", 1);
        }
    }
    free(str_file);
    return 0;
}

int main(int argc, char **argv)
{
    return append_str_to_file(argv[1]);
}