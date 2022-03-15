/*
** EPITECH PROJECT, 2021
** unit test
** File description:
** error handling
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "unsold.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(error_handling, not_enough_args, .init=redirect_all_stdout)
{
    int ac = 1;
    char *av[3] = {"\0", "hey", "56"};

    error_handling(ac, av);
    cr_assert_stderr_eq_str("Error: too many or few arguments (please retry with -h)\n", "");
}

Test(error_handling, too_many_args, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[3] = {"\0", "hey", "56"};

    error_handling(ac, av);
    cr_assert_stderr_eq_str("Error: too many or few arguments (please retry with -h)\n", "");
}

Test(error_handling, all_arg_letters, .init=redirect_all_stdout)
{
    int ac = 3;
    char *av[3] = {"\0", "hey", "hey"};

    error_handling(ac, av);
    cr_assert_stderr_eq_str("Error: Arguments must be numbers (please retry with -h)\n", "");
}

Test(error_handling, first_arg_letters, .init=redirect_all_stdout)
{
    int ac = 3;
    char *av[3] = {"\0", "hey", "56"};

    error_handling(ac, av);
    cr_assert_stderr_eq_str("Error: Arguments must be numbers (please retry with -h)\n", "");
}

Test(error_handling, second_arg_letters, .init=redirect_all_stdout)
{
    int ac = 3;
    char *av[3] = {"\0", "56", "hey"};

    error_handling(ac, av);
    cr_assert_stderr_eq_str("Error: Arguments must be numbers (please retry with -h)\n", "");
}

Test(error_handling, first_too_small, .init=redirect_all_stdout)
{
    int ac = 3;
    char *av[3] = {"\0", "40", "56"};

    error_handling(ac, av);
    cr_assert_stderr_eq_str("Error: Numbers must be greater than 50 (please retry with -h)\n", "");
}

Test(error_handling, second_too_small, .init=redirect_all_stdout)
{
    int ac = 3;
    char *av[3] = {"\0", "56", "30"};

    error_handling(ac, av);
    cr_assert_stderr_eq_str("Error: Numbers must be greater than 50 (please retry with -h)\n", "");
}

Test(error_handling, all_too_small, .init=redirect_all_stdout)
{
    int ac = 3;
    char *av[3] = {"\0", "16", "30"};

    error_handling(ac, av);
    cr_assert_stderr_eq_str("Error: Numbers must be greater than 50 (please retry with -h)\n", "");
}