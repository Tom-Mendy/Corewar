/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** free_champion
*/

#include <stdlib.h>
#include "my_champion_list.h"

void free_champion(champion_t *champion)
{
    if (champion->tab_register)
        free(champion->tab_register);
    if (champion->prog_script)
        free(champion->prog_script);
    if (champion->name)
        free(champion->name);
    if (champion)
        free(champion);
}
