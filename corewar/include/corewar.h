/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** vm
*/

#ifndef COREWAR_H_
    #define COREWAR_H_
    #define OK 0
    #define KO 84
    #include "my_champion_list.h"
    #include "my_vm.h"

    int display_help(void);
    int start_vm(char const *argv[]);
    my_vm_t *init_vm(char const *argv[]);
    int my_str_to_int(char const *str);
    void free_champion(champion_t *champion);
    champion_list_t *check_and_add_champion_in_list
    (champion_list_t *champion_list, champion_t *champion);
    int load_and_check_header_in_memory(champion_t *champion,
    char const *filename);
    my_vm_t *switch_to_tab_champion(my_vm_t *my_vm);
    my_vm_t *create_tab_champion(my_vm_t *my_vm);
    int init_champion_register_program_counter_and_carry
    (champion_t ** tab_champion);
    int display_memory(int *memory);
    int read_instruction(champion_t *champion, my_vm_t *my_vm);
    int loop_corewar(my_vm_t *my_vm);

#endif /* !COREWAR_H_ */
