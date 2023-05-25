/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** find_name_comment
*/

#include <sys/stat.h>
#include "../../include/my_project.h"
#include "asm.h"
#include "op.h"

int find_name_in_line(char *actual_line, char **name)
{
    char **split_line = spliter(actual_line, " \t");
    if (split_line == NULL)
        return KO;
    if (my_str_cmp(split_line[0], NAME_CMD_STRING) == 0) {
        my_free_char_map(split_line);
        if (my_count_nb_char_in_str(actual_line, '\"') != 2)
            return KO;
        char **cote = spliter(actual_line, "\"");
        if (cote == NULL || my_char_map_len(cote) != 2)
            return KO;
        *name = generate_malloc_str_from_str(cote[1]);
        my_free_char_map(cote);
        if (my_str_len(*name) > PROG_NAME_LENGTH){
            free(*name);
            return KO;
        }
        return OK;
    }
    my_free_char_map(split_line);
    return KO;
}

int find_comment_in_line(char *actual_line, char **comment)
{
    char **split_line = spliter(actual_line, " \t");
    if (split_line == NULL)
        return KO;
    if (my_str_cmp(split_line[0], COMMENT_CMD_STRING) == 0) {
        my_free_char_map(split_line);
        if (my_count_nb_char_in_str(actual_line, '\"') != 2)
            return KO;
        char **cote = spliter(actual_line, "\"");
        if (cote == NULL || my_char_map_len(cote) != 2)
            return KO;
        *comment = generate_malloc_str_from_str(cote[1]);
        my_free_char_map(cote);
        if (my_str_len(*comment) > COMMENT_LENGTH){
            free(*comment);
            return KO;
        }
        return OK;
    }
    my_free_char_map(split_line);
    return KO;
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
