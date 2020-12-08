/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** player2_manager
*/

#include "include/my_runner.h"

void check_hitbox(struct game *params)
{
    for (int i = 0; i < params->nb_obs; i++) {
        if (params->player->coo.x + 100 >= params->obs[i]->coo.x\
&& params->player->coo.x <= params->obs[i]->coo.x + 100) {
            params->player->max_y = params->obs[i]->coo.y - 100;
            printf("%d ", i);
            return;
        } else {
            params->player->max_y = 927;
        }
    }
}

void player_gestion(struct game *params)
{
    double grav = params->player->vel < 876 ? 87.6 : 0;
    double dt = 1.0 / 60;
    params->player->vel += grav;
    params->player->coo.y += params->player->vel * dt;
    check_hitbox(params);
    printf("%d\n", params->player->max_y);
    if (params->player->coo.y > params->player->max_y) {
        params->player->vel = 0;
        params->player->coo.y = params->player->max_y;
    }
    sfSprite_setPosition(params->player->sprite, params->player->coo);
}