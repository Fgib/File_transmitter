/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-florian.gibault
** File description:
** reinitialisation
*/

#include "my_runner.h"

void reinit_obs(struct game *params)
{
    int boola;
    srand(time(NULL));
    for (int i = 0; i < params->nb_obs; i++) {
        boola = random_gen(0, 1);
        params->obs[i]->coo.x = 1920 + (2020 / params->nb_obs) * i;
        params->obs[i]->coo.y = boola == 1 ? \
    random_gen(500, 980) : random_gen(-480, 0);
    }
}

void reinit_coin(struct game *params)
{
    for (int i = 0; i < params->nb_coin; i++) {
        params->coins[i]->coo.y = sinus(i * 25) * 150 + 500;
        params->coins[i]->coo.x = 500 + 48 * 5 * i;
        params->coins[i]->status = 1;
    }
}