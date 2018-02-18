#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "quad_tree.h"

/**
 *
 */
START_TEST(test_create)
{
    QuadTreeNode node = create();

    ck_assert_int_eq(node.children[0], NULL);
    ck_assert_int_eq(node.children[1], NULL);
    ck_assert_int_eq(node.children[2], NULL);
    ck_assert_int_eq(node.children[3], NULL);

    ck_assert_int_eq(node.data, 0);
}
END_TEST

/**
 *
 */
START_TEST(test_allocateChildren)
{
    QuadTreeNode node = create();

    ck_assert_int_eq(node.children[0], NULL);
    ck_assert_int_eq(node.children[1], NULL);
    ck_assert_int_eq(node.children[2], NULL);
    ck_assert_int_eq(node.children[3], NULL);

    ck_assert_int_eq(node.data, 0);

    allocateChildren(&node);

    ck_assert_int_ne(node.children[0], NULL);
    ck_assert_int_ne(node.children[1], NULL);
    ck_assert_int_ne(node.children[2], NULL);
    ck_assert_int_ne(node.children[3], NULL);

    ck_assert_int_eq(node.children[0]->children[0], NULL);
    ck_assert_int_eq(node.children[0]->children[1], NULL);
    ck_assert_int_eq(node.children[0]->children[2], NULL);
    ck_assert_int_eq(node.children[0]->children[3], NULL);
    ck_assert_int_eq(node.children[0]->data, 0);

    ck_assert_int_eq(node.children[1]->children[0], NULL);
    ck_assert_int_eq(node.children[1]->children[1], NULL);
    ck_assert_int_eq(node.children[1]->children[2], NULL);
    ck_assert_int_eq(node.children[1]->children[3], NULL);
    ck_assert_int_eq(node.children[1]->data, 0);

    ck_assert_int_eq(node.children[2]->children[0], NULL);
    ck_assert_int_eq(node.children[2]->children[1], NULL);
    ck_assert_int_eq(node.children[2]->children[2], NULL);
    ck_assert_int_eq(node.children[2]->children[3], NULL);
    ck_assert_int_eq(node.children[2]->data, 0);

    ck_assert_int_eq(node.children[3]->children[0], NULL);
    ck_assert_int_eq(node.children[3]->children[1], NULL);
    ck_assert_int_eq(node.children[3]->children[2], NULL);
    ck_assert_int_eq(node.children[3]->children[3], NULL);
    ck_assert_int_eq(node.children[3]->data, 0);
}
END_TEST

/**
 *
 */
START_TEST(test_freeQT)
{
    /* free when there is only a root node */

    QuadTreeNode firstNode = create();

    ck_assert_int_eq(firstNode.children[0], NULL);
    ck_assert_int_eq(firstNode.children[1], NULL);
    ck_assert_int_eq(firstNode.children[2], NULL);
    ck_assert_int_eq(firstNode.children[3], NULL);

    ck_assert_int_eq(firstNode.data, 0);

    freeQT(&firstNode);

    /* free when there are multiple nested nodes */

    QuadTreeNode secondNode = create();

    ck_assert_int_eq(secondNode.children[0], NULL);
    ck_assert_int_eq(secondNode.children[1], NULL);
    ck_assert_int_eq(secondNode.children[2], NULL);
    ck_assert_int_eq(secondNode.children[3], NULL);

    ck_assert_int_eq(secondNode.data, 0);

    allocateChildren(&secondNode);

    allocateChildren(secondNode.children[0]);

    ck_assert_int_ne(secondNode.children[0]->children[0], NULL);
    ck_assert_int_eq(secondNode.children[1]->children[0], NULL);

    freeQT(&secondNode);

    ck_assert_int_eq(secondNode.children[0], NULL);
    ck_assert_int_eq(secondNode.children[1], NULL);
    ck_assert_int_eq(secondNode.children[2], NULL);
    ck_assert_int_eq(secondNode.children[3], NULL);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("quad_tree");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_allocateChildren);
    tcase_add_test(tcase, test_freeQT);

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
