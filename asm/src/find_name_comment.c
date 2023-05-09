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
    if (actual_line == NULL || name == NULL)
        return KO;
    if (my_str_n_cmp(&(actual_line[j]), NAME_CMD_STRING,
    my_str_len(NAME_CMD_STRING)) == 0){
        if (*name != NULL)
            return KO;
        char **azerty = spliter(actual_line, "\"");
        int nb_hashtag = my_count_nb_char_in_str(azerty[0], COMMENT_CHAR);
        if (nb_hashtag != 0)
            return OK;
        *name = generate_malloc_str_from_str(azerty[1]);
        my_free_char_map(azerty);
        return OK;
    }
    return 1;
}

static int find_comment(char *actual_line, int const j, char **comment,
char **name)
{
    if (actual_line == NULL || comment == NULL || name == NULL)
        return KO;
    if (*name == NULL)
        return 1;
    if (my_str_n_cmp(&(actual_line[j]), COMMENT_CMD_STRING,
    my_str_len(COMMENT_CMD_STRING)) == 0){
        if (*comment != NULL)
            return KO;
        char **azerty = spliter(actual_line, "\"");
        int nb_hashtag = my_count_nb_char_in_str(azerty[0], COMMENT_CHAR);
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
    if (actual_line == NULL || comment == NULL || name == NULL)
        return KO;
    for (int j = 0; actual_line[j] != '\0'; j += 1){
        if (actual_line[j] == COMMENT_CHAR)
            return 0;
        if (find_name(actual_line, j, name) == OK)
            return OK;
        if (find_comment(actual_line, j, comment, name) == OK)
            return OK;
    }
    return OK;
}
