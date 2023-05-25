/*
** EPITECH PROJECT, 2023
** display_memory
** File description:
** display_memory
*/

#include <unistd.h>
#include "corewar.h"

void count_line_display_memory(int line_counter)
{
    if (line_counter % 32 == 0) {
            line_counter = 0;
            my_put_char('\n');
        } else
            my_put_char(' ');
}

int display_memory(int *memory)
{
    static const char hex_tab[] = "0123456789ABCDEF";
    int line_counter = 0;

    if (memory == NULL) {
        my_put_str("ERROR (dump_memory) : memory == NULL.\n");
        return KO;
    }
    for (int i = 0; i < MEM_SIZE; i++) {
        if (hex_tab[((unsigned char)memory[i]) / 16] == 70) {
            my_put_char(hex_tab[0]);
            my_put_char(hex_tab[0]);
        } else {
            my_put_char(hex_tab[((unsigned char)memory[i]) / 16]);
            my_put_char(hex_tab[((unsigned char)memory[i]) % 16]);
        }
        line_counter++;
        count_line_display_memory(line_counter);
    }
    return OK;
}
