/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** load_settings
*/

#include "my_runner.h"

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

struct trigger *initialize_trigger(int i, int px, int py)
{
    struct trigger *trigger_s = malloc(sizeof(struct trigger));

    write(1, "Trigger initialisation...\n", 26);
    trigger_s->coo = get_vector(px, py);
    trigger_s->size = get_vector(65, 65);
    trigger_s->state = i;
    trigger_s->on = get_sprite("assets/pics/trigger_ON.png");
    trigger_s->off = get_sprite("assets/pics/trigger_OFF.png");
    sfSprite_setPosition(trigger_s->on, trigger_s->coo);
    sfSprite_setPosition(trigger_s->off, trigger_s->coo);

    return (trigger_s);
}

void load_settings(struct game *params, int width, int height)
{
    params->frics = 0;
    params->score = 0;
    params->nb_obs = 4;
    params->nb_coin = 100;
    params->game_step = 0;
    params->lives_int = 120;
    params->win_size.x = width;
    params->win_size.y = height;
    params->player = initialize_player();
    params->parallax = initialize_parallax();
    params->exit_b = initialize_button(0, 0, 150, 150);
    params->stng_b = initialize_button(1770, 0, 150, 150);
    params->play_b = initialize_button(768, 500, 384, 216);
    params->redo_b = initialize_button(885, 800, 150, 150);
    params->cstm_b = initialize_button(885, 800, 150, 150);
    initialize_texts(params);
    obstacle_generator(params);
    coin_generator(params);
    load_textures(params);
    write(1, "Successfully initialized settings\n", 34);
}