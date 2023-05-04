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

int add(int *i)
{
    if (str_file[*i] == 1){
        int nb_1 = get_number_from(&str_file[*i + 1]);
        int nb_2 = get_number_from(&str_file[*i + 5]);
        my_put_nbr(nb_1 + nb_2);
        write(1, "\n", 1);
        *i += 8;
    }
    return 0;
}

int sub(int *i)
{
    if (str_file[*i] == 2){
        int nb_1 = get_number_from(&str_file[*i + 1]);
        int nb_2 = get_number_from(&str_file[*i + 5]);
        my_put_nbr(nb_1 - nb_2);
        write(1, "\n", 1);
        *i += 8;
    }
    return 0;
}

int put(int * i)
{
    if (str_file[*i] == 4){
        int len_word = get_number_from(&str_file[*i + 1]);
        *i += 4;
        for (int j = 0; j < len_word; j += 1){
            write(1, &str_file[*i + j], 1);
        }
        write(1, "\n", 1);
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argv[1] == NULL)
        return -1;
    char *str_file = my_load_file_in_memory(argv[1]);
    if (str_file == NULL)
        return -1;
    int have_to_read = 0;
    for (int i = 0; str_file[i] != '\0'|| have_to_read > i; i += 1){
        u_int8_t tmp_int = str_file[i];
        if (str_file[i] == 1 || str_file[i] == 2)
            have_to_read = i + 9;
        add(&i);
        sub(&i);
        put(&i);
    }
    free(str_file);
    return 0;
}
