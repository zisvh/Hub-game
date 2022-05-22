/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** structures
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>
#include <dirent.h>
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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>
#include <dirent.h>

#ifndef STRUCTURES_H_
    #define STRUCTURES_H_

    typedef struct utils {
        sfRenderWindow *window;
        sfVideoMode video_mode;
        sfEvent event;
        sfMusic *music;
    } utils_t;

    typedef struct intro {
        sfTexture *my_tbg;
        sfTexture *my_ttitle;
        sfSprite *my_bg;
        sfSprite *my_title;
        sfVector2f scale;
        sfVector2f settitlepos;
        sfVector2f titlemove;
        sfVector2f titlepos;
        sfMusic *music;
    } intro_t;

    typedef struct lb {
        sfTexture *tbg;
        sfSprite *bg;
        sfText *score;
    } lb_t;

    typedef struct settings {
        sfTexture *my_tsettings;
        sfTexture *my_tfps;
        sfTexture *my_tsound;
        sfSprite *my_settings;
        sfSprite *my_fps;
        sfSprite *my_sound;
        sfIntRect frect;
        sfIntRect srect;
        sfVector2f fpos;
        sfVector2f spos;
        sfVector2f fscale;
        sfVector2f sscale;
    } settings_t;

    typedef struct menu {
        sfTexture *my_tmenu;
        sfTexture *my_tplay;
        sfTexture *my_tplayb;
        sfTexture *my_tctrl;
        sfTexture *my_tctrlb;
        sfTexture *my_texit;
        sfTexture *my_texitb;
        sfTexture *thow1;
        sfTexture *thow2;
        sfSprite *how1;
        sfSprite *how2;
        sfSprite *my_menu;
        sfSprite *my_play;
        sfSprite *my_playb;
        sfSprite *my_ctrl;
        sfSprite *my_ctrlb;
        sfSprite *my_exit;
        sfSprite *my_exitb;
        sfVector2f playpos;
        sfVector2f ctrlpos;
        sfVector2f exitpos;
        sfVector2f scale;
    } menu_t;

    typedef struct knight {
        int x;
        int y;
        int dir;
        int count;
        sfVector2f scale;
        sfVector2f pos;
        sfSprite *sprite;
        sfSprite *sprite2;
        sfSprite *sprite3;
        sfTexture *texture;
        sfTexture *texture2;
        sfTexture *texture3;
        sfIntRect rect;
    } knight_t;

    typedef struct map {
        sfIntRect rect;
        sfSprite *sprite;
        sfVector2f pos;
        sfVector2f scale;
        sfTexture *texture;
        char **map;
    } map_t;

    typedef struct sky {
        sfSprite *sprite;
        sfVector2f pos;
        sfVector2f scale;
        sfTexture *texture;
    } sky_t;

    typedef struct select {
        sfSprite *lucian;
        sfTexture *tlucian;
        sfVector2f posl;
        sfVector2f scalel;
        sfSprite *zombie;
        sfTexture *tzombie;
        sfVector2f posz;
        sfVector2f scalez;
        sfSprite *knight;
        sfTexture *tknight;
        sfVector2f posk;
        sfVector2f scalek;
        sfSprite *sprite;
        sfVector2f pos;
        sfVector2f scale;
        sfTexture *texture;
        int car;
    } select_t;

    typedef struct quest {
        sfSprite *quest;
        sfTexture *tquest;
        sfVector2f posq;
        sfVector2f scaleq;
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f pos;
        sfVector2f scale;
        sfIntRect rect;
        int count;
        int sword;
    } quest_t;

    typedef struct inventory {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f pos;
        sfVector2f scale;
        sfSprite *sprite2;
        sfTexture *texture2;
        sfVector2f pos2;
        sfVector2f scale2;
        int yes;
    } inventory_t;

    typedef struct game {
        int x;
        int y;
        sfSprite *sky;
        sfSprite *my_bg;
        sfSprite *my_life;
        sfSprite *my_shop;
        sfTime time;
        float seconds;
        sfClock *clock;
    } game_t;

    typedef struct pause {
        sfTexture *my_tpause;
        sfTexture *my_tresume;
        sfTexture *my_tmenu;
        sfTexture *my_tquit;
        sfSprite *my_pause;
        sfSprite *my_resume;
        sfSprite *my_menu;
        sfSprite *my_quit;
        sfVector2f scale;
        sfVector2f pos;
        sfFloatRect n;
    } pause_t;

    typedef struct t {
        int i;
        int type;
        sfTexture *text;
        sfSprite *my_t;
        sfIntRect rect;
        sfVector2f pos;
    } t_t;

    typedef struct mobs {
        sfSprite *mobs_sprite1;
        sfTexture *mobs_texture1;
        sfVector2f mobs_pos1;
        sfVector2f mobs_scale1;
        sfSprite *mobs_sprite2;
        sfTexture *mobs_texture2;
        sfVector2f mobs_pos2;
        sfVector2f mobs_scale2;
        sfSprite *mobs_sprite3;
        sfTexture *mobs_texture3;
        sfVector2f mobs_pos3;
        sfVector2f mobs_scale3;
    } mobs_t;

    typedef struct list_s {
        struct list_s *next;
        int x;
        int y;
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f pos;
        sfVector2f scale;
        sfIntRect rect;
    } list_t;

        typedef struct hunter {
        sfVideoMode mode;
        sfRenderWindow *window;
        unsigned char ui;
        sfEvent event;
        sfSprite *spritesplayer;
        sfTexture *textureplayer;
        sfSprite *sp_sky;
        sfSprite *sp_sky2;
        sfSprite *sp_sky3;
        sfSprite *sp_ground;
        sfSprite *sp_ground2;
        sfSprite *sp_ground3;
        sfSprite *sp_midlle;
        sfSprite *sp_midlle2;
        sfSprite *sp_midlle3;
        sfSprite *sp_second_ground;
        sfSprite *sp_second_ground2;
        sfSprite *sp_second_ground3;
        sfSprite *sp_foreground;
        sfSprite *sp_foreground2;
        sfSprite *sp_foreground3;
        sfSprite *sp_bg;
        sfSprite *sp_bg2;
        sfSprite *sp_bg3;
        sfTexture *tex_sky;
        sfTexture *tex_foreground;
        sfTexture *tex_midlle;
        sfTexture *tex_bg;
        sfTexture *tex_ground;
        sfTexture *tex_second_grnd;
        sfSprite *player;
        sfTexture *texture_player;
        sfIntRect rect;
        sfTime time;
        sfSprite *sprite_life;
        sfSprite *sprite;
        sfSprite *sprite2;
        sfVector2f vector_sprite;
        sfClock *clock;
        sfTexture *texture_duck;
        int count2;
        sfTexture *texture_life;
        float seconds;
        sfVideoMode video_mode;
        sfSoundBuffer *soundbufferbird;
        sfSound *soundbird;
        sfSoundBuffer *soundbufferfinal;
        sfSound *soundfinal;
        sfTexture *background;
        sfIntRect rect_life;
        sfVector2f vect_sprite;
        int score;
        sfVector2f varspeed;
        sfTexture *game_over;
        sfSprite *sprite4;
        sfFont *font;
        sfText *text;
        sfClock *clockcombo;
        sfText *textmeme;
        sfTime timecombo;
        float secondcombo;

        sfSprite *sp_combo;
        sfTexture *tex_combo1;
        sfTexture *tex_combo2;
        sfTexture *tex_combo3;
        sfTexture *tex_combo4;
        sfTexture *tex_combo5;
    } hunter_t;


typedef struct cut_struct_s {
    int status_b;
    int status_p;
    int status_r;
    int status_y;
    int life_b;
    int life_p;
    int life_r;
    int life_y;
    sfSprite *background;
    sfTexture *background_texture;
    sfSprite *cable_b;
    sfTexture *cable_b_texture;
    sfSprite *cable_p;
    sfTexture *cable_p_texture;
    sfSprite *cable_r;
    sfTexture *cable_r_texture;
    sfSprite *cable_y;
    sfTexture *cable_y_texture;
    sfSprite *cut_b;
    sfTexture *cut_b_texture;
    sfSprite *cut_p;
    sfTexture *cut_p_texture;
    sfSprite *cut_r;
    sfTexture *cut_r_texture;
    sfSprite *cut_y;
    sfTexture *cut_y_texture;
    sfVector2f pos;
    sfEvent event;
}cut_struct_t;

typedef struct {
        inventory_t *inventory;
        knight_t *knight;
        cut_struct_t *cut;
        quest_t *quest;
        sky_t *sky;
        select_t *select;
        map_t *map;
        utils_t *utils;
        hunter_t *hunter;
        intro_t *intro;
        menu_t *menu;
        settings_t *settings;
        lb_t *lb;
        game_t *game;
        pause_t *pause;
        t_t *t;
        mobs_t *mobs;
        int count;
        int i;
        list_t *list;
    sfRenderWindow *window;
} all_t;

void base_hunter(all_t *all);


#endif
