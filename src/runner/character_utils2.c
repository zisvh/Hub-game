/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** character_utils2
*/

#include "../include/my_runner.h"

void check_mc_pos(data_t *data)
{
    character_t *cursor = data->characters;

    while (cursor->id != 1)
        cursor = cursor->next;
    cursor->pos = sfSprite_getPosition(cursor->sprite);
    if (cursor->pos.x >= 960 && (is_mc_run(data) == 1 && is_facing_left(data)
        == 0)) {
        set_move(data, 1, (sfVector2f){0.0, 0.0});
        set_moving_background_2(data);
        set_move(data, 2, (sfVector2f){-8.0, 0.0});
        data->r_limits = 1;
        sfSprite_setPosition(cursor->sprite, (sfVector2f){960.0, 750});
    } else if (cursor->pos.x <= (48 * 2.5) && (is_mc_run(data) == 1 &&
        is_facing_left(data) == 1)) {
        set_move(data, 1, (sfVector2f){0.0, 0.0});
        data->l_limits = 1;
        sfSprite_setPosition(cursor->sprite, (sfVector2f){138.0, 750});
    } else {
        data->r_limits = 0;
        data->l_limits = 0;
    }
}

void set_relative_pos_id(data_t *data, unsigned int id, sfVector2f relative_pos)
{
    character_t *cursor = data->characters;

    while (cursor->id != id)
        cursor = cursor->next;
    cursor->pos.x += relative_pos.x;
    cursor->pos.y += relative_pos.y;
    sfSprite_setPosition(cursor->sprite, cursor->pos);
}

void set_scale_id(data_t *data, unsigned int id, sfVector2f scale)
{
    character_t *cursor = data->characters;

    while (cursor->id != id)
        cursor = cursor->next;
    sfSprite_setScale(cursor->sprite, scale);
}

void set_anim_var(data_t *data, unsigned int id, int max_idle, float anim_speed)
{
    character_t *cursor = data->characters;

    while (cursor->id != id)
        cursor = cursor->next;
    cursor->max_idle = max_idle;
    cursor->current_max = max_idle;
    cursor->anim_speed = anim_speed;
}

int is_facing_left(data_t *data)
{
    character_t *cursor = data->characters;

    while (cursor->next != NULL)
        cursor = cursor->next;
    if (sfSprite_getScale(cursor->sprite).x < 0)
        return (1);
    return (0);
}
