/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** convert
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_project.h"
#include "asm.h"
#include "op.h"

static int check_comma(char **file, int i, int j)
{
    if (file[i][j] == ',')
        j += 1;
    return j;
}

static int if_rows(char **file, int i, int j, int rows)
{
    if (file[i][j] == ' ')
        rows += 1;
    return (rows);
}

static int get_rows(char **file)
{
    int rows = 0;
    int i = 0, j = 0;
    for (i = 2; file[i] != NULL; i++, rows++) {
        for (j = 0; file[i][j] == ' '; j++);
        for ( ; file[i][j] != '\0'; j++) {
            rows = if_rows(file, i, j, rows);
        }
    }
    return (rows);
}

char **simplify_array(char **file)
{
    int i = 0, j = 0, k = 0, l = 0;
    int rows = get_rows(file);
    char **info = malloc(sizeof(char *) * rows);
    for (i = 2, j = 0; file[i] != NULL; k++) {
        if ((info[k] = malloc(sizeof(char) * 10)) == NULL)
            return NULL;
        for ( ; file[i][j] == ' '; j++);
        for (l = 0; file[i][j] != ' ' && file[i][j] != ','
        && file[i][j] != '\0'; j++, l++) {
            info[k][l] = file[i][j];
        }
        info[k][l] = '\0';
        j = check_comma(file, i, j);
        if (file[i][j] == '\0') {
            i += 1;
            j = 0;
        }
    }
    info[k] = NULL;
    return (info);
}
