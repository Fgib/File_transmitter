/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** obstacle_manager
*/

#include "my_runner.h"

void respawn_obstacle(struct obstacle *obs)
{
    int boola = random_gen(0, 1);
    obs->coo.x = 1920;
    obs->coo.y = boola == 1 ? random_gen(500, 980) : random_gen(-480, 0);
}

void obstacle_manager(struct game *params)
{
    for (int i = 0; i < params->nb_obs; i++) {
        params->obs[i]->coo.x += params->obs[i]->vel;
        if (params->obs[i]->coo.x <= -100) {
            respawn_obstacle(params->obs[i]);
        }
        sfSprite_setPosition(params->obs[i]->sprt, params->obs[i]->coo);
    }
}