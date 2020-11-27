/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** score_drawer
*/

#include "../include/my_hunter.h"

void print_score(struct game *params)
{
   
}

void load_scoreboard(struct game *params)
{
    params->t_score = sfText_create();
    sfText_setString(params->t_score, get_str(params->score));
    sfText_setFont(params->t_score, params->font_armada);
    sfText_setColor(params->t_score, sfWhite);
    sfText_setCharacterSize(params->t_score, 50);
    sfText_setPosition(params->t_score, set_position(900, 25));
}