#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "linked_list.h"

/**
 *
 */
START_TEST(test_create)
{
    LinkedListNode first_node = create(0);
    ck_assert_int_eq(at(&first_node, 0), 0);

    LinkedListNode second_node = create(10);
    ck_assert_int_eq(at(&second_node, 0), 10);

    LinkedListNode third_node = create(100);
    ck_assert_int_eq(at(&third_node, 0), 100);
}
END_TEST

/**
 *
 */
START_TEST(test_insertAtTheEnd)
{
    /* test with a few nodes */

    LinkedListNode first_node = create(0);
    insertAtTheEnd(&first_node, 10);
    insertAtTheEnd(&first_node, 20);
    insertAtTheEnd(&first_node, 30);
    insertAtTheEnd(&first_node, 40);

    ck_assert_int_eq(at(&first_node, 0), 0);
    ck_assert_int_eq(at(&first_node, 4), 40);
    ck_assert_int_eq(at(&first_node, 1), 10);
    ck_assert_int_eq(at(&first_node, 3), 30);
    ck_assert_int_eq(at(&first_node, 2), 20);

    /* test with a lot of nodes */

    LinkedListNode second_node = create(0);

    for (int i = 1; i < 1000; i++)
    {
        insertAtTheEnd(&second_node, i);
    }

    for (int i = 0; i < 1000; i++)
    {
        ck_assert_int_eq(at(&second_node, i), i);
    }
}
END_TEST

/**
 *
 */
START_TEST(test_size)
{
    /* test with one node */

    LinkedListNode first_node = create(10);
    ck_assert_int_eq(size(&first_node), 1);

    /* test with a few nodes */

    LinkedListNode second_node = create(10);
    insertAtTheEnd(&second_node, 10);
    insertAtTheEnd(&second_node, 20);
    insertAtTheEnd(&second_node, 30);
    insertAtTheEnd(&second_node, 40);
    ck_assert_int_eq(size(&second_node), 5);

    /* test with a lot of nodes */

    LinkedListNode third_node = create(0);

    for (int i = 1; i < 1000; i++)
    {
        insertAtTheEnd(&third_node, i);
    }

    ck_assert_int_eq(size(&third_node), 1000);
}
END_TEST

/**
 *
 */
START_TEST(test_all)
{
    /* test with one node */

    LinkedListNode first_node = create(10);

    int first_expected[1] = {10};
    int* first_got = all(&first_node);

    ck_assert_int_eq(first_got[0], first_expected[0]);

    /* test with many nodes */

    LinkedListNode second_node = create(10);
    insertAtTheEnd(&second_node, 20);
    insertAtTheEnd(&second_node, 30);
    insertAtTheEnd(&second_node, 40);
    insertAtTheEnd(&second_node, 50);

    int second_expected[5] = {10, 20, 30, 40, 50};
    int* second_got = all(&second_node);

    ck_assert_int_eq(second_got[0], second_expected[0]);
    ck_assert_int_eq(second_got[1], second_expected[1]);
    ck_assert_int_eq(second_got[2], second_expected[2]);
    ck_assert_int_eq(second_got[3], second_expected[3]);
    ck_assert_int_eq(second_got[4], second_expected[4]);

    /* test with a lot of nodes */

    LinkedListNode third_node = create(0);

    int* third_expected = (int*) malloc(1000 * sizeof(int));
    for (int i = 0; i < 1000; i++)
    {
        insertAtTheEnd(&third_node, i + 1);
        third_expected[i] = i;
    }

    int* third_got = all(&third_node);
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
    /* insert at the beginning when list contains one node */

    LinkedListNode first_node = create(10);

    insert(&first_node, 0, 20);

    ck_assert_int_eq(at(&first_node, 0), 20);
    ck_assert_int_eq(at(&first_node, 1), 10);

    /* insert at the beginning when list contains many nodes */

    LinkedListNode second_node = create(10);
    insertAtTheEnd(&second_node, 20);
    insertAtTheEnd(&second_node, 30);
    insertAtTheEnd(&second_node, 40);

    insert(&second_node, 0, 50);

    ck_assert_int_eq(at(&second_node, 0), 50);
    ck_assert_int_eq(at(&second_node, 1), 10);
    ck_assert_int_eq(at(&second_node, 2), 20);
    ck_assert_int_eq(at(&second_node, 3), 30);
    ck_assert_int_eq(at(&second_node, 4), 40);

    /* insert in the middle when only contains two nodes */

    LinkedListNode third_node = create(10);
    insertAtTheEnd(&third_node, 20);

    insert(&third_node, 1, 40);

    ck_assert_int_eq(at(&third_node, 0), 10);
    ck_assert_int_eq(at(&third_node, 1), 40);
    ck_assert_int_eq(at(&third_node, 2), 20);

    /* insert in the middle when contains many nodes */

    LinkedListNode fourth_node = create(10);
    insertAtTheEnd(&fourth_node, 20);
    insertAtTheEnd(&fourth_node, 30);
    insertAtTheEnd(&fourth_node, 40);

    insert(&fourth_node, 2, 50);

    ck_assert_int_eq(at(&fourth_node, 0), 10);
    ck_assert_int_eq(at(&fourth_node, 1), 20);
    ck_assert_int_eq(at(&fourth_node, 2), 50);
    ck_assert_int_eq(at(&fourth_node, 3), 30);
    ck_assert_int_eq(at(&fourth_node, 4), 40);
}
END_TEST

/**
 *
 */
START_TEST(test_drop)
{
    /* delete one node from the middle of the list */

    LinkedListNode first_node = create(10);
    insertAtTheEnd(&first_node, 20);
    insertAtTheEnd(&first_node, 30);
    insertAtTheEnd(&first_node, 40);

    drop(&first_node, 2);

    ck_assert_int_eq(at(&first_node, 0), 10);
    ck_assert_int_eq(at(&first_node, 1), 20);
    ck_assert_int_eq(at(&first_node, 2), 40);

    /* delete the first node when many nodes */

    LinkedListNode second_node = create(10);
    insertAtTheEnd(&second_node, 20);
    insertAtTheEnd(&second_node, 30);

    drop(&second_node, 0);

    ck_assert_int_eq(at(&second_node, 0), 20);
    ck_assert_int_eq(at(&second_node, 1), 30);

    /* delete the first node when only two nodes */

    LinkedListNode third_node = create(10);
    insertAtTheEnd(&third_node, 20);

    drop(&third_node, 0);

    ck_assert_int_eq(at(&third_node, 0), 20);

    /* delete the last node when many nodes */

    LinkedListNode fourth_node = create(10);
    insertAtTheEnd(&fourth_node, 20);
    insertAtTheEnd(&fourth_node, 30);

    drop(&fourth_node, 2);

    ck_assert_int_eq(at(&fourth_node, 0), 10);
    ck_assert_int_eq(at(&fourth_node, 1), 20);

    /* delete the last node when only two nodes */

    LinkedListNode fifth_node = create(10);
    insertAtTheEnd(&fifth_node, 20);

    drop(&fifth_node, 1);

    ck_assert_int_eq(at(&fifth_node, 0), 10);
}
END_TEST

/**
 *
 */
START_TEST(test_pop)
{
    /* delete the last node when many nodes */

    LinkedListNode first_node = create(10);
    insertAtTheEnd(&first_node, 20);
    insertAtTheEnd(&first_node, 30);
    insertAtTheEnd(&first_node, 40);

    ck_assert_int_eq(size(&first_node), 4);

    pop(&first_node);

    ck_assert_int_eq(size(&first_node), 3);

    pop(&first_node);

    ck_assert_int_eq(size(&first_node), 2);

    /* delete the last node when only two nodes */

    LinkedListNode second_node = create(10);
    insertAtTheEnd(&second_node, 20);

    ck_assert_int_eq(size(&second_node), 2);

    pop(&second_node);

    ck_assert_int_eq(size(&second_node), 1);
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
    tcase_add_test(tcase, test_size);
    tcase_add_test(tcase, test_all);
    tcase_add_test(tcase, test_insert);
    tcase_add_test(tcase, test_drop);
    tcase_add_test(tcase, test_pop);

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
