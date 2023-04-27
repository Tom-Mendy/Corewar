/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** my_project
*/

#include "my_project.h"

int my_project(int argc, char **argv)
{
    int **toto = my_create_int_map(5, 6, 5);
    my_display_int_map(toto);
    my_free_int_map(toto);
    return 0;
}
