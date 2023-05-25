/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** jump_instruction
*/

#include "corewar.h"

static int nb_parameter(char *str, decimal_to_code_byte_t coding_byte)
{
    int nb = 0;

    if (my_str_cmp(str, coding_byte.option_1) == 0)
        nb++;
    if (my_str_cmp(str, coding_byte.option_2) == 0)
        nb++;
    if (my_str_cmp(str, coding_byte.option_3) == 0)
        nb++;
    if (my_str_cmp(str, coding_byte.option_4) == 0)
        nb++;
    return nb;
}

int jump_instruction_with_index(int coding_byte_decimal)
{
    int nb_indir = 0;
    int nb_reg = 0;
    int nb_dir = 0;
    decimal_to_code_byte_t coding_byte;

    if (decimal_to_code_byte(coding_byte_decimal, &coding_byte) == KO)
        return -1;
    nb_indir = nb_parameter("11", coding_byte);
    nb_reg = nb_parameter("01", coding_byte);
    nb_dir = nb_parameter("10", coding_byte);
    return nb_indir * IND_SIZE + nb_reg * IND_SIZE + nb_dir * IND_SIZE + 2;
}

int jump_instruction(int coding_byte_decimal)
{
    int nb_indir = 0;
    int nb_reg = 0;
    int nb_dir = 0;
    decimal_to_code_byte_t coding_byte;

    if (decimal_to_code_byte(coding_byte_decimal, &coding_byte) == KO)
        return -1;
    nb_indir = nb_parameter("11", coding_byte);
    nb_reg = nb_parameter("01", coding_byte);
    nb_dir = nb_parameter("10", coding_byte);
    return nb_indir * IND_SIZE + nb_reg + nb_dir * DIR_SIZE + 2;
}
