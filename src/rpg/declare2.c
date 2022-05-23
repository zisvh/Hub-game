/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** struct_init
*/

#include "my.h"

void declare_select(all_t *all)
{
    all->select->car = 1;
    all->select->pos = (sfVector2f){0, 0};
    all->select->scale = (sfVector2f){1, 1};
    all->select->texture = sfTexture_createFromFile("spr/select/back.png",
    sfFalse);
    all->select->sprite = set_sprite(all->select->scale,
    all->select->pos, all->select->texture);

    all->select->posk = (sfVector2f){0, 0};
    all->select->scalek = (sfVector2f){1, 1};
    all->select->tknight = sfTexture_createFromFile("spr/select/knight.png",
    sfFalse);
    all->select->knight = set_sprite(all->select->scalek,
    all->select->posk, all->select->tknight);
}

void declare_select2(all_t *all)
{
    all->select->posz = (sfVector2f){0, 0};
    all->select->scalez = (sfVector2f){1, 1};
    all->select->tzombie = sfTexture_createFromFile("spr/select/zombie.png",
    sfFalse);
    all->select->zombie = set_sprite(all->select->scalez,
    all->select->posz, all->select->tzombie);

    all->select->posl = (sfVector2f){0, 0};
    all->select->scalel = (sfVector2f){1, 1};
    all->select->tlucian = sfTexture_createFromFile("spr/select/lucian.png",
    sfFalse);
    all->select->lucian = set_sprite(all->select->scalel,
    all->select->posl, all->select->tlucian);
}

void declare_quest(all_t *all)
{
    all->quest->sword = 0;
    all->quest->count = 0;
    all->quest->pos = (sfVector2f){0, 0};
    all->quest->scale = (sfVector2f){1, 1};
    all->quest->texture = sfTexture_createFromFile
    ("spr/game/quest/dialogue.png", sfFalse);
    all->quest->sprite = set_sprite(all->quest->scale,
    all->quest->pos, all->quest->texture);

    all->quest->posq = (sfVector2f){0, 0};
    all->quest->scaleq = (sfVector2f){1, 1};
    all->quest->tquest = sfTexture_createFromFile("spr/game/quest/title.png",
    sfFalse);
    all->quest->quest = set_sprite(all->quest->scaleq,
    all->quest->posq, all->quest->tquest);
}

void declare_inventory(all_t *all)
{
    all->inventory->yes = 0;
    all->inventory->pos = (sfVector2f){0, 0};
    all->inventory->scale = (sfVector2f){1, 1};
    all->inventory->texture =
    sfTexture_createFromFile("spr/game/hud/inventory.png",
    sfFalse);
    all->inventory->sprite = set_sprite(all->inventory->scale,
    all->inventory->pos, all->inventory->texture);

    all->inventory->pos2 = (sfVector2f){0, 0};
    all->inventory->scale2 = (sfVector2f){1, 1};
    all->inventory->texture2 =
    sfTexture_createFromFile("spr/game/hud/inventory2.png",
    sfFalse);
    all->inventory->sprite2 = set_sprite(all->inventory->scale2,
    all->inventory->pos2, all->inventory->texture2);
}
