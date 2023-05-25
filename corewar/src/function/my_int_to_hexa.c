/*
** EPITECH PROJECT, 2023
** int to hexa
** File description:
** my_in_to_hexa
*/

#include <unistd.h>
#include "corewar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *int_to_hexa(int nbr)
{
    int len = 0;
    int tmp = nbr;
    for (; tmp != 0; len++) {
        tmp /= 16;
    }
    char *hexa = malloc(sizeof(char) * (len + 1));
    if (hexa == NULL)
        return NULL;
    hexa[len] = '\0';
    for (int i = len - 1; nbr != 0; i--) {
        int j = nbr % 16;
        if (j < 10)
            hexa[i] = j + '0';
        else
            hexa[i] = j + 'A' - 10;
        nbr /= 16;
    }
    return hexa;
}
