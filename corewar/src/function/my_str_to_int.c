/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** my_str_to_int
*/

int my_str_to_int(char const *str)
{
    int nb = 0;
    int count = 0;
    if (str[0] == '-' && str[1] != '\0')
        count = 1;
    for (int i = count; str[i] != '\0'; i++ ) {
        nb *= 10;
        nb += (int)(str[i] - '0');
    }
    if (count == 1)
        nb *= -1;
    return nb;
}
