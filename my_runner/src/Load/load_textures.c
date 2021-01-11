/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** load_textures
*/

#include "my_runner.h"

void load_textures(struct game *params)
{
    for (int i = 0; i < params->nb_obs; i++)
        params->obs[i]->sprt = get_sprite("assets/pics/waller.png");
    for (int i = 0; i < params->nb_coin; i++)
        params->coins[i]->sprite = get_sprite("assets/pics/coiner.png");
    params->font_armada = sfFont_createFromFile("assets/font/astroarmada.ttf");
    params->redo_b->sprite = get_sprite("assets/pics/restart_button.png");
    params->play_b->sprite = get_sprite("assets/pics/play_button.png");
    params->cstm_b->sprite = get_sprite("assets/pics/cstm_button.png");
    params->parallax->third_row = get_sprite("assets/pics/tower.png");
    params->parallax->second_row = get_sprite("assets/pics/cub.png");
    params->parallax->first_row = get_sprite("assets/pics/poto.png");
    params->stng_b->sprite = get_sprite("assets/pics/settings.png");
    params->exit_b->sprite = get_sprite("assets/pics/exit_btn.png");
    params->player->sprite = get_sprite("assets/pics/ovni.png");
    params->bg_menu = get_sprite("assets/pics/menu_back.png");
    params->bg_cstm = get_sprite("assets/pics/cstm_back.png");
    params->bg_set = get_sprite("assets/pics/stng_back.png");
    params->coin = get_sprite("assets/pics/coin.png");
    sfSprite_setPosition(params->coin, get_vector(1775, 0));
    write(1, "Successfully initialized textures\n", 34);
}