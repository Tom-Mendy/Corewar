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
        int nbr_cycle;
        champion_list_t *champion_list;
    } my_vm_t;

#endif /* !MY_VM_H_ */
