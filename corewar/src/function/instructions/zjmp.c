/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** zjmp
*/

#include <unistd.h>
#include "corewar.h"
#include "my_project.h"

static int two_complement(int num, int bits)
{
    int mask = 1 << (bits - 1);
    int complement = ~(num - 1);
    return complement & (mask - 1);
}

int zjmp_instruction(champion_t *champion, my_vm_t *my_vm)
{
    if (champion->carry != 1)
        return OK;
    champion->program_counter -= two_complement
    (my_vm->memory[(champion->program_counter + 1) % MEM_SIZE],
    my_vm->memory[(champion->program_counter + 1) % MEM_SIZE]) % IDX_MOD;
    write(1, "zjmp\n", 5);
    return OK;
}
