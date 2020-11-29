/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** screen_printer
*/

#include "../include/my_hunter.h"

void window_update(sfRenderWindow *window, struct game *params)
{
    if (params->windows_step == 0) {
        start_menu(window, params);
    }
    if (params->windows_step == 1) {
        game_engine(window, params);
    }
    if (params->windows_step == 2) {
        end_menu(window, params);
    }
    if (params->windows_step == 3) {
        settings_menu(window, params);
    }
}

void start_menu(sfRenderWindow *window, struct game *params)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_drawSprite(window, params->menu_background, NULL);
    sfRenderWindow_drawSprite(window, params->exit, NULL);
    sfRenderWindow_drawSprite(window, params->play, NULL);
    sfRenderWindow_drawSprite(window, params->title->sprite, NULL);
    sfRenderWindow_drawSprite(window, params->settings, NULL);
    sfSprite_setPosition(params->title->sprite, set_position(params->w_width_x\
/ 2 - 535, params->w_height_y / 4 - 100));
    sfSprite_setPosition(params->play, set_position(params->w_width_x / 2 - \
240, params->w_height_y / 2 - 135));
    sfSprite_setPosition(params->settings, set_position(params->w_width_x -150\
, 0));
}

void game_engine(sfRenderWindow *window, struct game *params)
{
    lego_gestion(params);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setPosition(params->target, set_position(params->mouse_coo.x - 50\
, params->mouse_coo.y - 50));
    sfRenderWindow_drawSprite(window, params->background, NULL);
    sfRenderWindow_drawSprite(window, params->lego->sprite, NULL);
    sfRenderWindow_drawSprite(window, params->target, NULL);
    sfRenderWindow_drawText(window, params->t_score, NULL);
    sfRenderWindow_drawText(window, params->t_lives, NULL);
    sfRenderWindow_drawText(window, params->f_remain, NULL);
}

void end_menu(sfRenderWindow *window, struct game *params)
{
    update_score(params);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_drawSprite(window, params->menu_background, NULL);
    sfRenderWindow_drawSprite(window, params->game_over, NULL);
    sfRenderWindow_drawSprite(window, params->restart, NULL);
    sfRenderWindow_drawSprite(window, params->exit, NULL);
    sfSprite_setPosition(params->game_over, set_position(params->w_width_x / 2\
- 240, params->w_height_y / 4 - 150));
    sfSprite_setPosition(params->restart, set_position(params->w_width_x / 2\
- 240, params->w_height_y /2 - 135));
    sfRenderWindow_drawText(window, params->f_score, NULL);
    sfRenderWindow_drawText(window, params->f_best_score, NULL);
    sfRenderWindow_drawText(window, params->t_score, NULL);
    sfRenderWindow_drawText(window, params->t_best_score, NULL);
}

void settings_menu(sfRenderWindow *window, struct game *params)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_drawSprite(window, params->menu_background, NULL);
    sfRenderWindow_drawSprite(window, params->res_fhd, NULL);
    sfRenderWindow_drawSprite(window, params->res_hd, NULL);
    sfRenderWindow_drawSprite(window, params->res_sd, NULL);
    sfSprite_setPosition(params->res_fhd, set_position(480, 720));
    sfSprite_setPosition(params->res_hd, set_position(810, 720));
    sfSprite_setPosition(params->res_sd, set_position(1140, 720));
}