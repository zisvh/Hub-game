/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** get nbr of a sting
*/

int my_getnbr(char *str)
{
    int res = 0;
    int neg = 1;
    int i = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while ((str[i] >= '0') && (str[i] <= '9')) {
        res = res * 10 + str[i] - 48;
        i++;
    }
    if (res >= 2147483647 || res <= -2147483648)
        return 0;
    return res * neg;
}
