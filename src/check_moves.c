/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-keziah.picq
** File description:
** check_moves
*/

#include "../include/my.h"

int check_up(all_t *all)
{
    int x = all->knight->x / 64 - 1;
    int y = (all->knight->y - 2) / 64 + 1;

    if (all->map->map[y][x] != '2')
        return 1;
    else {
        all->knight->y -= 2;
        return 2;
    }
}

int check_down(all_t *all)
{
    int x = all->knight->x / 64 - 1;
    int y = (all->knight->y + 2) / 64 + 1;

    if (all->map->map[y][x] != '2')
        return 1;
    else {
        all->knight->y += 2;
        return 2;
    }
}

int check_left(all_t *all)
{
    int x = (all->knight->x - 2) / 64 - 1;
    int y = all->knight->y / 64 + 1;

    if (all->map->map[y][x] != '2')
        return 1;
    else {
        all->knight->x -= 2;
        return 2;
    }
}

int check_right(all_t *all)
{
    int x = (all->knight->x + 2) / 64 - 1;
    int y = all->knight->y / 64 + 1;

    if (all->map->map[y][x] != '2')
        return 1;
    else {
        all->knight->x += 2;
        return 2;
    }
}
