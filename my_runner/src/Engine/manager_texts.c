/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myrunner-florian.gibault
** File description:
** manage_texts
*/

#include "my_runner.h"

void text_manager(struct game *params)
{
    if (params->game_step == 0)
        start_menu_text(params);
    if (params->game_step == 1)
        settings_menu_text(params);
    if (params->game_step == 2)
        custom_menu_text(params);
    if (params->game_step == 3)
        game_engine_text(params);
    if (params->game_step == 4)
        game_over_text(params);
}

void start_menu_text(struct game *params)
{
    sfText_setString(params->title_t, "Jetpack Runner");
    sfText_setFont(params->title_t, params->font_armada);
    sfText_setColor(params->title_t, sfWhite);
    sfText_setCharacterSize(params->title_t, 100);
    sfText_setPosition(params->title_t, get_vector(600, 30));
}

void settings_menu_text(struct game *params)
{
    sfText_setString(params->setxt->cheat_on, "Cheat On");
    sfText_setFont(params->setxt->cheat_on, params->font_armada);
    sfText_setColor(params->setxt->cheat_on, sfWhite);
    sfText_setCharacterSize(params->setxt->cheat_on, 100);
    sfText_setPosition(params->setxt->cheat_on, get_vector(1200, 450));
    sfText_setString(params->setxt->cheat_off, "Cheat Off");
    sfText_setFont(params->setxt->cheat_off, params->font_armada);
    sfText_setColor(params->setxt->cheat_off, sfWhite);
    sfText_setCharacterSize(params->setxt->cheat_off, 100);
    sfText_setPosition(params->setxt->cheat_off, get_vector(1200, 550));
    settings_menu_text_2(params);

}

void custom_menu_text(struct game *params)
{
    sfText_setString(params->cstom_t, "Customisation");
    sfText_setFont(params->cstom_t, params->font_armada);
    sfText_setColor(params->cstom_t, sfWhite);
    sfText_setCharacterSize(params->cstom_t, 100);
    sfText_setPosition(params->cstom_t, get_vector(600, 50));
}

void game_engine_text(struct game *params)
{
    sfText_setString(params->lives_t, get_str(params->lives_int / 1.2));
    sfText_setFont(params->lives_t, params->font_armada);
    sfText_setColor(params->lives_t, sfWhite);
    sfText_setCharacterSize(params->lives_t, 65);
    sfText_setPosition(params->lives_t, get_vector(250, 1007));
    sfText_setString(params->frics_t, get_str(params->frics));
    sfText_setFont(params->frics_t, params->font_armada);
    sfText_setColor(params->frics_t, sfWhite);
    sfText_setCharacterSize(params->frics_t, 100);
    sfText_setPosition(params->frics_t, get_vector(1600, -30));
    sfText_setString(params->shiel_t, "Shield\nStrength");
    sfText_setFont(params->shiel_t, params->font_armada);
    sfText_setColor(params->shiel_t, sfWhite);
    sfText_setCharacterSize(params->shiel_t, 30);
    sfText_setPosition(params->shiel_t, get_vector(50, 1000));
    game_engine_text_2(params);
}