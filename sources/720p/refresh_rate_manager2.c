/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** refresh_rate_manager
*/

#include "../include/my_hunter.h"

void refresh_window2(sfClock *back_clock, \
sfRenderWindow *window, struct game *params)
{
    sfClock_restart(back_clock);
    sfRenderWindow_clear(window, sfBlack);
    window_update2(window, params);
    sfRenderWindow_display(window);
}

void refresh_anim2(sfClock *frame_clock, \
sfRenderWindow *window, struct game *params)
{
    sfClock_restart(frame_clock);
    params->lego->skin_id++;
    params->title->skin_id++;
    sfSprite_setTextureRect(params->lego->sprite, text_lego_rank2(params));
    sfSprite_setTextureRect(params->title->sprite, text_title_rank2(params));
}