/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** menu
*/

#include "../include/my_runner.h"

void render_text(data_t *data)
{
    text_t *cursor = data->text;

    while (cursor != NULL) {
        sfRenderWindow_drawText(data->window, cursor->text, NULL);
        cursor = cursor->next;
    }
}

void render_menu(data_t *data)
{
    sfRenderWindow_drawSprite(data->window, data->select, NULL);
    render_text(data);
}

void analyse_events_menu(sfRenderWindow *window, sfEvent event, data_t *data)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        switch (event.type) {
            case (sfEvtClosed): sfRenderWindow_close(window);
            break;
            case (sfEvtKeyPressed): menu_key_press(data, event);
            break;
            default: ;
            break;
        }
    }
}

void menu_key_press(data_t *data, sfEvent event)
{
    switch (event.key.code) {
        case (sfKeyUp): menu_up(data);
        break;
        case (sfKeyDown): menu_down(data);
        break;
        case (sfKeyEnter): menu_select(data);
        break;
    }
}

void menu_select(data_t *data)
{
    switch (data->selected) {
        case (1): set_play(data);
        break;
        case (2): set_commands(data);
        break;
        case (3): sfRenderWindow_close(data->window);
        break;
    }
}
