/*
** EPITECH PROJECT, 2020
** B-PSU-100-LYN-1-1-myprintf-maxence.pellouin
** File description:
** redirect_print
*/

#include "../include/navy.h"

void redirect_print(char *s, va_list list, int i, int j)
{
    if (j == 0 || j == 1)
        return (my_put_nbr(va_arg(list, int)));
    if (j == 6)
        return (my_putchar(va_arg(list, int)));
    if (j == 7)
        my_modif_str(s, va_arg(list, char *), i, j);
    if (j == 9)
        return (write(1, "%", 1));
    if (j == 11)
        return (my_putstr_oct(va_arg(list, char *)));
    if (j == 8)
        return (my_put_ptr(va_arg(list, void *)));
    if (j == 10 || j == 2 || j == 3 || j == 4 || j == 5)
        my_addons_unsigned(s, va_arg(list, long unsigned int), i, j);
}