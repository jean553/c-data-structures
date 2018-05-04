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
START_TEST(test_insert_first_and_second_violation)
{
    /**
     * Try to resolve the following violation:
     *
     *     5B
     *     |
     *    ---
     *      |
     *      7R
     *      |
     *     ---
     *       |
     *       10R
     *
     * to:
     *
     *     7B
     *     |
     *   -----
     *   |   |
     *   5R  10R
     *
     * then
     *
     *     7B
     *     |
     *   -----
     *   |   |
     *   5R  10R
     *       |
     *      ---
     *        |
     *        15R
     *
     * to:
     *
     *     7B
     *     |
     *   -----
     *   |   |
     *   5B  10B
     *       |
     *      ---
     *        |
     *        15R
     */
    RedBlackTreeNode third_rb_tree = create(5);

    ck_assert_int_eq(third_rb_tree.color, BLACK);
    ck_assert_int_eq(third_rb_tree.key, 5);

    insert(&third_rb_tree, 7);

    ck_assert_int_eq(third_rb_tree.color, BLACK);
    ck_assert_int_eq(third_rb_tree.key, 5);
    ck_assert_int_eq(third_rb_tree.right->color, RED);
    ck_assert_int_eq(third_rb_tree.right->key, 7);

    insert(&third_rb_tree, 10);

    ck_assert_int_eq(third_rb_tree.color, BLACK);
    ck_assert_int_eq(third_rb_tree.key, 7);
    ck_assert_int_eq(third_rb_tree.left->color, RED);
    ck_assert_int_eq(third_rb_tree.left->key, 5);
    ck_assert_int_eq(third_rb_tree.right->color, RED);
    ck_assert_int_eq(third_rb_tree.right->key, 10);
    ck_assert_ptr_eq(third_rb_tree.right->right, NULL);

    insert(&third_rb_tree, 15);

    ck_assert_int_eq(third_rb_tree.color, BLACK);
    ck_assert_int_eq(third_rb_tree.key, 7);
    ck_assert_int_eq(third_rb_tree.left->color, BLACK);
    ck_assert_int_eq(third_rb_tree.left->key, 5);
    ck_assert_int_eq(third_rb_tree.right->color, BLACK);
    ck_assert_int_eq(third_rb_tree.right->key, 10);
    ck_assert_int_eq(third_rb_tree.right->right->color, RED);
    ck_assert_int_eq(third_rb_tree.right->right->key, 15);

    /**
     * Try to resolve the following violation:
     *
     *     5B
     *     |
     *    ---
     *    |
     *    4R
     *    |
     *   ---
     *   |
     *   3R
     *
     * to:
     *
     *     4B
     *     |
     *   -----
     *   |   |
     *   3R  5R
     *
     * then
     *
     *     4B
     *     |
     *   -----
     *   |   |
     *   3R  5R
     *   |
     *  ---
     *  |
     *  2R
     *
     * to:
     *
     *     4B
     *     |
     *   -----
     *   |   |
     *   3B  5B
     *   |
     *  ---
     *  |
     *  2R
     */
    RedBlackTreeNode fourth_rb_tree = create(5);

    ck_assert_int_eq(fourth_rb_tree.color, BLACK);
    ck_assert_int_eq(fourth_rb_tree.key, 5);

    insert(&fourth_rb_tree, 4);

    ck_assert_int_eq(fourth_rb_tree.color, BLACK);
    ck_assert_int_eq(fourth_rb_tree.key, 5);
    ck_assert_int_eq(fourth_rb_tree.left->color, RED);
    ck_assert_int_eq(fourth_rb_tree.left->key, 4);

    insert(&fourth_rb_tree, 3);

    ck_assert_int_eq(fourth_rb_tree.color, BLACK);
    ck_assert_int_eq(fourth_rb_tree.key, 4);
    ck_assert_int_eq(fourth_rb_tree.right->color, RED);
    ck_assert_int_eq(fourth_rb_tree.right->key, 5);
    ck_assert_int_eq(fourth_rb_tree.left->color, RED);
    ck_assert_int_eq(fourth_rb_tree.left->key, 3);

    insert(&fourth_rb_tree, 2);

    ck_assert_int_eq(fourth_rb_tree.color, BLACK);
    ck_assert_int_eq(fourth_rb_tree.key, 4);
    ck_assert_int_eq(fourth_rb_tree.right->color, BLACK);
    ck_assert_int_eq(fourth_rb_tree.right->key, 5);
    ck_assert_int_eq(fourth_rb_tree.left->color, BLACK);
    ck_assert_int_eq(fourth_rb_tree.left->key, 3);
    ck_assert_int_eq(fourth_rb_tree.left->left->color, RED);
    ck_assert_int_eq(fourth_rb_tree.left->left->key, 2);

    /**
     * Try to resolve the following violation:
     *
     *     5B
     *     |
     *    ---
     *    |
     *    4R
     *    |
     *   ---
     *   |
     *   3R
     *
     * to:
     *
     *     4B
     *     |
     *   -----
     *   |   |
     *   3R  5R
     *
     * then
     *
     *     4B
     *     |
     *   -----
     *   |   |
     *   3R  5R
     *   |
     *  ---
     *  |
     *  2R
     *
     * to:
     *
     *     4B
     *     |
     *   -----
     *   |   |
     *   3B  5B
     *   |
     *  ---
     *  |
     *  2R
     *
     * then
     *
     *     4B
     *     |
     *   -----
     *   |   |
     *   3B  5B
     *   |
     *  ---
     *  |
     *  2R
     *  |
     * ---
     * |
     * 1R
     *
     * to:
     *
     *     4B
     *     |
     *   -----
     *   |   |
     *   2B  5B
     *   |
     *  ----
     *  |  |
     *  1R 3R
     */
    RedBlackTreeNode fifth_rb_tree = create(5);

    ck_assert_int_eq(fifth_rb_tree.color, BLACK);
    ck_assert_int_eq(fifth_rb_tree.key, 5);

    insert(&fifth_rb_tree, 4);

    ck_assert_int_eq(fifth_rb_tree.color, BLACK);
    ck_assert_int_eq(fifth_rb_tree.key, 5);
    ck_assert_int_eq(fifth_rb_tree.left->color, RED);
    ck_assert_int_eq(fifth_rb_tree.left->key, 4);

    insert(&fifth_rb_tree, 3);

    ck_assert_int_eq(fifth_rb_tree.color, BLACK);
    ck_assert_int_eq(fifth_rb_tree.key, 4);
    ck_assert_int_eq(fifth_rb_tree.right->color, RED);
    ck_assert_int_eq(fifth_rb_tree.right->key, 5);
    ck_assert_int_eq(fifth_rb_tree.left->color, RED);
    ck_assert_int_eq(fifth_rb_tree.left->key, 3);

    insert(&fifth_rb_tree, 2);

    ck_assert_int_eq(fifth_rb_tree.color, BLACK);
    ck_assert_int_eq(fifth_rb_tree.key, 4);
    ck_assert_int_eq(fifth_rb_tree.right->color, BLACK);
    ck_assert_int_eq(fifth_rb_tree.right->key, 5);
    ck_assert_int_eq(fifth_rb_tree.left->color, BLACK);
    ck_assert_int_eq(fifth_rb_tree.left->key, 3);
    ck_assert_int_eq(fifth_rb_tree.left->left->color, RED);
    ck_assert_int_eq(fifth_rb_tree.left->left->key, 2);

    insert(&fifth_rb_tree, 1);

    ck_assert_int_eq(fifth_rb_tree.color, BLACK);
    ck_assert_int_eq(fifth_rb_tree.key, 4);
    ck_assert_int_eq(fifth_rb_tree.right->color, BLACK);
    ck_assert_int_eq(fifth_rb_tree.right->key, 5);
    ck_assert_int_eq(fifth_rb_tree.left->color, BLACK);
    ck_assert_int_eq(fifth_rb_tree.left->key, 2);
    ck_assert_int_eq(fifth_rb_tree.left->left->color, RED);
    ck_assert_int_eq(fifth_rb_tree.left->left->key, 1);
    ck_assert_ptr_eq(fifth_rb_tree.left->left->left, NULL);
    ck_assert_ptr_eq(fifth_rb_tree.left->left->right, NULL);
    ck_assert_int_eq(fifth_rb_tree.left->right->color, RED);
    ck_assert_int_eq(fifth_rb_tree.left->right->key, 3);
    ck_assert_ptr_eq(fifth_rb_tree.left->right->left, NULL);
    ck_assert_ptr_eq(fifth_rb_tree.left->right->right, NULL);

    /**
     * Try to resolve the following violation:
     *
     *     10B
     *     |
     *    ---
     *    |
     *    5R
     *    |
     *   ---
     *   |
     *   2R
     *
     * to:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   2R  10R
     *
     * then
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   2R  10R
     *   |
     *  ---
     *  |
     *  0R
     *
     * to:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   2B  10B
     *   |
     *  ---
     *  |
     *  0R
     *
     * then
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   2B  10B
     *   |
     *  ---
     *  |
     *  0R
     *  |
     * ---
     *   |
     *   1R
     *
     * to:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   1B  10B
     *   |
     *  ----
     *  |  |
     *  0R 2R
     */
    RedBlackTreeNode sixth_rb_tree = create(10);

    ck_assert_int_eq(sixth_rb_tree.color, BLACK);
    ck_assert_int_eq(sixth_rb_tree.key, 10);

    insert(&sixth_rb_tree, 5);

    ck_assert_int_eq(sixth_rb_tree.color, BLACK);
    ck_assert_int_eq(sixth_rb_tree.key, 10);
    ck_assert_int_eq(sixth_rb_tree.left->color, RED);
    ck_assert_int_eq(sixth_rb_tree.left->key, 5);

    insert(&sixth_rb_tree, 2);

    ck_assert_int_eq(sixth_rb_tree.color, BLACK);
    ck_assert_int_eq(sixth_rb_tree.key, 5);
    ck_assert_int_eq(sixth_rb_tree.left->color, RED);
    ck_assert_int_eq(sixth_rb_tree.left->key, 2);
    ck_assert_int_eq(sixth_rb_tree.right->color, RED);
    ck_assert_int_eq(sixth_rb_tree.right->key, 10);

    insert(&sixth_rb_tree, 0);

    ck_assert_int_eq(sixth_rb_tree.color, BLACK);
    ck_assert_int_eq(sixth_rb_tree.key, 5);
    ck_assert_int_eq(sixth_rb_tree.left->color, BLACK);
    ck_assert_int_eq(sixth_rb_tree.left->key, 2);
    ck_assert_int_eq(sixth_rb_tree.right->color, BLACK);
    ck_assert_int_eq(sixth_rb_tree.right->key, 10);
    ck_assert_int_eq(sixth_rb_tree.left->left->color, RED);
    ck_assert_int_eq(sixth_rb_tree.left->left->key, 0);

    insert(&sixth_rb_tree, 1);

    ck_assert_int_eq(sixth_rb_tree.color, BLACK);
    ck_assert_int_eq(sixth_rb_tree.key, 5);
    ck_assert_int_eq(sixth_rb_tree.left->color, BLACK);
    ck_assert_int_eq(sixth_rb_tree.left->key, 1);
    ck_assert_int_eq(sixth_rb_tree.right->color, BLACK);
    ck_assert_int_eq(sixth_rb_tree.right->key, 10);
    ck_assert_ptr_eq(sixth_rb_tree.right->left, NULL);
    ck_assert_ptr_eq(sixth_rb_tree.right->right, NULL);
    ck_assert_int_eq(sixth_rb_tree.left->left->color, RED);
    ck_assert_int_eq(sixth_rb_tree.left->left->key, 0);
    ck_assert_ptr_eq(sixth_rb_tree.left->left->left, NULL);
    ck_assert_ptr_eq(sixth_rb_tree.left->left->right, NULL);
    ck_assert_int_eq(sixth_rb_tree.left->right->color, RED);
    ck_assert_int_eq(sixth_rb_tree.left->right->key, 2);
    ck_assert_ptr_eq(sixth_rb_tree.left->right->left, NULL);
    ck_assert_ptr_eq(sixth_rb_tree.left->right->right, NULL);

    /**
     * Try to resolve the following violation:
     *
     *     10B
     *     |
     *    ---
     *    |
     *    5R
     *    |
     *   ---
     *   |
     *   2R
     *
     * to:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   2R  10R
     *
     * then
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   2R  10R
     *   |
     *  ---
     *    |
     *    4R
     *
     * to:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   2B  10B
     *   |
     *  ---
     *    |
     *    4R
     *
     * then
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   2B  10B
     *   |
     *  ---
     *    |
     *    4R
     *    |
     *   ---
     *   |
     *   3R
     *
     * to:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   3B  10B
     *   |
     *  ----
     *  |  |
     *  2R 4R
     */
    RedBlackTreeNode seventh_rb_tree = create(10);

    ck_assert_int_eq(seventh_rb_tree.color, BLACK);
    ck_assert_int_eq(seventh_rb_tree.key, 10);

    insert(&seventh_rb_tree, 5);

    ck_assert_int_eq(seventh_rb_tree.color, BLACK);
    ck_assert_int_eq(seventh_rb_tree.key, 10);
    ck_assert_int_eq(seventh_rb_tree.left->color, RED);
    ck_assert_int_eq(seventh_rb_tree.left->key, 5);

    insert(&seventh_rb_tree, 2);

    ck_assert_int_eq(seventh_rb_tree.color, BLACK);
    ck_assert_int_eq(seventh_rb_tree.key, 5);
    ck_assert_int_eq(seventh_rb_tree.left->color, RED);
    ck_assert_int_eq(seventh_rb_tree.left->key, 2);
    ck_assert_int_eq(seventh_rb_tree.right->color, RED);
    ck_assert_int_eq(seventh_rb_tree.right->key, 10);

    insert(&seventh_rb_tree, 4);

    ck_assert_int_eq(seventh_rb_tree.color, BLACK);
    ck_assert_int_eq(seventh_rb_tree.key, 5);
    ck_assert_int_eq(seventh_rb_tree.left->color, BLACK);
    ck_assert_int_eq(seventh_rb_tree.left->key, 2);
    ck_assert_int_eq(seventh_rb_tree.left->right->color, RED);
    ck_assert_int_eq(seventh_rb_tree.left->right->key, 4);
    ck_assert_int_eq(seventh_rb_tree.right->color, BLACK);
    ck_assert_int_eq(seventh_rb_tree.right->key, 10);

    insert(&seventh_rb_tree, 3);

    ck_assert_int_eq(seventh_rb_tree.color, BLACK);
    ck_assert_int_eq(seventh_rb_tree.key, 5);
    ck_assert_int_eq(seventh_rb_tree.left->color, BLACK);
    ck_assert_int_eq(seventh_rb_tree.left->key, 3);
    ck_assert_int_eq(seventh_rb_tree.left->left->color, RED);
    ck_assert_int_eq(seventh_rb_tree.left->left->key, 2);
    ck_assert_int_eq(seventh_rb_tree.left->right->color, RED);
    ck_assert_int_eq(seventh_rb_tree.left->right->key, 4);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("red_black_tree");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_insert_first_and_second_violation);

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
