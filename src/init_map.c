/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-keziah.picq
** File description:
** init_map
*/

#include "../include/my.h"

char *map_read(char *filename)
{
    char *map;
    int fd = open(filename, O_RDONLY);
    struct stat *name;
    int size;

    name = malloc(sizeof(struct stat));
    stat(filename, name);
    size = name->st_size;
    map = malloc(sizeof(char) * size);
    read(fd, map, size);
    return map;
}

char **init_map(char *map)
{
    char **mapx;
    int x = 0;
    int y = 0;

    mapx = malloc(sizeof(char *) * 10002);
    mapx[0] = malloc(sizeof(char) * 10002);

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != '\n') {
            mapx[y][x] = map[i];
            x++;
        } else if (map[i] == '\n') {
            mapx[y][x] = '\n';
            y++;
            x = 0;
            mapx[y] = malloc(sizeof(char) * 10002);
        }
    }
    return mapx;
}
