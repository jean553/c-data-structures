#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "vector.h"

/**
 *
 */
START_TEST(test_create)
{
    Vector first_list = create();
    ck_assert_int_eq(at(&first_list, 0), 0);
}
END_TEST

/**
 *
 */
START_TEST(test_insertAtTheEnd)
{
    Vector first_list = create();
    insertAtTheEnd(&first_list, 5);
    insertAtTheEnd(&first_list, 50);

    ck_assert_int_eq(at(&first_list, 0), 5);
    ck_assert_int_eq(at(&first_list, 1), 50);

    Vector second_list = create();
    insertAtTheEnd(&second_list, 25);
    insertAtTheEnd(&second_list, 35);

    ck_assert_int_eq(at(&second_list, 0), 25);
    ck_assert_int_eq(at(&second_list, 1), 35);
}
END_TEST

/**
 *
 */
START_TEST(test_insertAt)
{
    Vector first_list = create();
    insertAtTheEnd(&first_list, 10);
    insertAtTheEnd(&first_list, 20);
    insertAtTheEnd(&first_list, 30);
    insertAtTheEnd(&first_list, 40);
    insertAtTheEnd(&first_list, 50);

    ck_assert_int_eq(at(&first_list, 0), 10);
    ck_assert_int_eq(at(&first_list, 1), 20);
    ck_assert_int_eq(at(&first_list, 2), 30);
    ck_assert_int_eq(at(&first_list, 3), 40);
    ck_assert_int_eq(at(&first_list, 4), 50);

    /* insert many items */

    Vector second_list = create();
    insertAtTheEnd(&second_list, 10);
    insertAtTheEnd(&second_list, 20);
    insertAtTheEnd(&second_list, 30);
    insertAtTheEnd(&second_list, 40);
    insertAtTheEnd(&second_list, 50);

    ck_assert_int_eq(at(&second_list, 0), 10);
    ck_assert_int_eq(at(&second_list, 1), 20);
    ck_assert_int_eq(at(&second_list, 2), 30);
    ck_assert_int_eq(at(&second_list, 3), 40);
    ck_assert_int_eq(at(&second_list, 4), 50);

    insertAt(&second_list, 3, 60);

    ck_assert_int_eq(at(&second_list, 0), 10);
    ck_assert_int_eq(at(&second_list, 1), 20);
    ck_assert_int_eq(at(&second_list, 2), 30);
    ck_assert_int_eq(at(&second_list, 3), 60);
    ck_assert_int_eq(at(&second_list, 4), 40);
    ck_assert_int_eq(at(&second_list, 5), 50);

    insertAt(&second_list, 0, 100);
    insertAt(&second_list, 0, 200);
    insertAt(&second_list, 0, 300);
    insertAt(&second_list, 0, 400);
    insertAt(&second_list, 0, 500);
    insertAt(&second_list, 0, 600);
    insertAt(&second_list, 0, 700);
    insertAt(&second_list, 0, 800);

    ck_assert_int_eq(at(&second_list, 0), 800);
    ck_assert_int_eq(at(&second_list, 1), 700);
    ck_assert_int_eq(at(&second_list, 2), 600);
    ck_assert_int_eq(at(&second_list, 3), 500);
    ck_assert_int_eq(at(&second_list, 4), 400);
    ck_assert_int_eq(at(&second_list, 5), 300);
    ck_assert_int_eq(at(&second_list, 6), 200);
    ck_assert_int_eq(at(&second_list, 7), 100);
    ck_assert_int_eq(at(&second_list, 8), 10);
    ck_assert_int_eq(at(&second_list, 9), 20);
    ck_assert_int_eq(at(&second_list, 10), 30);
    ck_assert_int_eq(at(&second_list, 11), 60);
    ck_assert_int_eq(at(&second_list, 12), 40);
    ck_assert_int_eq(at(&second_list, 13), 50);
}
END_TEST

/**
 *
 */
START_TEST(test_updateAt)
{
    /* insert only one node */

    Vector first_list = create();
    insertAtTheEnd(&first_list, 100);
    insertAtTheEnd(&first_list, 200);
    insertAtTheEnd(&first_list, 300);
    insertAtTheEnd(&first_list, 400);
    insertAtTheEnd(&first_list, 500);
    insertAtTheEnd(&first_list, 600);
    insertAtTheEnd(&first_list, 700);
    insertAtTheEnd(&first_list, 800);
    insertAtTheEnd(&first_list, 900);
    insertAtTheEnd(&first_list, 1000);

    updateAt(&first_list, 0, 0);
    updateAt(&first_list, 1, 10);
    updateAt(&first_list, 2, 20);
    updateAt(&first_list, 3, 30);
    updateAt(&first_list, 4, 40);
    updateAt(&first_list, 5, 50);
    updateAt(&first_list, 6, 60);
    updateAt(&first_list, 7, 70);
    updateAt(&first_list, 8, 80);
    updateAt(&first_list, 9, 90);

    ck_assert_int_eq(at(&first_list, 0), 0);
    ck_assert_int_eq(at(&first_list, 1), 10);
    ck_assert_int_eq(at(&first_list, 2), 20);
    ck_assert_int_eq(at(&first_list, 3), 30);
    ck_assert_int_eq(at(&first_list, 4), 40);
    ck_assert_int_eq(at(&first_list, 5), 50);
    ck_assert_int_eq(at(&first_list, 6), 60);
    ck_assert_int_eq(at(&first_list, 7), 70);
    ck_assert_int_eq(at(&first_list, 8), 80);
    ck_assert_int_eq(at(&first_list, 9), 90);
}
END_TEST

/**
 *
 */
START_TEST(test_insertAtTheEnd_realloc)
{
    Vector first_list_realloc = create();
    insertAtTheEnd(&first_list_realloc, 10);
    insertAtTheEnd(&first_list_realloc, 20);
    insertAtTheEnd(&first_list_realloc, 30);
    insertAtTheEnd(&first_list_realloc, 40);
    insertAtTheEnd(&first_list_realloc, 50);
    insertAtTheEnd(&first_list_realloc, 60);
    insertAtTheEnd(&first_list_realloc, 70);
    insertAtTheEnd(&first_list_realloc, 80);
    insertAtTheEnd(&first_list_realloc, 90);
    insertAtTheEnd(&first_list_realloc, 100);

    ck_assert_int_eq(at(&first_list_realloc, 0), 10);
    ck_assert_int_eq(at(&first_list_realloc, 1), 20);
    ck_assert_int_eq(at(&first_list_realloc, 2), 30);
    ck_assert_int_eq(at(&first_list_realloc, 3), 40);
    ck_assert_int_eq(at(&first_list_realloc, 4), 50);
    ck_assert_int_eq(at(&first_list_realloc, 5), 60);
    ck_assert_int_eq(at(&first_list_realloc, 6), 70);
    ck_assert_int_eq(at(&first_list_realloc, 7), 80);
    ck_assert_int_eq(at(&first_list_realloc, 8), 90);
    ck_assert_int_eq(at(&first_list_realloc, 9), 100);
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
    tcase_add_test(tcase, test_insertAtTheEnd);
    tcase_add_test(tcase, test_insertAt);
    tcase_add_test(tcase, test_updateAt);
    tcase_add_test(tcase, test_insertAtTheEnd_realloc);

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
