#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "binary_search_tree.h"

/**
 *
 */
START_TEST(test_create)
{
    BinarySearchTreeNode tree = create(10);
}
END_TEST

/**
 *
 */
START_TEST(test_insert)
{
    BinarySearchTreeNode tree = create(10);
    insert(&tree, 20);
    insert(&tree, 15);
    insert(&tree, 25);
    insert(&tree, 12);
    insert(&tree, 17);
    insert(&tree, 22);
    insert(&tree, 27);
    insert(&tree, 15);

    ck_assert_int_eq(search(&tree, 10), 1);
    ck_assert_int_eq(search(&tree, 20), 1);
    ck_assert_int_eq(search(&tree, 15), 1);
    ck_assert_int_eq(search(&tree, 25), 1);
    ck_assert_int_eq(search(&tree, 12), 1);
    ck_assert_int_eq(search(&tree, 17), 1);
    ck_assert_int_eq(search(&tree, 22), 1);
    ck_assert_int_eq(search(&tree, 27), 1);
    ck_assert_int_eq(search(&tree, 15), 1);

    ck_assert_int_eq(search(&tree, 9), 0);
    ck_assert_int_eq(search(&tree, 14), 0);
    ck_assert_int_eq(search(&tree, 16), 0);
    ck_assert_int_eq(search(&tree, 23), 0);
    ck_assert_int_eq(search(&tree, 26), 0);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("binary_search_tree");
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
