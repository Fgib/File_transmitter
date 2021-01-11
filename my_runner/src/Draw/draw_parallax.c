/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** draw_parallax
*/

#include "my_runner.h"

void refresh_parallax(struct game *params)
{
    params->parallax->third_step++;
    params->parallax->second_step += 2;
    params->parallax->first_step += 3;
    if (params->parallax->third_step > 1920)
        params->parallax->third_step = 0;
    if (params->parallax->second_step > 1920)
        params->parallax->second_step = 0;
    if (params->parallax->first_step > 1920)
        params->parallax->first_step = 0;
    sfSprite_setTextureRect(params->parallax->third_row, \
    get_intrect(0, params->parallax->third_step, 1920, 1080));
    sfSprite_setTextureRect(params->parallax->second_row, \
    get_intrect(0, params->parallax->second_step, 1920, 1080));
    sfSprite_setTextureRect(params->parallax->first_row, \
    get_intrect(0, params->parallax->first_step, 1920, 1080));
}

sfIntRect par_obs(struct game *params)
{
    if (params->obs[1]->skin_id > 100) {
        params->obs[1]->skin_id = 0;
    }
    return (get_intrect(0, params->obs[1]->skin_id * 100, 100, 680));
}

void refresh_obstacle(struct game *params)
{
    params->obs[1]->skin_id++;
    sfSprite_setTextureRect(params->obs[1]->sprt, par_obs(params));
}