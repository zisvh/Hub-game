/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-keziah.picq
** File description:
** rpg_quest
*/

#include "../include/my.h"

void portal1(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) && all->knight->x >= 320
    && all->knight->x <= 358 && all->knight->y >= 5312
    && all->knight->y <= 5330 && all->knight->dir == 1) {
        base_hunter(all);
    }
}

void portal2(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) && all->knight->x >= 384
    && all->knight->x <= 426 && all->knight->y >= 5312
    && all->knight->y <= 5330 && all->knight->dir == 1) {
        game_cut(all);
    }
}

void portal3(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) && all->knight->x >= 454
    && all->knight->x <= 490 && all->knight->y >= 5312
    && all->knight->y <= 5330 && all->knight->dir == 1) {
        printf("portal 3 opened!");
    }
}

void portal4(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) && all->knight->x >= 520
    && all->knight->x <= 560 && all->knight->y >= 5312
    && all->knight->y <= 5330 && all->knight->dir == 1) {
        printf("portal 4 opened!");
    }
}

void portal5(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) && all->knight->x >= 590
    && all->knight->x <= 626 && all->knight->y >= 5312
    && all->knight->y <= 5330 && all->knight->dir == 1) {
        printf("portal 5 opened!");
    }
}

void portal6(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) && all->knight->x >= 654
    && all->knight->x <= 703 && all->knight->y >= 5312
    && all->knight->y <= 5330 && all->knight->dir == 1) {
        printf("portal 6 opened!");
    }
}

void make_quest(all_t *all)
{
    portal1(all);
    portal2(all);
    portal3(all);
    portal4(all);
    portal5(all);
    portal6(all);
}
