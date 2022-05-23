/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
** First edition:
** 18:39:23 20/05/22
*/

#include "../../include/my.h"

void puzzle(all_t *all)
{
    puzzle_t *puzzle = malloc(sizeof (puzzle_t));
    init_puzzle_list(puzzle);
    while (all->i == 6)
        display_puzzle(puzzle, all);
}