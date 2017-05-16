#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "xor_double_linked_list.h"

/**
 *
 */
START_TEST(test_create)
{
    XorDoubleLinkedList first_list = create(10);
    XorDoubleLinkedList second_list = create(20);
    XorDoubleLinkedList third_list = create(30);
}
END_TEST

/**
 *
 */
START_TEST(test_insertAtTheEnd)
{
    XorDoubleLinkedList first_list = create(10);
    insertAtTheEnd(&first_list, 20);
    insertAtTheEnd(&first_list, 30);
    insertAtTheEnd(&first_list, 40);
}
END_TEST

/**
 *
 */
Suite* xor_double_linked_list_suite()
{
    Suite *suite = suite_create("xor_double_linked_list");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_insertAtTheEnd);

    suite_add_tcase(suite, tcase);

    return suite;
}

/**
 *
 */
int main(int argc, char *argv[])
{
    Suite *suite = xor_double_linked_list_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
