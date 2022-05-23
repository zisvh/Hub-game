/*
** EPITECH PROJECT, 2022
** puzzle_roation.c
** File description:
** puzzle_roation.c
** First edition:
** 01:39:25 21/05/22
*/

#include "../../include/my.h"

piece_t *rotate_left(puzzle_t * puzzle)
{
    piece_t *ptr = puzzle->puzzle;

    while (ptr != NULL) {
        if (ptr->state == 1 && ptr->rect.left != 0)
            ptr->rect.left -= 334;
        else if (ptr->state == 1 && ptr->rect.left == 0)
            ptr->rect.left = 3 * 334;
        ptr = ptr->next;
    }
    return puzzle->puzzle;
}

piece_t *rotate_right(puzzle_t * puzzle)
{
    piece_t *ptr = puzzle->puzzle;

    while (ptr != NULL) {
        if (ptr->state == 1 && ptr->rect.left != 3 * 334)
            ptr->rect.left += 334;
        else if (ptr->state == 1 && ptr->rect.left == 3 * 334)
            ptr->rect.left = 0;
        ptr = ptr->next;
    }
    return puzzle->puzzle;
}

piece_t *rotate_pieces(puzzle_t *puzzle, sfKeyCode key)
{
    if (key == sfKeyQ)
        return rotate_left(puzzle);
    else if (key == sfKeyD)
        return rotate_right(puzzle);
    else
        return puzzle->puzzle;
}