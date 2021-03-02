/*
** EPITECH PROJECT, 2020
** myprintf
** File description:
** my_put_str_oct
*/

#include "../include/navy.h"

int my_putstr_oct(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            write(1, "\\0", 2);
            my_put_nbr_base(str[i], "01234567");
        } else
            my_putchar(str[i]);
        i++;
    }
    return (0);
}