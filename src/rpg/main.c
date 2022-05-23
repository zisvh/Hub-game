/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** defender
*/

#include "../../include/my.h"

int main(int ac, char **av)
{
    all_t *all = malloc(sizeof(all_t));
    my_malloc(all);
    all->utils->video_mode = (sfVideoMode){1920, 1080, 32};
    all->utils->window = sfRenderWindow_create(all->utils->video_mode,
    "My Game", sfDefaultStyle, NULL);

    if (ac != 1 && av[1][0] == '-' && av[1][1] == 'h') {
        myh();
        return (0);
    }
    declare(all);
    my_game(all);
    myfree(all);
}
