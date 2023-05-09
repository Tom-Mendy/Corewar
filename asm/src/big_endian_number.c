/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** big_endian_number
*/

#include <sys/stat.h>
#include "my_project.h"
#include "asm.h"
#include "op.h"

static int *nb_to_hexa_tab(unsigned int nbr)
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

int big_endian_number(int nb)
{
    int result = 0;
    int *hexa_nb = nb_to_hexa_tab(nb);
    for (int i = 0; hexa_nb[i] != -1; i += 2) {
        int tmp = hexa_nb[i];
        hexa_nb[i] = hexa_nb[i + 1];
        hexa_nb[i + 1] = tmp;
    }
    for (int i = 0; hexa_nb[i] != -1; i += 1) {
        result += (hexa_nb[i] * my_compute_power_rec(16, 7 - i));
    }
    free(hexa_nb);
    return result;
}
