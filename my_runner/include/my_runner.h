/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** my_runner
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

struct game {
    sfEvent event;
    int score;
    int frics;
    int nb_obs;
    int nb_coin;
    sfSound *arc;
    int game_step;
    int lives_int;
    int best_score;
    int vic_or_lose;
    sfText *game_ov;
    sfText *shiel_t;
    sfText *lives_t;
    sfText *frics_t;
    sfText *cstom_t;
    sfText *title_t;
    sfMusic *musique;
    sfSprite *coin;
    sfSprite *bg_set;
    sfSprite *bg_menu;
    sfSprite *bg_cstm;
    sfFont *font_armada;
    sfVector2f win_size;
    sfSoundBuffer *buffer;
    struct set_txt *setxt;
    struct player *player;
    struct button *play_b;
    struct button *exit_b;
    struct button *redo_b;
    struct button *stng_b;
    struct button *cstm_b;
    struct obstacle *obs[5];
    struct money *coins[1000];
    struct parallax *parallax;
};

struct set_txt {
    int bool_cheat;
    int bool_level;
    int bool_color;
    sfText *cheat_on;
    sfText *cheat_off;
    sfText *easy;
    sfText *medium;
    sfText *hard;
    sfText *t_white;
    sfText *t_black;
    struct trigger *tr_on;
    struct trigger *tr_off;
    struct trigger *tr_eas;
    struct trigger *tr_med;
    struct trigger *tr_har;
    struct trigger *white;
    struct trigger *black;
};

struct button {
    sfVector2f coo;
    sfVector2f size;
    sfSprite *sprite;
};

struct player {
    int jump;
    int max_y;
    int min_y;
    double vel;
    int skin_id;
    int action_id;
    sfVector2f coo;
    sfSprite *sprite;
};

struct parallax {
    sfSprite *first_row;
    sfSprite *second_row;
    sfSprite *third_row;
    int first_step;
    int second_step;
    int third_step;
};

struct obstacle {
    double vel;
    int bool;
    int skin_id;
    sfVector2f coo;
    sfVector2f size;
    sfSprite *sprt;
};

struct trigger
{
    int state;
    sfSprite *on;
    sfSprite *off;
    sfVector2f coo;
    sfVector2f size;
};

struct money
{
    double vel;
    int status;
    int skin_id;
    sfVector2f coo;
    sfSprite *sprite;
};

//Draw_window
void window_update(sfRenderWindow *window, struct game *params);
void start_menu(sfRenderWindow *window, struct game *params);
void settings_menu(sfRenderWindow *window, struct game *params);
void custom_menu(sfRenderWindow *window, struct game *params);
void game_engine(sfRenderWindow *window, struct game *params);

//Draw_window_bis
void draw_triggers(sfRenderWindow *window, struct game *params);
void game_over_menu(sfRenderWindow *window, struct game *params);

//Draw_parallax
sfIntRect par_rekt(struct game *params);
void refresh_parallax(struct game *params);
sfIntRect par_obs(struct game *params);

//Generator
void obstacle_generator(struct game *params);
void coin_generator(struct game *params);
void obstacle_interval_refresh(struct game *params);

//Load_settings
struct button *initialize_button(int px, int py, int sx, int sy);
struct player *initialize_player(void);
struct parallax *initialize_parallax(void);
struct trigger *initialize_trigger(int i, int px, int py);
void load_settings(struct game *params, int width, int height);

//Load_settings_bis
void initialize_texts(struct game *params);
void initialize_texts_2(struct game *params);
struct money *initialize_coins(int i);
struct obstacle *initialize_obstacle(void);

//Load_textures
void load_textures(struct game *params);

//Main
void dispose(sfRenderWindow *window, struct game *params);
void refresh_window(sfClock *frame_rate, sfRenderWindow *window, \
struct game *params);
void refresh_animation(sfClock *anima_rate, struct game *params);
void refresh_window(sfClock *frame_rate, sfRenderWindow *window, \
struct game *params);
void run_game(sfRenderWindow *window, int width, int height);

//Manager_coins
void coin_manager(struct game *params);

//Manager_event
void manage_events(sfRenderWindow *window, sfEvent event, struct game *params);
void start_menu_event(sfEvent event, struct game *params);
void settings_menu_event(sfEvent event, struct game *params);
void custom_menu_event(sfEvent event, struct game *params);
void game_engine_event(sfEvent event, struct game *params);

//Manage_event_bis
void trigers(sfEvent event, struct game *params);
void game_over_event(sfEvent event, struct game *params);

//Manager_event_keyboard
void qwerty_game_event(sfEvent event, struct game *params);
void azerty_game_event(sfEvent event, struct game *params);

//Manager_obstacle
void respawn_obstacle(struct obstacle *obs);
void obstacle_manager(struct game *params);

//Manager_player
void update_score(struct game *params, int i);
int check_hitbox(struct game *params, int i);
void player_gestion(struct game *params);
void check_win_lose(struct game *params);

//Manager_sound
void sound_boss(struct game *params);
void electrucute(struct game *params);

//Manager_text
void text_manager(struct game *params);
void start_menu_text(struct game *params);
void settings_menu_text(struct game *params);
void custom_menu_text(struct game *params);
void game_engine_text(struct game *params);

//Manager_text_bis
void settings_menu_text_2(struct game *params);
void game_engine_text_2(struct game *params);
void game_over_text(struct game *params);
void game_over_text_2(struct game *params);

//Maths
int random_gen(int min, int max);
float tange(double x);
float cosinus(double x);
float sinus(double x);

//My collision
char my_collision(struct player *pl, struct obstacle *obs);
char my_coin_collision(struct player *pl, struct money *obs);

//My_get
sfSprite *get_sprite(char *path);
sfIntRect get_intrect(int top, int left, int width, int height);
sfVector2f get_vector(double x, double y);
int score_debugger(int nbr);
char *get_str(int val);

//My_window_create
sfRenderWindow *window_creator(int width, int height);

//My_click
char click_b(sfEvent event, struct button *target);
char click_t(sfEvent event, struct trigger *target);
char press_s(struct game *params);

//Reinitialisation
void reinit_obs(struct game *params);
void reinit_coin(struct game *params);