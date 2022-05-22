/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** loops
*/

#include "../include/my_runner.h"

void menu(data_t *data)
{
    analyse_events_menu(data->window, data->event, data);
    sfRenderWindow_clear(data->window, sfWhite);
    render_background(data);
    animate_characters(data);
    render_characters(data);
    render_menu(data);
    sfRenderWindow_display(data->window);
}

void game(data_t *data)
{
    analyse_events(data->window, data->event, data);
    sfRenderWindow_clear(data->window, sfWhite);
    move_background(data);
    jump_characters(data);
    move_characters(data);
    move_ennemies(data);
    animate_characters(data);
    animate_ennemies(data);
    check_ennemies(data);
    check_mc_pos(data);
    if (data->god == 0)
        check_hitboxes(data);
    render_background(data);
    render_characters(data);
    render_ennemies(data);
    sfRenderWindow_display(data->window);
}

void cinematic(data_t *data)
{
    sfRenderWindow_clear(data->window, sfWhite);
    move_background(data);
    move_characters(data);
    animate_characters(data);
    render_background(data);
    render_characters(data);
    if (cinematic_end(data) == 1)
        start_play(data);
    sfRenderWindow_display(data->window);
}

void loop(data_t *data)
{
    while (sfRenderWindow_isOpen(data->window)) {
        switch (data->ui) {
            case (0): menu(data);
            break;
            case (1): game(data);
            break;
            case (2): end_cinematic(data);
            break;
            case (3): cinematic(data);
            break;
            case (4): loose(data);
            break;
            default: return;
            break;
        }
    }
}
