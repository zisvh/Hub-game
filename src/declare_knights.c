/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-keziah.picq
** File description:
** declare_knights
*/

#include "my.h"

void declare_knight1(all_t *all)
{
    all->knight->x = 544;
    all->knight->y = 5600;
    all->knight->scale.x = 2;
    all->knight->scale.y = 2;
    all->knight->pos.x = 960;
    all->knight->pos.y = 540;
    all->knight->rect.top = 520;
    all->knight->rect.left = 0;
    all->knight->rect.height = 65;
    all->knight->rect.width = 55;
    all->knight->texture =
    sfTexture_createFromFile("spr/game/enemy/knight.png", sfFalse);
}

void declare_knight2(all_t *all)
{
    all->knight->texture2 =
    sfTexture_createFromFile("spr/game/enemy/zombie.png", sfFalse);
    all->knight->texture3 =
    sfTexture_createFromFile("spr/game/enemy/lucian.png", sfFalse);
    all->knight->sprite = set_sprite(all->knight->scale,
    all->knight->pos, all->knight->texture);
    sfSprite_setTextureRect(all->knight->sprite, all->knight->rect);
    all->knight->sprite2 = set_sprite(all->knight->scale,
    all->knight->pos, all->knight->texture2);
    sfSprite_setTextureRect(all->knight->sprite, all->knight->rect);
    all->knight->sprite3 = set_sprite(all->knight->scale,
    all->knight->pos, all->knight->texture3);
    sfSprite_setTextureRect(all->knight->sprite, all->knight->rect);
}
