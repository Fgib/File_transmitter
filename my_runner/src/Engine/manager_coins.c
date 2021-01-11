/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-florian.gibault
** File description:
** manager_coins
*/

#include "my_runner.h"

void coin_manager(struct game *params)
{
    for (int i = 0; i < params->nb_coin; i++) {
        params->coins[i]->coo.x += params->coins[i]->vel;
        sfSprite_setPosition(params->coins[i]->sprite, params->coins[i]->coo);
    }
}