/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** scoreboard
*/

#include "my.h"

void make_leaderboard(all_t *all)
{
    sfRenderWindow_drawSprite(all->utils->window, all->lb->bg, NULL);
}

int return_menulb(all_t *all, int i)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)all->utils->window);

    if (all->utils->event.type == sfEvtMouseButtonPressed && mouse.x >= 470 &&
    mouse.x <= 547 && mouse.y >= 267 && mouse.y <= 345 && i == 5)
        i = 1;
    return (i);
}
