/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** event_manager
*/

#include "include/my_runner.h"

void manage_events(sfRenderWindow *window, sfEvent event, struct game *params)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    params->game_step = 0;

    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeySpace) {
            params->player->vel = -1940;
        }
        if (event.key.code == sfKeyM) {
            params->player->vel = -2770;
        }/*
        if (event.key.code == sfKeyLeft) {
            params->player->coo.x -= 2;
        }*/
    }
}