/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-florian.gibault
** File description:
** manager_event_bis
*/

#include "my_runner.h"

void trigers(sfEvent event, struct game *params)
{
    if (click_t(event, params->setxt->tr_eas) == 'y') {
        params->setxt->bool_level = 0;
        params->nb_obs = 2;
        obstacle_interval_refresh(params);
    }
    if (click_t(event, params->setxt->tr_med) == 'y') {
        params->setxt->bool_level = 1;
        params->nb_obs = 3;
        obstacle_interval_refresh(params);
    }
    if (click_t(event, params->setxt->tr_har) == 'y') {
        params->setxt->bool_level = 2;
        params->nb_obs = 4;
        obstacle_interval_refresh(params);
    }
}

void game_over_event(sfEvent event, struct game *params)
{
    if (params->game_step != 4 || event.type != sfEvtMouseButtonPressed)
        return;
    if (click_b(event, params->redo_b) == 'y') {
        params->score = 0;
        params->frics = 0;
        params->game_step = 0;
        params->lives_int = 120;
        reinit_coin(params);
        reinit_obs(params);
        return;
    }
    if (click_b(event, params->exit_b) == 'y') {
        params->game_step += 15;
        return;
    }
}