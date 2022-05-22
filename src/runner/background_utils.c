/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** background_utils
*/

#include "../include/my_runner.h"

void set_moving_background_2(data_t *data)
{
    object_t *cursor = data->background;
    float i = 0;
    int half = 0;

    while (cursor != NULL) {
        cursor->actual_movement.x = cursor->expected_movement.x + i;
        cursor = cursor->next;
        if (half % 2 == 0)
            i += -1;
        half++;
    }
}

void stop_moving_background(data_t *data)
{
    object_t *cursor = data->background;

    while (cursor != NULL) {
        cursor->actual_movement = (sfVector2f){0.0, 0.0};
        cursor = cursor->next;
    }
}

void set_moving_background(data_t *data)
{
    object_t *cursor = data->background;

    while (cursor != NULL) {
        cursor->actual_movement = cursor->expected_movement;
        cursor = cursor->next;
    }
}

void set_speed_and_pos(data_t *data, unsigned int id, float speed)
{
    object_t *cursor = data->background;
    object_t *cursor2 = data->background;

    while (cursor->id != id)
        cursor = cursor->next;
    while (cursor2->id != id + 1)
        cursor2 = cursor2->next;
    cursor->expected_movement.x = speed;
    cursor2->expected_movement.x = speed;
    cursor2->pos.x = 1920.0;
    sfSprite_setPosition(cursor2->sprite, cursor2->pos);
}
