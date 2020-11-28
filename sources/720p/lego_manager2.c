/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** lego_manager
*/

#include "../include/my_hunter.h"

void respawn_lego2(struct game *params)
{
    params->lego->speed;
    params->lego->coo.x = 5;
    params->lego->coo.y = 690;
    params->lego->r_angle = random_gen(0, 10) - 5;
    params->lego->r_offset = random_gen(0, 230);
}

void lego_gestion2(struct game *params)
{
    float v_0 = .01;
    int alpha = 40 + params->lego->r_angle;
    int grav = 10;
    int x = params->lego->coo.x += (params->lego->speed + params->score);
    if (params->lego->coo.x > params->w_width_x || params->lego->coo.y > \
params->w_height_y || params->lego->coo.x <= 0 || params->lego->coo.y <= 0) {
        params->score_over += 1;
        respawn_lego2(params);
        if (params->score_over > 3)
            params->windows_step++;
    }
    params->lego->coo.y = 640 - params->lego->r_offset - \
((-grav / 2 * v_0 * v_0 * cosinus(alpha)) * x * x + tange(alpha) * x);
    sfSprite_setPosition(params->lego->sprite, \
set_position(params->lego->coo.x, params->lego->coo.y));
}

