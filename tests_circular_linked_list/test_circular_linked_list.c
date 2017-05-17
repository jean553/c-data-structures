#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "linked_list.h"
#include "circular_linked_list.h"

/**
 *
 */
START_TEST(test_create)
{
    CircularLinkedList first_list = createCLL(0);
    CircularLinkedList second_list = createCLL(10);
    CircularLinkedList third_list = createCLL(100);
}
END_TEST

/**
 *
 */
START_TEST(test_insertAtTheEndCLL)
{
    CircularLinkedList first_list = createCLL(10);
    insertAtTheEndCLL(&first_list, 20);
    insertAtTheEndCLL(&first_list, 30);

    ck_assert_int_eq(atCLL(&first_list, 0), 10);
    ck_assert_int_eq(atCLL(&first_list, 1), 20);
    ck_assert_int_eq(atCLL(&first_list, 2), 30);
}
END_TEST

/**
 *
 */
START_TEST(test_insertAtTheBeginningCLL)
{
    CircularLinkedList first_list = createCLL(10);
    insertAtTheBeginningCLL(&first_list, 20);
    insertAtTheBeginningCLL(&first_list, 30);

    ck_assert_int_eq(atCLL(&first_list, 0), 30);
    ck_assert_int_eq(atCLL(&first_list, 1), 20);
    ck_assert_int_eq(atCLL(&first_list, 2), 10);
}
END_TEST

/**
 *
 */
START_TEST(test_listIsCircular)
{
    CircularLinkedList first_list = createCLL(10);
    insertAtTheEndCLL(&first_list, 20);
    insertAtTheEndCLL(&first_list, 30);

    ck_assert_int_eq(atCLL(&first_list, 0), 10);
    ck_assert_int_eq(atCLL(&first_list, 1), 20);
    ck_assert_int_eq(atCLL(&first_list, 2), 30);

    ck_assert_int_eq(atCLL(&first_list, 3), 10);
    ck_assert_int_eq(atCLL(&first_list, 4), 20);
    ck_assert_int_eq(atCLL(&first_list, 5), 30);

    ck_assert_int_eq(atCLL(&first_list, 6), 10);
    ck_assert_int_eq(atCLL(&first_list, 7), 20);
    ck_assert_int_eq(atCLL(&first_list, 8), 30);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("circular_linked_list");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_insertAtTheEndCLL);
    tcase_add_test(tcase, test_insertAtTheBeginningCLL);
    tcase_add_test(tcase, test_listIsCircular);

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
