/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** vm
*/

#include <unistd.h>
#include "corewar.h"

void free_vm(my_vm_t *my_vm)
{
    if (my_vm == NULL)
        return;
    if (my_vm->tab_champion)
        free(my_vm->tab_champion);
    free_champion_list(my_vm->champion_list);
    free(my_vm->memory);
    free(my_vm);
}

int start_vm(char const *argv[])
{
    my_vm_t *my_vm = NULL;
    if (argv == NULL)
        return KO;
    my_vm = init_vm(argv);
    if (my_vm == NULL)
        return KO;
    if (init_champion_register_program_counter_and_carry
    (my_vm->tab_champion) == KO) {
        free_vm(my_vm);
        return KO;
    }
    loop_corewar(my_vm);
    free_vm(my_vm);
    return OK;
}
