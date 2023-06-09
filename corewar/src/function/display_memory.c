/*
** EPITECH PROJECT, 2023
** display_memory
** File description:
** display_memory
*/

#include <unistd.h>
#include "corewar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_first_column(int line_counter)
{
    char *hexa = int_to_hexa(line_counter);

    write(1, hexa, my_str_len(hexa));
    if (line_counter >= 256)
        write(1, "0 : ", 4);
    else if (line_counter >= 16)
        write(1, "0  : ", 5);
    else
        write(1, "0   : ", 6);
    free(hexa);
}

void display_memory_help(int i, int *line_counter,
                        int cols_counter)
{
    if (cols_counter % 32 == 0) {
        *line_counter += 2;
        cols_counter = 0;
        my_put_char('\n');
        if ((i + 1) != MEM_SIZE)
            print_first_column(*line_counter);
    } else
        my_put_char(' ');
}

int display_memory(int *memory)
{
    static const char hex_tab[] = "0123456789ABCDEF";
    int cols_counter = 0;
    int line_counter = 0;

    if (memory == NULL) {
        write(2, "ERROR (dump_memory) : memory == NULL.\n", 38);
        return KO;
    }
    write(1, "0    : ", 7);
    for (int i = 0; i < MEM_SIZE; i++) {
        if (memory[i] != -1) {
            my_put_char(hex_tab[(memory[i]) / 16]);
            my_put_char(hex_tab[(memory[i]) % 16]);
        }
        cols_counter++;
        if (memory[i] == -1)
            write(1, "00", 2);
        display_memory_help(i, &line_counter, cols_counter);
    }
    return OK;
}
