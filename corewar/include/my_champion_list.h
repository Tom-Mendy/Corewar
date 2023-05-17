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
    typedef struct champion_s {
        char *name;
        char *champion_script;
        int prog_number;
        int load_address;
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

#endif /* !MY_CHAMPION_LIST_H_ */
