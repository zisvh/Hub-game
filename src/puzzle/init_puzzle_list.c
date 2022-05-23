/*
** EPITECH PROJECT, 2022
** init_puzzle_array.c
** File description:
** init_puzzle_array.c
** First edition:
** 18:57:10 20/05/22
*/

#include "../../include/my.h"

unsigned char generate_random_val(int min, int max)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    srand(tv.tv_sec + tv.tv_usec * 1000000ul);
    return (rand() % max + min);
}

piece_t *create_piece(piece_t *piece, int i)
{
    piece_t *new = malloc(sizeof(piece_t));
    new->state = generate_random_val(1, 4);
    new->next = piece;
    new->pos.x = (float )(i % 3) * 334 + 410;
    new->pos.y = (float)(int)(i / 3) * 334 + 10;
    new->rect.top = i * 334;
    new->rect.left = (new->state - 1) * 334;
    new->rect.width = 334;
    new->rect.height = 334;
    new->texture = sfTexture_createFromFile("spr/puzzle_sprite/meme_puzzle.png", sfFalse);
    new->scale.y = 1;
    new->scale.x = 1;
    new->piece = set_sprite(new->scale, new->pos, new->texture);
    sfSprite_setTextureRect(new->piece, new->rect);
    return new;
}

void init_puzzle_list(puzzle_t *puzzle) {
    puzzle->puzzle = NULL;
    for (int i = 0; i < 9; i++)
        puzzle->puzzle = create_piece(puzzle->puzzle, i);
}
