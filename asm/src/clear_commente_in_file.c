/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** clear_commente_in_file
*/

#include "my_project.h"
#include "asm.h"
#include "op.h"

static void clear_commente_in_line(char *str)
{
    int is_hashtag = false;
    for (int k = 0; str[k] != '\0'; k += 1) {
        if (str[k] == COMMENT_CHAR)
            is_hashtag = true;
        if (is_hashtag == true)
            str[k] = '\0';
    }
}

static void clear_commente_in_file_sub(char **file, int *i)
{
    if (file[(*i)][0] == COMMENT_CHAR){
        free(file[(*i)]);
        for (int j = (*i); file[j] != NULL; j += 1) {
            file[j] = file[j + 1];
        }
        (*i) -= 1;
    } else
        clear_commente_in_line(file[(*i)]);
}

int clear_commente_in_file(char **file)
{
    if (file == NULL)
        return KO;
    for (int i = 0; file[i] != NULL; i += 1) {
        int nb_hashtag = my_count_nb_char_in_str(file[i], COMMENT_CHAR);
        if (nb_hashtag == 1)
            clear_commente_in_file_sub(file, &i);
    }
    return OK;
}
