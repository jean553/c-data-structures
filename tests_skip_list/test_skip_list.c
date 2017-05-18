#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "skip_list.h"

/**
 *
 */
START_TEST(test_create)
{
    SkipList first_list = create(5, 10);
    SkipList second_list = create(10, 20);
    SkipList third_list = create(15, 30);
}
END_TEST

/**
 *
 */
START_TEST(test_insert)
{
    SkipList first_list = create(5, 10);
    insert(&first_list, 6, 20);
    insert(&first_list, 7, 30);
    insert(&first_list, 10, 40);
    insert(&first_list, 20, 50);

    ck_assert_int_eq(at(&first_list, 5), 10);
    ck_assert_int_eq(at(&first_list, 6), 20);
    ck_assert_int_eq(at(&first_list, 7), 30);
    ck_assert_int_eq(at(&first_list, 10), 40);
    ck_assert_int_eq(at(&first_list, 20), 50);

    SkipList second_list = create(5, 10);
    insert(&second_list, 4, 20);
    insert(&second_list, 3, 30);
    insert(&second_list, 2, 40);
    insert(&second_list, 0, 50);

    ck_assert_int_eq(at(&second_list, 5), 10);
    ck_assert_int_eq(at(&second_list, 4), 20);
    ck_assert_int_eq(at(&second_list, 3), 30);
    ck_assert_int_eq(at(&second_list, 2), 40);
    ck_assert_int_eq(at(&second_list, 0), 50);

    SkipList third_list = create(5, 10);
    insert(&third_list, 5, 20);

    ck_assert_int_eq(at(&third_list, 5), 20);

    SkipList fourth_list = create(5, 10);
    insert(&fourth_list, 4, 20);
    insert(&fourth_list, 3, 30);
    insert(&fourth_list, 6, 40);
    insert(&fourth_list, 7, 50);
    insert(&fourth_list, 2, 60);
    insert(&fourth_list, 8, 70);
    insert(&fourth_list, 1, 80);
    insert(&fourth_list, 9, 90);

    ck_assert_int_eq(at(&fourth_list, 1), 80);
    ck_assert_int_eq(at(&fourth_list, 2), 60);
    ck_assert_int_eq(at(&fourth_list, 3), 30);
    ck_assert_int_eq(at(&fourth_list, 4), 20);
    ck_assert_int_eq(at(&fourth_list, 5), 10);
    ck_assert_int_eq(at(&fourth_list, 6), 40);
    ck_assert_int_eq(at(&fourth_list, 7), 50);
    ck_assert_int_eq(at(&fourth_list, 8), 70);
    ck_assert_int_eq(at(&fourth_list, 9), 90);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("skip_list");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_insert);

    suite_add_tcase(suite, tcase);

    return suite;
}

/**
 *
 */
int main(int argc, char *argv[])
{
    Suite *suite = linked_list_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
