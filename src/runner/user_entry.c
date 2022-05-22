/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** user_entry
*/

#include "../include/my_runner.h"

void move_right(data_t *data)
{
    if (data->pressed == 0 && is_facing_left(data) == 1)
        set_relative_pos_id(data, 1, (sfVector2f){-48.0 * 2.5, 0.0});
    if (data->r_limits == 0) {
        data->pressed = 1;
        set_scale_id(data, 1, (sfVector2f){5.0, 5.0});
        set_move(data, 2, (sfVector2f){-4.0, 0.0});
        set_moving_background(data);
        set_move(data, 1, (sfVector2f){4.0, 0.0});
        if (!(is_mc_run(data)))
            set_run(data, 1);
    }
}

void move_left(data_t *data)
{
    if (data->pressed == 0 && is_facing_left(data) == 0)
        set_relative_pos_id(data, 1, (sfVector2f){48.0 * 2.5, 0.0});
    if (data->l_limits == 0) {
        data->pressed = 1;
        set_move(data, 2, (sfVector2f){0.0, 0.0});
        stop_moving_background(data);
        set_move(data, 1, (sfVector2f){-8.0, 0.0});
        set_scale_id(data, 1, (sfVector2f){-5.0, 5.0});
        if (!(is_mc_run(data)))
            set_run(data, 1);
    }
}

void jump(data_t *data)
{
    if (data->jumping == 0) {
        set_jump(data, 1);
        data->jump = -70.0;
        data->jumping = 1;
    }
}

void stop_all(data_t *data)
{
    set_move(data, 2, (sfVector2f){0.0, 0.0});
    stop_moving_background(data);
    set_move(data, 1, (sfVector2f){0.0, 0.0});
    set_idle(data, 1);
    data->pressed = 0;
}

void analyse_events(sfRenderWindow *window, sfEvent event, data_t *data)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        switch (event.type) {
            case (sfEvtClosed): sfRenderWindow_close(window);
            break;
            case (sfEvtKeyPressed): manage_key_press(data, event);
            break;
            default: ;
            break;
        }
    }
}

void manage_key_press(data_t *data, sfEvent event)
{
    switch (event.key.code) {
        case (sfKeySpace): jump(data);
        break;
    }
}

void manage_key_release(data_t *data, sfEvent event)
{
    switch (event.key.code) {
        case (sfKeyRight): stop_all(data);
        break;
        case (sfKeyLeft): stop_all(data);
        break;
    }
}
