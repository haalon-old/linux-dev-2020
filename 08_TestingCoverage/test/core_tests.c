/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "core_tests.ts" instead.
 */

#include <check.h>

#line 1 "core_tests.ts"
#include <stdint.h>
#include "buf.h"

START_TEST(buf_init)
{
#line 5
    float *a = 0;
    ck_assert_msg(buf_capacity(a) == 0, "capacity init");
    ck_assert_msg(buf_size(a) == 0, "size init");
    buf_push(a, 1.3f);
    ck_assert_msg(buf_size(a) == 1, "size 1");
    ck_assert_msg(a[0] == (float)1.3f, "value");
    buf_clear(a);
    ck_assert_msg(buf_size(a) == 0, "clear");
    ck_assert_msg(a != 0, "clear not-free");
    buf_free(a);
    ck_assert_msg(a == 0, "free");


}
END_TEST

START_TEST(buf_clear_null)
{
#line 19
    float *a = 0;
    buf_clear(a);
    ck_assert_msg(buf_size(a) == 0, "clear empty");
    ck_assert_msg(a == 0, "clear no-op");


}
END_TEST

START_TEST(buf_push)
{
#line 26
    long *ai = 0;
    for (int i = 0; i < 10000; i++)
        buf_push(ai, i);
    ck_assert_msg(buf_size(ai) == 10000, "size 10000");
    int match = 0;
    for (int i = 0; i < (int)(buf_size(ai)); i++)
        match += ai[i] == i;
    ck_assert_msg(match == 10000, "match 10000");
    buf_free(ai);


}
END_TEST

START_TEST(buf_grow)
{
#line 38
    long *ai = 0;
    /* buf_grow(), buf_trunc() */
    buf_grow(ai, 1000);
    ck_assert_msg(buf_capacity(ai) == 1000, "grow 1000");
    ck_assert_msg(buf_size(ai) == 0, "size 0 (grow)");
    buf_trunc(ai, 100);
    ck_assert_msg(buf_capacity(ai) == 100, "trunc 100");
    buf_free(ai);


}
END_TEST

START_TEST(buf_pop)
{
#line 49
    float *a = 0;
    buf_push(a, 1.1);
    buf_push(a, 1.2);
    buf_push(a, 1.3);
    buf_push(a, 1.4);
    ck_assert_msg(buf_size(a) == 4, "size 4");
    ck_assert_msg(buf_pop(a) == (float)1.4f, "pop 3");
    buf_trunc(a, 3);
    ck_assert_msg(buf_size(a) == 3, "size 3");
    ck_assert_msg(buf_pop(a) == (float)1.3f, "pop 2");
    ck_assert_msg(buf_pop(a) == (float)1.2f, "pop 1");
    ck_assert_msg(buf_pop(a) == (float)1.1f, "pop 0");
    ck_assert_msg(buf_size(a) == 0, "size 0 (pop)");
    buf_free(a);
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, buf_init);
    tcase_add_test(tc1_1, buf_clear_null);
    tcase_add_test(tc1_1, buf_push);
    tcase_add_test(tc1_1, buf_grow);
    tcase_add_test(tc1_1, buf_pop);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
