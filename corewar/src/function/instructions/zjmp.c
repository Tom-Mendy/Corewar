/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** zjmp
*/

#include <unistd.h>
#include "corewar.h"

int zjmp_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "zjmp\n", 6);
    return OK;
}
