/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-keziah.picq
** File description:
** rpg_settings2
*/

#include "my.h"

void change_fps(all_t *all)
{
    if (all->settings->frect.top == 0)
        sfRenderWindow_setFramerateLimit(all->utils->window, 30);
    if (all->settings->frect.top == 200)
        sfRenderWindow_setFramerateLimit(all->utils->window, 60);
    if (all->settings->frect.top == 400)
        sfRenderWindow_setFramerateLimit(all->utils->window, 120);
}

void change_volume(all_t *all)
{
    if (all->settings->srect.top == 0) {
        sfMusic_setVolume(all->intro->music, 0);
    }
    if (all->settings->srect.top == 200) {
        sfMusic_setVolume(all->intro->music, 25);
    }
    if (all->settings->srect.top == 400) {
        sfMusic_setVolume(all->intro->music, 50);
    }
    if (all->settings->srect.top == 600) {
        sfMusic_setVolume(all->intro->music, 75);
    }
    if (all->settings->srect.top == 800) {
        sfMusic_setVolume(all->intro->music, 100);
    }
}
