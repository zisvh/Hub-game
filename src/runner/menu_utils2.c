/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** menu_utils2
*/

#include "../include/my_runner.h"

void set_menu_quit(data_t *data)
{
    sfSprite_setPosition(data->select, (sfVector2f){300, 695});
    data->selected = 3;
}

void set_menu_comm(data_t *data)
{
    sfSprite_setPosition(data->select, (sfVector2f){300, 495});
    data->selected = 2;
}

void set_menu_play(data_t *data)
{
    sfSprite_setPosition(data->select, (sfVector2f){300, 295});
    data->selected = 1;
}
