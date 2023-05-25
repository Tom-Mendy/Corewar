/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** st
*/

#include <unistd.h>
#include "corewar.h"

int st_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "st\n", 4);
    return OK;
}
