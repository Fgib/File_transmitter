/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** player2_manager
*/

#include "my_runner.h"

void update_score(struct game *params, int i)
{
    if (my_collision(params->player, params->obs[i]) == 'y') {
        electrucute(params);
        params->lives_int--;
    }
    return;
}

void ceiling_floor_checker(struct game *params)
{
    if (params->player->coo.y > 930) {
        params->player->vel = 0;
        params->player->coo.y = 930;
    }
    if (params->player->coo.y < 0) {
        params->player->vel = 88;
        params->player->coo.y = 0;
    }
}

void player_gestion(struct game *params)
{
    double grav = params->player->vel < 876 ? 87.6 : 0;
    double dt = 1.0 / 60;
    params->player->vel += (press_s(params) == 'y') ? (8 * -grav) : grav;
    if (params->player->vel < -1876)
        params->player->vel = -1876;
    params->player->coo.y += params->player->vel * dt;
    for (int i = 0; i < params->nb_obs; i++) {
        update_score(params, i);
    }
    for (int i = 0; i < params->nb_coin; i++) {
        if (my_coin_collision(params->player, params->coins[i]) == 'y') {
            params->frics += params->coins[i]->status == 1 ? 1 : 0;
            params->coins[i]->status = 0;
        }
    }
    ceiling_floor_checker(params);
    check_win_lose(params);
    sfSprite_setPosition(params->player->sprite, params->player->coo);
}

void check_win_lose(struct game *params)
{
    if (params->lives_int < 0 && params->setxt->bool_cheat == 0) {
        params->game_step++;
        params->vic_or_lose = 0;
    } else if (params->coins[99]->coo.x < params->player->coo.x) {
        params->game_step++;
        params->vic_or_lose = 1;
    } else {
        return;
    }
}