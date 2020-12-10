/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** load_settings
*/

#include "include/my_runner.h"

struct button *initialize_button(int px, int py, int sx, int sy)
{
    struct button *button_s = malloc(sizeof(struct button));

    write(1, "Button initialisation...\n", 25);
    button_s->coo = get_vector(px, py);
    button_s->size = get_vector(sx, sy);
    return (button_s);
}

struct player *initialize_player(void)
{
    struct player *player_s = malloc(sizeof(struct player));

    write(1, "Player initialisation...\n", 25);
    player_s->skin_id = 0;
    player_s->action_id = 0;
    player_s->coo = get_vector(150, 50);
    return (player_s);
}

struct parallax *initialize_parallax(void)
{
    struct parallax *parallax_s = malloc(sizeof(struct parallax));

    write(1, "Parallax initialisation...\n", 27);
    parallax_s->first_step = 0;
    parallax_s->second_step = 0;
    parallax_s->third_step = 0;
    return (parallax_s);
}

struct obstacle *initialize_obstacle(int i, struct game *params)
{
    struct obstacle *obstacle_s = malloc(sizeof(struct obstacle));

    obstacle_s->vel = -7.0;
    obstacle_s->coo.x = 960 + (2020 / params->nb_obs) * i;
    obstacle_s->coo.y = random_gen(400, 880);
    return (obstacle_s);
}

void load_settings(struct game *params, int width, int height)
{
    int spacing = 300;
    params->lives = 3;
    params->score = 0;
    params->nb_obs = 4;
    params->game_step = 0;
    params->win_size.x = width;
    params->win_size.y = height;
    params->player = initialize_player();
    params->parallax = initialize_parallax();
    params->exit_b = initialize_button(0, 0, 150, 150);
    params->play_b = initialize_button(600, 600, 300, 400);
    for (int i = 0; i < params->nb_obs; i++) {
        params->obs[i] = initialize_obstacle(i, params);
        params->obs[i]->spacing = spacing;
    }
    write(1, "Successfully initialized settings\n", 34);
    load_textures(params);
}