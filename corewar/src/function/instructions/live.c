/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** live
*/

#include <unistd.h>
#include "corewar.h"
#include "my_project.h"

int live_instruction(champion_t *champion, my_vm_t *my_vm)
{
    champion->program_counter += 5;
    my_put_str("The player ");
    my_put_nbr(champion->prog_number);
    my_put_char('(');
    my_put_str(champion->header.prog_name);
    my_put_char(')');
    my_put_str("is alive.\n");
    return OK;
}
