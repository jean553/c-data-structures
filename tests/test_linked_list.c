#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "../includes/linked_list.h"

/**
 *
 */
START_TEST(test_create)
{
    Node first_node = create(0);
    ck_assert_int_eq(at(&first_node, 0), 0);

    Node second_node = create(10);
    ck_assert_int_eq(at(&second_node, 0), 10);

    Node third_node = create(100);
    ck_assert_int_eq(at(&third_node, 0), 100);
}
END_TEST

/**
 *
 */
START_TEST(test_push)
{
    /* test with a few nodes */

    Node first_node = create(0);
    push(&first_node, 10);
    push(&first_node, 20);
    push(&first_node, 30);
    push(&first_node, 40);

    ck_assert_int_eq(at(&first_node, 0), 0);
    ck_assert_int_eq(at(&first_node, 4), 40);
    ck_assert_int_eq(at(&first_node, 1), 10);
    ck_assert_int_eq(at(&first_node, 3), 30);
    ck_assert_int_eq(at(&first_node, 2), 20);

    /* test with a lot of nodes */

    Node second_node = create(0);

    for (int i = 1; i < 1000; i++)
    {
        push(&second_node, i);
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

    Node first_node = create(10);
    ck_assert_int_eq(size(&first_node), 1);

    /* test with a few nodes */

    Node second_node = create(10);
    push(&second_node, 10);
    push(&second_node, 20);
    push(&second_node, 30);
    push(&second_node, 40);
    ck_assert_int_eq(size(&second_node), 5);

    /* test with a lot of nodes */

    Node third_node = create(0);

    for (int i = 1; i < 1000; i++)
    {
        push(&third_node, i);
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

    Node first_node = create(10);

    int first_expected[1] = {10};
    int* first_got = all(&first_node);

    ck_assert_int_eq(first_got[0], first_expected[0]);

    /* test with many nodes */

    Node second_node = create(10);
    push(&second_node, 20);
    push(&second_node, 30);
    push(&second_node, 40);
    push(&second_node, 50);

    int second_expected[5] = {10, 20, 30, 40, 50};
    int* second_got = all(&second_node);

    ck_assert_int_eq(second_got[0], second_expected[0]);
    ck_assert_int_eq(second_got[1], second_expected[1]);
    ck_assert_int_eq(second_got[2], second_expected[2]);
    ck_assert_int_eq(second_got[3], second_expected[3]);
    ck_assert_int_eq(second_got[4], second_expected[4]);

    /* test with a lot of nodes */

    Node third_node = create(0);

    int* third_expected = (int*) malloc(1000 * sizeof(int));
    for (int i = 0; i < 1000; i++)
    {
        push(&third_node, i + 1);
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
Suite* linked_list_suite()
{
    Suite *suite = suite_create("linked_list");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_push);
    tcase_add_test(tcase, test_size);
    tcase_add_test(tcase, test_all);

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