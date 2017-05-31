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

    RedBlackTreeNode tree = create(10);
    insert(&tree, 5);
    insert(&tree, 15);
    insert(&tree, 3);

    ck_assert_int_eq(tree.color, BLACK);
    ck_assert_int_eq(tree.right->color, BLACK);
    ck_assert_int_eq(tree.left->color, BLACK);
    ck_assert_int_eq(tree.left->left->color, RED);
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
