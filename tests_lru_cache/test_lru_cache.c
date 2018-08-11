#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "lru_cache.h"
#include "self_organizing_list.h"

/**
 *
 */
START_TEST(test_lru_cache)
{
    LRUCache cache = createLRU(5);
    insertKey(&cache, 10);
    insertKey(&cache, 20);
    insertKey(&cache, 30);
    insertKey(&cache, 40);
    insertKey(&cache, 50);

    ck_assert_int_eq(atLL(cache.list, 0), 50);
    ck_assert_int_eq(atLL(cache.list, 1), 40);
    ck_assert_int_eq(atLL(cache.list, 2), 30);
    ck_assert_int_eq(atLL(cache.list, 3), 20);
    ck_assert_int_eq(atLL(cache.list, 4), 10);

    getKey(&cache, 10);

    ck_assert_int_eq(atLL(cache.list, 0), 10);
    ck_assert_int_eq(atLL(cache.list, 1), 50);
    ck_assert_int_eq(atLL(cache.list, 2), 40);
    ck_assert_int_eq(atLL(cache.list, 3), 30);
    ck_assert_int_eq(atLL(cache.list, 4), 20);

    getKey(&cache, 30);

    ck_assert_int_eq(atLL(cache.list, 0), 30);
    ck_assert_int_eq(atLL(cache.list, 1), 10);
    ck_assert_int_eq(atLL(cache.list, 2), 50);
    ck_assert_int_eq(atLL(cache.list, 3), 40);
    ck_assert_int_eq(atLL(cache.list, 4), 20);
}
END_TEST

/**
 *
 */
Suite* lru_cache_suite()
{
    Suite *suite = suite_create("lru_cache");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_lru_cache);

    suite_add_tcase(suite, tcase);

    return suite;
}

/**
 *
 */
int main(int argc, char *argv[])
{
    Suite *suite = lru_cache_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
