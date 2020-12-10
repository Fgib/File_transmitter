/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** main
*/

#include "include/my_runner.h"

sfRenderWindow *window_creator(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "My_runner", sfTitlebar | sfClose, NULL);
    return (window);
}

void refresh_window(sfClock *frame_rate, sfRenderWindow *window, struct game *params)
{
    sfClock_restart(frame_rate);
    obstacle_manager(params);
    player_gestion(params);
    window_update(window, params);
    sfRenderWindow_display(window);
}

void run_game(sfRenderWindow *window, sfEvent event, int width, int height)
{
    srand(time(NULL));
    sfClock *frame_rate = sfClock_create();
    struct game *params = malloc(sizeof(struct game));
    load_settings(params, width, height);
    sfRenderWindow_setFramerateLimit(window, 240);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            manage_events(window, event, params);
        }
        if (sfClock_getElapsedTime(frame_rate).microseconds > 16665) {
            refresh_window(frame_rate, window, params);
            refresh_parallax(params);
        }
    }
    free(params);
}

int main(void)
{
    sfRenderWindow *window = window_creator(1920, 1080);
    sfEvent event;
    run_game(window, event, 1920, 1080);
    return (0);
}