/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** outils
*/

#include "my.h"

sfSprite *set_sprite(sfVector2f scale, sfVector2f pos, sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}

void set_my_textures(all_t *all)
{
    sfSprite_setTexture(all->intro->my_bg, all->intro->my_tbg, sfFalse);
    sfSprite_setTexture(all->select->sprite, all->select->texture, sfFalse);
    sfSprite_setTexture(all->intro->my_title, all->intro->my_ttitle, sfFalse);
    sfSprite_setTexture(all->menu->my_menu, all->menu->my_tmenu, sfFalse);
    sfSprite_setTexture(all->menu->how1, all->menu->thow1, sfFalse);
    sfSprite_setTexture(all->menu->how2, all->menu->thow2, sfFalse);
    sfSprite_setTexture(all->menu->my_playb, all->menu->my_tplayb, sfFalse);
    sfSprite_setTexture(all->menu->my_exitb, all->menu->my_texitb, sfFalse);
    sfSprite_setTexture(all->menu->my_ctrlb, all->menu->my_tctrlb, sfFalse);
    sfSprite_setTexture(all->settings->my_settings,
    all->settings->my_tsettings, sfFalse);
    sfSprite_setTexture(all->lb->bg, all->lb->tbg, sfFalse);
}
