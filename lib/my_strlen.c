/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** returns the number of char found in string
*/

int my_strlen(char const *str)
{
    int i = 0;
    int total = 0;

    while (str[i] != '\0') {
        total++;
        i++;
    }
    return (total);
}
