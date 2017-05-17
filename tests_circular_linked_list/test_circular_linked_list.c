#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "linked_list.h"
#include "circular_linked_list.h"

/**
 *
 */
START_TEST(test_create)
{
    LinkedListNode first_list = createCLL(0);
    LinkedListNode second_list = createCLL(10);
    LinkedListNode third_list = createCLL(100);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("circular_linked_list");
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
    Suite *suite = linked_list_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}