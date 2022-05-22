/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_strcat2
*/

#include "../include/my_runner.h"

char *my_strcat2(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int len = 0;
    char *res;

    while (s1[len])
        len++;
    while (s2[i]) {
        len++;
        i++;
    }
    i = -1;
    res = malloc((len + 1) * sizeof(char));
    while (s1[++i])
        res[i] = s1[i];
    while (s2[j])
        res[i++] = s2[j++];
    res[i] = '\0';
    return (res);
}
