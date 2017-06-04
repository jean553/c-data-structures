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

    const int first_value = 10;

    insert(&first_hashmap, "val1", &first_value);
}
END_TEST

/**
 *
 */
START_TEST(test_at)
{
    Hashmap first_hashmap = create(10);

    const int first_value = 25;
    insert(&first_hashmap, "val1", &first_value);
    ck_assert_int_eq(*(int*) at(&first_hashmap, "val1"), first_value);

    Hashmap second_hashmap = create(10);

    const int second_value = 20;
    const int third_value = 30;
    const int fourth_value = 40;
    insert(&second_hashmap, "val1", &second_value);
    insert(&second_hashmap, "wal0", &third_value);
    insert(&second_hashmap, "xak0", &fourth_value);

    ck_assert_int_eq(*(int*) at(&second_hashmap, "val1"), second_value);
    ck_assert_int_eq(*(int*) at(&second_hashmap, "wal0"), third_value);
    ck_assert_int_eq(*(int*) at(&second_hashmap, "xak0"), fourth_value);
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
