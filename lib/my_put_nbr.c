/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** given a number it should display it's equivalent int
*/
#include "../include/navy.h"

int my_while_loop(int nb, int number_count, int value)
{
    while ((nb / number_count) >= 10) {
        number_count *= 10;
    }
    while (number_count > 0) {
        value = nb / number_count;
        value %= 10;
        my_putchar(value + 48);
        number_count /= 10;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    int number_count = 1;
    int value = 0;

    if (nb == -2147483648) {
        nb = 147483648;
        my_putchar('-');
        my_putchar('2');
    }
    if (nb < 0) {
        nb = nb *-1;
        my_putchar('-');
    }
    my_while_loop(nb, number_count, value);
    return (0);
}
