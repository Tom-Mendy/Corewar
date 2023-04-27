/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "my_project.h"
#include "asm.h"

int handle_option(int const argc, char *argv[], bool *h_option_specified)
{
    int opt;
    while ((opt = getopt(argc, argv, "h")) != -1) {
        switch (opt) {
            case 'h':
                if (*h_option_specified) {
                    fprintf(stderr, "Error: option '-h' can only be");
                    fprintf(stderr, " specified once.\n");
                    return KO;
                }
                *h_option_specified = true;
                break;
            default:
                fprintf(stderr, "Unknown option '%c' detected.\n", optopt);
                return KO;
        }
    }
    return OK;
}

int main(int const argc, char *argv[])
{
    bool h_option_specified = false;
    if (handle_option(argc, argv, &h_option_specified) == 84)
        return KO;
    int display_help_value = display_help(h_option_specified);
    if (display_help_value != 1)
        return display_help_value;
    return OK;
}
