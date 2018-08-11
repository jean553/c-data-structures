#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "linked_list.h"
#include "self_organizing_list.h"

/**
 *
 */
START_TEST(test_atWithMTF)
{
    /* index in the middle */

    LinkedList first_node = createLL(10);
    insertAtTheEndLL(&first_node, 20);
    insertAtTheEndLL(&first_node, 30);
    insertAtTheEndLL(&first_node, 40);

    ck_assert_int_eq(atWithMTF(&first_node, 2), 30);
    ck_assert_int_eq(atLL(&first_node, 0), 30);
    ck_assert_int_eq(atLL(&first_node, 1), 10);
    ck_assert_int_eq(atLL(&first_node, 2), 20);
    ck_assert_int_eq(atLL(&first_node, 3), 40);

    /* index at the end */

    LinkedList second_node = createLL(10);
    insertAtTheEndLL(&second_node, 20);
    insertAtTheEndLL(&second_node, 30);
    insertAtTheEndLL(&second_node, 40);

    ck_assert_int_eq(atWithMTF(&second_node, 3), 40);
    ck_assert_int_eq(atLL(&second_node, 0), 40);
    ck_assert_int_eq(atLL(&second_node, 1), 10);
    ck_assert_int_eq(atLL(&second_node, 2), 20);
    ck_assert_int_eq(atLL(&second_node, 3), 30);

    /* index at the beginning */

    LinkedList third_node = createLL(10);
    insertAtTheEndLL(&third_node, 20);
    insertAtTheEndLL(&third_node, 30);
    insertAtTheEndLL(&third_node, 40);

    ck_assert_int_eq(atWithMTF(&third_node, 0), 10);
    ck_assert_int_eq(atLL(&third_node, 0), 10);
    ck_assert_int_eq(atLL(&third_node, 1), 20);
    ck_assert_int_eq(atLL(&third_node, 2), 30);
    ck_assert_int_eq(atLL(&third_node, 3), 40);
}
END_TEST

/**
 *
 */
START_TEST(test_atTranspose)
{
    /* index in the middle */

    LinkedList first_node = createLL(10);
    insertAtTheEndLL(&first_node, 20);
    insertAtTheEndLL(&first_node, 30);
    insertAtTheEndLL(&first_node, 40);

    ck_assert_int_eq(atTranspose(&first_node, 2), 30);
    ck_assert_int_eq(atLL(&first_node, 0), 10);
    ck_assert_int_eq(atLL(&first_node, 1), 30);
    ck_assert_int_eq(atLL(&first_node, 2), 20);
    ck_assert_int_eq(atLL(&first_node, 3), 40);

    /* index atLL the end */

    LinkedList second_node = createLL(10);
    insertAtTheEndLL(&second_node, 20);
    insertAtTheEndLL(&second_node, 30);
    insertAtTheEndLL(&second_node, 40);

    ck_assert_int_eq(atTranspose(&second_node, 3), 40);
    ck_assert_int_eq(atLL(&second_node, 0), 10);
    ck_assert_int_eq(atLL(&second_node, 1), 20);
    ck_assert_int_eq(atLL(&second_node, 2), 40);
    ck_assert_int_eq(atLL(&second_node, 3), 30);

    /* index atLL the beginning */

    LinkedList third_node = createLL(10);
    insertAtTheEndLL(&third_node, 20);
    insertAtTheEndLL(&third_node, 30);
    insertAtTheEndLL(&third_node, 40);

    ck_assert_int_eq(atTranspose(&third_node, 0), 10);
    ck_assert_int_eq(atLL(&third_node, 0), 10);
    ck_assert_int_eq(atLL(&third_node, 1), 20);
    ck_assert_int_eq(atLL(&third_node, 2), 30);
    ck_assert_int_eq(atLL(&third_node, 3), 40);

    /* index atLL the second position */

    LinkedList fourth_node = createLL(10);
    insertAtTheEndLL(&fourth_node, 20);
    insertAtTheEndLL(&fourth_node, 30);
    insertAtTheEndLL(&fourth_node, 40);

    ck_assert_int_eq(atTranspose(&fourth_node, 1), 20);
    ck_assert_int_eq(atLL(&fourth_node, 0), 20);
    ck_assert_int_eq(atLL(&fourth_node, 1), 10);
    ck_assert_int_eq(atLL(&fourth_node, 2), 30);
    ck_assert_int_eq(atLL(&fourth_node, 3), 40);
}
END_TEST

/**
 *
 */
Suite* self_organizing_list_suite()
{
    Suite *suite = suite_create("self_organizing_list");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_atWithMTF);
    tcase_add_test(tcase, test_atTranspose);

    suite_add_tcase(suite, tcase);

    return suite;
}

/**
 *
 */
int main(int argc, char *argv[])
{
    Suite *suite = self_organizing_list_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
