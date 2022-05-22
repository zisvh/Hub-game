/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** ennemies
*/

#include "../include/my_runner.h"

void make_ennemy_types(data_t *data)
{
    data->ennemy_types = malloc(sizeof(ennemy_types_t));

    data->ennemy_types->type_1 = sfTexture_createFromFile("images/1Idle.png", NULL);
    data->ennemy_types->type_2 = sfTexture_createFromFile("images/2Walk.png", NULL);
}

sfTexture *choose_ennemy_texture(unsigned int type, data_t *data)
{
    switch (type) {
        case (1): return (data->ennemy_types->type_1);
        break;
        case (2): return (data->ennemy_types->type_2);
        break;
    }
}

void type_specific(data_t *data, ennemy_pos_t *pos, ennemies_t *new)
{
    if (pos->type == 1) {
        sfSprite_setTexture(new->sprite, data->ennemy_types->type_1, sfTrue);
        sfSprite_setScale(new->sprite, (sfVector2f){-5, 5});
        new->rect = (sfIntRect){0, 0, 48, 48};
        new->anim_speed = 0.4;
        new->anim_max = 192;
    } else {
        sfSprite_setTexture(new->sprite, data->ennemy_types->type_2, sfTrue);
        sfSprite_setScale(new->sprite, (sfVector2f){-5, 5});
        new->rect = (sfIntRect){0, 0, 32, 32};
        new->anim_speed = 0.2;
        new->anim_max = 192;
    }
}

void create_ennemy(data_t *data, ennemy_pos_t *pos)
{
    ennemies_t *new = malloc(sizeof(ennemies_t));
    sfTexture *text = choose_ennemy_texture(pos->type, data);

    new->sprite = sfSprite_create();
    new->pos.x = pos->x;
    new->pos.y = pos->y;
    new->clock = sfClock_create();
    type_specific(data, pos, new);
    sfSprite_setTextureRect(new->sprite, new->rect);
    sfSprite_setPosition(new->sprite, new->pos);
    new->next = data->ennemies;
    data->ennemies = new;
}

void make_ennemies(data_t *data)
{
    data->ennemies = NULL;
    ennemy_pos_t *cursor = data->ennemy_pos;

    while (cursor != NULL) {
        data->ennemy_count++;
        create_ennemy(data, cursor);
        cursor = cursor->next;
    }
}
