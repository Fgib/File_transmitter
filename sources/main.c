/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** main
*/

#include "include/my_hunter.h"

int launcher1(void)
{
    sfRenderWindow *window = create_my_window(1920, 1080);
    sfEvent event;
    run_window(window, event, 1920, 1080);
    return 0;
}

int launcher2(void)
{
    sfRenderWindow *window = create_my_window(1280, 720);
    sfEvent event;
    run_window(window, event, 1280, 720);
    return 0;
}

int launcher3(void)
{
    sfRenderWindow *window = create_my_window(720, 480);
    sfEvent event;
    run_window(window, event, 720, 480);
    return 0;
}

void print_helper(void)
{
    write(1, "An hunter game rendered in a CSFML window\n\n", 44);
    write(1, "USAGE\n\t./my_hunter [OPTION]\n\n", 29);
    write(1, "OPTION\n", 7);
    write(1, "\t1\tfor a game in the best resolution,"
    " weak computer not recomended\n", 67);
    write(1, "\t2\tfor a game in a normal resolution\n", 37);
    write(1, "\t3\tfor a game in the lowest resolution,"
    " fits with any computer\n\n", 64);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        print_helper();
        return (84);
    }
    if (my_getnbr(argv[1]) == 1) {
        launcher1();
        return (0);
    }
    if (my_getnbr(argv[1]) == 2) {
        launcher2();
        return (0);
    }
    if (my_getnbr(argv[1]) == 3) {
        launcher3();
        return (0);
    }
    print_helper();
    return (84);
}