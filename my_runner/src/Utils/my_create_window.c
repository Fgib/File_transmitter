/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-florian.gibault
** File description:
** my_create_window
*/

#include "my_runner.h"

sfRenderWindow *window_creator(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, \
    "My_runner", sfTitlebar | sfClose, NULL);
    return (window);
}