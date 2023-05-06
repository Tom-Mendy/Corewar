/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** find_name_comment
*/

#include <sys/stat.h>
#include "my_project.h"
#include "asm.h"
#include "op.h"

static int find_name(char *actual_line, int const j, char **name)
{
    if (my_str_n_cmp(&(actual_line[j]), ".name", 5) == 0){
        if (*name != NULL)
            return KO;
        char **azerty = spliter(actual_line, "\"");
        int nb_hashtag = my_count_nb_char_in_str(azerty[0], '#');
        if (nb_hashtag != 0)
            return OK;
        *name = generate_malloc_str_from_str(azerty[1]);
        my_free_char_map(azerty);
        return OK;
    }
    return 1;
}

static int find_comment(char *actual_line, int const j, char **comment)
{
    if (my_str_n_cmp(&(actual_line[j]), ".comment", 8) == 0){
        if (*comment != NULL)
            return KO;
        char **azerty = spliter(actual_line, "\"");
        int nb_hashtag = my_count_nb_char_in_str(azerty[0], '#');
        if (nb_hashtag != 0)
            return OK;
        *comment = generate_malloc_str_from_str(azerty[1]);
        my_free_char_map(azerty);
        return OK;
    }
    return 1;
}

int find_name_comment(char *actual_line, char **name, char **comment)
{
    for (int j = 0; actual_line[j] != '\0'; j += 1){
        if (actual_line[j] == '#')
            return 0;
        if (find_name(actual_line, j, name) == OK)
            return OK;
        if (find_comment(actual_line, j, comment) == OK)
            return OK;
    }
    return OK;
}
