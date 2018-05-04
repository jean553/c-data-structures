#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "merkle_tree.h"

/**
 *
 */
START_TEST(test_create)
{
    MerkleTree tree = createMerkleTree();

    ck_assert_ptr_eq(tree.merkleNode.left, NULL);
    ck_assert_ptr_eq(tree.merkleNode.right, NULL);
    ck_assert_ptr_eq(tree.merkleNode.hash, NULL);
    ck_assert_int_eq(tree.leavesAmount, 0);
}
END_TEST

/**
 *
 */
Suite* merkle_tree_suite()
{
    Suite *suite = suite_create("merkle_tree");
    TCase *tcase = tcase_create("case");

    suite_add_tcase(suite, tcase);

    return suite;
}

/**
 *
 */
int main(int argc, char *argv[])
{
    Suite *suite = merkle_tree_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
