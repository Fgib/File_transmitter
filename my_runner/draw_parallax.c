/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** draw_parallax
*/

#include "include/my_runner.h"

sfIntRect par_rekt(struct game *params)
{
    if (params->parallax->third_step > 1920) {
        params->parallax->third_step = 0;
    }
    return (get_intrect(0, params->parallax->third_step, 1920, 1080));
}

void refresh_parallax(struct game *params)
{
    params->parallax->third_step++;
    sfSprite_setTextureRect(params->parallax->third_row, par_rekt(params));
}