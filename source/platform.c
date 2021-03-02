/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** platform
*/

#include "../include/navy.h"

char **malloc_struct(char **maps)
{
    int k = 0;

    maps = malloc(sizeof(char *) * 8);
    for (int i = 0; i < 8; i++)
        maps[i] = malloc(sizeof(char) * 9);
    for (int j = 0; j < 8; j++) {
        for (k = 0; k < 8; k++)
            maps[j][k] = '.';
        maps[j][k] = '\0';
    }
    return (maps);
}

int check_length(char *pos)
{
    int i = 0;
    for (i = 0; i + 6 < 31; i += 8) {
        if ((pos[i + 2] == pos[i + 5] && pos[i + 3] == pos[i + 6]) ||
        (pos[i + 2] != pos[i + 5] && pos[i + 3] != pos[i + 6]))
            return (84);
        if (pos[i + 2] == pos[i + 5] && pos[i + 3] - pos[i + 6] !=
        pos[i] - 49 && pos[i + 6] - pos[i + 3] != pos[i] - 49)
            return (84);
        if (pos[i + 3] == pos[i + 6] && pos[i + 2] - pos[i + 5] != pos[i] - 49
        && pos[i + 5] - pos[i + 2] != pos[i] - 49)
            return (84);
    }
    return (0);
}

int verify_buffer(char *pos)
{
    char *coord = {"12345678ABCDEFGH:\n"};
    int j = 0;

    if (my_strlen(pos) != 31)
        return (84);
    if (pos[0] != '2' || pos[8] != '3' || pos[16] != '4' || pos[24] != '5')
        return (84);
    for (int i = 0; pos[i] != '\0'; i++) {
        for (j = 0; j < 19; j++)
            if (pos[i] == coord[j])
                j = 100;
        if (j != 101)
            return (84);
    }
    return (check_length(pos));
}

void get_line_or_column(navy_t *navy, int coord_x, int coord_y)
{
    char *x_coord = {"ABCDEFGH"};

    if (navy->pos1[coord_x] == navy->pos1[coord_x + 2]) {
        for (int i = 0; x_coord[i] != '\0'; i++)
            x_coord[i] == navy->pos1[coord_x] ? navy->x = navy->x_max = i : 0;
        navy->y = navy->pos1[coord_y];
        navy->y_max = navy->pos1[coord_y + 2];
    } else {
        navy->y = navy->y_max = navy->pos1[coord_y];
        navy->x = navy->pos1[coord_x];
        navy->x_max = navy->pos1[coord_x + 2];
    }
}

int platform(navy_t *navy)
{
    navy->coord1 = malloc(sizeof(int) * 16);
    navy->coord2 = malloc(sizeof(int) * 16);
    navy->map1 = malloc_struct(navy->map1);
    navy->map2 = malloc_struct(navy->map2);
    return (0);
}