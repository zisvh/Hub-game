/*
** EPITECH PROJECT, 2022
** check_win_puzzle.c
** File description:
** check_win_puzzle.c
** First edition:
** 13:30:49 23/05/22
*/

#include "../../include/my.h"

int check_puzzle_win(piece_t *piece)
{
    piece_t *ptr = piece;

    while (ptr != NULL) {
        if (ptr->rect.left != 0)
            return 1;
        ptr = ptr->next;
    }
    return 0;
}