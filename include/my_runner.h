/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_runner
*/

#ifndef MY_RUNNER_H_
    #define MY_RUNNER_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/System.h>
    #include <SFML/OpenGL.h>

typedef struct object {
    unsigned int id;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock;
    sfVector2f pos;
    sfVector2f actual_movement;
    sfVector2f expected_movement;
    void *next;
} object_t;

typedef struct character {
    unsigned int id;
    sfSprite *sprite;
    sfTexture *idle;
    int max_idle;
    sfTexture *run;
    int max_run;
    sfTexture *jump;
    int max_jump;
    int current_max;
    float anim_speed;
    sfIntRect rect;
    sfClock *clock;
    sfVector2f pos;
    sfVector2f actual_movement;
    sfVector2f expected_movement;
    void *next;
} character_t;

typedef struct text {
    sfText *text;
    void *next;
} text_t;

typedef struct ennemies {
    sfSprite *sprite;
    sfVector2f pos;
    sfClock *clock;
    sfIntRect rect;
    float anim_speed;
    int anim_max;
    void *next;
} ennemies_t;

typedef struct ennemy_types {
    sfTexture *type_1;
    sfTexture *type_2;
} ennemy_types_t;

typedef struct ennemy_pos {
    float x;
    float y;
    unsigned int type;
    void *next;
} ennemy_pos_t;

typedef struct data {
    int god;
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    unsigned int ui;
    object_t *background;
    unsigned int background_count;
    character_t *characters;
    unsigned int characters_count;
    sfFont *font;
    text_t *text;
    unsigned int text_count;
    ennemy_pos_t *ennemy_pos;
    ennemies_t *ennemies;
    unsigned int ennemy_count;
    ennemy_types_t *ennemy_types;
    sfSprite *select;
    int selected;
    int jumping;
    int half_jump;
    float jump;
    sfClock *global_clock;
    sfTime time;
    unsigned int distance;
    float seconds;
    int r_limits;
    int l_limits;
    int pressed;
    int won;
    unsigned char lives;
    unsigned int score;
} data_t;

// main.c
int game_start(int god, char *filepath, sfRenderWindow *window);

// loose.c
void lost(data_t *data);
void loose(data_t *data);

// end_cinematic.c
int end_cinematic_end(data_t *data);
void start_end(data_t *data);
void end_cinematic_start(data_t *data);
void end_cinematic(data_t *data);

// hitboxes.c
void animate_ennemies(data_t *data);
void render_ennemies(data_t *data);
void move_ennemies(data_t *data);
void check_hitboxes(data_t *data);
void check_ennemies(data_t *data);

// ennemies.c
void make_ennemy_types(data_t *data);
sfTexture *choose_ennemy_texture(unsigned int type, data_t *data);
void type_specific(data_t *data, ennemy_pos_t *pos, ennemies_t *new);
void create_ennemy(data_t *data, ennemy_pos_t *pos);
void make_ennemies(data_t *data);

// map_utils.c
unsigned int line_size(char *buffer);
unsigned int nb_lines(char *buffer);
void make_line(char *map_line, unsigned int i, char *buffer);

// read_map.c
char **map_to_double_array(char *buffer);
void delete_map(char **map);
void set_ennemy(unsigned int x, unsigned int y, char type, data_t *data);
void create_ennemies(data_t *data, char **map, unsigned int y_max);
void create_map(data_t *data, char *filepath);

// menu.c
void render_text(data_t *data);
void render_menu(data_t *data);
void analyse_events_menu(sfRenderWindow *window, sfEvent event, data_t *data);
void menu_key_press(data_t *data, sfEvent event);
void menu_select(data_t *data);

// menu_utils.c
void menu_up(data_t *data);
void menu_down(data_t *data);
void set_play(data_t *data);
void set_commands(data_t *data);

// menu_utils2.c
void set_menu_quit(data_t *data);
void set_menu_comm(data_t *data);
void set_menu_play(data_t *data);

// cinematic.c
int cinematic_end(data_t *data);
void start_play(data_t *data);

// background_utils.c
void set_moving_background_2(data_t *data);
void stop_moving_background(data_t *data);
void set_moving_background(data_t *data);
void set_speed_and_pos(data_t *data, unsigned int id, float speed);

// rendering.c
void animate_characters(data_t *data);
void render_characters(data_t *data);
void render_background(data_t *data);

// movement.c
void move_characters(data_t *data);
void move_background(data_t *data);
void jump_characters(data_t *data);

// loops.c
void menu(data_t *data);
void game(data_t *data);
void cinematic(data_t *data);
void loop(data_t *data);

// user_entry.c
void move_right(data_t *data);
void stop_all(data_t *data);
void analyse_events(sfRenderWindow *window, sfEvent event, data_t *data);
void manage_key_press(data_t *data, sfEvent event);
void manage_key_release(data_t *data, sfEvent event);

// destroy_linked_lists.c
void destroy_linked_lists(data_t *data);
void destroy_characters(character_t *list_start);
void destroy_texts(text_t *list_start);
void destroy_list(object_t *list_start);

// create_linked_lists.c
void create_text(data_t *data, char *text, sfVector2f pos);
void create_character(data_t *data, char *filepath, sfIntRect rectsize);
void add_background(data_t *data, char *filepath, sfIntRect rectsize);
void create_background(data_t *data, char *filepath, sfIntRect rectsize);
void move_to_last_b(unsigned int id, data_t *data);

// character_utils.c
void set_scale(data_t *data, unsigned int id, sfVector2f scale);
void set_move(data_t *data, unsigned int id, sfVector2f movement);
void set_start_pos(data_t *data, unsigned int id, float x, float y);
void set_idle(data_t *data, unsigned int id);

// character_utils3.c
void set_run(data_t *data, unsigned int id);
void set_jump(data_t *data, unsigned int id);
void set_run_max(data_t *data, unsigned int id, int max_run);
void set_jump_max(data_t *data, unsigned int id, int max_jump);
int is_mc_run(data_t *data);

// character_utils2.c
void check_mc_pos(data_t *data);
void set_relative_pos_id
    (data_t *data, unsigned int id, sfVector2f relative_pos);
void set_scale_id(data_t *data, unsigned int id, sfVector2f scale);
void set_anim_var
    (data_t *data, unsigned int id, int max_idle, float anim_speed);
int is_facing_left(data_t *data);

// initialization.c
void init_background(data_t *data);
void init_characters(data_t *data, int main_character);
data_t *data_init(void);
void init_menu(data_t *data);

// my_strcat2.c
char *my_strcat2(char *s1, char *s2);

#endif /* !MY_RUNNER_H_ */
