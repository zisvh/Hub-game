/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** map_utils
*/

#include "../include/my_runner.h"

unsigned int line_size(char *buffer)
{
    unsigned int size = 0;
    unsigned int i = 0;

    while (buffer[i] != '\n') {
        i++;
        size++;
    }
    return (size);
}

unsigned int nb_lines(char *buffer)
{
    unsigned int nb = 0;
    unsigned int i = 0;

    while (buffer[i]) {
        if (buffer[i] == '\n')
            nb++;
        i++;
    }
    return (nb);
}

void make_line(char *map_line, unsigned int i, char *buffer)
{
    unsigned int cursor = 0;
    unsigned int count = 0;
    unsigned int j = 0;

    while (count < i) {
        if (buffer[cursor] == '\n')
            count++;
        cursor++;
    }
    while (buffer[cursor] != '\n') {
        map_line[j] = buffer[cursor];
        j++;
        cursor++;
    }
    map_line[j] = '\0';
}
