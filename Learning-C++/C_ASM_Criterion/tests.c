//
// Created by bq666 on 7/31/19.
//
#include <criterion/criterion.h>

int my_strlen(char *);
int summation(int);



Test(simple, test){
    cr_assert(strlen("1") == 1, "Hello world");
    cr_expect(strlen("test") == 4, "<--my test");
    cr_expect(my_strlen("test") == 4, "Expected \"Test\" to have length of 4. Chura");
    cr_assert_eq(summation(1), 1);
    cr_assert_eq(summation(2), 3);
    cr_assert_eq(summation(5), 15);
    cr_assert_eq(summation(8), 36);
}
