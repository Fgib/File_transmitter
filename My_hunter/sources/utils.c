/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-florian.gibault
** File description:
** utils
*/

#include "include/my_hunter.h"

int score_debugger(int nbr)
{
    int n = 1;
    int po = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= po) {
        n++;
        if (po > 214748364)
            break;
        po *= 10;
    }
    return (n);
}

char *get_str(int val)
{
    int len = score_debugger(val);
    char *result = malloc(sizeof(char) * len);

    result[len] = '\0';
    while (len--) {
        result[len] = val %10 + 48;
        val = val / 10;
    }
    return (result);
}

int my_strlen(char const *str)
{
    int cpt = 0;

    while (str[cpt] != '\0') {
        cpt ++;
    }
    return (cpt);
}

int checker_teker(int negativ_count, const char *str, long v)
{
    for (int i = 0; str[i] < 48 || str[i] >= 58; i++) {
        if (str[i] == '-') {
            negativ_count++;
        }
    }
    if (negativ_count % 2 == 1 && negativ_count != 0) {
        v = -1 * v;
    }
    if (v == -2147483648) {
        return (v);
    }
    else if (v == 2147483648) {
        return (0);
    }
    return (v);
}

int my_getnbr(char const *str)
{
    int negativ_count = 0;
    int lenght_char = 0;
    int cpt_nbr = 0;
    long var_out = 0;

    lenght_char = my_strlen(str) + 1;
    while (str[cpt_nbr] != '\0') {
        if (str[cpt_nbr] >= 48 && str[cpt_nbr] < 58) {
            var_out = 10 * var_out + (str[cpt_nbr] - 48);
        }
        else if (str[cpt_nbr] >= 65 && str[cpt_nbr] < 123) {
            return (var_out);
        }
        if (var_out > 2147483648 || var_out < -2147483648) {
            return (0);
        }
        cpt_nbr++;
    }
    return (checker_teker(negativ_count, str, var_out));
}