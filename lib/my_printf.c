/*
** EPITECH PROJECT, 2020
** B-PSU-100-LYN-1-1-myprintf-maxence.pellouin
** File description:
** my_printf
*/

#include "../include/navy.h"

int my_printf(char const *format, ...)
{
    int i = 0;
    int j = 0;
    va_list list;
    va_start(list, format);
    char *flags = "diouxXcsp%bS";
    for (; format[i] && j != 84; i++) {
        j = match_flags(format, flags, i);
        if (j != -1) {
            redirect_print(format, list, i, j);
            i++;
            for (; format[i] != flags[j]; i++);
        } else
            my_putchar(format[i]);
    }
    va_end(list);
    return (i);
}