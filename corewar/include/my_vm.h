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
        champion_list_t *champion_list;
        champion_list_t **champion;
    } my_vm_t;
    void free_vm(my_vm_t *my_vm);

#endif /* !MY_VM_H_ */
