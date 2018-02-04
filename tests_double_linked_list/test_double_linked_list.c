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
START_TEST(test_insertAtTheEnd)
{
    DoubleLinkedList first_list = create(0);
    insertAtTheEnd(&first_list, 10);
    insertAtTheEnd(&first_list, 20);
    insertAtTheEnd(&first_list, 30);

    ck_assert_int_eq(at(&first_list, 0), 0);
    ck_assert_int_eq(at(&first_list, 1), 10);
    ck_assert_int_eq(at(&first_list, 2), 20);
    ck_assert_int_eq(at(&first_list, 3), 30);
}
END_TEST

/**
 *
 */
START_TEST(test_insertAtTheBeginning)
{
    DoubleLinkedList first_list = create(0);
    insertAtTheBeginning(&first_list, 10);
    insertAtTheBeginning(&first_list, 20);
    insertAtTheBeginning(&first_list, 30);

    ck_assert_int_eq(at(&first_list, 0), 30);
    ck_assert_int_eq(at(&first_list, 1), 20);
    ck_assert_int_eq(at(&first_list, 2), 10);
    ck_assert_int_eq(at(&first_list, 3), 0);

    DoubleLinkedList second_list = create(0);
    insertAtTheEnd(&second_list, 10);
    insertAtTheBeginning(&second_list, 20);
    insertAtTheEnd(&second_list, 30);
    insertAtTheBeginning(&second_list, 40);

    ck_assert_int_eq(at(&second_list, 0), 40);
    ck_assert_int_eq(at(&second_list, 1), 20);
    ck_assert_int_eq(at(&second_list, 2), 0);
    ck_assert_int_eq(at(&second_list, 3), 10);
    ck_assert_int_eq(at(&second_list, 4), 30);
}
END_TEST

/**
 *
 */
START_TEST(test_size)
{
    DoubleLinkedList first_list = create(10);
    insertAtTheEnd(&first_list, 20);
    insertAtTheEnd(&first_list, 30);
    insertAtTheEnd(&first_list, 40);

    ck_assert_int_eq(size(&first_list), 4);

    DoubleLinkedList second_list = create(20);

    ck_assert_int_eq(size(&second_list), 1);
}
END_TEST

/**
 *
 */
START_TEST(test_at)
{
    DoubleLinkedList first_list = create(10);
    insertAtTheEnd(&first_list, 20);
    insertAtTheEnd(&first_list, 30);
    insertAtTheEnd(&first_list, 40);
    insertAtTheEnd(&first_list, 50);

    /* browse list from head to tail */

    ck_assert_int_eq(at(&first_list, 0), 10);
    ck_assert_int_eq(at(&first_list, 1), 20);

    /* browse list from tail to head */

    ck_assert_int_eq(at(&first_list, 2), 30);
    ck_assert_int_eq(at(&first_list, 3), 40);
    ck_assert_int_eq(at(&first_list, 4), 50);
}
END_TEST

/**
 *
 */
START_TEST(test_insertAt)
{
    /* insert at the beginning when list contains many nodes */

    DoubleLinkedList second_list = create(10);
    insertAtTheEnd(&second_list, 20);
    insertAtTheEnd(&second_list, 30);
    insertAtTheEnd(&second_list, 40);

    insertAfter(&second_list, 0, 50);

    ck_assert_int_eq(at(&second_list, 0), 10);
    ck_assert_int_eq(at(&second_list, 1), 50);
    ck_assert_int_eq(at(&second_list, 2), 20);
    ck_assert_int_eq(at(&second_list, 3), 30);
    ck_assert_int_eq(at(&second_list, 4), 40);

    /* insert in the middle when only contains five nodes */

    DoubleLinkedList third_list = create(10);
    insertAtTheEnd(&third_list, 20);
    insertAtTheEnd(&third_list, 30);
    insertAtTheEnd(&third_list, 40);
    insertAtTheEnd(&third_list, 50);

    insertAfter(&third_list, 2, 60);

    ck_assert_int_eq(at(&third_list, 0), 10);
    ck_assert_int_eq(at(&third_list, 1), 20);
    ck_assert_int_eq(at(&third_list, 2), 30);
    ck_assert_int_eq(at(&third_list, 3), 60);
    ck_assert_int_eq(at(&third_list, 4), 40);
    ck_assert_int_eq(at(&third_list, 5), 50);

    /* insert in the middle when contains four nodes */

    DoubleLinkedList fourth_list = create(10);
    insertAtTheEnd(&fourth_list, 20);
    insertAtTheEnd(&fourth_list, 30);
    insertAtTheEnd(&fourth_list, 40);

    insertAfter(&fourth_list, 2, 50);

    ck_assert_int_eq(at(&fourth_list, 0), 10);
    ck_assert_int_eq(at(&fourth_list, 1), 20);
    ck_assert_int_eq(at(&fourth_list, 2), 30);
    ck_assert_int_eq(at(&fourth_list, 3), 50);
    ck_assert_int_eq(at(&fourth_list, 4), 40);

    /* insert just before the end of the list */

    DoubleLinkedList fifth_list = create(10);
    insertAtTheEnd(&fifth_list, 20);
    insertAtTheEnd(&fifth_list, 30);
    insertAtTheEnd(&fifth_list, 40);
    insertAtTheEnd(&fifth_list, 50);

    insertAfter(&fifth_list, 3, 60);

    ck_assert_int_eq(at(&fifth_list, 0), 10);
    ck_assert_int_eq(at(&fifth_list, 1), 20);
    ck_assert_int_eq(at(&fifth_list, 2), 30);
    ck_assert_int_eq(at(&fifth_list, 3), 40);
    ck_assert_int_eq(at(&fifth_list, 4), 60);
    ck_assert_int_eq(at(&fifth_list, 5), 50);
}
END_TEST

/**
 *
 */
START_TEST(test_dropAt)
{
    /* drop when only one node */

    DoubleLinkedList first_list = create(0);
    ck_assert_int_ne(first_list.head, NULL);

    dropAt(&first_list, 0);

    ck_assert_int_eq(first_list.head, NULL);

    /* drop at the beginning when two items */

    DoubleLinkedList second_list = create(10);
    insertAtTheEnd(&second_list, 20);

    ck_assert_int_ne(second_list.head, NULL);
    ck_assert_int_ne(second_list.head->next, NULL);
    ck_assert_int_ne(second_list.head->next->previous, NULL);
    ck_assert_int_eq(at(&second_list, 0), 10);
    ck_assert_int_eq(at(&second_list, 1), 20);

    dropAt(&second_list, 0);

    ck_assert_int_eq(at(&second_list, 0), 20);
    ck_assert_int_ne(second_list.head, NULL);
    ck_assert_int_eq(second_list.head->next, NULL);

    /* drop at the end when two items */

    DoubleLinkedList third_list = create(10);
    insertAtTheEnd(&third_list, 20);

    ck_assert_int_ne(third_list.head, NULL);
    ck_assert_int_ne(third_list.head->next, NULL);
    ck_assert_int_ne(third_list.head->next->previous, NULL);
    ck_assert_int_eq(at(&third_list, 0), 10);
    ck_assert_int_eq(at(&third_list, 1), 20);

    dropAt(&third_list, 1);

    ck_assert_int_eq(at(&third_list, 0), 10);
    ck_assert_int_ne(third_list.head, NULL);
    ck_assert_int_eq(third_list.head->next, NULL);

    /* drop at the beginning when three items */

    DoubleLinkedList fourth_list = create(10);
    insertAtTheEnd(&fourth_list, 20);
    insertAtTheEnd(&fourth_list, 30);

    ck_assert_int_ne(fourth_list.head, NULL);
    ck_assert_int_ne(fourth_list.head->next, NULL);
    ck_assert_int_ne(fourth_list.head->next->previous, NULL);
    ck_assert_int_ne(fourth_list.head->next->next->previous, NULL);
    ck_assert_int_eq(at(&fourth_list, 0), 10);
    ck_assert_int_eq(at(&fourth_list, 1), 20);
    ck_assert_int_eq(at(&fourth_list, 2), 30);

    dropAt(&fourth_list, 0);

    ck_assert_int_eq(at(&fourth_list, 0), 20);
    ck_assert_int_eq(at(&fourth_list, 1), 30);
    ck_assert_int_ne(fourth_list.head, NULL);
    ck_assert_int_ne(fourth_list.head->next, NULL);
    ck_assert_int_eq(fourth_list.head->next->previous, fourth_list.head);
    ck_assert_int_eq(fourth_list.head->next->next, NULL);
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
    tcase_add_test(tcase, test_insertAtTheEnd);
    tcase_add_test(tcase, test_insertAtTheBeginning);
    tcase_add_test(tcase, test_size);
    tcase_add_test(tcase, test_at);
    tcase_add_test(tcase, test_insertAt);
    tcase_add_test(tcase, test_dropAt);

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
