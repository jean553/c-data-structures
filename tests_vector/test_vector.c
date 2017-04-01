#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "vector.h"

/**
 *
 */
START_TEST(test_create)
{
    /* TODO: check the size and access */

    Vector first_list = create(10);
}
END_TEST

/**
 *
 */
START_TEST(test_push)
{
    /* TODO: check the size and access */

    Vector first_list = create(10);
    push(&first_list, 5);
    push(&first_list, 50);
}
END_TEST

/**
 *
 */
Suite* vector_suite()
{
    Suite *suite = suite_create("vector");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_push);

    suite_add_tcase(suite, tcase);

    return suite;
}

/**
 *
 */
int main(int argc, char *argv[])
{
    Suite *suite = vector_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
