#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "binary_search_tree.h"

/**
 *
 */
START_TEST(test_create)
{
    BinarySearchTree tree = create(10);
}
END_TEST

/**
 *
 */
START_TEST(test_insert)
{
    BinarySearchTree tree = create(10);
    insert(&tree, 20);
    insert(&tree, 15);
    insert(&tree, 25);
    insert(&tree, 12);
    insert(&tree, 17);
    insert(&tree, 22);
    insert(&tree, 27);
    insert(&tree, 15);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("binary_search_tree");
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
