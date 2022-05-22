/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-keziah.picq
** File description:
** rpg_select
*/

#include "../include/my.h"

void display_select(all_t *all)
{
    sfRenderWindow_clear(all->utils->window, sfBlack);
    sfRenderWindow_drawSprite(all->utils->window, all->sky->sprite, NULL);
    sfRenderWindow_drawSprite(all->utils->window, all->select->sprite, NULL);
    if (all->select->car % 3 == 1)
        sfRenderWindow_drawSprite(all->utils->window,
        all->select->knight, NULL);
    if (all->select->car % 3 == 2)
        sfRenderWindow_drawSprite(all->utils->window,
        all->select->zombie, NULL);
    if (all->select->car % 3 == 0)
        sfRenderWindow_drawSprite(all->utils->window,
        all->select->lucian, NULL);
}

void change_character(all_t *all)
{

    sfVector2i mouse = sfMouse_getPosition((sfWindow *)all->utils->window);

    if (all->utils->event.type == sfEvtMouseButtonPressed
    && mouse.x >= 600 && mouse.x <= 642
    && mouse.y >= 506 && mouse.y <= 584) {
        all->select->car++;
    }
    if (all->utils->event.type == sfEvtMouseButtonPressed
    && mouse.x >= 1278 && mouse.x <= 1324
    && mouse.y >= 498 && mouse.y <= 582) {
        all->select->car += 2;
    }
    if (all->utils->event.type == sfEvtMouseButtonPressed
    && mouse.x >= 870 && mouse.x <= 1044
    && mouse.y >= 878 && mouse.y <= 956) {
        all->i = 5;
    }
}

void make_select(all_t *all)
{
    display_select(all);
}
