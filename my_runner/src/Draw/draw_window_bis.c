/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-florian.gibault
** File description:
** draw_window_bis
*/

#include "my_runner.h"

void draw_triggers(sfRenderWindow *window, struct game *params)
{
    if (params->setxt->bool_cheat == 0) {
        sfRenderWindow_drawSprite(window, params->setxt->tr_on->off, NULL);
        sfRenderWindow_drawSprite(window, params->setxt->tr_off->on, NULL);
    } else {
        sfRenderWindow_drawSprite(window, params->setxt->tr_on->on, NULL);
        sfRenderWindow_drawSprite(window, params->setxt->tr_off->off, NULL);
    }
    if (params->setxt->bool_level == 0) {
        sfRenderWindow_drawSprite(window, params->setxt->tr_eas->on, NULL);
        sfRenderWindow_drawSprite(window, params->setxt->tr_med->off, NULL);
        sfRenderWindow_drawSprite(window, params->setxt->tr_har->off, NULL);
    } else if (params->setxt->bool_level == 1) {
        sfRenderWindow_drawSprite(window, params->setxt->tr_eas->off, NULL);
        sfRenderWindow_drawSprite(window, params->setxt->tr_med->on, NULL);
        sfRenderWindow_drawSprite(window, params->setxt->tr_har->off, NULL);
    } else {
        sfRenderWindow_drawSprite(window, params->setxt->tr_eas->off, NULL);
        sfRenderWindow_drawSprite(window, params->setxt->tr_med->off, NULL);
        sfRenderWindow_drawSprite(window, params->setxt->tr_har->on, NULL);
    }
}

void game_over_menu(sfRenderWindow *window, struct game *params)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_drawSprite(window, params->bg_menu, NULL);
    sfSprite_setPosition(params->redo_b->sprite, params->redo_b->coo);
    sfRenderWindow_drawSprite(window, params->redo_b->sprite, NULL);
    sfRenderWindow_drawSprite(window, params->exit_b->sprite, NULL);
    sfRenderWindow_drawText(window, params->game_ov, NULL);
    sfRenderWindow_drawText(window, params->title_t, NULL);
    sfRenderWindow_drawText(window, params->frics_t, NULL);
    sfRenderWindow_drawText(window, params->shiel_t, NULL);
    sfRenderWindow_drawText(window, params->cstom_t, NULL);
}