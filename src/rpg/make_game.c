/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-keziah.picq
** File description:
** make_game
*/

#include "my.h"

void change_rect_up(all_t *all)
{
    if (all->knight->rect.top == 1400) {
        if (all->knight->rect.left <= 330) {
            all->knight->rect.left += 64;
        } else {
            all->knight->rect.left = 0;
            all->knight->rect.top = 520;
            all->knight->count = 0;
        }
    }
}

void character_attack(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyF) && all->knight->dir == 1) {
        all->knight->rect.top = 1400;
    }
    change_rect_up(all);
}
