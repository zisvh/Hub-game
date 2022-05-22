/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-keziah.picq
** File description:
** rpg_inventory
*/

#include "../include/my.h"

void display_inventory(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyI) && all->quest->sword == 0)
        sfRenderWindow_drawSprite(all->utils->window,
        all->inventory->sprite, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyI) && all->quest->sword == 1)
        sfRenderWindow_drawSprite(all->utils->window,
        all->inventory->sprite2, NULL);
}

void make_inventory(all_t *all)
{
    display_inventory(all);
}
