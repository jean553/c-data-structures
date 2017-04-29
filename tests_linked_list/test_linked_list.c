#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "linked_list.h"

/**
 *
 */
START_TEST(test_create)
{
    LinkedList first_list = create(0);
    ck_assert_int_eq(at(&first_list, 0), 0);

    LinkedList second_list = create(10);
    ck_assert_int_eq(at(&second_list, 0), 10);

    LinkedList third_list = create(100);
    ck_assert_int_eq(at(&third_list, 0), 100);
}
END_TEST

/**
 *
 */
START_TEST(test_insertAtTheEnd)
{
    /* test with a few nodes */

    LinkedList first_list = create(0);
    insertAtTheEnd(&first_list, 10);
    insertAtTheEnd(&first_list, 20);
    insertAtTheEnd(&first_list, 30);
    insertAtTheEnd(&first_list, 40);

    ck_assert_int_eq(at(&first_list, 0), 0);
    ck_assert_int_eq(at(&first_list, 4), 40);
    ck_assert_int_eq(at(&first_list, 1), 10);
    ck_assert_int_eq(at(&first_list, 3), 30);
    ck_assert_int_eq(at(&first_list, 2), 20);

    /* test with a lot of nodes */

    LinkedList second_list = create(0);

    for (int i = 1; i < 1000; i++)
    {
        insertAtTheEnd(&second_list, i);
    }

    for (int i = 0; i < 1000; i++)
    {
        ck_assert_int_eq(at(&second_list, i), i);
    }
}
END_TEST

/**
 *
 */
START_TEST(test_insertAtTheBeginning)
{
    /* test with a simple node */

    LinkedList first_list = create(5);
    insertAtTheBeginning(&first_list, 10);

    ck_assert_int_eq(at(&first_list, 0), 10);
    ck_assert_int_eq(at(&first_list, 1), 5);

    /* TODO: add tests with many nodes */
}
END_TEST

/**
 *
 */
START_TEST(test_size)
{
    /* test with one node */

    LinkedList first_list = create(10);
    ck_assert_int_eq(size(&first_list), 1);

    /* test with a few nodes */

    LinkedList second_list = create(10);
    insertAtTheEnd(&second_list, 10);
    insertAtTheEnd(&second_list, 20);
    insertAtTheEnd(&second_list, 30);
    insertAtTheEnd(&second_list, 40);
    ck_assert_int_eq(size(&second_list), 5);

    /* test with a lot of nodes */

    LinkedList third_list = create(0);

    for (int i = 1; i < 1000; i++)
    {
        insertAtTheEnd(&third_list, i);
    }

    ck_assert_int_eq(size(&third_list), 1000);
}
END_TEST

/**
 *
 */
START_TEST(test_all)
{
    /* test with one node */

    LinkedList first_list = create(10);

    int first_expected[1] = {10};
    int* first_got = all(&first_list);

    ck_assert_int_eq(first_got[0], first_expected[0]);

    /* test with many nodes */

    LinkedList second_list = create(10);
    insertAtTheEnd(&second_list, 20);
    insertAtTheEnd(&second_list, 30);
    insertAtTheEnd(&second_list, 40);
    insertAtTheEnd(&second_list, 50);

    int second_expected[5] = {10, 20, 30, 40, 50};
    int* second_got = all(&second_list);

    ck_assert_int_eq(second_got[0], second_expected[0]);
    ck_assert_int_eq(second_got[1], second_expected[1]);
    ck_assert_int_eq(second_got[2], second_expected[2]);
    ck_assert_int_eq(second_got[3], second_expected[3]);
    ck_assert_int_eq(second_got[4], second_expected[4]);

    /* test with a lot of nodes */

    LinkedList third_list = create(0);

    int* third_expected = (int*) malloc(1000 * sizeof(int));
    for (int i = 0; i < 1000; i++)
    {
        insertAtTheEnd(&third_list, i + 1);
        third_expected[i] = i;
    }

    int* third_got = all(&third_list);
    for (int i = 0; i < 1000; i++)
    {
        ck_assert_int_eq(third_got[i], third_expected[i]);
    }
}
END_TEST

/**
 *
 */
START_TEST(test_insert)
{
    /* insert at the beginning when list contains many nodes */

    LinkedList second_list = create(10);
    insertAtTheEnd(&second_list, 20);
    insertAtTheEnd(&second_list, 30);
    insertAtTheEnd(&second_list, 40);

    insertAfter(&second_list, 0, 50);

    ck_assert_int_eq(at(&second_list, 0), 10);
    ck_assert_int_eq(at(&second_list, 1), 50);
    ck_assert_int_eq(at(&second_list, 2), 20);
    ck_assert_int_eq(at(&second_list, 3), 30);
    ck_assert_int_eq(at(&second_list, 4), 40);

    /* insert in the middle when only contains two nodes */

    LinkedList third_list = create(10);
    insertAtTheEnd(&third_list, 20);
    insertAtTheEnd(&third_list, 30);

    insertAfter(&third_list, 1, 40);

    ck_assert_int_eq(at(&third_list, 0), 10);
    ck_assert_int_eq(at(&third_list, 1), 20);
    ck_assert_int_eq(at(&third_list, 2), 40);
    ck_assert_int_eq(at(&third_list, 3), 30);

    /* insert in the middle when contains many nodes */

    LinkedList fourth_list = create(10);
    insertAtTheEnd(&fourth_list, 20);
    insertAtTheEnd(&fourth_list, 30);
    insertAtTheEnd(&fourth_list, 40);

    insertAfter(&fourth_list, 2, 50);

    ck_assert_int_eq(at(&fourth_list, 0), 10);
    ck_assert_int_eq(at(&fourth_list, 1), 20);
    ck_assert_int_eq(at(&fourth_list, 2), 30);
    ck_assert_int_eq(at(&fourth_list, 3), 50);
    ck_assert_int_eq(at(&fourth_list, 4), 40);
}
END_TEST

/**
 *
 */
START_TEST(test_drop)
{
    /* delete one node from the middle of the list */

    LinkedList first_list = create(10);
    insertAtTheEnd(&first_list, 20);
    insertAtTheEnd(&first_list, 30);
    insertAtTheEnd(&first_list, 40);

    dropAt(&first_list, 2);

    ck_assert_int_eq(at(&first_list, 0), 10);
    ck_assert_int_eq(at(&first_list, 1), 20);
    ck_assert_int_eq(at(&first_list, 2), 40);

    /* delete the first node when many nodes */

    LinkedList second_list = create(10);
    insertAtTheEnd(&second_list, 20);
    insertAtTheEnd(&second_list, 30);

    dropAt(&second_list, 0);

    ck_assert_int_eq(at(&second_list, 0), 20);
    ck_assert_int_eq(at(&second_list, 1), 30);

    /* delete the first node when only two nodes */

    LinkedList third_list = create(10);
    insertAtTheEnd(&third_list, 20);

    dropAt(&third_list, 0);

    ck_assert_int_eq(at(&third_list, 0), 20);

    /* delete the last node when many nodes */

    LinkedList fourth_list = create(10);
    insertAtTheEnd(&fourth_list, 20);
    insertAtTheEnd(&fourth_list, 30);

    dropAt(&fourth_list, 2);

    ck_assert_int_eq(at(&fourth_list, 0), 10);
    ck_assert_int_eq(at(&fourth_list, 1), 20);

    /* delete the last node when only two nodes */

    LinkedList fifth_list = create(10);
    insertAtTheEnd(&fifth_list, 20);

    dropAt(&fifth_list, 1);

    ck_assert_int_eq(at(&fifth_list, 0), 10);
}
END_TEST

/**
 *
 */
START_TEST(test_dropAtTheEnd)
{
    /* delete the last node when many nodes */

    LinkedList first_list = create(10);
    insertAtTheEnd(&first_list, 20);
    insertAtTheEnd(&first_list, 30);
    insertAtTheEnd(&first_list, 40);

    ck_assert_int_eq(size(&first_list), 4);

    dropAtTheEnd(&first_list);

    ck_assert_int_eq(size(&first_list), 3);

    dropAtTheEnd(&first_list);

    ck_assert_int_eq(size(&first_list), 2);

    /* delete the last node when only two nodes */

    LinkedList second_list = create(10);
    insertAtTheEnd(&second_list, 20);

    ck_assert_int_eq(size(&second_list), 2);

    dropAtTheEnd(&second_list);

    ck_assert_int_eq(size(&second_list), 1);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("linked_list");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_insertAtTheEnd);
    tcase_add_test(tcase, test_insertAtTheBeginning);
    tcase_add_test(tcase, test_size);
    tcase_add_test(tcase, test_all);
    tcase_add_test(tcase, test_insert);
    tcase_add_test(tcase, test_drop);
    tcase_add_test(tcase, test_dropAtTheEnd);

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
