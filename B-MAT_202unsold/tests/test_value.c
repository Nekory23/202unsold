/*
** EPITECH PROJECT, 2021
** 202unsold
** File description:
** test_value
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "unsold.h"

Test(results, test_x_y)
{
    double tab[6][6] = {
        {0.100, 0.080, 0.060, 0.040, 0.020},
        {0.083, 0.067, 0.050, 0.033, 0.017},
        {0.067, 0.053, 0.040, 0.027, 0.013},
        {0.050, 0.040, 0.030, 0.020, 0.010},
        {0.033, 0.027, 0.020, 0.013, 0.007}
    };
    data_t s;

    compute(&s, 60, 70);
    for (int i = 0; i != 5; i++)
        for (int j = 0; j != 5; j++)
        cr_assert_float_eq(s.tab[i][j], tab[i][j], 0.001);
}

Test(results, test_xlaw)
{
    double tab[6][6] = {
        {0.100, 0.080, 0.060, 0.040, 0.020, 0.300},
        {0.083, 0.067, 0.050, 0.033, 0.017, 0.250},
        {0.067, 0.053, 0.040, 0.027, 0.013, 0.200},
        {0.050, 0.040, 0.030, 0.020, 0.010, 0.150},
        {0.033, 0.027, 0.020, 0.013, 0.007, 0.100},
        {0.333, 0.267, 0.200, 0.133, 0.067, 1.000}
    };
    data_t s;

    compute(&s, 60, 70);
    for (int i = 0; i != 5; i++)
        cr_assert_float_eq(s.tab[5][i], tab[5][i], 0.001);
}

Test(results, test_ylaw)
{
    double tab[6][6] = {
        {0.100, 0.080, 0.060, 0.040, 0.020, 0.300},
        {0.083, 0.067, 0.050, 0.033, 0.017, 0.250},
        {0.067, 0.053, 0.040, 0.027, 0.013, 0.200},
        {0.050, 0.040, 0.030, 0.020, 0.010, 0.150},
        {0.033, 0.027, 0.020, 0.013, 0.007, 0.100},
        {0.333, 0.267, 0.200, 0.133, 0.067, 1.000}
    };
    data_t s;

    compute(&s, 60, 70);
    for (int i = 0; i != 6; i++)
        cr_assert_float_eq(s.tab[i][5], tab[i][5], 0.001);
}

Test(results, test_zlaw)
{
    double tab[9] = {0.100, 0.163, 0.193, 0.193, 0.167, 0.100, 0.053, 0.023, 0.007};
    data_t s;

    compute(&s, 60, 70);
    compute_z(&s);
    for (int i = 0; i != 9; i++)
        cr_assert_float_eq(s.tabz[i], tab[i], 0.001);
}

Test(results, var_and_expected_x)
{
    double expected = 23.3;
    double variance = 155.6;
    data_t s;

    compute(&s, 60, 70);
    compute_z(&s);
    compute_other_var(&s);
    cr_assert_float_eq(s.x[0], expected, 0.1);
    cr_assert_float_eq(s.x[1], variance, 0.1);
}

Test(results, var_and_expected_y)
{
    double expected = 25.0;
    double variance = 175.0;
    data_t s;

    compute(&s, 60, 70);
    compute_z(&s);
    compute_other_var(&s);
    cr_assert_float_eq(s.y[0], expected, 0.1);
    cr_assert_float_eq(s.y[1], variance, 0.1);
}

Test(results, var_and_expected_z)
{
    double expected = 48.3;
    double variance = 330.6;
    data_t s;

    compute(&s, 60, 70);
    compute_z(&s);
    compute_other_var(&s);
    cr_assert_float_eq(s.z[0], expected, 0.1);
    cr_assert_float_eq(s.z[1], variance, 0.1);
}