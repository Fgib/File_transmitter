/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** window_god
*/

#include "../include/my_hunter.h"

void run_window2(sfRenderWindow *window, sfEvent event, int width, int height)
{
    struct game *params = malloc(sizeof(struct game));
    sfClock *frame_clock = sfClock_create();
    sfClock *back_clock = sfClock_create();
    load_textures2(params);
    initialize_settings2(params, width, height);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            manage_clicks2(window, event, params);
        if (sfClock_getElapsedTime(back_clock).microseconds > 16000)
            refresh_window2(back_clock, window, params);
        if (sfClock_getElapsedTime(frame_clock).microseconds > 41666)
            refresh_anim2(frame_clock, window, params);
        if (params->windows_step > 4) {
            dispose(window, params);
            free(params);
            return;
        }
    }
    dispose(window, params);
    free(params);
}