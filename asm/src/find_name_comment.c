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
    if (actual_line == NULL || name == NULL || j < 0)
        return KO;
    if (my_str_n_cmp(&(actual_line[j]), NAME_CMD_STRING,
    my_str_len(NAME_CMD_STRING)) == 0){
        if (*name != NULL)
            return KO;
        char **cote = spliter(actual_line, "\"");
        int nb_hashtag = my_count_nb_char_in_str(cote[0], COMMENT_CHAR);
        if (nb_hashtag != 0)
            return OK;
        *name = generate_malloc_str_from_str(cote[1]);
        my_free_char_map(cote);
        return OK;
    }
    return 1;
}

static int find_comment(char *actual_line, int const j, char **comment)
{
    if (actual_line == NULL || comment == NULL || j < 0)
        return KO;
    if (my_str_n_cmp(&(actual_line[j]), COMMENT_CMD_STRING,
    my_str_len(COMMENT_CMD_STRING)) == 0){
        if (*comment != NULL)
            return KO;
        char **cote = spliter(actual_line, "\"");
        int nb_hashtag = my_count_nb_char_in_str(cote[0], COMMENT_CHAR);
        if (nb_hashtag != 0)
            return OK;
        *comment = generate_malloc_str_from_str(cote[1]);
        my_free_char_map(cote);
        return OK;
    }
    return 1;
}

int find_name_in_line(char *actual_line, char **name)
{
    for (int j = 0; actual_line[j] != '\0'; j += 1){
        if (find_name(actual_line, j, name) == OK)
            return OK;
    }
    return 1;
}

int find_comment_in_line(char *actual_line, char **comment)
{
    for (int j = 0; actual_line[j] != '\0'; j += 1){
        if (find_comment(actual_line, j, comment) == OK)
            return OK;
    }
    return 1;
}

int find_name_comment(char **file_in_array, char **name, char **comment)
{
    if (!file_in_array || !(*file_in_array) || !comment || !name)
        return KO;
    if (find_name_in_line(file_in_array[0], name) == KO)
        return KO;
    if (find_comment_in_line(file_in_array[1], comment) == KO)
        return KO;
    return OK;
}
