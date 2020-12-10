/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** obstacle_manager
*/

#include "include/my_runner.h"

void respawn_obstacle(struct obstacle *obs)
{
    obs->coo.x = 1920;
    obs->coo.y = random_gen(400, 850);
}

void obstacle_manager(struct game *params)
{
    for (int i = 0; i < params->nb_obs; i++) {
        params->obs[i]->coo.x += params->obs[i]->vel;
        if (params->obs[i]->coo.x <= -100) {
            respawn_obstacle(params->obs[i]);
        }
        sfSprite_setPosition(params->obs[i]->bot, params->obs[i]->coo);
        sfSprite_setPosition(params->obs[i]->top, get_vector(params->obs[i]->coo.x, params->obs[i]->coo.y - params->obs[i]->spacing));
        sfSprite_setScale(params->obs[i]->top, get_vector(1, -1));
    }
}