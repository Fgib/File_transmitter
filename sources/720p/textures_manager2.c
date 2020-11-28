/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** textures_manager
*/

#include "../include/my_hunter.h"

sfSprite *scaller2(sfSprite *sprite)
{
    sfVector2f reduc;
    reduc.x = 0.667;
    reduc.y = 0.667;
    sfSprite_setScale(sprite, reduc);
    return (sprite);
}

void load_textures2(struct game *params)
{
    load_textures_one2(params);
    load_textures_two2(params);
    load_scoreboard(params);
    load_scale720p(params);
}

void load_textures_one2(struct game *params)
{
    params->lego = initialize_lego2();
    params->title = initialize_title2();
    params->title->sprite = get_sprite(\
sfTexture_createFromFile("pics/HD/title_sheeter.png", NULL));
    params->lego->sprite = get_sprite(\
sfTexture_createFromFile("pics/HD/yellow_sheeter.png", NULL));
    params->play = get_sprite(\
sfTexture_createFromFile("pics/FHD/play.png", NULL));
    params->game_over = get_sprite(\
sfTexture_createFromFile("pics/FHD/game_over.png", NULL));
    params->restart = get_sprite(\
sfTexture_createFromFile("pics/FHD/restart.png", NULL));
    params->exit = get_sprite(\
sfTexture_createFromFile("pics/FHD/exit.png", NULL));
    params->menu_background = get_sprite(\
sfTexture_createFromFile("pics/FHD/menu_background.png", NULL));
    params->background = get_sprite(\
sfTexture_createFromFile("pics/FHD/background.png", NULL));
}

void load_textures_two2(struct game *params)
{
    params->target = get_sprite(\
sfTexture_createFromFile("pics/FHD/target.png", NULL));
    params->settings = get_sprite(\
sfTexture_createFromFile("pics/FHD/settings.png", NULL));
    params->res_fhd = get_sprite(\
sfTexture_createFromFile("pics/FHD/1080.png", NULL));
    params->res_hd = get_sprite(\
sfTexture_createFromFile("pics/FHD/720.png", NULL));
    params->res_sd = get_sprite(\
sfTexture_createFromFile("pics/FHD/480.png", NULL));
    params->font_armada = sfFont_createFromFile("pics/astroarmada.ttf");
}

void load_scale720p(struct game *params)
{
    params->exit = scaller2(params->exit);
    params->settings = scaller2(params->settings);
    params->play = scaller2(params->play);
    params->menu_background = scaller2(params->menu_background);
    params->background = scaller2(params->background);
    params->res_fhd = scaller2(params->res_fhd);
    params->res_hd = scaller2(params->res_hd);
    params->res_sd = scaller2(params->res_sd);
    params->target = scaller2(params->target);
    params->game_over = scaller2(params->game_over);
    params->restart = scaller2(params->restart);
}