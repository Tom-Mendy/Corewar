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
    free(champion->prog_script);
    free(champion->name);
    free(champion);
}
