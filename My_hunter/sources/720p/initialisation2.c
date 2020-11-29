/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** initialisation
*/

#include "../include/my_hunter.h"

struct lego *initialize_lego2(void)
{
    struct lego *lego_p = malloc(sizeof(struct lego));

    lego_p->skin_id = 0;
    lego_p->speed = 2;
    lego_p->coo = set_position(1, 1);
    return (lego_p);
}

struct giffer *initialize_title2(void)
{
    struct giffer *game_name = malloc(sizeof(struct giffer));

    game_name->skin_id = 0;
}

void initialize_settings2(struct game *params, int width, int height)
{
    params->score = 0;
    params->score_over = 0;
    params->windows_step = 0;
    params->w_width_x = width;
    params->w_height_y = height;
    params->play_sx = 320;
    params->play_sy = 180;
    sfMusic_play(params->music);
    sfMusic_setLoop(params->music, sfTrue);
    params->bricks = sfSound_create();
    sfSound_setBuffer(params->bricks, params->b_bricks);
}