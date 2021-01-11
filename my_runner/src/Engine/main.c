/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** main
*/

#include "my_runner.h"

void dispose(sfRenderWindow *window, struct game *params)
{
    sfRenderWindow_destroy(window);
    sfMusic_destroy(params->musique);
    sfSound_destroy(params->arc);
    sfSoundBuffer_destroy(params->buffer);
    free(params);
    write(1, "Successfully free\n", 18);
}

void refresh_window(sfClock *frame_rate, sfRenderWindow *window, \
struct game *params)
{
    sfRenderWindow_clear(window, sfBlack);
    if (params->game_step == 3) {
        obstacle_manager(params);
        coin_manager(params);
        player_gestion(params);
    }
    window_update(window, params);
    sfRenderWindow_display(window);
    sfClock_restart(frame_rate);
}

void refresh_animation(sfClock *anima_rate, struct game *params)
{
    params->player->skin_id += params->player->skin_id < 23 ? 1 : -23;
    sfSprite_setTextureRect(params->player->sprite,
    get_intrect(params->setxt->bool_color * 100,
    params->player->skin_id * 156.25, 150, 100));
    for (int i = 0; i < params->nb_coin; i++) {
        params->coins[i]->skin_id += params->coins[i]->skin_id < 23 ? 1 : -23;
        sfSprite_setTextureRect(params->coins[i]->sprite,
        get_intrect(0, params->coins[i]->skin_id * 48, 48, 48));
    }
    for (int i = 0; i < params->nb_obs; i++) {
        params->obs[i]->skin_id += params->obs[i]->skin_id < 49 ? 1 : -49;
        sfSprite_setTextureRect(params->obs[i]->sprt,
        get_intrect(0, params->obs[i]->skin_id * 100, 100, 680));
    }
    sfClock_restart(anima_rate);
}

void run_game(sfRenderWindow *window, int width, int height)
{
    srand(time(NULL));
    sfClock *frame_rate = sfClock_create();
    sfClock *anima_rate = sfClock_create();
    struct game *params = malloc(sizeof(struct game));
    load_settings(params, width, height);
    sound_boss(params);
    while (sfRenderWindow_isOpen(window) && params->game_step < 10) {
        while (sfRenderWindow_pollEvent(window, &params->event)) {
            manage_events(window, params->event, params);
        }
        if (sfClock_getElapsedTime(frame_rate).microseconds > 15000) {
            refresh_window(frame_rate, window, params);
        }
        if (sfClock_getElapsedTime(anima_rate).microseconds > 90000) {
            refresh_animation(anima_rate, params);
        }
    }
    dispose(window, params);
}

int main(void)
{
    sfRenderWindow *window = window_creator(1920, 1080);
    run_game(window, 1920, 1080);
    return (0);
}
