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

    ck_assert_ptr_eq(tree.merkleNode, NULL);
    ck_assert_int_eq(tree.leavesAmount, 0);
}
END_TEST

/**
 *
 */
START_TEST(test_insert)
{
    MerkleTree tree = createMerkleTree();

    insertMT(&tree, 'A');

    /* expected digest: 6DCD4CE23D88E2EE9568BA546C007C63D9131C1B */
    ck_assert_int_eq(tree.merkleNode->left->hash[0], 0x6D);
    ck_assert_int_eq(tree.merkleNode->left->hash[19], 0x1B);

    ck_assert_int_eq(tree.merkleNode->left->data, 'A');
    ck_assert_int_eq(tree.leavesAmount, 1);

    insertMT(&tree, 'B');

    ck_assert_int_eq(tree.merkleNode->data, 0);
    /* expected digest: B3E76D777129BD79A970CB4EA882ECFCF7EF9C01 */
    ck_assert_int_eq(tree.merkleNode->hash[0], 0xB3);
    ck_assert_int_eq(tree.merkleNode->hash[19], 0x01);

    ck_assert_int_eq(tree.merkleNode->left->data, 'A');
    ck_assert_ptr_eq(tree.merkleNode->left->left, NULL);
    ck_assert_ptr_eq(tree.merkleNode->left->right, NULL);
    /* expected digest: 6DCD4CE23D88E2EE9568BA546C007C63D9131C1B */
    ck_assert_int_eq(tree.merkleNode->left->hash[0], 0x6D);
    ck_assert_int_eq(tree.merkleNode->left->hash[19], 0x1B);

    ck_assert_int_eq(tree.merkleNode->right->data, 'B');
    ck_assert_ptr_eq(tree.merkleNode->right->left, NULL);
    ck_assert_ptr_eq(tree.merkleNode->right->right, NULL);
    /* expected digest: AE4F281DF5A5D0FF3CAD6371F76D5C29B6D953EC */
    ck_assert_int_eq(tree.merkleNode->right->hash[0], 0xAE);
    ck_assert_int_eq(tree.merkleNode->right->hash[19], 0xEC);

    ck_assert_int_eq(tree.leavesAmount, 2);

    insertMT(&tree, 'C');

    ck_assert_int_eq(tree.merkleNode->data, 0);
    /* expected digest: D2...B2 */
    ck_assert_int_eq(tree.merkleNode->hash[0], 0xD2);
    ck_assert_int_eq(tree.merkleNode->hash[19], 0xB2);

    ck_assert_int_eq(tree.merkleNode->left->data, 0);
    ck_assert_int_eq(tree.merkleNode->left->left->data, 'A');
    ck_assert_int_eq(tree.merkleNode->left->right->data, 'B');
    /* expected digest: B3E76D777129BD79A970CB4EA882ECFCF7EF9C01 */
    ck_assert_int_eq(tree.merkleNode->left->hash[0], 0xB3);
    ck_assert_int_eq(tree.merkleNode->left->hash[19], 0x01);
    /* expected digest: 6DCD4CE23D88E2EE9568BA546C007C63D9131C1B */
    ck_assert_int_eq(tree.merkleNode->left->left->hash[0], 0x6D);
    ck_assert_int_eq(tree.merkleNode->left->left->hash[19], 0x1B);
    /* expected digest: AE4F281DF5A5D0FF3CAD6371F76D5C29B6D953EC */
    ck_assert_int_eq(tree.merkleNode->left->right->hash[0], 0xAE);
    ck_assert_int_eq(tree.merkleNode->left->right->hash[19], 0xEC);

    ck_assert_int_eq(tree.merkleNode->right->data, 0);
    ck_assert_int_eq(tree.merkleNode->right->left->data, 'C');
    ck_assert_int_eq(tree.merkleNode->right->right->data, 0);
    /* expected digest: C8...E2 */
    ck_assert_int_eq(tree.merkleNode->right->hash[0], 0xC8);
    ck_assert_int_eq(tree.merkleNode->right->hash[19], 0xE2);
    /* expected digest: 32096C2E0EFF33D844EE6D675407ACE18289357D */
    ck_assert_int_eq(tree.merkleNode->right->left->hash[0], 0x32);
    ck_assert_int_eq(tree.merkleNode->right->left->hash[19], 0x7D);
    /* expected digest: 5B...4F */
    ck_assert_int_eq(tree.merkleNode->right->right->hash[0], 0x5B);
    ck_assert_int_eq(tree.merkleNode->right->right->hash[19], 0x4F);

    insertMT(&tree, 'D');

    ck_assert_int_eq(tree.merkleNode->right->right->data, 'D');
    /* expected digest: 50C9E8D5FC98727B4BBC93CF5D64A68DB647F04F */
    ck_assert_int_eq(tree.merkleNode->right->right->hash[0], 0x50);
    ck_assert_int_eq(tree.merkleNode->right->right->hash[19], 0x4F);
    /* expected digest: 32096C2E0EFF33D844EE6D675407ACE18289357D */
    ck_assert_int_eq(tree.merkleNode->right->left->hash[0], 0x32);
    ck_assert_int_eq(tree.merkleNode->right->left->hash[19], 0x7D);
    /* expected digest: 9E...7A */
    ck_assert_int_eq(tree.merkleNode->right->hash[0], 0x9E);
    ck_assert_int_eq(tree.merkleNode->right->hash[19], 0x7A);
    /* expected digest: B3E76D777129BD79A970CB4EA882ECFCF7EF9C01 */
    ck_assert_int_eq(tree.merkleNode->left->hash[0], 0xB3);
    ck_assert_int_eq(tree.merkleNode->left->hash[19], 0x01);
    /* expected digest: 6DCD4CE23D88E2EE9568BA546C007C63D9131C1B */
    ck_assert_int_eq(tree.merkleNode->left->left->hash[0], 0x6D);
    ck_assert_int_eq(tree.merkleNode->left->left->hash[19], 0x1B);
    /* expected digest: AE4F281DF5A5D0FF3CAD6371F76D5C29B6D953EC */
    ck_assert_int_eq(tree.merkleNode->left->right->hash[0], 0xAE);
    ck_assert_int_eq(tree.merkleNode->left->right->hash[19], 0xEC);
    /* expected digest: 83...7E */
    ck_assert_int_eq(tree.merkleNode->hash[0], 0x83);
    ck_assert_int_eq(tree.merkleNode->hash[19], 0x7E);

    insertMT(&tree, 'E');

    /* expected digest: E0184ADEDF913B076626646D3F52C3B49C39AD6D */
    ck_assert_int_eq(tree.merkleNode->right->left->left->hash[0], 0xE0);
    ck_assert_int_eq(tree.merkleNode->right->left->left->hash[19], 0x6D);
    /* expected digest: 58...A8 */
    ck_assert_int_eq(tree.merkleNode->right->left->hash[0], 0x58);
    ck_assert_int_eq(tree.merkleNode->right->left->hash[19], 0xA8);
    /* expected digest: 0D...5D */
    ck_assert_int_eq(tree.merkleNode->right->hash[0], 0x0D);
    ck_assert_int_eq(tree.merkleNode->right->hash[19], 0x5D);
    /* expected digest: 83...7E */
    ck_assert_int_eq(tree.merkleNode->left->hash[0], 0x83);
    ck_assert_int_eq(tree.merkleNode->left->hash[19], 0x7E);
}
END_TEST

/**
 *
 */
Suite* merkle_tree_suite()
{
    Suite *suite = suite_create("merkle_tree");
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
    Suite *suite = merkle_tree_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
