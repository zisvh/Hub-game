/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** movement
*/

#include "../include/my_runner.h"

void move_background(data_t *data)
{
    object_t *cursor = data->background;

    while (cursor != NULL) {
        sfSprite_move(cursor->sprite, cursor->actual_movement);
        cursor->pos = sfSprite_getPosition(cursor->sprite);
        if (cursor->pos.x <= -1920)
            sfSprite_setPosition(cursor->sprite, (sfVector2f){1920.0, 0.0});
        cursor = cursor->next;
    }
}

void move_characters(data_t *data)
{
    character_t *cursor = data->characters;

    while (cursor != NULL) {
        sfSprite_move(cursor->sprite, cursor->actual_movement);
        cursor->pos = sfSprite_getPosition(cursor->sprite);
        if (cursor->id == 2) {
            if (cursor->pos.x <= 0 - cursor->rect.width)
                sfSprite_setPosition(cursor->sprite, (sfVector2f){(1920.0 + cursor->rect.width * 5.0), 800.0});
        }
        cursor = cursor->next;
    }
}

void follow_jump(data_t *data, character_t *cursor)
{
    if (data->jump < 0.8)
        data->jump = 0.8;
    else if (data->jump < 40.0)
        data->jump *= 1.2;
    if (sfSprite_getPosition(cursor->sprite).y >= 750.0) {
        data->jumping = 0;
        cursor->actual_movement.y = 0.0;
        set_run(data, 1);
        sfSprite_setPosition(cursor->sprite,
            (sfVector2f){sfSprite_getPosition(cursor->sprite).x, 750.0});
        data->half_jump = 0;
    }
}

void jump_characters(data_t *data)
{
    character_t *cursor = data->characters;

    if (data->jumping == 1) {
        while (cursor->id != 1)
            cursor = cursor->next;
        cursor->actual_movement.y = data->jump;
        if (data->half_jump == 0) {
            if (data->jump <= -0.8)
                data->jump /= 1.2;
            else {
                data->jump = 0;
                data->half_jump = 1;
            }
        }
        if (data->half_jump == 1)
            follow_jump(data, cursor);
    }
}
