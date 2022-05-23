/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** memory
*/

#include "my.h"

void myfree(all_t *all)
{
    free(all->inventory);
    free(all->quest);
    free(all->select);
    free(all->map);
    free(all->knight);
    free(all->sky);
    free(all->utils);
    free(all->intro);
    free(all->menu);
    free(all->settings);
    free(all->lb);
    free(all->game);
    free(all->pause);
    free(all->t);
    free(all);
}

void my_malloc(all_t *all)
{
    all->inventory = malloc(sizeof (inventory_t));
    all->quest = malloc(sizeof (quest_t));
    all->select = malloc(sizeof (select_t));
    all->sky = malloc(sizeof (sky_t));
    all->map = malloc(sizeof (map_t));
    all->knight = malloc(sizeof (knight_t));
    all->utils = malloc(sizeof(utils_t));
    all->intro = malloc(sizeof(intro_t));
    all->menu = malloc(sizeof(menu_t));
    all->settings = malloc(sizeof(settings_t));
    all->lb = malloc(sizeof(lb_t));
    all->game = malloc(sizeof(game_t));
    all->pause = malloc(sizeof(pause_t));
    all->t = malloc(7 * sizeof(t_t));
}
