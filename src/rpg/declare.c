/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** struct_init
*/

#include "my.h"

void declare_sky(all_t *all)
{
    all->sky->pos = (sfVector2f){0, 0};
    all->sky->scale = (sfVector2f){1, 1};
    all->sky->texture =
    sfTexture_createFromFile("spr/game/bg/sky.png", sfFalse);
    all->sky->sprite = set_sprite(all->sky->scale,
    all->sky->pos, all->sky->texture);
}

void declare_map(all_t *all)
{
    all->map->scale.x = 3;
    all->map->scale.y = 3;
    all->map->pos.x = 0;
    all->map->pos.y = 0;
    all->map->rect.top = 5458;
    all->map->rect.left = 87;
    all->map->rect.height = 1920;
    all->map->rect.width = 1080;
    all->map->texture =
    sfTexture_createFromFile("spr/game/bg/map2.png", sfFalse);
    all->map->sprite = set_sprite(all->map->scale,
    all->map->pos, all->map->texture);
    sfSprite_setTextureRect(all->map->sprite, all->map->rect);
}

void declare_menub(all_t *all)
{
    all->menu->my_texit = sfTexture_createFromFile("spr/menu/exit.png", NULL);
    all->menu->my_texitb =
    sfTexture_createFromFile("spr/menu/exitc.png", NULL);
    all->menu->my_exit = set_sprite(all->menu->scale, all->menu->exitpos,
    all->menu->my_texit);
    all->menu->my_exitb = sfSprite_create();
    all->menu->my_tctrl = sfTexture_createFromFile("spr/menu/ctrl.png", NULL);
    all->menu->my_tctrlb =
    sfTexture_createFromFile("spr/menu/startclick.png", NULL);
    all->menu->my_ctrl = set_sprite(all->menu->scale, all->menu->ctrlpos,
    all->menu->my_tctrl);
    all->menu->my_ctrlb = sfSprite_create();
}

void declare_menu(all_t *all)
{
    all->menu->playpos = (sfVector2f){0, 48.5};
    all->menu->ctrlpos = (sfVector2f){0, 53};
    all->menu->exitpos = (sfVector2f){0, 58};
    all->menu->scale = (sfVector2f){1, 0.94};
    all->menu->my_tmenu = sfTexture_createFromFile("spr/menu/menu.png", NULL);
    all->menu->my_menu = sfSprite_create();
    all->menu->thow1 =
    sfTexture_createFromFile("spr/menu/howclose.png", NULL);
    all->menu->how1 = sfSprite_create();
    all->menu->thow2 =
    sfTexture_createFromFile("spr/menu/howopen.png", NULL);
    all->menu->how2 = sfSprite_create();
    all->menu->my_tplay =
    sfTexture_createFromFile("spr/menu/start.png", NULL);
    all->menu->my_tplayb =
    sfTexture_createFromFile("spr/menu/startc.png", NULL);
    all->menu->my_play = set_sprite(all->menu->scale, all->menu->playpos,
    all->menu->my_tplay);
    all->menu->my_playb = sfSprite_create();
}

void declare(all_t *all)
{
    int x = 0;
    int y = 0;
    char *buffer = map_read("map");

    all->game->clock = sfClock_create();
    all->map->map = malloc(sizeof (char *) * 90);
    all->map->map[0] = malloc(sizeof (char) * 60);

    for (int i = 0; buffer[i] != 0; i++) {
        if (buffer[i] == '\n') {
            y++;
            x = 0;
            all->map->map[y] = malloc(sizeof(char) * 60);
        } else {
            all->map->map[y][x] = buffer[i];
            x++;
        }
    }
    declare_sky(all);
    declare_map(all);
    declare_knight1(all);
    declare_knight2(all);
    declare_intro(all);
    declare_menu(all);
    declare_menub(all);
    declare_settings(all);
    declare_settings2(all);
    declare_pause(all);
    set_my_textures(all);
    declare_select(all);
    declare_select2(all);
    declare_quest(all);
    declare_inventory(all);
    all->i = 0;
}
