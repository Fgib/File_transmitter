/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-florian.gibault
** File description:
** generator
*/

#include "my_runner.h"

void obstacle_generator(struct game *params)
{
    for (int i = 0; i <= params->nb_obs; i++) {
        params->obs[i] = initialize_obstacle();
    }
}

void coin_generator(struct game *params)
{
    for (int i = 0; i < params->nb_coin; i++) {
        params->coins[i] = initialize_coins(i);
    }
}

void obstacle_interval_refresh(struct game *params)
{
    int boola;
    for (int i = 0; i < params->nb_obs; i++) {
        boola = random_gen(0, 1);
        params->obs[i]->coo.x = 1920 + (2020 / params->nb_obs) * i;
        params->obs[i]->coo.y = boola == 1 ? \
    random_gen(500, 980) : random_gen(-480, 0);
    }

}