/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** init_champion_list
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "my_champion_list.h"
#include "corewar.h"
#include "my_str.h"

static champion_list_t *get_champion_data(champion_t *champion,
champion_list_t *champion_list, char const *argv[], int *i)
{
    if (argv[(*i)] == NULL) {
        free_champion_list(champion_list);
        return NULL;
    }
    champion->name = malloc(sizeof(char) * (my_str_len(argv[(*i)]) + 1));
    if (champion->name == NULL) {
        free_champion_list(champion_list);
        return NULL;
    }
    my_str_cpy(champion->name, argv[(*i)]);
    if (load_and_check_header_in_memory(champion, argv[(*i)]) == KO) {
        free_champion_list(champion_list);
        return NULL;
    }
    (*i)++;
    return check_and_add_champion_in_list(champion_list, champion);
}

static champion_t *malloc_champion(void)
{
    champion_t *champion = malloc(sizeof(champion_t));
    champion->prog_script = NULL;
    champion->name = NULL;
    champion->load_address = -1;
    champion->prog_number = -1;
    return champion;
}

static champion_list_t *put_champion_in_list(champion_list_t *champion_list,
char const *argv[], int *i)
{
    champion_t *champion = malloc_champion();
    if (my_str_cmp(argv[(*i)], "-n") == 0) {
        (*i)++;
        if (argv[(*i)] == NULL || my_str_is_num(argv[(*i)]) == 0) {
            free_champion_list(champion_list);
            return NULL;
        }
        champion->prog_number = my_str_to_int(argv[(*i)]);
        (*i)++;
    }
    if (argv[(*i)] != NULL && my_str_cmp(argv[(*i)], "-a") == 0) {
        (*i)++;
        if (argv[(*i)] == NULL || my_str_is_num(argv[(*i)]) == 0) {
            free_champion_list(champion_list);
            return NULL;
        }
        champion->load_address = my_str_to_int(argv[(*i)]);
        (*i)++;
    }
    return get_champion_data(champion, champion_list, argv, i);
}

static champion_list_t *init_champion_list(char const *argv[])
{
    int i = 3;
    champion_list_t *champion_list = NULL;

    while (argv[i] != NULL) {
        champion_list = put_champion_in_list(champion_list, argv, &i);
        if (champion_list == NULL)
            return NULL;
    }
    return champion_list;
}

my_vm_t *init_vm(char const *argv[])
{
    my_vm_t *my_vm = malloc(sizeof(my_vm_t));
    if (argv == NULL || my_vm == NULL)
        return NULL;
    if (my_str_cmp(argv[1], "-dump") != 0) {
        if (write(2, "bad argument, try ./corewar -h\n", 32) == -1)
            return NULL;
        return NULL;
    }
    if (my_str_is_num(argv[2]) != 1) {
        if (write(2, "bad argument, try ./corewar -h\n", 32) == -1)
            return NULL;
        return NULL;
    }
    my_vm->nbr_cycle = my_str_to_int(argv[2]);
    my_vm->champion_list = init_champion_list(argv);
    if (my_vm->champion_list == NULL) {
        free(my_vm);
        return NULL;
    }
    return switch_to_tab_champion(my_vm);
}
