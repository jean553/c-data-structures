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

    insert(
        &tree,
        20,
        500
    );

    ck_assert_int_eq(search(&tree, 10), 1);
    ck_assert_int_eq(search(&tree, 20), 1);
    ck_assert_int_eq(search(&tree, 30), 0);
    ck_assert_int_eq(search(&tree, 40), 0);

    insert(
        &tree,
        30,
        600
    );

    ck_assert_int_eq(search(&tree, 10), 1);
    ck_assert_int_eq(search(&tree, 20), 1);
    ck_assert_int_eq(search(&tree, 30), 1);
    ck_assert_int_eq(search(&tree, 40), 0);

    insert(
        &tree,
        40,
        700
    );

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

    insert(&tree, 5, 500);
    insert(&tree, 15, 600);
    insert(&tree, 25, 700);
    insert(&tree, 35, 800);
    insert(&tree, 45, 900);
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
