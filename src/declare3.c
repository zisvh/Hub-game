/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** declare3
*/

#include "my.h"

void declare_pause(all_t *all)
{
    all->pause->scale = (sfVector2f){1.5, 1.5};
    all->pause->pos = (sfVector2f){-500, -310};
    all->pause->my_tpause =
    sfTexture_createFromFile("spr/pause/pause.png", NULL);
    all->pause->my_tresume =
    sfTexture_createFromFile("spr/pause/pauser.png", NULL);
    all->pause->my_tmenu =
    sfTexture_createFromFile("spr/pause/pausem.png", NULL);
    all->pause->my_tquit =
    sfTexture_createFromFile("spr/pause/pauseq.png", NULL);
    all->pause->my_pause = set_sprite(all->pause->scale, all->pause->pos,
    all->pause->my_tpause);
    all->pause->my_resume = set_sprite(all->pause->scale, all->pause->pos,
    all->pause->my_tresume);
    all->pause->my_menu = set_sprite(all->pause->scale, all->pause->pos,
    all->pause->my_tmenu);
    all->pause->my_quit = set_sprite(all->pause->scale, all->pause->pos,
    all->pause->my_tquit);
}

void declare_settings2(all_t *all)
{
    all->settings->my_tsettings = sfTexture_createFromFile
    ("spr/settings/settings.png", NULL);
    all->settings->my_tfps = sfTexture_createFromFile
    ("spr/settings/fps.png", NULL);
    all->settings->my_tsound = sfTexture_createFromFile
    ("spr/settings/sound.png", NULL);
    all->settings->my_settings = sfSprite_create();
    all->settings->my_fps = set_sprite(all->settings->fscale,
    all->settings->fpos, all->settings->my_tfps);
    all->settings->my_sound = set_sprite(all->settings->sscale,
    all->settings->spos, all->settings->my_tsound);
    sfSprite_setTextureRect(all->settings->my_fps, all->settings->frect);
    sfSprite_setTextureRect(all->settings->my_sound, all->settings->srect);
}

void declare_settings(all_t *all)
{
    all->settings->fpos = (sfVector2f){840, 455};
    all->settings->spos = (sfVector2f){840, 690};
    all->settings->fscale = (sfVector2f){0.5, 0.5};
    all->settings->sscale = (sfVector2f){0.5, 0.5};
    all->settings->frect.height = 196;
    all->settings->frect.width = 458;
    all->settings->frect.top =  0;
    all->settings->frect.left = 0;
    all->settings->srect.height = 196;
    all->settings->srect.width = 458;
    all->settings->srect.top = 200;
    all->settings->srect.left = 0;
}

void declare_intro(all_t *all)
{
    all->intro->my_tbg = sfTexture_createFromFile("spr/intro/intro.png", NULL);
    all->intro->my_ttitle =
    sfTexture_createFromFile("spr/intro/title.png", NULL);
    all->intro->my_bg = sfSprite_create();
    all->intro->my_title = sfSprite_create();
    all->intro->scale = (sfVector2f){1, 1};
    all->intro->settitlepos = (sfVector2f){0, -650};
    sfSprite_setScale(all->intro->my_title, all->intro->scale);
    sfSprite_setPosition(all->intro->my_title, all->intro->settitlepos);
    all->intro->titlemove = (sfVector2f){0, 0.2};
    all->intro->music = sfMusic_createFromFile("spr/songs/game.ogg");
}

void declare_mobs(all_t *all)
{
    all->list = init_mob(all);
}
