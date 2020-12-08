/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** load_textures
*/

#include "include/my_runner.h"

void load_textures(struct game *params)
{
    for (int i = 0; i < params->nb_obs; i++) {
        params->obs[i]->sprite = get_sprite(sfTexture_createFromFile("pics/wall.png", NULL));
    }
    params->parallax->third_row = get_sprite(sfTexture_createFromFile("pics/parallax/parallax.png", NULL));
    params->player->sprite = get_sprite(sfTexture_createFromFile("pics/Cube.png", NULL));
    write(1, "Successfully initialized textures\n", 34);
}