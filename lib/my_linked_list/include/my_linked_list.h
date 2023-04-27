/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-myls-tom.mendy
** File description:
** my_list
*/

#ifndef MY_LIST_H_
    #define MY_LIST_H_
    #include <stdlib.h>
    #include <stdbool.h>
    #include "my_str.h"
    typedef int list_type_t;
    typedef struct elt {
        list_type_t data;
        struct elt *next;
        struct elt *prev;
    }elt_t;
    int get_list_size(elt_t * list);
    int put_end_list(elt_t **list, list_type_t value);
    int print_linked_list(elt_t *list);
    int print_linked_list_and_empty(elt_t **list);
    void delete_first_element_list(elt_t **list);
    void delete_actual_node_list(elt_t *list);
#endif /* !MY_LIST_H_ */
