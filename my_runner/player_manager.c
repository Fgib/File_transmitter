/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** player2_manager
*/

#include "include/my_runner.h"

void ceiling_floor_checker(struct game *params)
{
    if (params->player->coo.y > params->player->max_y) {
        params->player->vel = 0;
        params->player->coo.y = params->player->max_y;
    }
    if (params->player->coo.y < params->player->min_y) {
        params->player->vel = 88;
        params->player->coo.y = params->player->min_y;
    }
}

int check_hitbox(struct game *params, int i)
{
    if (params->player->coo.x + 50 >= params->obs[i]->coo.x && params->player->coo.x <= params->obs[i]->coo.x + 150) {
        if (params->player->coo.y + 49 > params->obs[i]->coo.y) {
            params->player->max_y = params->obs[i]->coo.y - 50;
            return (0);
        } else if (params->player->coo.y < params->obs[i]->coo.y - params->obs[i]->spacing) {
            params->player->min_y = params->obs[i]->coo.y - params->obs[i]->spacing;
            return (0);
        }
    } else {
        params->player->max_y = 977;
        params->player->min_y = 0;
    }
    return (1);
}

void player_gestion(struct game *params)
{
    double grav = params->player->vel < 876 ? 87.6 : 0;
    double dt = 1.0 / 60;
    params->player->vel += grav;
    params->player->coo.y += params->player->vel * dt;
    for (int i = 0; i < params->nb_obs; i++) {
        if (check_hitbox(params, i) == 0)
            break;
    }
    ceiling_floor_checker(params);
    sfSprite_setPosition(params->player->sprite, params->player->coo);
}