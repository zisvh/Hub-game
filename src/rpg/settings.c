/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** settings
*/
#include "my.h"

void launch_settings(all_t *all)
{
    sfRenderWindow_drawSprite(all->utils->window,
    all->settings->my_settings, NULL);
    sfRenderWindow_drawSprite(all->utils->window,
    all->settings->my_fps, NULL);
    sfRenderWindow_drawSprite(all->utils->window,
    all->settings->my_sound, NULL);
}

void fps(all_t *all, int i)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)all->utils->window);

    if (all->utils->event.type == sfEvtMouseButtonPressed && mouse.x >= 1065 &&
    mouse.x <= 1105 && mouse.y >= 500 && mouse.y <= 550 && i == 2 &&
    all->settings->frect.top < 400) {
        all->settings->frect.top += 200;
        sfSprite_setTextureRect(all->settings->my_fps, all->settings->frect);
    } else if (all->utils->event.type == sfEvtMouseButtonPressed &&
    mouse.x >= 804 && mouse.x <= 844 && mouse.y >= 500 && mouse.y <= 550 &&
    i == 2 && all->settings->frect.top > 195) {
        all->settings->frect.top -= 200;
        sfSprite_setTextureRect(all->settings->my_fps, all->settings->frect);
    }

}

void volume(all_t *all, int i)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)all->utils->window);

    if (all->utils->event.type == sfEvtMouseButtonPressed && mouse.x >= 1065 &&
    mouse.x <= 1105 && mouse.y >= 740 && mouse.y <= 790 && i == 2 &&
    all->settings->srect.top < 800) {
        all->settings->srect.top += 200;
        sfSprite_setTextureRect(all->settings->my_sound, all->settings->srect);
    } else if (all->utils->event.type == sfEvtMouseButtonPressed &&
    mouse.x >= 804 && mouse.x <= 844 && mouse.y >= 740 && mouse.y <= 790 &&
    i == 2 && all->settings->srect.top > 195) {
        all->settings->srect.top -= 200;
        sfSprite_setTextureRect(all->settings->my_sound, all->settings->srect);
    }

}

int return_menu(all_t *all, int i)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)all->utils->window);

    if (all->utils->event.type == sfEvtMouseButtonPressed && mouse.x >= 404 &&
    mouse.x <= 456 && mouse.y >= 228 && mouse.y <= 274 && i == 2)
        i = 1;
    return (i);
}
