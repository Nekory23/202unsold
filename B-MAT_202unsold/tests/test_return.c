/*
** EPITECH PROJECT, 2021
** B-MAT_202unsold
** File description:
** test_return
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "unsold.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(return_value, success, .exit_code=0, .init=redirect_all_stdout)
{
    display_help();
}

Test(return_value, no_errors, .exit_code=0, .init=redirect_all_stdout)
{
    int ac = 3;
    char *av[3] = {"\0", "60\0", "70\0"};

    error_handling(ac, av);
}