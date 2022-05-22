/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** destroy_linked_lists
*/

#include "../include/my_runner.h"

void destroy_linked_lists(data_t *data)
{
    if (data->background != NULL) {
        destroy_list(data->background);
        data->background_count = 0;
        data->background = NULL;
    } if (data->characters != NULL) {
        destroy_characters(data->characters);
        data->characters_count = 0;
        data->characters = NULL;
    } if (data->text != NULL) {
        destroy_texts(data->text);
        data->text_count = 0;
        data->text = NULL;
    }
}

void destroy_characters(character_t *list_start)
{
    character_t *cursor = list_start;
    character_t *cursor2 = cursor->next;

    free(cursor);
    while (cursor2 != NULL) {
        cursor = cursor2;
        cursor2 = cursor2->next;
        free(cursor);
    }
}

void destroy_texts(text_t *list_start)
{
    text_t *cursor = list_start;
    text_t *cursor2 = cursor->next;

    free(cursor);
    while (cursor2 != NULL) {
        cursor = cursor2;
        cursor2 = cursor2->next;
        free(cursor);
    }
}

void destroy_list(object_t *list_start)
{
    object_t *cursor = list_start;
    object_t *cursor2 = cursor->next;

    free(cursor);
    while (cursor2 != NULL) {
        cursor = cursor2;
        cursor2 = cursor2->next;
        free(cursor);
    }
}
