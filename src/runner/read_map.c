/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** read_map
*/

#include "../include/my_runner.h"

char **map_to_double_array(char *buffer)
{
    unsigned int l_size = line_size(buffer);
    unsigned int lines = nb_lines(buffer);
    unsigned int i = 0;
    char **map = malloc((lines + 1) * sizeof(char *));

    map[lines] = NULL;
    while (i < lines) {
        map[i] = malloc((l_size + 1) * sizeof(char));
        make_line(map[i], i, buffer);
        i++;
    }
    return (map);
}

void delete_map(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        free(map[i]);
        i++;
    }
    free(map[i]);
}

void set_ennemy(unsigned int x, unsigned int y, char type, data_t *data)
{
    ennemy_pos_t *new = malloc(sizeof(ennemy_pos_t));

    new->x = (float)((x * 400) + 2300);
    new->y = (float)(750 - (--y * 400));
    new->type = type - 48;
    new->next = data->ennemy_pos;
    data->ennemy_pos = new;
}

void create_ennemies(data_t *data, char **map, unsigned int y_max)
{
    unsigned int x = 0;
    unsigned int y = 0;
    data->ennemy_pos = NULL;

    while (map[y] != NULL) {
        while (map[y][x] != '\0') {
            if (map[y][x] != ' ')
                set_ennemy(x, y_max - y, map[y][x], data);
            x++;
        }
        x = 0;
        y++;
    }
}

void create_map(data_t *data, char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[30000];
    char **map;

    read(fd, buffer, 30000);
    map = map_to_double_array(buffer);
    create_ennemies(data, map, nb_lines(buffer));
    delete_map(map);
    free(map);
    close(fd);
}
