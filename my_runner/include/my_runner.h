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
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

struct game {
    int score;
    int lives;
    int nb_obs;
    int game_step;
    int best_score;
    int plat_count;
    sfVector2f win_size;
    struct player *player;
    struct button *play_b;
    struct button *exit_b;
    struct obstacle *obs[15];
    struct parallax *parallax;
};

struct button {
    sfVector2f coo;
    sfVector2f size;
    sfSprite *sprite;
};

struct player {
    int max_y;
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
    sfVector2f coo;
    sfSprite *sprite;
};

//Draw_window
void window_update(sfRenderWindow *window, struct game *params);
void start_menu(sfRenderWindow *window, struct game *params);

//Draw_parallax
sfIntRect par_rekt(struct game *params);
void refresh_parallax(struct game *params);

//Event_manager
void manage_events(sfRenderWindow *window, sfEvent event, struct game *params);

//Load_settings
struct button *initialize_button(int px, int py, int sx, int sy);
struct player *initialize_player(void);
struct parallax *initialize_parallax(void);
void load_settings(struct game *params, int width, int height);

//Load_textures
void load_textures(struct game *params);

//Main
sfRenderWindow *window_creator(int width, int height);
void refresh_window(sfClock *frame_rate, sfRenderWindow *window, struct game *params);
void run_game(sfRenderWindow *window, sfEvent event, int width, int height);

//Maths
int random_gen(int min, int max);
float tange(double x);
float cosinus(double x);
float sinus(double x);

//My_get
sfSprite *get_sprite(sfTexture *texture);
sfIntRect get_intrect(int top, int left, int width, int height);
sfVector2f get_vector(double x, double y);

//Obstacle_manager
void respawn_obstacle(struct obstacle *obs);
void obstacle_manager(struct game *params);

//player_manager
void check_hitbox(struct game *params);
void player_gestion(struct game *params);










void player2_gestion(struct game *params);