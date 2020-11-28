/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** spritesheet_manager
*/

#include "../include/my_hunter.h"

sfIntRect sprite_info(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.height = height;
    rect.width = width;
    rect.left = left;
    rect.top = top;
    return (rect);
}

sfIntRect text_lego_rank(struct game *params)
{
    if (params->lego->skin_id > 48)
        params->lego->skin_id = 0;
    return (sprite_info(0, 125 * params->lego->skin_id, 125, 125));
}

sfIntRect text_title_rank(struct game *params)
{
    if (params->title->skin_id > 23)
        params->title->skin_id = 0;
    return (sprite_info(params->title->skin_id * 220, 0, 1070, 220));
}