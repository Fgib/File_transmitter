/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** events_manager
*/

#include "../include/my_hunter.h"

void manage_clicks3(sfRenderWindow *window, sfEvent event, struct game *params)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    if (event.type == sfEvtMouseMoved) {
        params->mouse_coo = set_position(event.mouseMove.x, event.mouseMove.y);
    }
    manage_events3(params, event);
}

void manage_events3(struct game *params, sfEvent event)
{
    if (params->windows_step == 0) {
        start_menu_event3(event, params);
        return;
    }
    if (params->windows_step == 1) {
        game_event3(event, params);
        return;
    }
    if (params->windows_step == 2) {
        end_menu_event3(event, params);
        return;
    }
    if (params->windows_step > 5)
        return;
}

void start_menu_event3(sfEvent event, struct game *params)
{
    if (params->windows_step != 0 || event.type != sfEvtMouseButtonPressed)
        return;
    if (event.mouseButton.x > params->w_width_x / 2 - params->play_sx / 2 && event.mouseButton.x < params->w_width_x / 2 + params->play_sx / 2 && event.mouseButton.y > params->w_height_y / 2 - params->play_sy / 2 && event.mouseButton.y < params->w_height_y / 2 + params->play_sy / 2) {
        params->windows_step++;
        return;
    }
    if (event.mouseButton.x > 1770 && event.mouseButton.y < 150) {
        params->windows_step = 3;
    }
}

void game_event3(sfEvent event, struct game *params)
{
    if (params->windows_step != 1 || event.type != sfEvtMouseButtonPressed)
        return;
    if (event.mouseButton.x >= params->lego->coo.x && event.mouseButton.x <= params->lego->coo.x + 125 && event.mouseButton.y >= params->lego->coo.y && event.mouseButton.y <= params->lego->coo.y + 125) {
        params->score++;
        respawn_lego3(params);
        return;
    }
}

void end_menu_event3(sfEvent event, struct game *params)
{
    if (params->windows_step != 2 || event.type != sfEvtMouseButtonPressed)
        return;
    if (event.mouseButton.x > params->w_width_x / 2 - params->play_sx / 2 && event.mouseButton.x < params->w_width_x / 2 + params->play_sx / 2 && event.mouseButton.y > params->w_height_y / 2 - params->play_sy / 2 && event.mouseButton.y < params->w_height_y / 2 + params->play_sy / 2) {
        params->windows_step--;
        initialize_settings3(params, 1920, 1080);
        return;
    }
    if (event.mouseButton.x < 150 && event.mouseButton.y < 150) {
        params->windows_step += 5;
        return;
    }
}