/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** error_handling
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "unsold.h"

static bool display_error(const char *error)
{
    write(2, error, strlen(error));
    return true;
}

static bool check_number(char *av)
{
    for (int i = 0; av[i] != '\0'; i++)
        if (av[i] >= '0' && av[i] <= '9')
            continue;
        else
            return true;
    return false;
}

bool error_handling(int ac, char **av)
{
    int nb;
    int nb2;

    if (ac != 3)
        return display_error(ARG);
    if (check_number(av[1]) || check_number(av[2]))
        return display_error(ARGNBR);
    nb = atoi(av[1]);
    nb2 = atoi(av[2]);
    if (nb < 50 || nb2 < 50)
        return display_error(NBR);
    return false;
}