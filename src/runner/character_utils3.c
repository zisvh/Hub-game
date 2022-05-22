/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** character_utils3
*/

#include "../include/my_runner.h"

void set_run(data_t *data, unsigned int id)
{
    character_t *cursor = data->characters;

    while (cursor->id != id)
        cursor = cursor->next;
    sfSprite_setTexture(cursor->sprite, cursor->run, sfTrue);
    cursor->current_max = cursor->max_run;
    cursor->rect.left = 0;
}

void set_jump(data_t *data, unsigned int id)
{
    character_t *cursor = data->characters;

    while (cursor->id != id)
        cursor = cursor->next;
    sfSprite_setTexture(cursor->sprite, cursor->jump, sfTrue);
    cursor->current_max = cursor->max_jump;
    cursor->rect.left = 0;
}

void set_run_max(data_t *data, unsigned int id, int max_run)
{
    character_t *cursor = data->characters;

    while (cursor->id != id)
        cursor = cursor->next;
    cursor->max_run = max_run;
}

void set_jump_max(data_t *data, unsigned int id, int max_jump)
{
    character_t *cursor = data->characters;

    while (cursor->id != id)
        cursor = cursor->next;
    cursor->max_jump = max_jump;
}

int is_mc_run(data_t *data)
{
    character_t *cursor = data->characters;

    while (cursor->id != 1)
        cursor = cursor->next;
    if (cursor->current_max == cursor->max_run)
        return (1);
    return (0);
}
