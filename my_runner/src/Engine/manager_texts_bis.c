/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-florian.gibault
** File description:
** manager_texts_bis
*/

#include "my_runner.h"

void settings_menu_text_2(struct game *params)
{
    sfText_setString(params->setxt->easy, "easy");
    sfText_setFont(params->setxt->easy, params->font_armada);
    sfText_setColor(params->setxt->easy, sfWhite);
    sfText_setCharacterSize(params->setxt->easy, 100);
    sfText_setPosition(params->setxt->easy, get_vector(500, 400));
    sfText_setString(params->setxt->medium, "medium");
    sfText_setFont(params->setxt->medium, params->font_armada);
    sfText_setColor(params->setxt->medium, sfWhite);
    sfText_setCharacterSize(params->setxt->medium, 100);
    sfText_setPosition(params->setxt->medium, get_vector(500, 500));
    sfText_setString(params->setxt->hard, "hard");
    sfText_setFont(params->setxt->hard, params->font_armada);
    sfText_setColor(params->setxt->hard, sfWhite);
    sfText_setCharacterSize(params->setxt->hard, 100);
    sfText_setPosition(params->setxt->hard, get_vector(500, 600));
}

void game_engine_text_2(struct game *params)
{
    sfText_setString(params->title_t, get_str(params->score / 10));
    sfText_setFont(params->title_t, params->font_armada);
    sfText_setColor(params->title_t, sfWhite);
    sfText_setCharacterSize(params->title_t, 100);
    sfText_setPosition(params->title_t, get_vector(900, -30));
}

void game_over_text(struct game *params)
{
    sfText_setString(params->game_ov, \
    params->vic_or_lose == 0 ? "Game Over" : "Victory");
    sfText_setFont(params->game_ov, params->font_armada);
    sfText_setColor(params->game_ov, sfWhite);
    sfText_setCharacterSize(params->game_ov, 135);
    sfText_setPosition(params->game_ov, get_vector(600, 50));
    sfText_setString(params->frics_t, get_str(params->frics));
    sfText_setFont(params->frics_t, params->font_armada);
    sfText_setColor(params->frics_t, sfWhite);
    sfText_setCharacterSize(params->frics_t, 125);
    sfText_setPosition(params->frics_t, get_vector(1200, 400));
    sfText_setString(params->title_t, "coins recolted :");
    sfText_setFont(params->title_t, params->font_armada);
    sfText_setColor(params->title_t, sfWhite);
    sfText_setCharacterSize(params->title_t, 75);
    sfText_setPosition(params->title_t, get_vector(550, 440));
    game_over_text_2(params);
}

void game_over_text_2(struct game *params)
{
    sfText_setString(params->shiel_t, get_str(params->score / 10));
    sfText_setFont(params->shiel_t, params->font_armada);
    sfText_setColor(params->shiel_t, sfWhite);
    sfText_setCharacterSize(params->shiel_t, 125);
    sfText_setPosition(params->shiel_t, get_vector(1200, 500));
    sfText_setString(params->cstom_t, "meters traveled :");
    sfText_setFont(params->cstom_t, params->font_armada);
    sfText_setColor(params->cstom_t, sfWhite);
    sfText_setCharacterSize(params->cstom_t, 75);
    sfText_setPosition(params->cstom_t, get_vector(450, 540));
}
