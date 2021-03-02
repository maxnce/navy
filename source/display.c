/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** display
*/

#include "../include/navy.h"

void display(char **map)
{
    int j = 0;

    my_printf(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (j = 0; j < 7; j++)
            my_printf("%c ", map[i][j]);
        my_printf("%c\n", map[i][j]);
    }
}

void display_boards(navy_t *navy)
{
    my_printf("my positions:\n");
    display(navy->map1);
    my_printf("\nenemy's positions:\n");
    display(navy->map2);
}