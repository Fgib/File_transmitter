/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-florian.gibault
** File description:
** load_settings_bis
*/

#include "my_runner.h"

struct obstacle *initialize_obstacle(void)
{
    struct obstacle *obstacle_s = malloc(sizeof(struct obstacle));
    obstacle_s->vel = -7.0;
    obstacle_s->size.x = 100;
    obstacle_s->size.y = 680;
    obstacle_s->skin_id = 0;
    return (obstacle_s);
}

struct money *initialize_coins(int i)
{
    struct money *coin_s = malloc(sizeof(struct money));

    coin_s->vel = -7;
    coin_s->status = 1;
    coin_s->skin_id = 0;
    coin_s->coo.x = 500 + 48 * 5 * i;
    coin_s->coo.y = sinus(i * 25) * 150 + 500;
    return (coin_s);
}

void initialize_texts(struct game *params)
{
    params->setxt = malloc(sizeof(struct set_txt));
    params->setxt->bool_cheat = 0;
    params->setxt->bool_level = 2;
    params->game_ov = sfText_create();
    params->shiel_t = sfText_create();
    params->frics_t = sfText_create();
    params->lives_t = sfText_create();
    params->title_t = sfText_create();
    params->cstom_t = sfText_create();
    params->setxt->easy = sfText_create();
    params->setxt->hard = sfText_create();
    params->setxt->medium = sfText_create();
    params->setxt->cheat_on = sfText_create();
    params->setxt->cheat_off = sfText_create();
    params->setxt->tr_on = initialize_trigger(0, 1100, 490);
    params->setxt->tr_off = initialize_trigger(1, 1100, 590);
    params->setxt->tr_eas = initialize_trigger(1, 400, 440);
    params->setxt->tr_med = initialize_trigger(0, 400, 540);
    params->setxt->tr_har = initialize_trigger(0, 400, 640);
    params->buffer = sfSoundBuffer_createFromFile("assets/sound/arc.ogg");
}