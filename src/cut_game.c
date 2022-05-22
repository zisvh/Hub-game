/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** base.c
*/

#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RenderWindow.h>
#include "structures.h"

void init_cut(all_t *data)
{
    data->cut = malloc(sizeof(cut_struct_t));

    data->cut->status_b = 0;
    data->cut->status_p = 0;
    data->cut->status_r = 0;
    data->cut->status_y = 0;
    data->cut->life_b = 100;
    data->cut->life_p = 100;
    data->cut->life_r = 100;
    data->cut->life_y = 100;
    data->cut->background = sfSprite_create();
    data->cut->cable_b = sfSprite_create();
    data->cut->cable_r = sfSprite_create();
    data->cut->cable_y = sfSprite_create();
    data->cut->cable_p = sfSprite_create();
    data->cut->cut_b = sfSprite_create();
    data->cut->cut_r = sfSprite_create();
    data->cut->cut_y = sfSprite_create();
    data->cut->cut_p = sfSprite_create();
    data->cut->background_texture = sfTexture_createFromFile("spr/cut_game/back.png", NULL);
    data->cut->cable_b_texture = sfTexture_createFromFile("spr/cut_game/cables_b.png", NULL);
    data->cut->cable_r_texture = sfTexture_createFromFile("spr/cut_game/cables_r.png", NULL);
    data->cut->cable_y_texture = sfTexture_createFromFile("spr/cut_game/cables_y.png", NULL);
    data->cut->cable_p_texture = sfTexture_createFromFile("spr/cut_game/cables_p.png", NULL);
    data->cut->cut_b_texture = sfTexture_createFromFile("spr/cut_game/cables_cut_b.png", NULL);
    data->cut->cut_r_texture = sfTexture_createFromFile("spr/cut_game/cables_cut_r.png", NULL);
    data->cut->cut_y_texture = sfTexture_createFromFile("spr/cut_game/cables_cut_y.png", NULL);
    data->cut->cut_p_texture = sfTexture_createFromFile("spr/cut_game/cables_cut_p.png", NULL);
    sfSprite_setTexture(data->cut->background, data->cut->background_texture, sfTrue);
    sfSprite_setTexture(data->cut->cable_b, data->cut->cable_b_texture, sfTrue);
    sfSprite_setTexture(data->cut->cable_r, data->cut->cable_r_texture, sfTrue);
    sfSprite_setTexture(data->cut->cable_y, data->cut->cable_y_texture, sfTrue);
    sfSprite_setTexture(data->cut->cable_p, data->cut->cable_p_texture, sfTrue);
    sfSprite_setTexture(data->cut->cut_b, data->cut->cut_b_texture, sfTrue);
    sfSprite_setTexture(data->cut->cut_r, data->cut->cut_r_texture, sfTrue);
    sfSprite_setTexture(data->cut->cut_y, data->cut->cut_y_texture, sfTrue);
    sfSprite_setTexture(data->cut->cut_p, data->cut->cut_p_texture, sfTrue);
}

void display_cut_game(all_t *data)
{
    sfRenderWindow_clear(data->window, sfGreen);
    sfRenderWindow_drawSprite(data->window, data->cut->background, NULL);
    if (data->cut->status_b == 1)
        sfRenderWindow_drawSprite(data->window, data->cut->cut_b, NULL);
    else
        sfRenderWindow_drawSprite(data->window, data->cut->cable_b, NULL);
    if (data->cut->status_p == 1)
        sfRenderWindow_drawSprite(data->window, data->cut->cut_p, NULL);
    else
        sfRenderWindow_drawSprite(data->window, data->cut->cable_p, NULL);
    if (data->cut->status_r == 1)
        sfRenderWindow_drawSprite(data->window, data->cut->cut_r, NULL);
    else
        sfRenderWindow_drawSprite(data->window, data->cut->cable_r, NULL);
    if (data->cut->status_y == 1)
        sfRenderWindow_drawSprite(data->window, data->cut->cut_y, NULL);
    else
        sfRenderWindow_drawSprite(data->window, data->cut->cable_y, NULL);
    sfRenderWindow_display(data->window);
}

void event_mouse_cut(all_t *data, cut_struct_t *cut)
{
    int hit_y = data->utils->event.mouseButton.y;

    if (hit_y >= 193 && hit_y <= 193 + 45) {
        if (data->utils->event.type == sfEvtMouseButtonPressed)
            cut->status_y = 1;
    }
    if (hit_y >= 419 && hit_y <= 419 + 45) {
        if (data->utils->event.type == sfEvtMouseButtonPressed)
            cut->status_b = 1;
    }
    if (hit_y >= 642 && hit_y <= 642 + 45) {
        if (data->utils->event.type == sfEvtMouseButtonPressed)
            cut->status_r = 1;
    }
    if (hit_y >= 867 && hit_y <= 867 + 45) {
        if (data->utils->event.type == sfEvtMouseButtonPressed)
            cut->status_p = 1;
    }
}

void game_cut(all_t *data)
{
    init_cut(data);
    while (sfRenderWindow_isOpen(data->utils->window)) {
        sfRenderWindow_display(data->utils->window);
        while (sfRenderWindow_pollEvent(data->utils->window, &data->cut->event)) {

            write(1 , "cut\n", 4);
        }
        display_cut_game(data);
    }
}