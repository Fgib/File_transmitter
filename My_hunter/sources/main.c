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
    run_window2(window, event, 1280, 720);
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
    " fits with any computer [WORK IN PROGRESS]"
    " not available yet\n\n", 100);
}

void print_lore(void)
{
    write(1, "\nIn this game, your goal is to destroy LEGOs send by the", 56);
    write(1, " green team, if your side were hit three times by their", 55);
    write(1, " projectiles, you will loose.\n", 30);
    write(1, "This game is optimised to run in 1080p, but i realised", 55);
    write(1, " that some of my mate can't run it on their computer so", 55);
    write(1, " i made a 720p version (but this resolution isn't", 49);
    write(1, " optimised).\n\n", 14);
    write(1, "CREDITS :\n", 10);
    write(1, "\tGame develloper : Florian Gibault\n", 35);
    write(1, "\tTexture & spritesheet designer : Florian Gibault\n", 50);
    write(1, "\tBug maker : Florian Gibault\n", 29);
    write(1, "\tBug resolver : Alann Schnegg\n", 30);
    write(1, "\tInsane ideas creators : Lisa Glaziou & Paul Ancey\n", 51);
    write(1, "\tMoral support : Lisa Glaziou & Paul Ancey & Bryan Zakka", 56);
    write(1, "\n\tMakefile inspiration : Hugo Bach & Maxime Gravin\n\n", 52);
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
    if (argv[1][0] == '-') {
        print_lore();
        return (0);
    }
    print_helper();
    return (84);
}