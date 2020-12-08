/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** my_get
*/

#include "include/my_runner.h"

sfSprite *get_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

sfIntRect get_intrect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.height = height;
    rect.width = width;
    rect.left = left;
    rect.top = top;
    return (rect);
}

sfVector2f get_vector(double x, double y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}