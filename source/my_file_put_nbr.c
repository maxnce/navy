/*
** EPITECH PROJECT, 2020
** navy
** File description:
** my_file_put_nbr
*/

#include "../include/navy.h"

void my_putchar_file(char c, int fd)
{
    write(fd, &c, 1);
}

int my_while_loop_file(int nb, int number_count, int value, int fd)
{
    while ((nb / number_count) >= 10) {
        number_count *= 10;
    }
    while (number_count > 0) {
        value = nb / number_count;
        value %= 10;
        my_putchar_file(value + 48, fd);
        number_count /= 10;
    }
    return (0);
}

int my_put_nbr_file(int nb, int fd)
{
    int number_count = 1;
    int value = 0;

    if (nb == -2147483648) {
        nb = 147483648;
        my_putchar_file('-', fd);
        my_putchar_file('2', fd);
    }
    if (nb < 0) {
        nb = nb *-1;
        my_putchar_file('-', fd);
    }
    my_while_loop_file(nb, number_count, value, fd);
    return (0);
}