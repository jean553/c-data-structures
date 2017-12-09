#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "b_tree.h"

/**
 *
 */
START_TEST(test_create)
{
    BTreeNode tree = create(10, 20);
}
END_TEST

/**
 *
 */
START_TEST(test_search)
{
    BTreeNode tree = create(10, 20);

    ck_assert_int_eq(search(&tree, 0), 0);
    ck_assert_int_eq(search(&tree, 10), 1);
    ck_assert_int_eq(search(&tree, 20), 0);
}
END_TEST

/**
 *
 */
START_TEST(test_insert_in_root)
{
    BTreeNode tree = create(10, 20);

    ck_assert_int_eq(search(&tree, 10), 1);
    ck_assert_int_eq(search(&tree, 20), 0);
    ck_assert_int_eq(search(&tree, 30), 0);
    ck_assert_int_eq(search(&tree, 40), 0);

    insert(&tree, 20, 500);

    ck_assert_int_eq(search(&tree, 10), 1);
    ck_assert_int_eq(search(&tree, 20), 1);
    ck_assert_int_eq(search(&tree, 30), 0);
    ck_assert_int_eq(search(&tree, 40), 0);

    insert(&tree, 30, 600);

    ck_assert_int_eq(search(&tree, 10), 1);
    ck_assert_int_eq(search(&tree, 20), 1);
    ck_assert_int_eq(search(&tree, 30), 1);
    ck_assert_int_eq(search(&tree, 40), 0);

    insert(&tree, 40, 700);

    ck_assert_int_eq(search(&tree, 10), 1);
    ck_assert_int_eq(search(&tree, 20), 1);
    ck_assert_int_eq(search(&tree, 30), 1);
    ck_assert_int_eq(search(&tree, 40), 1);
}
END_TEST

/**
 *
 */
START_TEST(test_insert_in_root_child)
{
    BTreeNode tree = create(10, 100);
    insert(&tree, 20, 200);
    insert(&tree, 30, 300);
    insert(&tree, 40, 400);

    ck_assert_int_eq(search(&tree, 10), 1);
    ck_assert_int_eq(search(&tree, 20), 1);
    ck_assert_int_eq(search(&tree, 30), 1);
    ck_assert_int_eq(search(&tree, 40), 1);

    ck_assert_int_eq(search(&tree, 5), 0);
    ck_assert_int_eq(search(&tree, 15), 0);
    ck_assert_int_eq(search(&tree, 25), 0);
    ck_assert_int_eq(search(&tree, 35), 0);
    ck_assert_int_eq(search(&tree, 45), 0);

    insert(&tree, 5, 500);
    insert(&tree, 15, 600);
    insert(&tree, 25, 700);
    insert(&tree, 35, 800);
    insert(&tree, 45, 900);

    ck_assert_int_eq(search(&tree, 5), 1);
    ck_assert_int_eq(search(&tree, 15), 1);
    ck_assert_int_eq(search(&tree, 25), 1);
    ck_assert_int_eq(search(&tree, 35), 1);
    ck_assert_int_eq(search(&tree, 45), 1);
}
END_TEST

/**
 *
 */
START_TEST(test_insert_many_items_in_root_child)
{
    BTreeNode tree = create(10, 100);
    insert(&tree, 20, 200);
    insert(&tree, 30, 300);
    insert(&tree, 40, 400);

    ck_assert_int_eq(search(&tree, 10), 1);
    ck_assert_int_eq(search(&tree, 20), 1);
    ck_assert_int_eq(search(&tree, 30), 1);
    ck_assert_int_eq(search(&tree, 40), 1);

    insert(&tree, 5, 500);
    insert(&tree, 6, 600);
    insert(&tree, 7, 700);
    insert(&tree, 8, 800);

    ck_assert_int_eq(search(&tree, 9), 0);

    ck_assert_int_eq(search(&tree, 50), 0);
    ck_assert_int_eq(search(&tree, 51), 0);
    ck_assert_int_eq(search(&tree, 52), 0);
    ck_assert_int_eq(search(&tree, 53), 0);

    ck_assert_int_eq(search(&tree, 54), 0);
    ck_assert_int_eq(search(&tree, 55), 0);

    insert(&tree, 9, 900);

    insert(&tree, 50, 1000);
    insert(&tree, 51, 2000);
    insert(&tree, 52, 3000);
    insert(&tree, 53, 4000);

    insert(&tree, 54, 5000);
    insert(&tree, 55, 6000);

    ck_assert_int_eq(search(&tree, 5), 1);
    ck_assert_int_eq(search(&tree, 6), 1);
    ck_assert_int_eq(search(&tree, 7), 1);
    ck_assert_int_eq(search(&tree, 8), 1);

    ck_assert_int_eq(search(&tree, 9), 1);

    ck_assert_int_eq(search(&tree, 50), 1);
    ck_assert_int_eq(search(&tree, 51), 1);
    ck_assert_int_eq(search(&tree, 52), 1);
    ck_assert_int_eq(search(&tree, 53), 1);

    ck_assert_int_eq(search(&tree, 54), 1);
    ck_assert_int_eq(search(&tree, 55), 1);
}
END_TEST

/**
 *
 */
START_TEST(test_insert_unordered)
{
    BTreeNode tree = create(10, 100);

    ck_assert_int_eq(search(&tree, 10), 1);
    ck_assert_int_eq(search(&tree, 5), 0);
    ck_assert_int_eq(search(&tree, 2), 0);

    ck_assert_int_eq(tree.items[0]->key, 10);

    insert(&tree, 5, 150);

    ck_assert_int_eq(search(&tree, 10), 1);
    ck_assert_int_eq(search(&tree, 5), 1);
    ck_assert_int_eq(search(&tree, 2), 0);

    ck_assert_int_eq(tree.items[0]->key, 5);
    ck_assert_int_eq(tree.items[1]->key, 10);

    insert(&tree, 2, 150);

    ck_assert_int_eq(search(&tree, 10), 1);
    ck_assert_int_eq(search(&tree, 5), 1);
    ck_assert_int_eq(search(&tree, 2), 1);

    ck_assert_int_eq(tree.items[0]->key, 2);
    ck_assert_int_eq(tree.items[1]->key, 5);
    ck_assert_int_eq(tree.items[2]->key, 10);

    insert(&tree, 15, 150);

    ck_assert_int_eq(tree.items[0]->key, 2);
    ck_assert_int_eq(tree.items[1]->key, 5);
    ck_assert_int_eq(tree.items[2]->key, 10);
    ck_assert_int_eq(tree.items[3]->key, 15);
}
END_TEST

/**
 *
 */
Suite* b_tree_suite()
{
    Suite *suite = suite_create("b_tree");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_search);
    tcase_add_test(tcase, test_insert_in_root);
    tcase_add_test(tcase, test_insert_in_root_child);
    tcase_add_test(tcase, test_insert_many_items_in_root_child);
    tcase_add_test(tcase, test_insert_unordered);

    suite_add_tcase(suite, tcase);

    return suite;
}

/**
 *
 */
int main(int argc, char *argv[])
{
    Suite *suite = b_tree_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
