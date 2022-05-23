/*
** EPITECH PROJECT, 2022
** display_mob.c
** File description:
** display_mob.c
** First edition:
** 19:45:14 09/05/22
*/

#include "../include/my.h"


list_t *display_mob(list_t *list, all_t *all)
{
    int x = all->knight->x;
    int y = all->knight->y;
    int x_m;
    int y_m;
    list_t *ptr= list;

    while (ptr != NULL) {
        x_m = ptr->x * 64;
        y_m = ptr->y * 64;
        if ((x_m >= x - 960 && x_m <= x + 960) && (y_m >= y - 540 && y_m <= y + 540)) {
            ptr->pos.x = 960 - (x - x_m) - 64;
            ptr->pos.y = 540 - (y - y_m) - 64;
            sfSprite_setPosition(ptr->sprite, ptr->pos);
            sfRenderWindow_drawSprite(all->utils->window, ptr->sprite, NULL);
        }
        ptr = ptr->next;
    }
    return list;
}