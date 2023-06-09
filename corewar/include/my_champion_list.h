/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-myls-tom.mendy
** File description:
** my_list
*/

#ifndef MY_CHAMPION_LIST_H_
    #define MY_CHAMPION_LIST_H_
    #include <stdlib.h>
    #include <stdbool.h>
    #include "my_str.h"
    #include "op.h"
    typedef struct champion_s {
        char *name;
        header_t header;
        char *prog_script;
        int prog_number;
        int load_address;
        int *tab_register;
        int program_counter;
        int cycle_to_die;
        int carry;
        int cycle;
        bool instruction_in_progress;
        bool is_alive;
    } champion_t;

    typedef struct champion_list_s {
        champion_t *champion;
        struct champion_list_s *next;
        struct champion_list_s *prev;
    } champion_list_t;
    champion_list_t *create_champion(champion_t *champion);
    champion_list_t *add_champion_in_list(champion_list_t *list,
    champion_t *champion);
    void free_champion_list(champion_list_t *list);
    int my_list_champion_len(champion_list_t *list);

#endif /* !MY_CHAMPION_LIST_H_ */
