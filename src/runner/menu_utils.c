/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** menu_utils
*/

#include "../include/my_runner.h"

void menu_up(data_t *data)
{
    switch (data->selected) {
        case (2): set_menu_play(data);
        break;
        case (3): set_menu_comm(data);
        break;
    }
}

void menu_down(data_t *data)
{
    switch (data->selected) {
        case (1): set_menu_comm(data);
        break;
        case (2): set_menu_quit(data);
        break;
    }
}

void set_play(data_t *data)
{
    if (data->won == 1) {
        return;
    }
    set_moving_background_2(data);
    set_move(data, 2, (sfVector2f){-12.0, 0.0});
    set_move(data, 1, (sfVector2f){-4.0, 0.0});
    set_run(data, 1);
    data->ui = 3;
}

void set_commands(data_t *data)
{
    sfRenderWindow_close(data->window);
}
