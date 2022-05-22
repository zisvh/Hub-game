/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** hitboxes
*/

#include "../include/my_runner.h"

void animate_ennemies(data_t *data)
{
    ennemies_t *cursor = data->ennemies;
    sfTime time;
    float seconds;

    while (cursor != NULL) {
        time = sfClock_getElapsedTime(cursor->clock);
        seconds = sfTime_asMilliseconds(time) / 1000.0;
        if (seconds > cursor->anim_speed) {
            if (cursor->rect.left < cursor->anim_max - cursor->rect.width)
                cursor->rect.left += cursor->rect.width;
            else
                cursor->rect.left = 0;
            sfClock_restart(cursor->clock);
        }
        cursor = cursor->next;
    }
}

void render_ennemies(data_t *data)
{
    ennemies_t *cursor = data->ennemies;

    while (cursor != NULL) {
        sfSprite_setTextureRect(cursor->sprite, cursor->rect);
        sfRenderWindow_drawSprite(data->window, cursor->sprite, NULL);
        cursor = cursor->next;
    }
}

void move_ennemies(data_t *data)
{
    ennemies_t *cursor = data->ennemies;

    while (cursor != NULL) {
        sfSprite_move(cursor->sprite, (sfVector2f){-8.0, 0.0});
        cursor = cursor->next;
    }
}

void check_hitboxes(data_t *data)
{
    character_t *cursor = data->characters;
    ennemies_t *cursor2 = data->ennemies;

    while (cursor->id != 1)
        cursor = cursor->next;
    cursor->pos = sfSprite_getPosition(cursor->sprite);
    while (cursor2 != NULL) {
        cursor2->pos = sfSprite_getPosition(cursor2->sprite);
        if ((cursor2->pos.x + cursor2->rect.width * -5 > cursor->pos.x &&
        cursor2->pos.x + cursor2->rect.width * -5 < cursor->pos.x +
        cursor->rect.width * 5) && cursor2->pos.y < cursor->pos.y)
            lost(data);
        cursor2 = cursor2->next;
    }
}

void check_ennemies(data_t *data)
{
    ennemies_t *cursor = data->ennemies;
    unsigned int count = 0;

    while (cursor != NULL) {
        cursor->pos = sfSprite_getPosition(cursor->sprite);
        if (cursor->pos.x <= 0)
            count++;
        cursor = cursor->next;
    }
    if (count >= data->ennemy_count)
        end_cinematic_start(data);
}
