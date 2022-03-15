/*
** EPITECH PROJECT, 2021
** print res
** File description:
** print_res
*/

#include <stdio.h>
#include "unsold.h"

static const char SP[] = "----------------------------------------";

static void display_z(data_t *s)
{
    for (int i = 0; i != 9; i++) {
        if (i == 8) {
            printf("%.3f", s->tabz[i]);
            continue;
        }
        printf("%.3f\t", s->tabz[i]);
    }
}

void print_res(data_t *s)
{
    printf("%s%s\n", SP, SP);
    printf("    \tX=10\tX=20\tX=30\tX=40\tX=50\tY law\n");
    for (int i = 0, x = 10; i != 6; i++, x += 10) {
        if (x == 60)
            printf("X law\t");
        else
            printf("Y=%d\t", x);
        printf("%.3f\t%.3f\t%.3f", s->tab[i][0], s->tab[i][1], s->tab[i][2]);
        printf("\t%.3f\t%.3f\t%.3f", s->tab[i][3], s->tab[i][4], s->tab[i][5]);
        printf("\n");
    }
    printf("%s%s\nz\t20\t30\t40\t50\t60\t70\t80\t90\t100\np(Z=z)\t", SP, SP);
    display_z(s);
    printf("\n%s%s\n", SP, SP);
    printf("expected value of X:\t%.1f\n", s->x[0]);
    printf("variance of X:\t\t%.1f\n", s->x[1]);
    printf("expected value of Y:\t%.1f\n", s->y[0]);
    printf("variance of Y:\t\t%.1f\n", s->y[1]);
    printf("expected value of Z:\t%.1f\n", s->z[0]);
    printf("variance of Z:\t\t%.1f\n", s->z[1]);
    printf("%s%s\n", SP, SP);
}