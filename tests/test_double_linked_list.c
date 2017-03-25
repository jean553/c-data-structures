#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "../includes/double_linked_list.h"

/**
 *
 */
START_TEST(test_create)
{
    /* TODO: check with at() method */
    DoubleLinkedListNode first_node = create(0);
}
END_TEST

/**
 *
 */
Suite* double_linked_list_suite()
{
    Suite *suite = suite_create("double_linked_list");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);

    suite_add_tcase(suite, tcase);

    return suite;
}

/**
 *
 */
int main(int argc, char *argv[])
{
    Suite *suite = double_linked_list_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
