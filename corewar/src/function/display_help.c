/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** display_help
*/

#include "my_project.h"
#include "corewar.h"

int display_help_sub(void)
{
    if (my_put_str("-n prog_number sets the next program's number.") == -1)
        return KO;
    if (my_put_str(" By default, the first free number\n") == -1)
        return KO;
    if (my_put_str("in the parameter order\n") == -1)
        return KO;
    if (my_put_str("-a load_address sets the next program's") == -1)
        return KO;
    if (my_put_str(" loading address. When no address is\n") == -1)
        return KO;
    if (my_put_str("specified, optimize the addresses so that the") == -1)
        return KO;
    if (my_put_str(" processes are as far\n") == -1)
        return KO;
    if (my_put_str("away from each other as possible. The addresses") == -1)
        return KO;
    if (my_put_str(" are MEM_SIZE modulo.\n") == -1)
        return KO;
    return OK;
}

int display_help(void)
{
    if (my_put_str("USAGE\n") == -1)
        return KO;
    if (my_put_str("./corewar [-dump nbr_cycle] [[-n prog_number]") == -1)
        return KO;
    if (my_put_str(" [-a load_address] prog_name] ...\n") == -1)
        return KO;
    if (my_put_str("DESCRIPTION\n") == -1)
        return KO;
    if (my_put_str("-dump nbr_cycle dumps the memory after the ") == -1)
        return KO;
    if (my_put_str("nbr_cycle execution (if the round isn't\n") == -1)
        return KO;
    if (my_put_str("already over) with the following format: 32") == -1)
        return KO;
    if (my_put_str("bytes/line\n") == -1)
        return KO;
    if (my_put_str("in hexadecimal (A0BCDEFE1DD3...)\n") == -1)
        return KO;
    return display_help_sub();
}
