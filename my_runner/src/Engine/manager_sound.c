/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-florian.gibault
** File description:
** manager_sound
*/

#include "my_runner.h"

void sound_boss(struct game *params)
{
    params->musique = sfMusic_createFromFile("assets/sound/musix.ogg");
    sfMusic_play(params->musique);
    sfMusic_setLoop(params->musique, sfTrue);
    sfMusic_setVolume(params->musique, 25);
    params->arc = sfSound_create();
    sfSound_setBuffer(params->arc, params->buffer);
}

void electrucute(struct game *params)
{
    sfSound_play(params->arc);
}