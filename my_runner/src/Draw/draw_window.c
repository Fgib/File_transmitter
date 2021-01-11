/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** draw_window
*/

#include "my_runner.h"

void window_update(sfRenderWindow *window, struct game *params)
{
    text_manager(params);

    if (params->game_step == 0)
        start_menu(window, params);
    if (params->game_step == 1)
        settings_menu(window, params);
    if (params->game_step == 2)
        custom_menu(window, params);
    if (params->game_step == 3)
        game_engine(window, params);
    if (params->game_step == 4)
        game_over_menu(window, params);

}

void start_menu(sfRenderWindow *window, struct game *params)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfSprite_setPosition(params->play_b->sprite, params->play_b->coo);
    sfSprite_setPosition(params->stng_b->sprite, params->stng_b->coo);
    sfSprite_setPosition(params->cstm_b->sprite, params->cstm_b->coo);
    sfRenderWindow_drawSprite(window, params->bg_menu, NULL);
    sfRenderWindow_drawSprite(window, params->play_b->sprite, NULL);
    sfRenderWindow_drawSprite(window, params->cstm_b->sprite, NULL);
    sfRenderWindow_drawSprite(window, params->stng_b->sprite, NULL);
    sfRenderWindow_drawSprite(window, params->exit_b->sprite, NULL);
    sfRenderWindow_drawText(window, params->title_t, NULL);
}

void settings_menu(sfRenderWindow *window, struct game *params)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_drawSprite(window, params->bg_set, NULL);
    sfRenderWindow_drawText(window, params->setxt->cheat_on, NULL);
    sfRenderWindow_drawText(window, params->setxt->cheat_off, NULL);
    sfRenderWindow_drawText(window, params->setxt->easy, NULL);
    sfRenderWindow_drawText(window, params->setxt->medium, NULL);
    sfRenderWindow_drawText(window, params->setxt->hard, NULL);
    sfRenderWindow_drawSprite(window, params->exit_b->sprite, NULL);
    draw_triggers(window, params);
}

void custom_menu(sfRenderWindow *window, struct game *params)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfSprite_setPosition(params->player->sprite, get_vector(882, 500));
    sfRenderWindow_drawSprite(window, params->bg_menu, NULL);
    sfRenderWindow_drawSprite(window, params->player->sprite, NULL);
    sfRenderWindow_drawSprite(window, params->exit_b->sprite, NULL);
    sfRenderWindow_drawText(window, params->cstom_t, NULL);
}

void game_engine(sfRenderWindow *window, struct game *params)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    params->score++;
    refresh_parallax(params);
    sfRenderWindow_drawSprite(window, params->bg_menu, NULL);
    sfRenderWindow_drawSprite(window, params->parallax->third_row, NULL);
    sfRenderWindow_drawSprite(window, params->parallax->second_row, NULL);
    sfRenderWindow_drawSprite(window, params->parallax->first_row, NULL);
    sfRenderWindow_drawSprite(window, params->player->sprite, NULL);
    for (int i = 0; i < params->nb_obs; i++) {
        sfRenderWindow_drawSprite(window, params->obs[i]->sprt, NULL);
    }
    for (int i = 0; i < params->nb_coin; i++) {
        if (params->coins[i]->status == 1)
            sfRenderWindow_drawSprite(window, params->coins[i]->sprite, NULL);
    }
    sfRenderWindow_drawText(window, params->frics_t, NULL);
    sfRenderWindow_drawText(window, params->lives_t, NULL);
    sfRenderWindow_drawText(window, params->shiel_t, NULL);
    sfRenderWindow_drawText(window, params->title_t, NULL);
    sfRenderWindow_drawSprite(window, params->coin, NULL);
}