/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** init_champion_data
*/

#include "corewar.h"

int init_champion_register_program_counter_and_carry(champion_t ** tab_champion)
{
    if (REG_NUMBER <= 0 || !tab_champion || !*tab_champion)
        return KO;
    for (int i = 0; tab_champion[i] != NULL; i++) {
        tab_champion[i]->carry = 0;
        tab_champion[i]->program_counter = tab_champion[i]->load_address;
        tab_champion[i]->tab_register = malloc(sizeof(int) * REG_NUMBER);
        if (tab_champion[i]->tab_register == NULL)
            return KO;
        tab_champion[i]->tab_register[0] = tab_champion[i]->prog_number;
    }
    return OK;
}
