/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** fonctions
*/

#ifndef FONCTIONS_H_
    #define FONCTIONS_H_

    void handle_menu(all_t *all);
    void myh();
    void resizew(all_t *all);
    void my_malloc(all_t *all);
    void myfree(all_t *all);
    void declare(all_t *all);
    void declare_intro(all_t *all);
    void declare_settings(all_t *all);
    void declare_settings2(all_t *all);
    void declare_pause(all_t *all);
    void declare_pause(all_t *all);
    void set_my_textures(all_t *all);
    sfSprite *set_sprite(sfVector2f scale, sfVector2f pos, sfTexture *texture);
    void my_game(all_t *all);
    void make_intro(all_t *all);
    int skip_intro(all_t *all, int i);
    int check_menu(all_t *all);
    void make_menu(all_t *all);
    void launch_settings(all_t *all);
    void declare_quest(all_t *all);
    void display_quest(all_t *all);
    void make_quest(all_t *all);
    void change_fps(all_t *all);
    void check_settings_event(all_t *all);
    void change_volume(all_t *all);
    int return_menu(all_t *all, int i);
    void animate_sprite(all_t *all, int i);
    void buttons(int returnn, all_t *all);
    void make_inventory(all_t *all);
    void pausegame(all_t *all);
    void resume(all_t *all);
    void make_pause(all_t *all);
    int check_pause(all_t *all);
    void change_character(all_t *all);
    void game_movement2(all_t *all);
    void game_movement3(all_t *all);
    char **init_map(char *map);
    char *map_read(char *filename);
    void make_select(all_t *all);
    void declare2(all_t *all);
    void declare_select(all_t *all);
    void declare_select2(all_t *all);
    void character_attack(all_t *all);
    void declare_inventory(all_t *all);
    int check_left(all_t *all);
    int check_right(all_t *all);
    int check_down(all_t *all);
    int check_up(all_t *all);
    void mylist(all_t *all);
    char *my_strcat(char const *src1, char const *src2);
    char *getnbrr(int nbr);
    void make_defeat(all_t *all, int i);
    int return_menulo(all_t *all, int i);
    void display_select(all_t *all);
    int drawlose(all_t *all, int i);
    void destroy_node(all_t *all, int id);
    void close_window(all_t *all);
    void do_first(all_t *all, int i, int x);
    void handle_all(all_t *all, int i);
    void make_settings(all_t *all);
    void make_game(all_t *all);
    void switch_scene(all_t *all);
    void declare_mobs(all_t *all);
    void declare_knight1(all_t *all);
    void declare_knight2(all_t *all);
    list_t *init_mob(all_t *all);
    list_t *display_mob(list_t *list, all_t *all);
    void game_cut(all_t *data);
    void display_cut_game(all_t *data);

#endif