#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "skip_list.h"

/**
 *
 */
START_TEST(test_create)
{
    SkipList first_list = create(5, 10);
    SkipList second_list = create(10, 20);
    SkipList third_list = create(15, 30);
}
END_TEST

/**
 *
 */
START_TEST(test_insert)
{
    SkipList first_list = create(5, 10);
    insert(&first_list, 6, 20);

    SkipList second_list = create(5, 10);
    insert(&second_list, 4, 20);

    SkipList third_list = create(5, 10);
    insert(&third_list, 5, 20);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("skip_list");
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
