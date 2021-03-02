/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** navy
*/

#include "../include/navy.h"

void free_struct(navy_t *navy)
{
    free(navy->pos1);
    free(navy->pos2);
    free(navy);
}

int connection(int ac, char **av, navy_t *navy)
{
    navy->hit = 0;
    navy->taken_hit = 0;
    switch (ac) {
    case (2):
        navy->pos1 = read_pos(navy->fd, navy->pos1, av[1]);
        my_printf("my_pid: %d\nwaiting for enemy connection...\n", getpid());
        break;
    case (3):
        navy->pos1 = read_pos(navy->fd, navy->pos1, av[2]);
        my_printf("my_pid: %d\n", getpid());
        break;
    default:
        return (84);
    }
    if (navy->fd == 84 || navy->pos1 == NULL)
            return (84);
    if (verify_buffer(navy->pos1) == 84)
        return (84);
    return (0);
}

char *read_pos(int fd, char *buffer, char *av)
{
    struct stat sb;

    stat(av, &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    fd = open(av, O_RDONLY);
    if (fd == -1)
        return (NULL);
    buffer[read(fd, buffer, sb.st_size)] = '\0';
    return (buffer);
}

void my_handler(int signum, siginfo_t *sinfo, void *context)
{
    int fd;

    if (signum == SIGUSR1) {
        my_printf("\nennemy connected\n\n");
        fd = open("source/logs.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);
            if (fd == -1)
                fd = open("source/logs.txt", O_CREAT | O_TRUNC | O_WRONLY, 777);
        my_put_nbr_file(sinfo->si_pid, fd);
        close(fd);
        kill(sinfo->si_pid, SIGUSR2);
    }
    if (signum == SIGUSR2) {
        my_putstr("successfully connected\n\n");
    }
}

int main(int ac, char **av)
{
    struct sigaction sa = {0};
    navy_t *navy = malloc(sizeof(navy_t));

    navy->fd = 0;
    navy->input = 1;
    platform(navy);
    if (connection(ac, av, navy) == 84)
        return (84);
    if (ac == 3)
        kill(my_getnbr(av[1]), SIGUSR1);
    sa.sa_handler = &my_handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    pause();
    change_handler(sa);
    load_boats(navy->map1, navy->pos1);
    display_boards(navy);
    return (game_start(ac, av, navy));
}