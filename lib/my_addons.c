/*
** EPITECH PROJECT, 2020
** myprintf
** File description:
** my_addons
*/

#include "../include/navy.h"

char *my_display_addon(const char *format, int i)
{
    char *new;
    int len = 0;
    int temp = i;

    for (;format[temp] <= '9' && format[temp] >= '0'; len++, temp++);
    new = malloc(sizeof(char) * (len + 1));
    for (temp = 0; temp < len; temp++)
        new[temp] = format[i + temp];
    new[temp] = '\0';
    return (new);
}

int my_hashtag(char *format, int i, int j, long long unsigned int arg)
{
    char *flags = "diouxXcsp%bS";

    for (; format[i] != flags[j]; i++) {
        if ((j == 4 || j == 5) && format[i] == '#') {
            my_putchar('0');
            if (j == 4)
                my_putchar('x');
            if (j == 5)
                my_putchar('X');
            return (0);
        }
        if (j == 2 && format[i] == '#' && arg != 0) {
            my_putchar('0');
            return (0);
        }
    }
    return (0);
}

void my_addons_unsigned(char *format, long long unsigned int arg, int i, int j)
{
    unsigned char chara;
    short unsigned int sho = my_hashtag(format, i, j, arg);
    char *flags = "diouxXcsp%bS";
    int h_count = 0;
    int l_count = 0;

    for (; format[i] != flags[j]; i++) {
        if (format[i] == 'l')
            l_count++;
        if (format[i] == 'h')
            h_count++;
    }
    if (l_count >= h_count)
        my_put_base(arg, j);
    if (h_count == 1)
        my_put_base(sho = arg, j);
    if (h_count == 2)
        my_put_base(chara = arg, j);
}

void my_modif_str(char const *format, char *arg, int i, int j)
{
    char *flags = "diouxXcsp%bS";
    int x;

    for (; format[i] != flags[j]; i++) {
        if (format[i] == '.' && format[i + 1] >= '0' && format[i + 1] <= '9') {
            x = my_getnbr(my_display_addon(format, i + 1));
            my_put_str_x(arg, x);
            return ;
        }
    }
    my_putstr(arg);
}