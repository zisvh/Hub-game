/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-keziah.picq
** File description:
** my_game
*/

#include "../include/my.h"

void switch_scene(all_t *all)
{
    resizew(all);
    sfRenderWindow_display(all->utils->window);
    switch (all->i) {
        case 0: make_intro(all);
            break;
        case 1: make_menu(all);
            break;
        case 2: make_settings(all);
            break;
        case 3: make_pause(all);
            break;
        case 4: make_select(all);
            break;
        case 5: make_game(all);
        default:
            break;
    }
}

void my_game(all_t *all)
{
    sfMusic_play(all->intro->music);
    sfMusic_setLoop(all->intro->music, sfTrue);
    while (sfRenderWindow_isOpen(all->utils->window)) {
        switch_scene(all);
        while (sfRenderWindow_pollEvent(all->utils->window,
        &all->utils->event)) {
            change_character(all);
            if (all->utils->event.type == sfEvtMouseButtonPressed)
                check_settings_event(all);
            if (all->utils->event.type == sfEvtClosed)
                sfRenderWindow_close(all->utils->window);
        }
    }
}
