/*
** EPITECH PROJECT, 2020
** myprintf
** File description:
** my_put_base
*/

#include "../include/navy.h"

void my_put_base(long long unsigned int nb, int j)
{
    switch (j)
    {
    case 2:
        my_put_unsigned(nb, "01234567");
        break;
    case 3:
        my_put_unsigned(nb, "0123456789");
        break;
    case 4:
        my_put_unsigned(nb, "0123456789abcdef");
        break;
    case 5:
        my_put_unsigned(nb, "0123456789ABCDEF");
        break;
    default:
        my_put_unsigned(nb, "01");
        break;
    }
}