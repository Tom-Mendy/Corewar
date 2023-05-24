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

// static void print_vm(my_vm_t *my_vm)
// {
//     if (my_vm->tab_champion == NULL)
//         return;
//     for (int i = 0; my_vm->tab_champion[i] != NULL; i++) {
//         printf("champion name: %s\n", my_vm->tab_champion[i]
// ->header.prog_name);
//         printf("champion body:\n");
//         for (int j = my_vm->tab_champion[i]->load_address; j <
        // my_vm->tab_champion[i]->load_address + my_vm->tab_champion[i]->
        // header.prog_size; j++) {
//             printf(" %02x", my_vm->memory[j % MEM_SIZE]);
//         }
//         printf("\n");
//     }
// }

int display_memory(int *memory)
{
    static const char hex_tab[] = "0123456789ABCDEF";
    int line_counter = 0;

    if (memory == NULL) {
        my_put_str("ERROR (dump_memory) : memory == NULL.\n");
        return KO;
    }
    for (int i = 0; i < MEM_SIZE; i++) {
        if (hex_tab[((unsigned char)memory[i]) / 16] == 70) {
            my_put_char(hex_tab[0]);
            my_put_char(hex_tab[0]);
        } else {
            my_put_char(hex_tab[((unsigned char)memory[i]) / 16]);
            my_put_char(hex_tab[((unsigned char)memory[i]) % 16]);
        }
        line_counter++;
        if (line_counter % 32 == 0) {
            line_counter = 0;
            my_put_char('\n');
        } else {
            my_put_char(' ');
        }
    }
    return OK;
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
    display_memory(my_vm->memory);
    free_vm(my_vm);
    return OK;
}
