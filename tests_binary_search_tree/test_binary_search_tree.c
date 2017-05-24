#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "binary_search_tree.h"

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("binary_search_tree");
    TCase *tcase = tcase_create("case");

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
