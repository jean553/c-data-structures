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

    ck_assert_int_eq(search(&tree, 10)->key, 10);
    ck_assert_int_eq(search(&tree, 20)->key, 20);
    ck_assert_int_eq(search(&tree, 15)->key, 15);
    ck_assert_int_eq(search(&tree, 25)->key, 25);
    ck_assert_int_eq(search(&tree, 12)->key, 12);
    ck_assert_int_eq(search(&tree, 17)->key, 17);
    ck_assert_int_eq(search(&tree, 22)->key, 22);
    ck_assert_int_eq(search(&tree, 27)->key, 27);
    ck_assert_int_eq(search(&tree, 15)->key, 15);

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
START_TEST(test_removeAt)
{
    /* delete from the leaf */

    BinarySearchTreeNode first_tree = create(10);
    insert(&first_tree, 20);
    insert(&first_tree, 15);

    ck_assert_int_eq(search(&first_tree, 15)->key, 15);

    removeAt(&first_tree, 15);

    ck_assert_int_eq(search(&first_tree, 15), NULL);

    /* delete node with one child */

    BinarySearchTreeNode second_tree = create(10);
    insert(&second_tree, 20);
    insert(&second_tree, 15);

    ck_assert_int_eq(search(&second_tree, 10)->key, 10);
    ck_assert_int_eq(search(&second_tree, 20)->key, 20);
    ck_assert_int_eq(search(&second_tree, 15)->key, 15);

    removeAt(&second_tree, 20);

    ck_assert_int_eq(search(&second_tree, 10)->key, 10);
    ck_assert_int_eq(search(&second_tree, 20), NULL);
    ck_assert_int_eq(search(&second_tree, 15)->key, 15);

    /* others tests to delete node with one child */

    BinarySearchTreeNode third_tree = create(10);
    insert(&third_tree, 20);
    insert(&third_tree, 15);
    insert(&third_tree, 19);
    insert(&third_tree, 18);
    insert(&third_tree, 17);

    ck_assert_int_eq(search(&third_tree, 10)->key, 10);
    ck_assert_int_eq(search(&third_tree, 20)->key, 20);
    ck_assert_int_eq(search(&third_tree, 15)->key, 15);
    ck_assert_int_eq(search(&third_tree, 19)->key, 19);
    ck_assert_int_eq(search(&third_tree, 18)->key, 18);
    ck_assert_int_eq(search(&third_tree, 17)->key, 17);

    removeAt(&third_tree, 20);

    ck_assert_int_eq(search(&third_tree, 10)->key, 10);
    ck_assert_int_eq(search(&third_tree, 15)->key, 15);
    ck_assert_int_eq(search(&third_tree, 19)->key, 19);
    ck_assert_int_eq(search(&third_tree, 18)->key, 18);
    ck_assert_int_eq(search(&third_tree, 17)->key, 17);
    ck_assert_int_eq(search(&third_tree, 20), NULL);

    removeAt(&third_tree, 19);

    ck_assert_int_eq(search(&third_tree, 10)->key, 10);
    ck_assert_int_eq(search(&third_tree, 15)->key, 15);
    ck_assert_int_eq(search(&third_tree, 18)->key, 18);
    ck_assert_int_eq(search(&third_tree, 17)->key, 17);
    ck_assert_int_eq(search(&third_tree, 19), NULL);

    removeAt(&third_tree, 18);

    ck_assert_int_eq(search(&third_tree, 10)->key, 10);
    ck_assert_int_eq(search(&third_tree, 15)->key, 15);
    ck_assert_int_eq(search(&third_tree, 17)->key, 17);
    ck_assert_int_eq(search(&third_tree, 18), NULL);
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
    tcase_add_test(tcase, test_removeAt);

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
