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
    ck_assert_int_eq(third_rb_tree.right->right, NULL);

    insert(&third_rb_tree, 15);

    ck_assert_int_eq(third_rb_tree.color, BLACK);
    ck_assert_int_eq(third_rb_tree.key, 7);
    ck_assert_int_eq(third_rb_tree.left->color, BLACK);
    ck_assert_int_eq(third_rb_tree.left->key, 5);
    ck_assert_int_eq(third_rb_tree.right->color, BLACK);
    ck_assert_int_eq(third_rb_tree.right->key, 10);
    ck_assert_int_eq(third_rb_tree.right->right->color, RED);
    ck_assert_int_eq(third_rb_tree.right->right->key, 15);
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
