/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdlib.h>
#include <string.h>
#include "unsold.h"

int main(int ac, char **av)
{
    int nb;
    int nb2;
    data_t s;

    if (ac == 2 && strcmp(av[1], "-h") == TRUE)
        return display_help();
    if (error_handling(ac, av))
        return ERROR;
    nb = atoi(av[1]);
    nb2 = atoi(av[2]);
    if (compute(&s, nb, nb2))
        return FAIL;
    compute_z(&s);
    compute_other_var(&s);
    print_res(&s);
    return SUCCESS;
}