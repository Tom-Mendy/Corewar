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
