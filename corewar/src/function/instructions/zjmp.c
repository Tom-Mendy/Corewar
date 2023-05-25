/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** zjmp
*/

#include <unistd.h>
#include "corewar.h"
#include "my_project.h"

int zjmp_instruction(champion_t *champion, my_vm_t *my_vm)
{
    if (champion->carry != 1)
        return OK;
    champion->program_counter = champion->load_address;
    return OK;
}
