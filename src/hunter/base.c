/*
** EPITECH PROJECT, 2021
** Tek-Party
** File description:
** base.c
*/

#include "my.h"

void init_hunter(hunter_t *hunter, all_t *all)
{
    hunter->sp_sky = sfSprite_create();
    hunter->sp_sky2 = sfSprite_create();
    hunter->sp_sky3 = sfSprite_create();
    hunter->sp_ground = sfSprite_create();
    hunter->sp_ground2 = sfSprite_create();
    hunter->sp_ground3 = sfSprite_create();
    hunter->sp_midlle = sfSprite_create();
    hunter->sp_midlle2 = sfSprite_create();
    hunter->sp_midlle3 = sfSprite_create();
    hunter->sp_second_ground = sfSprite_create();
    hunter->sp_second_ground2 = sfSprite_create();
    hunter->sp_second_ground3 = sfSprite_create();
    hunter->sp_foreground = sfSprite_create();
    hunter->sp_foreground2 = sfSprite_create();
    hunter->sp_foreground3 = sfSprite_create();
    hunter->sp_bg = sfSprite_create();
    hunter->sp_bg2 = sfSprite_create();
    hunter->sp_bg3 = sfSprite_create();
    hunter->tex_bg = sfTexture_createFromFile("spr/hunter/BG_Decor.png", NULL);
    hunter->tex_foreground = sfTexture_createFromFile("spr/hunter/Foreground.png", NULL);
    hunter->tex_second_grnd = sfTexture_createFromFile("spr/hunter/Ground_02.png", NULL);
    hunter->tex_midlle = sfTexture_createFromFile("spr/hunter/Middle_Decor.png", NULL);
    hunter->tex_ground = sfTexture_createFromFile("spr/hunter/Ground_01.png", NULL);
    hunter->tex_sky = sfTexture_createFromFile("spr/hunter/cropped-1920-1080-551467.png", NULL);
    hunter->player = sfSprite_create();
    hunter->texture_player = sfTexture_createFromFile("src/jetpack_joytek/PNG/AdrienReadme.png", NULL);
    hunter->rect = (sfIntRect) {0,0,50, 75};
    hunter->clock = sfClock_create();
    sfSprite_move(hunter->player, (sfVector2f) {500, 500});
    sfSprite_setTexture(hunter->player, hunter->texture_player, sfTrue);
    sfSprite_setTextureRect(hunter->player, hunter->rect);
    hunter->sprite2 = sfSprite_create();
    hunter->texture_duck = sfTexture_createFromFile("spr/hunter/canard.png", NULL);
    hunter->clock = sfClock_create();
    hunter->sprite = sfSprite_create();
    hunter->rect = (sfIntRect) {0, 0, 110, 110};
    hunter->score = 0;
    hunter->vect_sprite = (sfVector2f) {1, 0};
    hunter->text = sfText_create();
    hunter->sprite4 = sfSprite_create();
    hunter->game_over = sfTexture_createFromFile("src/jetpack_joytek/PNG/Game-Over.png", NULL);
    hunter->text = sfText_create();
    hunter->font = sfFont_createFromFile("spr/hunter/bitmap.ttf");
    hunter->sprite_life = sfSprite_create();
    hunter->texture_life = sfTexture_createFromFile("spr/hunter/life.png", NULL);
    hunter->rect_life = (sfIntRect) {0, 0, 320, 320};
    sfSprite_setPosition(hunter->sprite2, (sfVector2f) {0, 500});
    hunter->varspeed = (sfVector2f) {-1, 0};
    hunter->vector_sprite = (sfVector2f) {2, 0};
    hunter->sp_combo = sfSprite_create();
    hunter->tex_combo1 = sfTexture_createFromFile("spr/hunter/6gzfmt.jpeg", NULL);
    sfSprite_setPosition(hunter->sp_combo, (sfVector2f) {700, 250});
    hunter->tex_combo2 = sfTexture_createFromFile("spr/hunter/olf.png", NULL);
    hunter->tex_combo3 = sfTexture_createFromFile("spr/hunter/suppr your shit.png", NULL);
    hunter->tex_combo4 = sfTexture_createFromFile("spr/hunter/papi.png", NULL);
    hunter->tex_combo5 = sfTexture_createFromFile("spr/hunter/Capture d’écran du 2022-05-21 12-12-59.png", NULL);
    hunter->clockcombo = sfClock_create();
    hunter->textmeme = sfText_create();
}


void close_win(hunter_t *hunter, all_t *all)
{
    if (hunter->event.type == sfEvtClosed) {
        sfRenderWindow_close(all->utils->window);
    }
    if (hunter->event.type == sfEvtKeyPressed && hunter->event.key.code == sfKeyEscape) {
        sfRenderWindow_close(all->utils->window);
    }
}

void move_sprt(hunter_t *hunter)
{

    sfSprite_move(hunter->sp_sky, hunter->varspeed);
    sfSprite_move(hunter->sp_sky, hunter->varspeed);
    sfSprite_move(hunter->sp_sky, hunter->varspeed);

    sfSprite_move(hunter->sp_bg, hunter->varspeed);
    sfSprite_move(hunter->sp_bg2, hunter->varspeed);
    sfSprite_move(hunter->sp_bg3, hunter->varspeed);

    sfSprite_move(hunter->sp_midlle, hunter->varspeed);
    sfSprite_move(hunter->sp_midlle2, hunter->varspeed);
    sfSprite_move(hunter->sp_midlle3, hunter->varspeed);

    sfSprite_move(hunter->sp_foreground, hunter->varspeed);
    sfSprite_move(hunter->sp_foreground2, hunter->varspeed);
    sfSprite_move(hunter->sp_foreground3, hunter->varspeed);

    sfSprite_move(hunter->sp_ground, hunter->varspeed);
    sfSprite_move(hunter->sp_ground2, hunter->varspeed);
    sfSprite_move(hunter->sp_ground3, hunter->varspeed);

    sfSprite_move(hunter->sp_second_ground, hunter->varspeed);
    sfSprite_move(hunter->sp_second_ground2, hunter->varspeed);
    sfSprite_move(hunter->sp_second_ground3, (sfVector2f) {-1, 0});
}

void display_hunter(hunter_t *hunter, all_t *all)
{
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_bg, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_bg2, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_bg3, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_midlle, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_midlle2, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_midlle3, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_foreground, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_foreground2, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_foreground3, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_ground, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_ground2, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_ground3, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_second_ground, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_second_ground2, NULL);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_second_ground3, NULL);
}

void reset_hunter(hunter_t *hunter)
{
    sfVector2f pos_bg = sfSprite_getPosition(hunter->sp_bg);
    sfVector2f pos_bg2 = sfSprite_getPosition(hunter->sp_bg2);
    sfVector2f pos_bg3 = sfSprite_getPosition(hunter->sp_bg3);
    sfVector2f pos_midlle = sfSprite_getPosition(hunter->sp_midlle);
    sfVector2f pos_midlle2 = sfSprite_getPosition(hunter->sp_midlle2);
    sfVector2f pos_midlle3 = sfSprite_getPosition(hunter->sp_midlle3);
    sfVector2f pos_ground = sfSprite_getPosition(hunter->sp_ground);
    sfVector2f pos_ground2 = sfSprite_getPosition(hunter->sp_ground2);
    sfVector2f pos_ground3 = sfSprite_getPosition(hunter->sp_ground3);
    sfVector2f pos_foreground = sfSprite_getPosition(hunter->sp_foreground);
    sfVector2f pos_foreground2 = sfSprite_getPosition(hunter->sp_foreground2);
    sfVector2f pos_foreground3 = sfSprite_getPosition(hunter->sp_foreground3);
    sfVector2f pos_secondground = sfSprite_getPosition(hunter->sp_second_ground);
    sfVector2f pos_secondground2 = sfSprite_getPosition(hunter->sp_second_ground2);
    sfVector2f pos_secondground3 = sfSprite_getPosition(hunter->sp_second_ground3);

    if (pos_bg.x < -1920)
        sfSprite_setPosition(hunter->sp_bg, (sfVector2f) {1920, 0});
    if (pos_bg2.x < -1920)
        sfSprite_setPosition(hunter->sp_bg2, (sfVector2f) {1920, 0});
    if (pos_bg3.x < -1920)
        sfSprite_setPosition(hunter->sp_bg3, (sfVector2f) {1920, 0});
    if (pos_midlle.x< -1920)
        sfSprite_setPosition(hunter->sp_midlle, (sfVector2f) {1920, 0});
    if (pos_midlle2.x < -1920)
        sfSprite_setPosition(hunter->sp_midlle2, (sfVector2f) {1920, 0});
    if (pos_midlle3.x < -1920)
        sfSprite_setPosition(hunter->sp_midlle3, (sfVector2f) {1920, 0});
    if (pos_ground.x < -1920)
        sfSprite_setPosition(hunter->sp_ground, (sfVector2f) {1920, 0});
    if (pos_ground2.x < -1920)
        sfSprite_setPosition(hunter->sp_ground2, (sfVector2f) {1920, 0});
    if (pos_ground3.x < -1920)
        sfSprite_setPosition(hunter->sp_ground3, (sfVector2f) {1920, 0});
    if (pos_foreground.x < -1920)
        sfSprite_setPosition(hunter->sp_foreground, (sfVector2f) {1920, 0});
    if (pos_foreground2.x < -1920)
        sfSprite_setPosition(hunter->sp_foreground2, (sfVector2f) {1920, 0});
    if (pos_foreground3.x < -1920)
        sfSprite_setPosition(hunter->sp_foreground3, (sfVector2f) {1920, 0});
    if (pos_secondground.x < -1920)
        sfSprite_setPosition(hunter->sp_second_ground, (sfVector2f) {1920, 0});
    if (pos_secondground2.x < -1920)
        sfSprite_setPosition(hunter->sp_second_ground2, (sfVector2f) {1920, 0});
    if (pos_secondground3.x < -1920)
        sfSprite_setPosition(hunter->sp_second_ground3, (sfVector2f) {1920, 0});
}

int mystrlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

void display_duck(hunter_t *hunter, all_t *all)
{
    sfSprite_setTexture(hunter->sprite2, hunter->texture_duck, sfTrue);
    sfSprite_setTextureRect(hunter->sprite2, hunter->rect);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sprite2, NULL);
}

void set_life(hunter_t *hunter, all_t *all)
{
    sfSprite_setTexture(hunter->sprite_life, hunter->texture_life, sfTrue);
    sfSprite_setTextureRect(hunter->sprite_life, hunter->rect_life);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sprite_life, NULL);
}

void test_clock(hunter_t *hunter)
{
    if (hunter->rect.left != 330)
        hunter->rect.left = hunter->rect.left + 110;
    if (hunter->rect.left >= 330)
        hunter->rect.left = 0;
    sfClock_restart(hunter->clock);
}

int check_forback(hunter_t *hunter, int count, all_t *all)
{
    sfVector2f bird_pos = {- 200, rand() %700};

    sfVector2f vect_sprite = sfSprite_getPosition(hunter->sprite2);

    if (vect_sprite.x > 1920) {
        sfSprite_setPosition(hunter->sprite2, bird_pos);
        count += 1;
    }
    if (count == 3) {
        myfree(all);
        sfRenderWindow_close(all->utils->window);
    }
    return count;
}
void my_revstr(char *str)
{
    int len = mystrlen(str);
    int i = 0;

    while (i < len / 2) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
        i++;
    }
}

char value(int nbr)
{
    if (nbr >= 0 && nbr <= 9) {
        return (char)(nbr) + '0';
    }
    else if (nbr > 9) {
        return (char)(nbr - 10);
    }
    return 'b';
}

char *mygetnbr(int nbr)
{
    int rank = 0;
    char *result = malloc(sizeof(char) * 255);
    if (nbr == 0) {
        return "0";
    }
    while (nbr != 0) {
        result[rank] = value(nbr % 10);
        nbr = nbr / 10;
        rank++;
    }
    result[rank++] = 0;
    my_revstr(result);
    return result;
}


char *my_strcat(char const *src1, char const *src2)
{
    int i = 0;
    int j = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src1) + \
    my_strlen(src2) + 1));

    for (; src1[i] != '\0'; i++)
        dest[i] = src1[i];
    for (; src2[j] != '\0'; i++, j++)
        dest[i] = src2[j];
    dest[i] = '\0';

    return (dest);
}

void my_text(hunter_t *hunter)
{
    sfVector2f text_pos1 = {1200, 50};
    sfVector2f text_scale1 = {1, 1};

    sfText_setPosition(hunter->text, text_pos1);
    sfText_setColor(hunter->text, sfYellow);
    sfText_setScale(hunter->text, text_scale1);
    sfText_setString(hunter->text, my_strcat
    ("ton score = ", mygetnbr(hunter->score)));
    sfText_setFont(hunter->text, hunter->font);
}

void sound_bird(hunter_t *game)
{
    game->soundbufferbird = sfSoundBuffer_createFromFile
    ("spr/hunter/src_jetpack_joytek_PNG_Minecraft Oof.wav");
    game->soundbird = sfSound_create();
    sfSound_setBuffer(game->soundbird, game->soundbufferbird);
    sfSound_play(game->soundbird);
}

void change_life(hunter_t *hunter, int count)
{
    if (count == 0)
        hunter->rect_life.left = 0;
    else if (count == 1)
        hunter->rect_life.left = 320;
    else if (count == 2)
        hunter->rect_life.left = 640;
}

void disp_txtmeme(hunter_t *hunter, char const *str, all_t *all)
{
    sfVector2f text_pos1 = {700, 800};
    sfVector2f text_scale1 = {1, 1};

    sfText_setPosition(hunter->textmeme, text_pos1);
    sfText_setColor(hunter->textmeme, sfBlack);
    sfText_setScale(hunter->textmeme, text_scale1);
    sfText_setString(hunter->textmeme, str);
    sfText_setFont(hunter->textmeme, hunter->font);
    sfRenderWindow_drawText(all->utils->window, hunter->textmeme, NULL);
}

void disp_meme(hunter_t *hunter, sfTexture *Texture, char const *str, all_t *all)
{
    sfSprite_setTexture(hunter->sp_combo, Texture, sfTrue);
    sfRenderWindow_drawSprite(all->utils->window, hunter->sp_combo, NULL);
    disp_txtmeme(hunter, str, all);
}

void display_combo(hunter_t * hunter, all_t *all)
{
    hunter->timecombo = sfClock_getElapsedTime(hunter->clockcombo);
    hunter->secondcombo = hunter->timecombo.microseconds / 1000000.0;

    if (hunter->score == 5) {
        disp_meme(hunter, hunter->tex_combo1, "celui la il est culotté", all);
    } else if (hunter->score == 10)
        disp_meme(hunter, hunter->tex_combo2, "ok la tu me commence a me choquer", all);
    else if (hunter->score == 15)
        disp_meme(hunter, hunter->tex_combo3, "pouaaaaaah le mec est bon", all);
    else if (hunter->score == 20)
        disp_meme(hunter, hunter->tex_combo4, "ah donc tu es ausis fort que ça", all);
}

int manage_menu(hunter_t *hunter, int count, all_t *all)
{
    move_sprt(hunter);
    display_hunter(hunter, all);
    reset_hunter(hunter);

    sfSprite_move(hunter->sprite2, hunter->vector_sprite);
    set_life(hunter, all);
    change_life(hunter, count);
    display_duck(hunter, all);
    display_combo(hunter, all);
    hunter->time = sfClock_getElapsedTime(hunter->clock);
    hunter->seconds = hunter->time.microseconds / 1000000.0;
    if (hunter->seconds > 0.2) {
        test_clock(hunter);
    }
    count = check_forback(hunter, count, all);
    my_text(hunter);
    sfRenderWindow_drawText(all->utils->window, hunter->text, NULL);
    return count;
}

void set_hunter(hunter_t *hunter)
{
    sfSprite_setTexture(hunter->sp_sky3, hunter->tex_sky, sfTrue);

    sfSprite_setTexture(hunter->sp_sky2, hunter->tex_sky, sfTrue);
    sfSprite_setTexture(hunter->sp_sky, hunter->tex_sky, sfTrue);
    sfSprite_setTexture(hunter->sp_bg, hunter->tex_bg, sfTrue);
    sfSprite_setTexture(hunter->sp_bg2, hunter->tex_bg, sfTrue);
    sfSprite_setTexture(hunter->sp_bg3, hunter->tex_bg, sfTrue);
    sfSprite_setTexture(hunter->sp_midlle, hunter->tex_midlle, sfTrue);
    sfSprite_setTexture(hunter->sp_midlle2, hunter->tex_midlle, sfTrue);
    sfSprite_setTexture(hunter->sp_midlle3, hunter->tex_midlle, sfTrue);
    sfSprite_setTexture(hunter->sp_second_ground, hunter->tex_second_grnd, sfTrue);
    sfSprite_setTexture(hunter->sp_second_ground2, hunter->tex_second_grnd, sfTrue);
    sfSprite_setTexture(hunter->sp_second_ground3, hunter->tex_second_grnd, sfTrue);
    sfSprite_setTexture(hunter->sp_foreground3, hunter->tex_foreground, sfTrue);
    sfSprite_setTexture(hunter->sp_foreground2, hunter->tex_foreground, sfTrue);
    sfSprite_setTexture(hunter->sp_foreground, hunter->tex_foreground, sfTrue);
    sfSprite_setTexture(hunter->sp_ground3, hunter->tex_ground, sfTrue);
    sfSprite_setTexture(hunter->sp_ground2, hunter->tex_ground, sfTrue);
    sfSprite_setTexture(hunter->sp_ground, hunter->tex_ground, sfTrue);
    sfSprite_setPosition(hunter->sp_sky, (sfVector2f) {0, 0});
    sfSprite_setPosition(hunter->sp_sky, (sfVector2f) {1920, 0});
    sfSprite_setPosition(hunter->sp_sky, (sfVector2f) {3840, 0});

    sfSprite_setPosition(hunter->sp_bg, (sfVector2f) {0, 0});
    sfSprite_setPosition(hunter->sp_bg2, (sfVector2f) {1920, 0});
    sfSprite_setPosition(hunter->sp_bg3, (sfVector2f) {3840, 0});

    sfSprite_setPosition(hunter->sp_midlle, (sfVector2f) {0, 0});
    sfSprite_setPosition(hunter->sp_midlle2, (sfVector2f) {1920, 0});
    sfSprite_setPosition(hunter->sp_midlle3, (sfVector2f) {3840, 0});

    sfSprite_setPosition(hunter->sp_second_ground, (sfVector2f) {0, 0});
    sfSprite_setPosition(hunter->sp_second_ground2, (sfVector2f) {1920, 0});
    sfSprite_setPosition(hunter->sp_second_ground3, (sfVector2f) {3840, 0});

    sfSprite_setPosition(hunter->sp_ground, (sfVector2f) {0, 0});
    sfSprite_setPosition(hunter->sp_ground2, (sfVector2f) {1920, 0});
    sfSprite_setPosition(hunter->sp_ground3, (sfVector2f) {3840, 0});

    sfSprite_setPosition(hunter->sp_foreground, (sfVector2f) {0, 0});
    sfSprite_setPosition(hunter->sp_foreground2, (sfVector2f) {1920, 0});
    sfSprite_setPosition(hunter->sp_foreground3, (sfVector2f) {3840, 0});
}

void display_mouse(hunter_t *hunter, sfMouseButtonEvent clic,
sfEvent event, all_t *all)
{
    sfVector2f bird_pos = {- 200, rand() %700};
    sfVector2f vect_sprite = sfSprite_getPosition(hunter->sprite2);

    if (event.type == sfEvtMouseButtonPressed && event.key.code == sfMouseLeft) {
        if (clic.x > vect_sprite.x && clic.x < vect_sprite.x +
        110 && clic.y > vect_sprite.y && clic.y <
        vect_sprite.y + 110) {
            hunter->score += 1;
            hunter->varspeed.x -= 1;
            sound_bird(hunter);
            hunter->vector_sprite.x += 1;
            sfSprite_setPosition(hunter->sprite2, bird_pos);
            hunter->count2 = hunter->count2 + 1;
        } else if (hunter->count2 == 5) {
            sfRenderWindow_close(all->utils->window);
        }
    }
}

void base_hunter(all_t *all)
{
    hunter_t *hunter = malloc(sizeof(hunter_t));
    int count = 0;

    init_hunter(hunter, all);
    set_hunter(hunter);

    while (sfRenderWindow_isOpen(all->utils->window)) {
        count = manage_menu(hunter, count, all);
        sfRenderWindow_display(all->utils->window);
        while (sfRenderWindow_pollEvent(all->utils->window, &hunter->event)) {
            display_mouse(hunter, hunter->event.mouseButton, hunter->event, all);
            close_win(hunter, all);
        }
    }
}
