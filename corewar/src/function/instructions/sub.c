/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sub
*/

#include <unistd.h>
#include "corewar.h"

int sub_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "sub\n", 4);
    return OK;
}
