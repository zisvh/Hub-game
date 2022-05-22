/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** cinematic
*/

#include "../include/my_runner.h"

int cinematic_end(data_t *data)
{
    character_t *cursor = data->characters;

    while (cursor->id != 1)
        cursor = cursor->next;
    cursor->pos = sfSprite_getPosition(cursor->sprite);
    if (cursor->pos.x <= 60.0)
        return (1);
    return (0);
}

void start_play(data_t *data)
{
    set_moving_background(data);
    set_move(data, 2, (sfVector2f){-8.0, 0.0});
    set_move(data, 1, (sfVector2f){0.0, 0.0});
    data->ui = 1;
}
