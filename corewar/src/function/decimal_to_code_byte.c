/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** decimal_to_code_byte
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_champion_list.h"
#include "corewar.h"
#include "my_project.h"
#include "my_vm.h"

static int put_nb_in_struct(int nb, decimal_to_code_byte_t *tab_coding_byte)
{
    if (nb > 255 || nb < 0 || !tab_coding_byte)
        return KO;
    for (int i = 0; i < 8; i += 1){
        if (i == 0 || i == 1)
            tab_coding_byte->option_4[i] = nb % 2;
        if (i == 2 || i == 3)
            tab_coding_byte->option_3[i - 2] = nb % 2;
        if (i == 4 || i == 5)
            tab_coding_byte->option_2[i - 4] = nb % 2;
        if (i == 6 || i == 7)
            tab_coding_byte->option_1[i - 6] = nb % 2;
        nb = nb / 2;
    }
    return OK;
}

static int initialise_struct_decimal_to_code_byte(decimal_to_code_byte_t
*tab_coding_byte)
{
    if (!tab_coding_byte)
        return KO;
    for (int i = 0; i < 3; i += 1){
        tab_coding_byte->option_1[i] = 0;
        tab_coding_byte->option_2[i] = 0;
        tab_coding_byte->option_3[i] = 0;
        tab_coding_byte->option_4[i] = 0;
    }
    return OK;
}

int decimal_to_code_byte(int nb, decimal_to_code_byte_t *tab_coding_byte)
{
    if (nb > 255 || nb < 0 || !tab_coding_byte)
        return KO;
    if (initialise_struct_decimal_to_code_byte(tab_coding_byte) == KO)
        return KO;
    if (put_nb_in_struct(nb, tab_coding_byte) == KO)
        return KO;
    return OK;
}