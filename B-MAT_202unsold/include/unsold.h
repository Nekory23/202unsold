/*
** EPITECH PROJECT, 2021
** unsold
** File description:
** unsold
*/

// Include //
#include <stdbool.h>

#ifndef UNSOLD_H_
#define UNSOLD_H_

// Static const INT //
static const int SUCCESS = 0;
static const int ERROR = 84;
static const int FAIL = 1;
static const int TRUE = 0;
static const int FALSE = 1;

// Static const CHAR //
static const char ARG[] = "Error: too many or few arguments (please retry with -h)\n";
static const char NBR[] = "Error: Numbers must be greater than 50 (please retry with -h)\n";
static const char ARGNBR[] = "Error: Arguments must be numbers (please retry with -h)\n";

// Structure //
typedef struct data_s
{
    double tab[6][6];
    double tabz[9];
    double x[2];
    double y[2];
    double z[2];
} data_t;

// Proto //
bool error_handling(int ac, char **av);
int compute(data_t *s, int nb, int nb2);
void compute_z(data_t *s);
void compute_other_var(data_t *s);
void print_res(data_t *s);
int display_help();

#endif /* !UNSOLD_H_ */