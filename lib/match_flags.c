/*
** EPITECH PROJECT, 2020
** B-PSU-100-LYN-1-1-myprintf-maxence.pellouin
** File description:
** match_flags
*/
#include "../include/navy.h"

int match_flags(char const *format, char *flags, int i)
{
    int j = 0;

    if (format[i] != '%')
        return (-1);
    i++;
    for (; format[i] != '\0' && format[i] != flags[j]; j++)
        if (j >= 12) {
            i++;
            j = -1;
        }
    if (format[i] == '\0')
        return (84);
    return (j);
}