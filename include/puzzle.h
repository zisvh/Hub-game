/*
** EPITECH PROJECT, 2022
** puzzle.h
** File description:
** puzzle.h
** First edition:
** 19:14:48 20/05/22
*/



#ifndef TEK_PARTY_PUZZLE_H
#define TEK_PARTY_PUZZLE_H

    #include <SFML/Network.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Text.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Types.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/OpenGL.h>
    #include <sys/time.h>

    typedef struct piece_s {
        struct piece_s *next;
        sfIntRect rect;
        sfSprite *piece;
        sfVector2f pos;
        sfVector2f scale;
        sfTexture *texture;
        int state;
    } piece_t;

    typedef struct puzzle_s {
        piece_t *puzzle;
        int time;
        sfClock *time_left;
    } puzzle_t;

    void display_puzzle(puzzle_t *puzzle, all_t *all);
    void init_puzzle_list(puzzle_t *puzzle);
    piece_t *rotate_pieces(puzzle_t *puzzle, sfKeyCode key);
    void puzzle(all_t *all);
    int check_puzzle_win(piece_t *piece);




#endif //TEK_PARTY_PUZZLE_H
