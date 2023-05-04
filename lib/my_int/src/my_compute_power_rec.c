/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** ecursive function that returns power
*/

long int my_compute_power_rec(long int const nb, int const power)
{
    if (power == 0)
        return 1;
    if (power == 1)
        return nb;
    if (power < 0)
        return 0;
    long int test = nb * my_compute_power_rec(nb, power - 1);
    if ((test * nb) > __LONG_MAX__)
        return 0;
    return test;
}
