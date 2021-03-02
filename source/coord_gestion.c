/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** coord_gestion
*/

#include "../include/navy.h"

void did_we_hit(navy_t *navy, int x, int y)
{
    int fd;
    char *hit;

    usleep(5000);
    usleep(5000);
    hit = read_pos(fd, hit, "source/hit.txt");
    if (hit[0] == 'y') {
        navy->map2[x][y] = 'x';
        navy->hit = navy->hit + 1;
        my_printf("%c%c: hit\n", y + 65, x + 49);
    } else {
        navy->map2[x][y] = 'o';
        my_printf("%c%c: missed\n", y + 65, x + 49);
    }
}

void did_we_got_hit(navy_t *navy)
{
    char *hit = read_pos(0, hit, "source/pos.txt");
    int fd = open("source/hit.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);

    fd = (fd == -1)?  open("source/hit.txt", O_CREAT | O_TRUNC |
        O_WRONLY, 0777) : fd;
    if (navy->map1[hit[1] - 49][hit[0] - 65] != '.' &&
    navy->map1[hit[1] - 49][hit[0] - 65] != 'x' &&
    navy->map1[hit[1] - 49][hit[0] - 65] != 'o') {
        write(fd, "y", 1);
        navy->map1[hit[1] - 49][hit[0] - 65] = 'x';
        navy->taken_hit = navy->taken_hit + 1;
        my_printf("%s: hit\n", hit);
    } else {
        write(fd, "n", 1);
        navy->map1[hit[1] - 49][hit[0] - 65] = 'o';
        my_printf("%s: missed\n", hit);
    }
    close(fd);
}

int put_coord(navy_t *navy)
{
    char *x_flags = {"ABCDEFGH"};
    int i = 0;
    int j = 0;
    int k = 1;
    char boat = '2';

    for (; i < 8; i++) {
        for (; j < 8; j++, k += 7) {
            if (navy->pos1[k] == boat) {
                j == navy->x || i == navy->y ? navy->input = boat : 0;
            }
        }
    }
    return (0);
}

void get_coordinates_p1(navy_t *navy)
{
    int size = 2;
    char *coord = malloc(sizeof(char) * 2);

    my_printf("\nattack: ");
    getline(&coord, &size, stdin);
    while (size != 2 || (coord[0] < 'A' || coord[0] > 'H') ||
    (coord[1] < '1' || coord[1] > '8')) {
        my_printf("wrong position\nattack: ");
        getline(&coord, &size, stdin);
    }
    shoot(navy, coord[1] - 49, coord[0] - 65);
    kill(navy->pid, SIGUSR2);
    did_we_hit(navy, coord[1] - 49, coord[0] - 65);
    if (navy->hit == 14)
        return (my_putchar('\n'));
    my_printf("\nwaiting for enemy's attack...\n");
    pause();
    did_we_got_hit(navy);
    kill(navy->pid, SIGUSR1);
    my_putchar('\n');
}

void get_coordinates_p2(navy_t *navy)
{
    int size = 2;
    char *coord = malloc(sizeof(char) * 2);

    my_printf("\nwaiting for enemy's attack...\n");
    pause();
    did_we_got_hit(navy);
    usleep(5000);
    if (navy->taken_hit == 14)
        return (my_putchar('\n'));
    my_printf("\nattack: ");
    getline(&coord, &size, stdin);
    while (size != 2 || (coord[0] < 'A' || coord[0] > 'H') ||
    (coord[1] < '1' || coord[1] > '8')) {
        my_printf("wrong position\nattack: ");
        getline(&coord, &size, stdin);
    }
    shoot(navy, coord[1] - 49, coord[0] - 65);
    kill(navy->pid, SIGUSR1);
    pause();
    did_we_hit(navy, coord[1] - 49, coord[0] - 65);
    return (my_putchar('\n'));
}
