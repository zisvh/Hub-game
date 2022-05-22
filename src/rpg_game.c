/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-keziah.picq
** File description:
** rpg_game
*/

#include "../include/my.h"

void game_movement(all_t *all)
{
    if ((sfKeyboard_isKeyPressed(sfKeyZ)
    || sfKeyboard_isKeyPressed(sfKeyUp)) && check_up(all) == 2)
        all->map->rect.top -= 2;
    if ((sfKeyboard_isKeyPressed(sfKeyD)
    || sfKeyboard_isKeyPressed(sfKeyRight)) && check_right(all) == 2)
        all->map->rect.left += 2;
    if ((sfKeyboard_isKeyPressed(sfKeyQ)
    || sfKeyboard_isKeyPressed(sfKeyLeft)) && check_left(all) == 2)
        all->map->rect.left -= 2;
    if ((sfKeyboard_isKeyPressed(sfKeyS)
    || sfKeyboard_isKeyPressed(sfKeyDown)) && check_down(all) == 2)
        all->map->rect.top += 2;
}

void game_movement2(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyUp)) {
        all->knight->rect.top = 520;
        all->knight->rect.left = all->knight->rect.left + 64;
        if (all->knight->rect.left >= 510)
            all->knight->rect.left = 0;
        all->knight->dir = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)
    || sfKeyboard_isKeyPressed(sfKeyRight)) {
        all->knight->rect.top = 710;
        all->knight->rect.left = all->knight->rect.left + 64;
        if (all->knight->rect.left >= 510)
            all->knight->rect.left = 0;
        all->knight->dir = 2;
    }
}

void game_movement3(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)
    || sfKeyboard_isKeyPressed(sfKeyLeft)) {
        all->knight->rect.top = 580;
        all->knight->rect.left = all->knight->rect.left + 64;
        if (all->knight->rect.left >= 510)
            all->knight->rect.left = 0;
        all->knight->dir = 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)
    || sfKeyboard_isKeyPressed(sfKeyDown)) {
        all->knight->rect.top = 640;
        all->knight->rect.left = all->knight->rect.left + 64;
        if (all->knight->rect.left >= 510)
            all->knight->rect.left = 0;
        all->knight->dir = 4;
    }
}

void display_game(all_t *all)
{
    sfRenderWindow_clear(all->utils->window, sfBlack);
    sfSprite_setTextureRect(all->map->sprite, all->map->rect);
    sfSprite_setTextureRect(all->knight->sprite, all->knight->rect);
    sfSprite_setTextureRect(all->knight->sprite2, all->knight->rect);
    sfSprite_setTextureRect(all->knight->sprite3, all->knight->rect);
    sfRenderWindow_drawSprite(all->utils->window, all->sky->sprite, NULL);
    sfRenderWindow_drawSprite(all->utils->window, all->map->sprite, NULL);
    all->list = display_mob(all->list, all);
    if (all->select->car % 3 == 1)
        sfRenderWindow_drawSprite(all->utils->window,
        all->knight->sprite, NULL);
    if (all->select->car % 3 == 2)
        sfRenderWindow_drawSprite(all->utils->window,
        all->knight->sprite2, NULL);
    if (all->select->car % 3 == 0)
        sfRenderWindow_drawSprite(all->utils->window,
        all->knight->sprite3, NULL);
}

void make_game(all_t *all)
{
    all->game->time = sfClock_getElapsedTime(all->game->clock);
    all->game->seconds = sfTime_asSeconds(all->game->time);
    pausegame(all);
    display_game(all);
    make_quest(all);
    make_inventory(all);
    if (all->game->seconds > 0.12) {
        game_movement2(all);
        game_movement3(all);
        character_attack(all);
        sfClock_restart(all->game->clock);
    }
    if (all->quest->count == 1)
        sfRenderWindow_drawSprite(all->utils->window,
        all->quest->quest, NULL);
    game_movement(all);
}
