/*
** EPITECH PROJECT, 2021
** compute
** File description:
** compute
*/

#include <math.h>
#include <stdio.h>
#include "unsold.h"

static data_t *fill_tab(data_t *s)
{
    for (int i = 0; i != 5; i++)
        for (int j = 0; j != 5; j++)
            s->tab[i][5] += s->tab[i][j];
    for (int i = 0; i != 5; i++)
        for (int j = 0; j != 5; j++)
            s->tab[5][i] += s->tab[j][i];
    for (int i = 0; i != 5; i++)
        s->tab[5][5] += s->tab[i][5];
    return s;
}

int compute(data_t *s, int nb, int nb2)
{
    int x = 10;
    int y = 10;
    double temp;
    double temp2;

    for (int i = 0; i != 5; i++, y += 10) {
        for (int j = 0; j != 5; j++, x += 10) {
            temp = (nb - x) * (nb2 - y);
            temp2 = ((5 * nb) - 150) * ((5 * nb2) - 150);
                if ((int) temp2 == 0)
                    return FAIL;
            s->tab[i][j] = temp / temp2;
        }
        x = 10;
    }
    s = fill_tab(s);
    return SUCCESS;
}

void compute_z(data_t *s)
{
    s->tabz[0] = s->tab[0][0];
    s->tabz[1] = s->tab[0][1] + s->tab[1][0];
    s->tabz[2] = s->tab[0][2] + s->tab[1][1] + s->tab[2][0];
    s->tabz[3] = s->tab[0][3] + s->tab[1][2] + s->tab[2][1] + s->tab[3][0];
    s->tabz[4] = s->tab[0][4] + s->tab[1][3] + s->tab[2][2] + s->tab[3][1];
    s->tabz[4] += s->tab[4][0];
    s->tabz[5] = s->tab[1][4] + s->tab[2][3] + s->tab[3][2] + s->tab[4][1];
    s->tabz[6] = s->tab[2][4] + s->tab[3][3] + s->tab[4][2];
    s->tabz[7] = s->tab[3][4] + s->tab[4][3];
    s->tabz[8] = s->tab[4][4];
}

void compute_other_var(data_t *s)
{
    for (int i = 0, x = 10; i != 5; i++, x += 10) {
        s->x[0] += x * s->tab[5][i];
        s->y[0] += x * s->tab[i][5];
    }
    for (int i = 0, x = 10; i != 5; i++, x += 10) {
        s->x[1] += ((x - s->x[0]) * (x - s->x[0])) * s->tab[5][i];
        s->y[1] += ((x - s->y[0]) * (x - s->y[0])) * s->tab[i][5];
    }
    s->z[0] = s->x[0] + s->y[0];
    s->z[1] = s->x[1] + s->y[1];
}