/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** rendering
*/

#include "../include/my_runner.h"

void animate_characters(data_t *data)
{
    character_t *cursor = data->characters;
    sfTime time;
    float seconds;

    while (cursor != NULL) {
        time = sfClock_getElapsedTime(cursor->clock);
        seconds = sfTime_asMilliseconds(time) / 1000.0;
        if (seconds > cursor->anim_speed) {
            if (cursor->rect.left < cursor->current_max - cursor->rect.width)
                cursor->rect.left += cursor->rect.width;
            else
                cursor->rect.left = (cursor->id == 1 && data->jumping == 1) ?
                    cursor->current_max - cursor->rect.width : 0;
            sfClock_restart(cursor->clock);
        }
        cursor = cursor->next;
    }
}

void render_characters(data_t *data)
{
    character_t *cursor = data->characters;

    while (cursor != NULL) {
        sfSprite_setTextureRect(cursor->sprite, cursor->rect);
        sfRenderWindow_drawSprite(data->window, cursor->sprite, NULL);
        cursor = cursor->next;
    }
}

void render_background(data_t *data)
{
    object_t *cursor = data->background;

    while (cursor->next != NULL) {
        sfSprite_setTextureRect(cursor->sprite, cursor->rect);
        sfRenderWindow_drawSprite(data->window, cursor->sprite, NULL);
        cursor = cursor->next;
    }
    sfSprite_setTextureRect(cursor->sprite, cursor->rect);
    sfRenderWindow_drawSprite(data->window, cursor->sprite, NULL);
}
