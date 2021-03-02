/*
** EPITECH PROJECT, 2020
** navy
** File description:
** shoot
*/

#include "../include/navy.h"

void shoot(navy_t *navy, int x, int y)
{
    int fd = open("source/pos.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);

    fd = (fd == -1)?  open("source/pos.txt", O_CREAT | O_TRUNC |
        O_WRONLY, 0777) : fd;
    my_putchar_file(y + 65, fd);
    my_putchar_file(x + 49, fd);
    close(fd);
}