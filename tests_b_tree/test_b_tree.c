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
Suite* b_tree_suite()
{
    Suite *suite = suite_create("b_tree");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_search);

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
