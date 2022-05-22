/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** main
*/

#include "../include/my_runner.h"

int game_start(int god, char *filepath, sfRenderWindow *window)
{
    data_t *data = data_init();

    data->god = 1;
    data->window = window;
    // sfRenderWindow_setMouseCursorVisible(data->window, sfFalse);
    // sfRenderWindow_setFramerateLimit(data->window, 60);
    if (!data->window)
        return (84);
    init_background(data);
    init_characters(data, god);
    create_map(data, filepath);
    make_ennemy_types(data);
    make_ennemies(data);
    stop_all(data);
    init_menu(data);
    loop(data);
    destroy_linked_lists(data);
    free(data);
    return (0);
}

//int main(int ac, char **av)
//{
//    int god = 0;
//    if (ac == 3)
//        god = 1;
//    if (ac >= 2)
//        return (game_start(god, av[1]));
//    return (0);
//}
