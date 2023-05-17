/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** asm
*/

#ifndef COREWAR_H_
    #define COREWAR_H_
    #define OK 0
    #define KO 84
    #include "my_champion_list.h"
    #include "my_vm.h"

    int display_help(void);
<<<<<<< HEAD
    int parcing_argv(int argc, char *argv[]);
=======
    int start_vm(char const *argv[]);
    my_vm_t *init_vm(char const *argv[]);
    int my_str_to_int(char const *str);
    void free_champion(champion_t *champion);
>>>>>>> 0becb5a ([UPT] parsing)

#endif /* !COREWAR_H_ */
