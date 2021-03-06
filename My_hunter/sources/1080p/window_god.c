/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** window_god
*/

#include "../include/my_hunter.h"

void dispose(sfRenderWindow *window, struct game *params)
{
    sfRenderWindow_destroy(window);
    sfMusic_destroy(params->music);
    sfSound_destroy(params->bricks);
    sfSoundBuffer_destroy(params->b_bricks);
}

sfRenderWindow *create_my_window(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "My_hunter", \
sfTitlebar | sfClose, NULL);
    return (window);
}

void run_window(sfRenderWindow *window, sfEvent event, int width, int height)
{
    struct game *params = malloc(sizeof(struct game));
    sfClock *frame_clock = sfClock_create();
    sfClock *back_clock = sfClock_create();
    load_textures(params);
    initialize_settings(params, width, height);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            manage_clicks(window, event, params);
        if (sfClock_getElapsedTime(back_clock).microseconds > 16000)
            refresh_window(back_clock, window, params);
        if (sfClock_getElapsedTime(frame_clock).microseconds > 41666)
            refresh_anim(frame_clock, window, params);
        if (params->windows_step > 4) {
            dispose(window, params);
            free(params);
            return;
        }
    }
    dispose(window, params);
    free(params);
}