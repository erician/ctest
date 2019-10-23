#ifndef CTEST_INCLUDE_CTEST_INTERNAL_CTEST_TESTSUIT_H_
#define CTEST_INCLUDE_CTEST_INTERNAL_CTEST_TESTSUIT_H_

#ifndef CTEST_INCLUDE_CTEST_INTERNAL_CTEST_TEST_H_
#include "ctest/internal/ctest_test.h"
#endif

/* 
 * we use googletest terms, for more info, please
 * visit: https://github.com/google/googletest/blob
 * /master/googletest/docs/primer.md.
 */
struct TestSuit {
    char            *testsuit_name;
    struct Test     *tests;
    struct Test     *tail;
};

struct TestSuit* init_testsuit(char *testsuit_name);
void register_test(struct TestSuit *testsuit, char *testsuit_name, \
    char * test_name, TestFun testfun);
void run_tests(struct TestSuit *testsuit);

#endif