#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "hashmap.h"

/**
 *
 */
START_TEST(test_create)
{
    Hashmap first_hashmap = createHM(10);
}
END_TEST

/**
 *
 */
START_TEST(test_insert)
{
    Hashmap first_hashmap = createHM(10);
    insertHM(&first_hashmap, "val1", 10);
}
END_TEST

/**
 *
 */
START_TEST(test_at)
{
    /* insert and read one node with the same key */

    Hashmap first_hashmap = createHM(10);
    insertHM(&first_hashmap, "val1", 25);
    ck_assert_int_eq(*atHM(&first_hashmap, "val1"), 25);

    /* insert and read many nodes with same hashes but different keys */

    Hashmap second_hashmap = createHM(10);
    insertHM(&second_hashmap, "val1", 20);
    insertHM(&second_hashmap, "wal0", 30);
    insertHM(&second_hashmap, "xak0", 40);

    ck_assert_int_eq(*atHM(&second_hashmap, "val1"), 20);
    ck_assert_int_eq(*atHM(&second_hashmap, "wal0"), 30);
    ck_assert_int_eq(*atHM(&second_hashmap, "xak0"), 40);

    /* try to get a value that does not exist */

    Hashmap third_hashmap = createHM(10);
    ck_assert_int_eq(atHM(&third_hashmap, "val1"), NULL);

    /* try to get a value that has the same hash but different key */

    Hashmap fourth_hashmap = createHM(10);
    insertHM(&fourth_hashmap, "val1", 20);
    ck_assert_int_eq(atHM(&fourth_hashmap, "wal0"), NULL);
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
