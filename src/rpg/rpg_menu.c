/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-keziah.picq
** File description:
** rpg_menu
*/

#include "../include/my.h"

void check_menu_click(all_t *all)
{
    int i = check_menu(all);

    switch (i) {
        case 1 :
            all->i = 4;
            break;
        case 2 :
            all->i = 2;
            break;
        case 3 :
            sfRenderWindow_drawSprite(all->utils->window,
            all->menu->my_exitb, NULL);
            sfRenderWindow_close(all->utils->window);
            break;
        default :
            break;
    }
}

int check_menu(all_t *all)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)all->utils->window);

    if (mouse.x >= 60 && mouse.x <= 376 && mouse.y >= 792 && mouse.y <= 827)
        return 1;
    if (mouse.x >= 60 && mouse.x <= 304 && mouse.y >= 872 && mouse.y <= 908)
        return 2;
    if (mouse.x >= 60 && mouse.x <= 177 && mouse.y >= 952 && mouse.y <= 984)
        return 3;
    if (mouse.x >= 1778 && mouse.x <= 1902 && mouse.y >= 66 && mouse.y <= 168)
        return 4;
    else
        return 0;
}

void display_menu_buttons(int value, all_t *all)
{
    switch (value) {
        case 1:
            sfRenderWindow_drawSprite(all->utils->window,
            all->menu->my_play, NULL);
            sfRenderWindow_drawSprite(all->utils->window,
            all->menu->how1, NULL);
            break;
        case 2:
            sfRenderWindow_drawSprite(all->utils->window,
            all->menu->my_ctrl, NULL);
            sfRenderWindow_drawSprite(all->utils->window,
            all->menu->how1, NULL);
            break;
        case 3:
            sfRenderWindow_drawSprite(all->utils->window,
            all->menu->my_exit, NULL);
            sfRenderWindow_drawSprite(all->utils->window,
            all->menu->how1, NULL);
            break;
        case 4:
            sfRenderWindow_drawSprite(all->utils->window,
            all->menu->how2, NULL);
            break;
        default:
            sfRenderWindow_drawSprite(all->utils->window,
            all->menu->how1, NULL);
            break;
    }
}

void make_menu(all_t *all)
{
    sfRenderWindow_drawSprite(all->utils->window, all->menu->my_menu, NULL);
    if (all->utils->event.type == sfEvtMouseButtonPressed)
        check_menu_click(all);
    display_menu_buttons(check_menu(all), all);
}
