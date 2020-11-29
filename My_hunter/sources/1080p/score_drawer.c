/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** score_drawer
*/

#include "../include/my_hunter.h"

void load_scoreboard(struct game *params)
{
    params->t_score = sfText_create();
    sfText_setString(params->t_score, get_str(params->score));
    sfText_setFont(params->t_score, params->font_armada);
    sfText_setColor(params->t_score, sfWhite);
    sfText_setCharacterSize(params->t_score, 50);
    sfText_setPosition(params->t_score, set_position(945, 25));
    params->t_lives = sfText_create();
    sfText_setString(params->t_lives, get_str(3 - params->score_over));
    sfText_setFont(params->t_lives, params->font_armada);
    sfText_setColor(params->t_lives, sfWhite);
    sfText_setCharacterSize(params->t_lives, 50);
    sfText_setPosition(params->t_lives, set_position(1150, 1000));
    params->f_remain = sfText_create();
    sfText_setString(params->f_remain, "Remaining lives :");
    sfText_setFont(params->f_remain, params->font_armada);
    sfText_setColor(params->f_remain, sfWhite);
    sfText_setCharacterSize(params->f_remain, 50);
    sfText_setPosition(params->f_remain, set_position(725, 1000));
}

void update_score(struct game * params)
{
    params->f_best_score = sfText_create();
    sfText_setString(params->f_best_score, "Best Score :");
    sfText_setFont(params->f_best_score, params->font_armada);
    sfText_setColor(params->f_best_score, sfWhite);
    sfText_setCharacterSize(params->f_best_score, 50);
    sfText_setPosition(params->f_best_score, set_position(475, 1000));
    params->f_score = sfText_create();
    sfText_setString(params->f_score, "Your Score :");
    sfText_setFont(params->f_score, params->font_armada);
    sfText_setColor(params->f_score, sfWhite);
    sfText_setCharacterSize(params->f_score, 50);
    sfText_setPosition(params->f_score, set_position(1050, 1000));
    update_score_next(params);
}

void update_score_next(struct game *params)
{
    params->t_best_score = sfText_create();
    sfText_setString(params->t_best_score, get_str(params->best_score));
    sfText_setFont(params->t_best_score, params->font_armada);
    sfText_setColor(params->t_best_score, sfWhite);
    sfText_setCharacterSize(params->t_best_score, 50);
    sfText_setPosition(params->t_best_score, set_position(825, 1000));
    params->t_score = sfText_create();
    sfText_setString(params->t_score, get_str(params->score));
    sfText_setFont(params->t_score, params->font_armada);
    sfText_setColor(params->t_score, sfWhite);
    sfText_setCharacterSize(params->t_score, 50);
    sfText_setPosition(params->t_score, set_position(1400, 1000));
}