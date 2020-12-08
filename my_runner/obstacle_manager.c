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
    //obs->coo.y = random_gen(400, 950);
    obs->coo.y = 950;
}

void obstacle_manager(struct game *params)
{
    for (int i = 0; i < params->nb_obs; i++) {
        params->obs[i]->coo.x += params->obs[i]->vel;
        if (params->obs[i]->coo.x <= -100) {
            respawn_obstacle(params->obs[i]);
        }
        sfSprite_setPosition(params->obs[i]->sprite, params->obs[i]->coo);
    }
}