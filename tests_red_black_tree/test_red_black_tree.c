#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "red_black_tree.h"

/**
 *
 */
START_TEST(test_create)
{
    RedBlackTreeNode first_tree = create(10);
}
END_TEST

/**
 *
 */
START_TEST(test_insert)
{
    /* simulate the red parent and red uncle violation
       when the grandparent is the root node of the tree */

    RedBlackTreeNode first_tree = create(10);
    insert(&first_tree, 5);
    insert(&first_tree, 15);
    insert(&first_tree, 3);

    ck_assert_int_eq(first_tree.color, BLACK);
    ck_assert_int_eq(first_tree.right->color, BLACK);
    ck_assert_int_eq(first_tree.left->color, BLACK);
    ck_assert_int_eq(first_tree.left->left->color, RED);

    /* simulate the red parent and black uncle violation
       when the inserted node is the left child and
       when the grandparent is the root node of the tree */

    RedBlackTreeNode second_tree = create(10);
    insert(&second_tree, 5);
    insert(&second_tree, 15);
    insert(&second_tree, 3);
    insert(&second_tree, 1);

    ck_assert_int_eq(second_tree.color, BLACK);
    ck_assert_int_eq(second_tree.right->color, BLACK);
    ck_assert_int_eq(second_tree.left->color, BLACK);
    ck_assert_int_eq(second_tree.left->left->color, RED);
    ck_assert_int_eq(second_tree.left->right->color, RED);

    ck_assert_int_eq(second_tree.key, 10);
    ck_assert_int_eq(second_tree.right->key, 15);
    ck_assert_int_eq(second_tree.left->key, 3);
    ck_assert_int_eq(second_tree.left->left->key, 1);
    ck_assert_int_eq(second_tree.left->right->key, 5);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("red_black_tree");
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
