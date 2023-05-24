/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** test_display_help
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my_project.h"
#include "asm.h"

void redirect_display_help_stdout(void)
{
    cr_redirect_stdout();
}

Test(display_help, test_display_help_output, .init =
redirect_display_help_stdout) {
    cr_assert_eq(display_help(), OK);
    cr_assert_stdout_eq_str("USAGE\n\
./asm file_name[.s]\nDESCRIPTION\n\
file_name file in assembly language to be converted into file_name.cor,\n\
an executable in the Virtual Machine.\n");
}
