/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** character_utils
*/

#include "../include/my_runner.h"

void set_scale(data_t *data, unsigned int id, sfVector2f scale)
{
    character_t *cursor = data->characters;

    while (cursor->id != id)
        cursor = cursor->next;
    sfSprite_setScale(cursor->sprite, scale);
}

void set_move(data_t *data, unsigned int id, sfVector2f movement)
{
    character_t *cursor = data->characters;

    while (cursor->id != id)
        cursor = cursor->next;
    cursor->expected_movement = movement;
    cursor->actual_movement = movement;
}

void set_start_pos(data_t *data, unsigned int id, float x, float y)
{
    character_t *cursor = data->characters;

    while (cursor->id != id)
        cursor = cursor->next;
    cursor->pos.x = x;
    cursor->pos.y = y;
    sfSprite_setPosition(cursor->sprite, cursor->pos);
    sfSprite_setScale(cursor->sprite, (sfVector2f){5.0, 5.0});
}

void set_idle(data_t *data, unsigned int id)
{
    character_t *cursor = data->characters;

    while (cursor->id != id)
        cursor = cursor->next;
    sfSprite_setTexture(cursor->sprite, cursor->idle, sfTrue);
    cursor->current_max = cursor->max_idle;
    cursor->rect.left = 0;
}
