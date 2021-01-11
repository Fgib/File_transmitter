/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-florian.gibault
** File description:
** my_collision
*/

#include "my_runner.h"

char my_collision(struct player *pl, struct obstacle *obs)
{
    if (pl->coo.x >= obs->coo.x && pl->coo.x <= obs->coo.x + 100\
    && pl->coo.y >= obs->coo.y && pl->coo.y <= obs->coo.y + 680) {
        return ('y');
    }
    if (pl->coo.x + 100 >= obs->coo.x && pl->coo.x + 100<= obs->coo.x + 100\
    && pl->coo.y >= obs->coo.y && pl->coo.y <= obs->coo.y + 680) {
        return ('y');
    }
    if (pl->coo.x >= obs->coo.x && pl->coo.x <= obs->coo.x + 100\
    && pl->coo.y + 100 >= obs->coo.y && pl->coo.y + 100 <= obs->coo.y + 680) {
        return ('y');
    }
    if (pl->coo.x + 100 >= obs->coo.x && pl->coo.x + 100 <= obs->coo.x + 100\
    && pl->coo.y + 100 >= obs->coo.y && pl->coo.y + 100 <= obs->coo.y + 680) {
        return ('y');
    }
    return ('n');
}

char my_coin_collision(struct player *pl, struct money *obs)
{
    if ((pl->coo.x >= obs->coo.x && pl->coo.x <= obs->coo.x + 48\
    && pl->coo.y >= obs->coo.y && pl->coo.y <= obs->coo.y + 48) ||
    (pl->coo.x + 48 >= obs->coo.x && pl->coo.x + 48 <= obs->coo.x + 48\
    && pl->coo.y >= obs->coo.y && pl->coo.y <= obs->coo.y + 48) ||
    (pl->coo.x >= obs->coo.x && pl->coo.x <= obs->coo.x + 48\
    && pl->coo.y + 48 >= obs->coo.y && pl->coo.y + 48 <= obs->coo.y + 48) ||
    (pl->coo.x + 48 >= obs->coo.x && pl->coo.x + 48 <= obs->coo.x + 48\
    && pl->coo.y + 48 >= obs->coo.y && pl->coo.y + 48 <= obs->coo.y + 48)) {
        return ('y');
    } else if ((obs->coo.x >= pl->coo.x && obs->coo.x <= pl->coo.x + 156\
    && obs->coo.y >= pl->coo.y && obs->coo.y <= pl->coo.y + 100) ||
    ((obs->coo.x + 48 >= pl->coo.x && obs->coo.x + 48 <= pl->coo.x + 156\
    && obs->coo.y >= pl->coo.y && obs->coo.y <= pl->coo.y + 100)) ||
    ((obs->coo.x >= pl->coo.x && obs->coo.x <= pl->coo.x + 156\
    && obs->coo.y + 48 >= pl->coo.y && obs->coo.y + 48<= pl->coo.y + 100)) ||
    ((obs->coo.x + 48 >= pl->coo.x && obs->coo.x + 48 <= pl->coo.x + 156\
    && obs->coo.y + 48 >= pl->coo.y && obs->coo.y + 48 <= pl->coo.y + 100))) {
        return ('y');
    } else
        return ('n');
}