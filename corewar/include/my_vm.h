/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** my_vm
*/

#include "my_champion_list.h"

#ifndef MY_VM_H_
    #define MY_VM_H_

    typedef struct my_vm_s {
        int dump;
        int *memory;
        int cycle_to_die;
        int dump_cycle;
        int nb_champion_alive;
        int nb_live;
        champion_list_t *champion_list;
        champion_t **tab_champion;
    } my_vm_t;
    typedef struct decimal_to_code_byte_s{
        char option_1[3];
        char option_2[3];
        char option_3[3];
        char option_4[3];
    }decimal_to_code_byte_t;
    void free_vm(my_vm_t *my_vm);
    int decimal_to_code_byte(int nb, decimal_to_code_byte_t *toto);

#endif /* !MY_VM_H_ */
