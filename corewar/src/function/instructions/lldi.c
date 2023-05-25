/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** lldi
*/

#include <unistd.h>
#include "corewar.h"

int lldi_instruction(champion_t *champion, my_vm_t *my_vm)
{
    write(1, "lldi\n", 6);
    return OK;
}
