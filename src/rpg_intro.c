/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-keziah.picq
** File description:
** rpg_intro
*/

#include "../include/my.h"

void make_intro(all_t *all)
{
    all->intro->titlepos = sfSprite_getPosition(all->intro->my_title);
    sfRenderWindow_drawSprite(all->utils->window, all->intro->my_bg, NULL);
    sfRenderWindow_drawSprite(all->utils->window, all->intro->my_title, NULL);

    if ((all->utils->event.type == sfEvtKeyPressed
    || all->utils->event.type == sfEvtMouseButtonPressed))
        all->i = 1;
    if (all->intro->titlepos.y < -100)
        sfSprite_move(all->intro->my_title, all->intro->titlemove);
}
