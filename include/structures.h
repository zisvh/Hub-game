/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** structures
*/

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

    typedef struct {
        inventory_t *inventory;
        knight_t *knight;
        quest_t *quest;
        sky_t *sky;
        select_t *select;
        map_t *map;
        utils_t *utils;
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

    } all_t;


#endif
