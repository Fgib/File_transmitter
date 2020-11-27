/*
** EPITECH PROJECT, 2020
** mon_mien
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

struct game {
    int score;
    int best_score;
    int score_over;
    int windows_step;
    int w_width_x;
    int w_height_y;
    sfVector2f mouse_coo;
    struct lego *lego;
    struct giffer *title;
    sfSprite *play;
    int play_sx;
    int play_sy;
    sfSprite *game_over;
    sfSprite *target;
    sfSprite *restart;
    sfSprite *exit;
    sfSprite *menu_background;
    sfSprite *background;
    sfSprite *settings;
    sfSprite *res_fhd;
    sfSprite *res_hd;
    sfSprite *res_sd;
    sfText *t_score;
    sfText *t_best_score;
    sfFont *font_armada;
};

struct giffer {
    sfSprite *sprite;
    int skin_id;
};

struct lego {
    sfSprite *sprite;
    sfVector2f coo;
    int r_offset;
    int r_angle;
    int speed;
    int skin_id;
};

//main
void print_helper(void);
int launcher(void);
int launcher2(void);
int launcher3(void);

//maths
int random_gen(int min, int max);
float tange(double x);
float cosinus(double x);
sfVector2f set_position(int x, int y);

//utils
int my_strlen(char const *str);
int checker_teker(int negativ_count, const char *str, long v);
int my_getnbr(char const *str);
char *get_str(int val);

//1080p
//events_manager
void manage_clicks(sfRenderWindow *window, sfEvent event, struct game *params);
void manage_events(struct game *params, sfEvent event, sfRenderWindow *window);
void start_menu_event(sfEvent event, struct game *params);
void game_event(sfEvent event, struct game *params);
void end_menu_event(sfEvent event, struct game *params);
void settings_menu_event(sfEvent event, struct game *params, sfRenderWindow *window);

//lego_manager
void respawn_lego(struct game *params);
void lego_gestion(struct game *params);

//scrore_drawer
void load_scoreboard(struct game *params);

//screen_printer
void window_update(sfRenderWindow *window, struct game *params);
void start_menu(sfRenderWindow *window, struct game *params);
void game_engine(sfRenderWindow *window, struct game *params);
void end_menu(sfRenderWindow *window, struct game *params);
void settings_menu(sfRenderWindow *window, struct game *params);

//initialisation
void initialize_settings(struct game *params, int width, int height);
struct lego *initialize_lego(void);
struct giffer *initialize_title(void);

//spritesheet_manager
sfIntRect sprite_info(int top, int left, int width, int height);
sfIntRect text_title_rank(struct game *params);
sfIntRect text_lego_rank(struct game *params);

//window_god
sfRenderWindow *create_my_window(int width, int height);
void run_window(sfRenderWindow *window, sfEvent event, int width, int height);
void dispose(sfRenderWindow *window);

//refresh_rate_manager
void refresh_anim(sfClock *frame_clock, \
sfRenderWindow *window, struct game *params);
void refresh_window(sfClock *back_clock, \
sfRenderWindow *window, struct game *params);

//textures_manager
sfSprite *get_sprite(sfTexture *texture);
void load_textures(struct game *params);
void load_textures_one(struct game *params);
void load_textures_two(struct game *params);

//720p
//events_manager
void manage_clicks2(sfRenderWindow *window, sfEvent event, struct game *params);
void manage_events2(struct game *params, sfEvent event);
void start_menu_event2(sfEvent event, struct game *params);
void game_event2(sfEvent event, struct game *params);
void end_menu_event2(sfEvent event, struct game *params);

//lego_manager
void respawn_lego2(struct game *params);
void lego_gestion2(struct game *params);

//screen_printer
void window_update2(sfRenderWindow *window, struct game *params);
void start_menu2(sfRenderWindow *window, struct game *params);
void game_engine2(sfRenderWindow *window, struct game *params);
void end_menu2(sfRenderWindow *window, struct game *params);
void settings_menu2(sfRenderWindow *window, struct game *params);

//initialisation
void initialize_settings2(struct game *params, int width, int height);
struct lego *initialize_lego2(void);
struct giffer *initialize_title2(void);

//spritesheet_manager
sfIntRect sprite_info2(int top, int left, int width, int height);
sfIntRect text_title_rank2(struct game *params);
sfIntRect text_lego_rank2(struct game *params);

//window_god
sfRenderWindow *create_my_window2(int width, int height);
void run_window2(sfRenderWindow *window, sfEvent event, int width, int height);

//refresh_rate_manager
void refresh_anim2(sfClock *frame_clock, \
sfRenderWindow *window, struct game *params);
void refresh_window2(sfClock *back_clock, \
sfRenderWindow *window, struct game *params);

//textures_manager
sfSprite *get_sprite2(sfTexture *texture);
void load_textures2(struct game *params);
void load_textures_one2(struct game *params);
void load_textures_two2(struct game *params);

//480p
//events_manager
void manage_clicks3(sfRenderWindow *window, sfEvent event, struct game *params);
void manage_events3(struct game *params, sfEvent event);
void start_menu_event3(sfEvent event, struct game *params);
void game_event3(sfEvent event, struct game *params);
void end_menu_event3(sfEvent event, struct game *params);

//lego_manager
void respawn_lego3(struct game *params);
void lego_gestion3(struct game *params);

//screen_printer
void window_update3(sfRenderWindow *window, struct game *params);
void start_menu3(sfRenderWindow *window, struct game *params);
void game_engine3(sfRenderWindow *window, struct game *params);
void end_menu3(sfRenderWindow *window, struct game *params);
void settings_menu3(sfRenderWindow *window, struct game *params);

//initialisation
void initialize_settings3(struct game *params, int width, int height);
struct lego *initialize_lego3(void);
struct giffer *initialize_title3(void);

//spritesheet_manager
sfIntRect sprite_info3(int top, int left, int width, int height);
sfIntRect text_title_rank3(struct game *params);
sfIntRect text_lego_rank3(struct game *params);

//window_god
sfRenderWindow *create_my_window3(int width, int height);
void run_window3(sfRenderWindow *window, sfEvent event, int width, int height);

//refresh_rate_manager
void refresh_anim3(sfClock *frame_clock, \
sfRenderWindow *window, struct game *params);
void refresh_window3(sfClock *back_clock, \
sfRenderWindow *window, struct game *params);

//textures_manager
sfSprite *get_sprite3(sfTexture *texture);
void load_textures3(struct game *params);
void load_textures_one3(struct game *params);
void load_textures_two3(struct game *params);