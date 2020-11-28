/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** maths
*/

#include "include/my_hunter.h"

int random_gen(int min, int max)
{
    int result;
    int low_num = 0;
    int hig_num = 0;

    if (min < max) {
        low_num = min;
        hig_num = max + 1;
    } else {
        low_num = min + 1;
        hig_num = min;
    }
    time(NULL);
    result = rand() % (hig_num - low_num) + low_num;
    return (result);
}

float tange(double x)
{
    double in_rad = x * M_PI / 180;
    return (tan(in_rad));
}

float cosinus(double x)
{
    double in_rad = x * M_PI / 180;
    return (cos(in_rad));
}

sfVector2f set_position(int x, int y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}