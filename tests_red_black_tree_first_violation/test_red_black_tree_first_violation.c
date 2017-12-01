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
START_TEST(test_insert_first_violation)
{
    /**
     * Try to resolve the following violation:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   2R  6R
     *   |
     *  ---
     *  |
     *  1R
     *
     * to:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   2B  6B
     *   |
     *  ---
     *  |
     *  1R
     */

    RedBlackTreeNode first_rb_tree = create(10);
    ck_assert_int_eq(first_rb_tree.color, BLACK);

    insert(&first_rb_tree, 5);
    ck_assert_int_eq(first_rb_tree.color, BLACK);
    ck_assert_int_eq(first_rb_tree.left->color, RED);

    insert(&first_rb_tree, 15);
    ck_assert_int_eq(first_rb_tree.color, BLACK);
    ck_assert_int_eq(first_rb_tree.left->color, RED);
    ck_assert_int_eq(first_rb_tree.right->color, RED);

    insert(&first_rb_tree, 3);
    ck_assert_int_eq(first_rb_tree.color, BLACK);
    ck_assert_int_eq(first_rb_tree.right->color, BLACK);
    ck_assert_int_eq(first_rb_tree.left->color, BLACK);
    ck_assert_int_eq(first_rb_tree.left->left->color, RED);

    /**
     * Try to resolve the following violation:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   2R  6R
     *   |
     *  ---
     *    |
     *    3R
     *
     * to:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   2B  6B
     *   |
     *  ---
     *    |
     *    3R
     */

    RedBlackTreeNode second_rb_tree = create(10);
    ck_assert_int_eq(second_rb_tree.color, BLACK);

    insert(&second_rb_tree, 5);
    ck_assert_int_eq(second_rb_tree.color, BLACK);
    ck_assert_int_eq(second_rb_tree.left->color, RED);

    insert(&second_rb_tree, 15);
    ck_assert_int_eq(second_rb_tree.color, BLACK);
    ck_assert_int_eq(second_rb_tree.left->color, RED);
    ck_assert_int_eq(second_rb_tree.right->color, RED);

    insert(&second_rb_tree, 7);
    ck_assert_int_eq(second_rb_tree.color, BLACK);
    ck_assert_int_eq(second_rb_tree.right->color, BLACK);
    ck_assert_int_eq(second_rb_tree.left->color, BLACK);
    ck_assert_int_eq(second_rb_tree.left->right->color, RED);

    /**
     * Try to resolve the following violation:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   1R  8R
     *       |
     *      ---
     *      |
     *      7R
     *
     * to:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   1B  8B
     *       |
     *      ---
     *      |
     *      7R
     */

    RedBlackTreeNode third_rb_tree = create(10);
    ck_assert_int_eq(third_rb_tree.color, BLACK);

    insert(&third_rb_tree, 5);
    ck_assert_int_eq(third_rb_tree.color, BLACK);
    ck_assert_int_eq(third_rb_tree.left->color, RED);

    insert(&third_rb_tree, 15);
    ck_assert_int_eq(third_rb_tree.color, BLACK);
    ck_assert_int_eq(third_rb_tree.left->color, RED);
    ck_assert_int_eq(third_rb_tree.right->color, RED);

    insert(&third_rb_tree, 12);
    ck_assert_int_eq(third_rb_tree.color, BLACK);
    ck_assert_int_eq(third_rb_tree.right->color, BLACK);
    ck_assert_int_eq(third_rb_tree.left->color, BLACK);
    ck_assert_int_eq(third_rb_tree.right->left->color, RED);

    /**
     * Try to resolve the following violation:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   1R  6R
     *       |
     *      ---
     *        |
     *        7R
     *
     * to:
     *
     *     5B
     *     |
     *   -----
     *   |   |
     *   1B  6B
     *       |
     *      ---
     *        |
     *        7R
     */
    RedBlackTreeNode fourth_rb_tree = create(10);
    ck_assert_int_eq(fourth_rb_tree.color, BLACK);

    insert(&fourth_rb_tree, 5);
    ck_assert_int_eq(fourth_rb_tree.color, BLACK);
    ck_assert_int_eq(fourth_rb_tree.left->color, RED);

    insert(&fourth_rb_tree, 15);
    ck_assert_int_eq(fourth_rb_tree.color, BLACK);
    ck_assert_int_eq(fourth_rb_tree.left->color, RED);
    ck_assert_int_eq(fourth_rb_tree.right->color, RED);

    insert(&fourth_rb_tree, 20);
    ck_assert_int_eq(fourth_rb_tree.color, BLACK);
    ck_assert_int_eq(fourth_rb_tree.right->color, BLACK);
    ck_assert_int_eq(fourth_rb_tree.left->color, BLACK);
    ck_assert_int_eq(fourth_rb_tree.right->right->color, RED);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("red_black_tree");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_insert_first_violation);

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
