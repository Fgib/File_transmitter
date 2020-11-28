/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** events_manager
*/

#include "../include/my_hunter.h"

void manage_clicks2(sfRenderWindow *window, sfEvent event, \
struct game *params)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    if (event.type == sfEvtMouseMoved) {
        params->mouse_coo = set_position(event.mouseMove.x, event.mouseMove.y);
    }
    manage_events2(params, event, window);
}

void manage_events2(struct game *params, sfEvent event, \
sfRenderWindow *window)
{
    if (params->windows_step == 0) {
        start_menu_event2(event, params);
        return;
    }
    if (params->windows_step == 1) {
        game_event2(event, params);
        return;
    }
    if (params->windows_step == 2) {
        end_menu_event2(event, params);
        return;
    }
    if (params->windows_step == 3) {
        settings_menu_event2(event, params, window);
    }
    if (params->windows_step > 5)
        return;
}

void start_menu_event2(sfEvent event, struct game *params)
{
    if (params->windows_step != 0 || event.type != sfEvtMouseButtonPressed)
        return;
    if (event.mouseButton.x > params->w_width_x / 2 - params->play_sx / 2 \
&& event.mouseButton.x < params->w_width_x / 2 + params->play_sx / 2 \
&& event.mouseButton.y > params->w_height_y / 2 - params->play_sy / 2 \
&& event.mouseButton.y < params->w_height_y / 2 + params->play_sy / 2) {
        params->windows_step++;
        return;
    }
    if (event.mouseButton.x > 1180 && event.mouseButton.y < 100) {
        params->windows_step = 3;
    }
    if (event.mouseButton.x < 100 && event.mouseButton.y < 100) {
        params->windows_step += 5;
        return;
    }
}

void game_event2(sfEvent event, struct game *params)
{
    if (params->windows_step != 1 || event.type != sfEvtMouseButtonPressed)
        return;
    if (event.mouseButton.x >= params->lego->coo.x \
&& event.mouseButton.x <= params->lego->coo.x + 125 \
&& event.mouseButton.y >= params->lego->coo.y \
&& event.mouseButton.y <= params->lego->coo.y + 125) {
        params->score++;
        respawn_lego2(params);
        return;
    }
}

void end_menu_event2(sfEvent event, struct game *params)
{
    if (params->windows_step != 2 || event.type != sfEvtMouseButtonPressed)
        return;
    if (event.mouseButton.x > 480\
&& event.mouseButton.x < 800\
&& event.mouseButton.y > 225\
&& event.mouseButton.y < 405) {
        params->windows_step = 0;
        initialize_settings2(params, 1280, 720);
        return;
    }
    if (event.mouseButton.x < 100 && event.mouseButton.y < 100) {
        params->windows_step += 5;
        return;
    }
}