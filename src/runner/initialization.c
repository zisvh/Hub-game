/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** initialization
*/

#include "../include/my_runner.h"

void init_background(data_t *data)
{
    create_background(data, "images/background/sky.png",
    (sfIntRect){0, 0, 1920, 1080});
    create_background(data, "images/background/houses3.png",
    (sfIntRect){0, 0, 1920, 1080});
    create_background(data, "images/background/houded2.png",
    (sfIntRect){0, 0, 1920, 1080});
    create_background(data, "images/background/houses1.png",
    (sfIntRect){0, 0, 1920, 1080});
    create_background(data, "images/background/road.png",
    (sfIntRect){0, 0, 1920, 1080});
    set_speed_and_pos(data, 2, -5.0);
    set_speed_and_pos(data, 4, -6.0);
    set_speed_and_pos(data, 6, -7.0);
    set_speed_and_pos(data, 8, -8.0);
}

void init_characters(data_t *data, int main_character)
{
    create_character(data, (main_character ? "images/characters/AdrienReadme.png" : "images/characters/TheVikend.png"),
    (sfIntRect){0, 0, 64, 64});
    create_character(data, "images/characters/Cat", (sfIntRect){0, 0, 48, 48});
    set_anim_var(data, 1, 192, 0.2);
    set_anim_var(data, 2, 192, 0.3);
    set_run_max(data, 1, 288);
    set_jump_max(data, 1, 192);
    set_start_pos(data, 1, 300.0, 750.0);
    set_start_pos(data, 2, 1920.0, 800.0);
    set_move(data, 2, (sfVector2f){-4.0, 0.0});
    set_scale(data, 2, (sfVector2f){-3.0, 3.0});
}

data_t *data_init(void)
{
    data_t *data = malloc(sizeof(data_t));

    data->mode.width = 1920;
    data->mode.height = 1080;
    data->mode.bitsPerPixel = 32;
    data->ui = 0;
    data->background = NULL;
    data->background_count = 0;
    data->characters = NULL;
    data->characters_count = 0;
    data->font = sfFont_createFromFile("fonts/Outfit-Regular.ttf");
    data->text = NULL;
    data->text_count = 0;
    data->seconds = 0.0;
    data->r_limits = 0;
    data->lives = 0;
    data->score = 0;
    return (data);
}

void init_menu(data_t *data)
{
    sfTexture *select_texture;
    sfIntRect rect = {0, 0, 80, 320};
    create_text(data, "Play", (sfVector2f){10.0, 300.0});
    create_text(data, "Help", (sfVector2f){10.0, 500.0});
    create_text(data, "QUIT", (sfVector2f){10.0, 700.0});
    data->select = sfSprite_create();
    select_texture = sfTexture_createFromFile("images/gradient.png", NULL);
    sfSprite_setTexture(data->select, select_texture, sfTrue);
    sfSprite_setTextureRect(data->select, rect);
    sfSprite_rotate(data->select, 90.0);
    data->selected = 1;
    sfSprite_setPosition(data->select, (sfVector2f){300, 295});
}
