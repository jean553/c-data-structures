#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "hashmap.h"

/**
 *
 */
START_TEST(test_create)
{
    Hashmap first_hashmap = create(10);
}
END_TEST

/**
 *
 */
START_TEST(test_insert)
{
    Hashmap first_hashmap = create(10);
    insert(&first_hashmap, "val1", 10);
}
END_TEST

/**
 *
 */
START_TEST(test_at)
{
    Hashmap first_hashmap = create(10);
    insert(&first_hashmap, "val1", 25);
    ck_assert_int_eq(at(&first_hashmap, "val1"), 25);
}
END_TEST

/**
 *
 */
Suite* vector_suite()
{
    Suite *suite = suite_create("hashmap");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_insert);
    tcase_add_test(tcase, test_at);

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
