/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** screen_printer
*/

#include "../include/my_hunter.h"

void window_update2(sfRenderWindow *window, struct game *params)
{
    if (params->windows_step == 0) {
        start_menu2(window, params);
    }
    if (params->windows_step == 1) {
        game_engine2(window, params);
    }
    if (params->windows_step == 2) {
        end_menu2(window, params);
    }
    if (params->windows_step == 3) {
        settings_menu2(window, params);
    }
}

void start_menu2(sfRenderWindow *window, struct game *params)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_drawSprite(window, params->menu_background, NULL);
    sfRenderWindow_drawSprite(window, params->exit, NULL);
    sfRenderWindow_drawSprite(window, params->play, NULL);
    sfRenderWindow_drawSprite(window, params->title->sprite, NULL);
    sfRenderWindow_drawSprite(window, params->settings, NULL);
    sfSprite_setPosition(params->title->sprite, set_position(params->w_width_x\
/ 2 - 353, params->w_height_y / 4 - 100));
    sfSprite_setPosition(params->play, set_position(params->w_width_x / 2 - \
160, params->w_height_y / 2 - 90));
    sfSprite_setPosition(params->settings, set_position(params->w_width_x - 100\
, 0));
}

void game_engine2(sfRenderWindow *window, struct game *params)
{
    lego_gestion2(params);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setPosition(params->target, set_position(params->mouse_coo.x - 50\
, params->mouse_coo.y - 50));
    sfRenderWindow_drawSprite(window, params->background, NULL);
    sfRenderWindow_drawSprite(window, params->lego->sprite, NULL);
    sfRenderWindow_drawSprite(window, params->target, NULL);
    sfRenderWindow_drawText(window, params->t_score, NULL);
}

void end_menu2(sfRenderWindow *window, struct game *params)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_drawSprite(window, params->menu_background, NULL);
    sfRenderWindow_drawSprite(window, params->game_over, NULL);
    sfRenderWindow_drawSprite(window, params->restart, NULL);
    sfRenderWindow_drawSprite(window, params->exit, NULL);
    sfSprite_setPosition(params->game_over, set_position(params->w_width_x / 2\
- 160, params->w_height_y / 4 - 150));
    sfSprite_setPosition(params->restart, set_position(params->w_width_x / 2\
- 160, params->w_height_y /2 - 135));
}

void settings_menu2(sfRenderWindow *window, struct game *params)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_drawSprite(window, params->menu_background, NULL);
    sfRenderWindow_drawSprite(window, params->res_fhd, NULL);
    sfRenderWindow_drawSprite(window, params->res_hd, NULL);
    sfRenderWindow_drawSprite(window, params->res_sd, NULL);
    sfSprite_setPosition(params->res_fhd, set_position(320, 480));
    sfSprite_setPosition(params->res_hd, set_position(540, 480));
    sfSprite_setPosition(params->res_sd, set_position(760, 480));
}