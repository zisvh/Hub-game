/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** end_cinematic
*/

#include "../include/my_runner.h"

int end_cinematic_end(data_t *data)
{
    character_t *cursor = data->characters;

    while (cursor->id != 1)
        cursor = cursor->next;
    cursor->pos = sfSprite_getPosition(cursor->sprite);
    if (cursor->pos.x >= 840.0)
        return (1);
    return (0);
}

void start_end(data_t *data)
{
    stop_all(data);
    create_text(data, "You WON !", (sfVector2f){780, 500});
    data->won = 1;
    data->ui = 0;
}

void end_cinematic(data_t *data)
{
    sfRenderWindow_clear(data->window, sfWhite);
    move_background(data);
    move_characters(data);
    animate_characters(data);
    render_background(data);
    render_characters(data);
    if (end_cinematic_end(data) == 1)
        start_end(data);
    sfRenderWindow_display(data->window);
}

void end_cinematic_start(data_t *data)
{
    stop_all(data);
    set_move(data, 1, (sfVector2f){8.0, 0.0});
    set_run(data, 1);
    data->ui = 2;
}
