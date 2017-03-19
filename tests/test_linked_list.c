#include <stdio.h>
#include <check.h>

#include "../includes/linked_list.h"

START_TEST(test_create)
{
    Node first_node = create(0);
    ck_assert_int_eq(at(&first_node, 0), 0);

    Node second_node = create(10);
    ck_assert_int_eq(at(&second_node, 0), 10);

    Node third_node = create(100);
    ck_assert_int_eq(at(&third_node, 0), 100);
}
END_TEST

Suite* linked_list_suite()
{
    Suite *suite = suite_create("linked_list");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    suite_add_tcase(suite, tcase);

    return suite;
}

int main(int argc, char *argv[])
{
    Suite *suite = linked_list_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
