/*
** EPITECH PROJECT, 2020
** myprintf
** File description:
** my_put_str_base
*/

#include "../include/navy.h"

int my_put_nbr_base(int nb, char *base)
{
    int temp;
    int holder;
    int len = my_strlen(base);

    if (nb < 0) {
        my_putchar('-');
        return (my_put_nbr_base(-nb, base));
    }
    holder = nb % len;
    temp = (nb - holder) / len;
    if (temp != 0)
        my_put_nbr_base(temp, base);
    my_putchar(base[holder]);
    return (0);
}