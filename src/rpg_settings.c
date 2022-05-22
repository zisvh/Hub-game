/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-keziah.picq
** File description:
** rpg_settings
*/

#include "../include/my.h"

void check_sound_event(all_t *all, int x)
{
    if (x >= 1065 && x <= 1105 && all->settings->srect.top < 800) {
        all->settings->srect.top += 200;
        sfSprite_setTextureRect(all->settings->my_sound, all->settings->srect);
        change_volume(all);
    } else if (x >= 804 && x <= 844 && all->settings->srect.top > 195) {
        all->settings->srect.top -= 200;
        sfSprite_setTextureRect(all->settings->my_sound, all->settings->srect);
        change_volume(all);
    }
}

void check_fps_event(all_t *all, int x)
{
    if (x >= 1065 && x <= 1105 && all->settings->frect.top < 400) {
        all->settings->frect.top += 200;
        sfSprite_setTextureRect(all->settings->my_fps, all->settings->frect);
        change_fps(all);
    } else if (x >= 804 && x <= 844 && all->settings->frect.top > 19) {
        all->settings->frect.top -= 200;
        sfSprite_setTextureRect(all->settings->my_fps, all->settings->frect);
        change_fps(all);
    }
}

void check_settings_event(all_t *all)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)all->utils->window);

    if (mouse.y >= 500 && mouse.y <= 550)
        check_fps_event(all, mouse.x);
    else if (mouse.y >= 740 && mouse.y <= 790)
        check_sound_event(all, mouse.x);
    else
        if (all->utils->event.type == sfEvtMouseButtonPressed
        && mouse.x >= 404 &&mouse.x <= 456 && mouse.y >= 228 && mouse.y <= 274)
            all->i = 1;

}

void display_settings(all_t *all)
{
    sfRenderWindow_drawSprite(all->utils->window,
    all->settings->my_settings, NULL);
    sfRenderWindow_drawSprite(all->utils->window,
    all->settings->my_fps, NULL);
    sfRenderWindow_drawSprite(all->utils->window,
    all->settings->my_sound, NULL);
}

void make_settings(all_t *all)
{
    display_settings(all);
}
