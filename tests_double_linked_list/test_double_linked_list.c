#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "double_linked_list.h"

/**
 *
 */
START_TEST(test_create)
{
    DoubleLinkedList first_list = create(10);
    ck_assert_int_eq(at(&first_list, 0), 10);

    DoubleLinkedList second_list = create(20);
    ck_assert_int_eq(at(&second_list, 0), 20);

    DoubleLinkedList third_list = create(30);
    ck_assert_int_eq(at(&third_list, 0), 30);
}
END_TEST

/**
 *
 */
START_TEST(test_push)
{
    DoubleLinkedList first_list = create(0);
    push(&first_list, 10);
    push(&first_list, 20);
    push(&first_list, 30);

    ck_assert_int_eq(at(&first_list, 0), 0);
    ck_assert_int_eq(at(&first_list, 1), 10);
    ck_assert_int_eq(at(&first_list, 2), 20);
    ck_assert_int_eq(at(&first_list, 3), 30);
}
END_TEST

/**
 *
 */
Suite* double_linked_list_suite()
{
    Suite *suite = suite_create("double_linked_list");
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
    Suite *suite = double_linked_list_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
