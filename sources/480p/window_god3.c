/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** window_god
*/

#include "../include/my_hunter.h"

void run_window3(sfRenderWindow *window, sfEvent event, int width, int height)
{
    struct game *params = malloc(sizeof(struct game));
    sfClock *frame_clock = sfClock_create();
    sfClock *back_clock = sfClock_create();
    load_textures(params);
    initialize_settings(params, width, height);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            manage_clicks3(window, event, params);
        if (sfClock_getElapsedTime(back_clock).microseconds > 16000)
            refresh_window3(back_clock, window, params);
        if (sfClock_getElapsedTime(frame_clock).microseconds > 41666)
            refresh_anim3(frame_clock, window, params);
        if (params->windows_step > 4) {
            free(params);
            dispose(window);
            return;
        }
    }
    dispose(window);
    free(params);
}