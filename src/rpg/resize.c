/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** resize
*/

#include "my.h"

void resizew(all_t *all)
{
    sfVector2u size = sfRenderWindow_getSize(all->utils->window);
    sfVector2u minsize = {800, 600};
    sfVector2u maxsize = {1920, 1080};

    if (size.x < 800 || size.y < 600)
        sfRenderWindow_setSize(all->utils->window, minsize);
    if (size.x > 1920 || size.y > 1080)
        sfRenderWindow_setSize(all->utils->window, maxsize);
}
