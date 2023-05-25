/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ldi
*/

#include <unistd.h>
#include "corewar.h"

int ldi_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "ldi\n", 4);
    return OK;
}
