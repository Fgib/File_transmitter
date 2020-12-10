/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** draw_window
*/

#include "include/my_runner.h"

void window_update(sfRenderWindow *window, struct game *params)
{
    if (params->game_step == 0) {
        start_menu(window, params);
    }
}

void start_menu(sfRenderWindow *window, struct game *params)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_drawSprite(window, params->parallax->third_row, NULL);
    sfRenderWindow_drawSprite(window, params->player->sprite, NULL);
    sfSprite_setOrigin(params->player->sprite, get_vector(50, 50));
    sfSprite_setRotation(params->player->sprite, params->player->vel / 20);
    for (int i = 0; i < params->nb_obs; i++) {
        sfRenderWindow_drawSprite(window, params->obs[i]->bot, NULL);
        sfRenderWindow_drawSprite(window, params->obs[i]->top, NULL);
    }
}