/*
** EPITECH PROJECT, 2022
** init_mob.c
** File description:
** init_mob.c
** First edition:
** 19:25:46 09/05/22
*/

#include "../include/my.h"

list_t *create_cell(int x, int y)
{
    list_t *cell = malloc(sizeof (list_t));
    cell->rect.height = 65;
    cell->rect.width = 55;
    cell->rect.left = 0;
    cell->rect.top = 520;
    cell->x = x;
    cell->y = y;
    cell->pos.y = 0;
    cell->pos.x = 0;
    cell->scale.y = 1;
    cell->scale.x = 1;
    cell->texture = sfTexture_createFromFile("spr/game/enemy/knight.png", sfFalse);
    cell->sprite = set_sprite(cell->scale, cell->pos, cell->texture);
    sfSprite_setTextureRect(cell->sprite, cell->rect);
    return cell;
}

list_t *add_list(int x, int y, list_t *list)
{
    list_t *cell = create_cell(x, y);
    cell->next = list;
    return cell;
}

list_t *init_mob(all_t *all)
{
    list_t *list = NULL;
    int count = 0;
    for (int i = 0; i < 90; i++) {
        for (int j = 0; j < 60; j++) {
            if (all->map->map[i][j] == '2' && count < 1) {
                list = add_list(j, i, list);
                count++;
                printf("passage %d  count = %d\n ", (i * 10 + j), count);
            }
            if (count == 10)
                return list;
        }
    }
    return list;
}