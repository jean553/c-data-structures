#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "vector.h"

/**
 *
 */
START_TEST(test_create)
{
    Vector first_list = create(10);
    ck_assert_int_eq(at(&first_list, 0), 0);
    ck_assert_int_eq(at(&first_list, 9), 0);

    ck_assert_int_eq(size(&first_list), 10);
}
END_TEST

/**
 *
 */
START_TEST(test_push)
{
    Vector first_list = create(10);
    push(&first_list, 5);
    push(&first_list, 50);

    ck_assert_int_eq(at(&first_list, 0), 0);
    ck_assert_int_eq(at(&first_list, 10), 5);
    ck_assert_int_eq(at(&first_list, 11), 50);

    ck_assert_int_eq(size(&first_list), 12);

    Vector second_list = create(0);
    push(&second_list, 25);
    push(&second_list, 35);

    ck_assert_int_eq(at(&second_list, 0), 25);
    ck_assert_int_eq(at(&second_list, 1), 35);

    ck_assert_int_eq(size(&second_list), 2);
}
END_TEST

/**
 *
 */
START_TEST(test_size)
{
    Vector first_list = create(0);

    ck_assert_int_eq(size(&first_list), 0);
}
END_TEST

/**
 *
 */
START_TEST(test_resize)
{
    /* increase the size */

    Vector first_list = create(5);
    push(&first_list, 10);
    ck_assert_int_eq(size(&first_list), 6);

    resize(&first_list, 15);
    ck_assert_int_eq(size(&first_list), 15);
    ck_assert_int_eq(at(&first_list, 14), 0);

    push(&first_list, 20);
    ck_assert_int_eq(at(&first_list, 15), 20);
    ck_assert_int_eq(size(&first_list), 16);

    /* decrease the size */

    Vector second_list = create(0);
    push(&second_list, 10);
    push(&second_list, 20);
    push(&second_list, 30);
    push(&second_list, 40);
    push(&second_list, 50);
    ck_assert_int_eq(size(&second_list), 5);

    resize(&second_list, 2);
    ck_assert_int_eq(size(&second_list), 2);
    ck_assert_int_eq(at(&second_list, 0), 10);
    ck_assert_int_eq(at(&second_list, 1), 20);

    push(&second_list, 100);
    ck_assert_int_eq(at(&second_list, 2), 100);
    ck_assert_int_eq(size(&second_list), 3);
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
    tcase_add_test(tcase, test_size);
    tcase_add_test(tcase, test_resize);

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
