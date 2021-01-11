/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_click
*/

#include "my_runner.h"

char click_b(sfEvent event, struct button *target)
{
    int hit_x = event.mouseButton.x;
    int hit_y = event.mouseButton.y;

    if (hit_x >= target->coo.x && hit_x <= target->coo.x + target->size.x &&
    hit_y >= target->coo.y && hit_y <= target->coo.y + target->size.y) {
        return ('y');
    }
    return ('n');
}

char click_t(sfEvent event, struct trigger *target)
{
    int hit_x = event.mouseButton.x;
    int hit_y = event.mouseButton.y;

    if (hit_x >= target->coo.x && hit_x <= target->coo.x + target->size.x &&
    hit_y >= target->coo.y && hit_y <= target->coo.y + target->size.y) {
        return ('y');
    }
    return ('n');
}

char press_s(struct game *params)
{
    if (params->event.type == sfEvtKeyPressed)
        if (params->event.key.code == sfKeySpace)
            return ('y');
    return ('n');
}