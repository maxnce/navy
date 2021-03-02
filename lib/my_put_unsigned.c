/*
** EPITECH PROJECT, 2020
** myprintf
** File description:
** my_unsigned_nbr_base
*/

#include "../include/navy.h"

int my_put_unsigned(long unsigned int nb, char *base)
{
    long unsigned int temp;
    long unsigned int holder;
    int len = my_strlen(base);

    holder = nb % len;
    temp = (nb - holder) / len;
    if (temp != 0)
        my_put_unsigned(temp, base);
    my_putchar(base[holder]);
    return (0);
}