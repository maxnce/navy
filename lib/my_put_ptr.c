/*
** EPITECH PROJECT, 2020
** myprintf
** File description:
** my_put_ptr
*/

#include "../include/navy.h"

int my_put_ptr(void *ptr)
{
    write(1, "0x", 2);
    my_put_unsigned(ptr, "0123456789abcdef");
    return (0);
}