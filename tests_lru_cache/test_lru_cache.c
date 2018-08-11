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
