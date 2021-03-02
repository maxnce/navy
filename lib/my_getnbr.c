/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** a function that returns a number, sent to the function as a string.
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int count_nbr = 0;
    long c_stock = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            count_nbr = count_nbr + 1;
        }
        i = i + 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        c_stock = c_stock * 10 + str[i] - 48;
        i += 1;
    }
    if ((count_nbr %2) == 1) {
        c_stock = c_stock * (-1);
    }
    return (c_stock);
}
