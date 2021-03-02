/*
** EPITECH PROJECT, 2020
** navy
** File description:
** load_boats
*/

#include "../include/navy.h"

void load_boats(char **map, char *file)
{
    int i = 2;

    for (; i <= 26; i += 8)
        for (int j = file[i] - 65; j <= file[i + 3] - 65; j++) {
            for (int k = file[i + 1] - 49; k <= file[i + 4] - 49; k++) {
                map[k][j] = file[i - 2];
            }
        }
}