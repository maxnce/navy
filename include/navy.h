/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

//includes
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ucontext.h>
#include <time.h>
#include <stdarg.h>

//struct
typedef struct game
{
    int result1;
    int result2;
    int x;
    int x_max;
    int y;
    int y_max;
    int input;
    int fd;
    char *pos1;
    char *pos2;
    char **map1;
    char **map2;
    char *coord1;
    char *coord2;
    int pid;
    int hit;
    int taken_hit;
}navy_t;

//lib C
int match_flags(const char *format, char *flags, int i);
char *my_display_addon(const char *format, int i);
int my_hashtag(char *format, int i, int j, long long unsigned int arg);
void my_addons_unsigned(char *format, long long unsigned int arg, int i, int j);
void my_modif_str(char const *format, char *arg, int i, int j);
int my_getnbr(char const *str);
int my_printf(char const *format, ...);
void my_put_base(long long unsigned int nb, int j);
int my_put_nbr_base(int nb, char *base);
int my_while_loop(int nb, int number_count, int value);
int my_put_nbr(int nb);
int my_put_ptr(void *ptr);
int my_put_str_x(char *str, int x);
int my_put_unsigned(long unsigned int nb, char *base);
void my_putchar(char c);
void my_putstr(char *str);
int my_putstr_oct(char const *str);
int my_strlen(char const *str);
void redirect_print(char *s, va_list list, int i, int j);

//navy

//position
//int read_pos(int fd, char *buffer, char *av);
char *read_pos(int fd, char *buffer, char *av);
void get_line_or_column(navy_t *navy, int coord_x, int coord_y);
int verify_buffer(char *pos);
void load_boats(char **map, char *file);
void get_coordinates_p1(navy_t *navy);
void get_coordinates_p2(navy_t *navy);
int game_start(int ac, char **av, navy_t *navy);
void my_putchar_file(char c, int fd);
int my_put_nbr_file(int nb, int fd);

//signals
void my_handler(int signum, siginfo_t *sinfo, void *context);
int connection(int ac, char **av, navy_t *navy);
void nothing_happens(int sig, siginfo_t *inf, void *context);

//displays
char **malloc_struct(char **maps);
int platform(navy_t *navy);
void display_boards(navy_t *navy);
void display(char **map);

#endif /* !NAVY_H_ */