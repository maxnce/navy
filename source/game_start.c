/*
** EPITECH PROJECT, 2020
** navy
** File description:
** game_start
*/

#include "../include/navy.h"

void change_handler(struct sigaction sa)
{
    sa.sa_handler = &nothing_happens;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}

void nothing_happens(int sig, siginfo_t *inf, void *context)
{
    return ;
}

void load_pid(navy_t *navy)
{
    char *pid = read_pos(0, pid, "source/logs.txt");

    navy->pid = my_getnbr(pid);
    free(pid);
}

int result(navy_t *navy)
{
    if (navy->taken_hit == 14 && navy->hit == 14) {
        my_printf("\nDraw\n");
        return 2;
    }
    if (navy->taken_hit == 14) {
        my_printf("\nEnemy won\n");
        return (1);
    } else {
        my_printf("\nI won\n");
        return (0);
    }
}

int game_start(int ac, char **av, navy_t *navy)
{
    if (ac == 2) {
        load_pid(navy);
        while (navy->hit != 14 && navy->taken_hit != 14) {
            get_coordinates_p1(navy);
            display_boards(navy);
        }
    }
    if (ac == 3) {
        navy->pid = my_getnbr(av[1]);
        while (navy->hit != 14 && navy->taken_hit != 14) {
            get_coordinates_p2(navy);
            display_boards(navy);
        }
    }
    return (result(navy));
}