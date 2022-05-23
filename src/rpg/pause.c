/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** pause
*/

#include "my.h"

int check_pause(all_t *all)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)all->utils->window);

    if (mouse.x >= 550 && mouse.x <= 822 && mouse.y >= 668 && mouse.y <= 692)
        return 1;
    if (mouse.x >= 904 && mouse.x <= 1082 && mouse.y >= 652 && mouse.y <= 690)
        return 2;
    if (mouse.x >= 1178 && mouse.x <= 1316 && mouse.y >= 658 && mouse.y <= 696)
        return 3;
    else
        return 0;
}

void buttons(int returnn, all_t *all)
{
    if (returnn == 1)
        sfRenderWindow_drawSprite(all->utils->window,
        all->pause->my_resume, NULL);
    if (returnn == 2)
        sfRenderWindow_drawSprite(all->utils->window,
        all->pause->my_menu, NULL);
    if (returnn == 3)
        sfRenderWindow_drawSprite(all->utils->window,
        all->pause->my_quit, NULL);
}

void make_pause(all_t *all)
{
    sfRenderWindow_drawSprite(all->utils->window, all->pause->my_pause, NULL);
    buttons(check_pause(all), all);
    if (all->utils->event.type == sfEvtMouseButtonPressed
    && check_pause(all) == 1)
        all->i = 5;
    if (all->utils->event.type == sfEvtMouseButtonPressed
    && check_pause(all) == 2)
        all->i = 1;
    if (all->utils->event.type == sfEvtMouseButtonPressed
    && check_pause(all) == 3)
        all->i = 0;
}

void pausegame(all_t *all)
{
    int press = 0;
    if (all->utils->event.type == sfEvtKeyPressed
    && all->utils->event.key.code == sfKeyEscape) {
        press = 1;
        all->i = 3;
    }
    if (press == 1)
        all->utils->event.key.code = sfKeyEqual;
}

void resume(all_t *all)
{
    int press = 0;
    if (all->utils->event.type == sfEvtKeyPressed
    && all->utils->event.key.code == sfKeyEscape) {
        press = 1;
        all->i = 2;
    }
    if (press == 1)
        all->utils->event.key.code = sfKeyEqual;
}
