/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** events_manager_bis
*/

#include "../include/my_hunter.h"

void settings_menu_event2(sfEvent event, struct game *params, \
sfRenderWindow *window)
{
    if (params->windows_step != 3 || event.type != sfEvtMouseButtonPressed)
        return;
    if (event.mouseButton.y > 480 && event.mouseButton.y < 586) {
        if (event.mouseButton.x > 320 && event.mouseButton.x < 520) {
            dispose(window);
            free(params);
            launcher1();
        }
        if (event.mouseButton.x > 540 && event.mouseButton.x < 740) {
            dispose(window);
            free(params);
            launcher2();
        }
        if (event.mouseButton.x > 760 && event.mouseButton.x < 960) {
            dispose(window);
            free(params);
            launcher3();
        }
    }
}