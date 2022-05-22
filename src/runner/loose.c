/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** loose
*/

#include "../include/my_runner.h"

void lost(data_t *data)
{
    create_text(data, "You LOST !", (sfVector2f){770, 500});
    data->ui = 0;
}

void loose(data_t *data)
{
    analyse_events(data->window, data->event, data);
    sfRenderWindow_clear(data->window, sfWhite);
    render_background(data);
    render_text(data);
    sfRenderWindow_display(data->window);
}
