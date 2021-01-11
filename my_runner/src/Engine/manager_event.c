/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** event_manager
*/

#include "my_runner.h"

void manage_events(sfRenderWindow *window, sfEvent event, struct game *params)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    if (params->game_step == 0) {
        start_menu_event(event, params);
    }
    if (params->game_step == 1) {
        settings_menu_event(event, params);
    }
    if (params->game_step == 2) {
        custom_menu_event(event, params);
    }
    if (params->game_step == 3) {
        game_engine_event(event, params);
    }
    if (params->game_step == 4) {
        game_over_event(event, params);
    }
}

void start_menu_event(sfEvent event, struct game *params)
{
    if (params->game_step != 0 || event.type != sfEvtMouseButtonPressed)
        return;
    if (click_b(event, params->stng_b) == 'y') {
        params->game_step = 1;
        return;
    }
    if (click_b(event, params->cstm_b) == 'y') {
        params->game_step = 2;
        return;
    }
    if (click_b(event, params->play_b) == 'y') {
        obstacle_interval_refresh(params);
        params->game_step = 3;
        return;
    }
    if (click_b(event, params->exit_b) == 'y') {
        params->game_step += 15;
        return;
    }
}

void settings_menu_event(sfEvent event, struct game *params)
{
    if (params->game_step != 1 || event.type != sfEvtMouseButtonPressed)
        return;
    if (click_b(event, params->exit_b) == 'y') {
        params->game_step = 0;
        return;
    }
    if (click_t(event, params->setxt->tr_on) == 'y')
        params->setxt->bool_cheat = 1;
    if (click_t(event, params->setxt->tr_off) == 'y')
        params->setxt->bool_cheat = 0;
    trigers(event, params);
    return;
}

void custom_menu_event(sfEvent event, struct game *params)
{
    if (params->game_step != 2 || event.type != sfEvtMouseButtonPressed)
        return;
    if (click_b(event, params->exit_b) == 'y') {
        params->game_step = 0;
        return;
    }
}

void game_engine_event(sfEvent event, struct game *params)
{
    if (params->game_step != 3)
        return;
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeySpace)
            params->player->vel -= 300;
        if (event.key.code == sfKeyJ)
            params->player->vel = -5200;
        if (event.key.code == sfKeyK)
            params->lives_int -= 90;
        if (event.key.code == sfKeyM)
            params->frics += 10;
    }
    return;
}