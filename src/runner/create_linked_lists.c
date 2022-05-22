/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** create_linked_lists
*/

#include "../include/my_runner.h"

void create_text(data_t *data, char *text, sfVector2f pos)
{
    text_t *new = malloc(sizeof(text_t));

    new->text = sfText_create();
    sfText_setFont(new->text, data->font);
    sfText_setString(new->text, text);
    sfText_setPosition(new->text, pos);
    sfText_setStyle(new->text, sfTextBold);
    sfText_setOutlineThickness(new->text, 5.0);
    sfText_setOutlineColor(new->text, sfBlack);
    sfText_setCharacterSize(new->text, 50);
    new->next = data->text;
    data->text = new;
}

void create_character(data_t *data, char *filepath, sfIntRect rectsize)
{
    character_t *new_character = malloc(sizeof(character_t));

    new_character->id = data->characters_count + 1;
    new_character->sprite = sfSprite_create();
    new_character->idle = sfTexture_createFromFile(filepath,  &(sfIntRect){0, 456, 510, 64});
    new_character->run = sfTexture_createFromFile(filepath, &(sfIntRect){0, 712, 571, 64});
    new_character->jump = sfTexture_createFromFile(filepath, &(sfIntRect){0, 200, 447, 64});
    new_character->rect = rectsize;
    new_character->clock = sfClock_create();
    new_character->expected_movement = (sfVector2f){0.0, 0.0};
    sfSprite_setTexture(new_character->sprite, new_character->idle, sfTrue);
    data->characters_count++;
    new_character->next = data->characters;
    data->characters = new_character;
}

void add_background(data_t *data, char *filepath, sfIntRect rectsize)
{
    object_t *new_background = malloc(sizeof(object_t));

    new_background->id = data->background_count + 1;
    new_background->texture = sfTexture_createFromFile(filepath, NULL);
    new_background->sprite = sfSprite_create();
    sfSprite_setTexture(new_background->sprite, new_background->texture,
        sfTrue);
    new_background->rect = rectsize;
    new_background->clock = sfClock_create();
    new_background->pos = (sfVector2f){0.0, 0.0};
    new_background->expected_movement = (sfVector2f){0.0, 0.0};
    new_background->next = data->background;
    data->background = new_background;
    data->background_count++;
}

void create_background(data_t *data, char *filepath, sfIntRect rectsize)
{
    object_t *new_background;

    if (data->background_count == 0) {
        new_background = malloc(sizeof(object_t));
        new_background->id = 1;
        new_background->texture = sfTexture_createFromFile(filepath, NULL);
        new_background->sprite = sfSprite_create();
        sfSprite_setTexture(new_background->sprite, new_background->texture,
            sfTrue);
        new_background->rect = rectsize;
        new_background->clock = sfClock_create();
        new_background->pos = (sfVector2f){0.0, 0.0};
        new_background->expected_movement = (sfVector2f){0.0, 0.0};
        new_background->next = data->background;
        data->background = new_background;
        data->background_count++;
    } else {
        add_background(data, filepath, rectsize);
        move_to_last_b(data->background_count, data);
        add_background(data, filepath, rectsize);
        move_to_last_b(data->background_count, data);
    }
}

void move_to_last_b(unsigned int id, data_t *data)
{
    object_t *cursor = data->background;
    object_t *to_move = data->background;

    data->background = cursor->next;
    if (to_move->id != id)
        to_move = to_move->next;
    while (to_move->id != id && to_move->next != NULL) {
        cursor = to_move;
        to_move = to_move->next;
    }
    if (to_move->next == NULL)
        return;
    cursor->next = to_move->next;
    while (cursor->next != NULL)
        cursor = cursor->next;
    cursor->next = to_move;
    to_move->next = NULL;
}
