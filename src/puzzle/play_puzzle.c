/*
** EPITECH PROJECT, 2022
** play_puzzle.c
** File description:
** play_puzzle.c
** First edition:
** 01:40:26 21/05/22
*/

#include "../../include/my.h"

void display_pieces(puzzle_t *puzzle, all_t *all)
{
    piece_t *piece = puzzle->puzzle;

    while (piece != NULL) {
        sfSprite_setTextureRect(piece->piece, piece->rect);
        sfRenderWindow_drawSprite(all->utils->window, piece->piece, NULL);
        piece = piece->next;
    }
}

piece_t *play_puzzle(puzzle_t *puzzle, sfVector2i pos)
{
    piece_t *ptr = puzzle->puzzle;
    int i = pos.y / 334 * 3 + 1 + (pos.x - 410) / 334;
    int count = 1;
    while (ptr != NULL) {
        if (count == 10 - i)
            ptr->state = 1;
        else
            ptr->state = 0;
        ptr = ptr->next;
        count++;
    }
    return puzzle->puzzle;
}

void handle_puzzle_event(all_t *all, puzzle_t *puzzle)
{
    sfVector2i pos = sfMouse_getPosition((const sfWindow *) all->window);
    if ((pos.x >= 410 && pos.x <= 1410) && (pos.y >= 15 && pos.y <= 1015))
        puzzle->puzzle = play_puzzle(puzzle, pos);
}

void display_puzzle(puzzle_t *puzzle, all_t *all)
{
    sfKeyCode key;
    init_puzzle_list(puzzle);
    while (sfRenderWindow_isOpen(all->utils->window)) {
        sfRenderWindow_display(all->utils->window);
        display_pieces(puzzle, all);
        while (sfRenderWindow_pollEvent(all->utils->window, &all->event)) {
            if (all->event.type == sfEvtMouseButtonPressed)
                handle_puzzle_event(all, puzzle);
            if (all->event.type == sfEvtKeyPressed) {
                key = all->event.key.code;
                puzzle->puzzle = rotate_pieces(puzzle, key);
            }
            if (all->event.type == sfEvtClosed)
                sfRenderWindow_close(all->utils->window);
            if (check_puzzle_win(puzzle->puzzle) == 0)
                all->i = 5;
        }
    }
}