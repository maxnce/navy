/*
** EPITECH PROJECT, 2020
** myprintf
** File description:
** my_put_str_x
*/

#include "../include/navy.h"

int my_put_str_x(char *str, int x)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0' && j < x) {
        my_putchar(str[i]);
        if (str[i] < 32 || str[i] >= 127)
            j--;
        i++;
        j++;
    }
    return (0);
}