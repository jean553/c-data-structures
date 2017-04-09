#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "vector.h"

/**
 *
 */
START_TEST(test_create)
{
    /* TODO: check the size and access */

    Vector first_list = create(10);
    ck_assert_int_eq(at(&first_list, 0), 0);
    ck_assert_int_eq(at(&first_list, 9), 0);
}
END_TEST

/**
 *
 */
START_TEST(test_push)
{
    /* TODO: check the size and access */

    Vector first_list = create(10);
    push(&first_list, 5);
    push(&first_list, 50);

    ck_assert_int_eq(at(&first_list, 0), 0);
    ck_assert_int_eq(at(&first_list, 10), 5);
    ck_assert_int_eq(at(&first_list, 11), 50);

    Vector second_list = create(0);
    push(&second_list, 25);
    push(&second_list, 35);

    ck_assert_int_eq(at(&second_list, 0), 25);
    ck_assert_int_eq(at(&second_list, 1), 35);
}
END_TEST

/**
 *
 */
Suite* vector_suite()
{
    Suite *suite = suite_create("vector");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_push);

    suite_add_tcase(suite, tcase);

    return suite;
}

/**
 *
 */
int main(int argc, char *argv[])
{
    Suite *suite = vector_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
