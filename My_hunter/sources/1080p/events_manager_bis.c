/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** events_manager_bis
*/

#include "../include/my_hunter.h"

void settings_menu_event(sfEvent event, struct game *params, \
sfRenderWindow *window)
{
    if (params->windows_step != 3 || event.type != sfEvtMouseButtonPressed)
        return;
    if (event.mouseButton.y > 720 && event.mouseButton.y < 880) {
        if (event.mouseButton.x > 480 && event.mouseButton.x < 780) {
            free(params);
            dispose(window, params);
            launcher1();
            return;
        }
        if (event.mouseButton.x > 810 && event.mouseButton.x < 1010) {
            free(params);
            dispose(window, params);
            launcher2();
            return;
        }
    }
}