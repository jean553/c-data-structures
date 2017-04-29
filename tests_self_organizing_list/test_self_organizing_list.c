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

    LinkedList first_node = create(10);
    insertAtTheEnd(&first_node, 20);
    insertAtTheEnd(&first_node, 30);
    insertAtTheEnd(&first_node, 40);

    ck_assert_int_eq(atWithMTF(&first_node, 2), 30);
    ck_assert_int_eq(at(&first_node, 0), 30);
    ck_assert_int_eq(at(&first_node, 1), 10);
    ck_assert_int_eq(at(&first_node, 2), 20);
    ck_assert_int_eq(at(&first_node, 3), 40);

    /* index at the end */

    LinkedList second_node = create(10);
    insertAtTheEnd(&second_node, 20);
    insertAtTheEnd(&second_node, 30);
    insertAtTheEnd(&second_node, 40);

    ck_assert_int_eq(atWithMTF(&second_node, 3), 40);
    ck_assert_int_eq(at(&second_node, 0), 40);
    ck_assert_int_eq(at(&second_node, 1), 10);
    ck_assert_int_eq(at(&second_node, 2), 20);
    ck_assert_int_eq(at(&second_node, 3), 30);

    /* index at the beginning */

    LinkedList third_node = create(10);
    insertAtTheEnd(&third_node, 20);
    insertAtTheEnd(&third_node, 30);
    insertAtTheEnd(&third_node, 40);

    ck_assert_int_eq(atWithMTF(&third_node, 0), 10);
    ck_assert_int_eq(at(&third_node, 0), 10);
    ck_assert_int_eq(at(&third_node, 1), 20);
    ck_assert_int_eq(at(&third_node, 2), 30);
    ck_assert_int_eq(at(&third_node, 3), 40);
}
END_TEST

/**
 *
 */
Suite* double_linked_list_suite()
{
    Suite *suite = suite_create("self_organizing_list");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_atWithMTF);

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
