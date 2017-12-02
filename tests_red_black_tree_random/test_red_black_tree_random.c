#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "red_black_tree.h"

/**
 * NOTE: in the following ASCII trees, B and R represents Black and Red
 * The number represents random values.
 */

/**
 *
 */
START_TEST(test_insert_random)
{
    /**
     * Test that simulates this sitation:
     * https://www.youtube.com/watch?v=PhY56LpCtP4&t=300s
     */
    RedBlackTreeNode tree = create(1);

    ck_assert_int_eq(tree.color, BLACK);
    ck_assert_int_eq(tree.key, 1);

    insert(&tree, 2);

    ck_assert_int_eq(tree.color, BLACK);
    ck_assert_int_eq(tree.key, 1);
    ck_assert_int_eq(tree.right->color, RED);
    ck_assert_int_eq(tree.right->key, 2);

    insert(&tree, 3);

    ck_assert_int_eq(tree.color, BLACK);
    ck_assert_int_eq(tree.key, 2);
    ck_assert_int_eq(tree.right->color, RED);
    ck_assert_int_eq(tree.right->key, 3);
    ck_assert_int_eq(tree.left->color, RED);
    ck_assert_int_eq(tree.left->key, 1);

    insert(&tree, 4);

    ck_assert_int_eq(tree.color, BLACK);
    ck_assert_int_eq(tree.key, 2);
    ck_assert_int_eq(tree.right->color, BLACK);
    ck_assert_int_eq(tree.right->key, 3);
    ck_assert_int_eq(tree.right->right->color, RED);
    ck_assert_int_eq(tree.right->right->key, 4);
    ck_assert_int_eq(tree.left->color, BLACK);
    ck_assert_int_eq(tree.left->key, 1);

    insert(&tree, 5);

    ck_assert_int_eq(tree.color, BLACK);
    ck_assert_int_eq(tree.key, 2);
    ck_assert_int_eq(tree.right->color, BLACK);
    ck_assert_int_eq(tree.right->key, 4);
    ck_assert_int_eq(tree.right->right->color, RED);
    ck_assert_int_eq(tree.right->right->key, 5);
    ck_assert_int_eq(tree.right->left->color, RED);
    ck_assert_int_eq(tree.right->left->key, 3);
    ck_assert_int_eq(tree.left->color, BLACK);
    ck_assert_int_eq(tree.left->key, 1);

    insert(&tree, 6);

    ck_assert_int_eq(tree.color, BLACK);
    ck_assert_int_eq(tree.key, 2);
    ck_assert_int_eq(tree.right->color, RED);
    ck_assert_int_eq(tree.right->key, 4);
    ck_assert_int_eq(tree.right->right->color, BLACK);
    ck_assert_int_eq(tree.right->right->key, 5);
    ck_assert_int_eq(tree.right->right->right->color, RED);
    ck_assert_int_eq(tree.right->right->right->key, 6);
    ck_assert_int_eq(tree.right->left->color, BLACK);
    ck_assert_int_eq(tree.right->left->key, 3);
    ck_assert_int_eq(tree.left->color, BLACK);
    ck_assert_int_eq(tree.left->key, 1);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("red_black_tree");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_insert_random);

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
