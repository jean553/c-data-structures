#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "unrolled_linked_list.h"

const unsigned short ARRAY_SIZE = 5;

/**
 *
 */
START_TEST(test_create)
{
    UnrolledLinkedList first_list = createULL(
        ARRAY_SIZE,
        10
    );

    ck_assert_int_eq(atULL(&first_list, 0), 0);
    ck_assert_int_eq(atULL(&first_list, 1), 0);
    ck_assert_int_eq(atULL(&first_list, 2), 0);
    ck_assert_int_eq(atULL(&first_list, 3), 0);
    ck_assert_int_eq(atULL(&first_list, 4), 0);
}
END_TEST

/**
 *
 */
Suite* double_linked_list_suite()
{
    Suite *suite = suite_create("unrolled_linked_list");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);

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
