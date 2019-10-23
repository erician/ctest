#ifndef CTEST_INCLUDE_CTEST_INTERNAL_CTEST_TESTSUIT_H_
#include "ctest/internal/ctest_testsuit.h"
#endif

#ifndef CTEST_INCLUDE_CTEST_CTEST_H_
#include "ctest/ctest.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TestSuit *testsuit = (void*)0;

struct TestSuit* init_testsuit(char *testsuit_name) {
    testsuit = (struct TestSuit *)malloc(sizeof(*testsuit));
    testsuit->tail = (void*)0;
    testsuit->testsuit_name = (char *)malloc(sizeof(100));
    strcpy(testsuit->testsuit_name, testsuit_name);
    testsuit->tests = (void*)0;
    return testsuit;
}

void register_test(struct TestSuit *testsuit, char * testsuit_name, \
    char *test_name, TestFun testfun) {
    struct Test *test;

    test = (struct Test *)malloc(sizeof(*test));
    test->next = (void*)0;
    test->test_name = (char *)malloc(strlen(test_name)+1);
    strcpy(test->test_name, test_name);
    test->testfun = testfun;

    if(testsuit == (void*)0)
        testsuit = init_testsuit(testsuit_name);

    if(testsuit->tail == (void*)0)
        testsuit->tests = test;
    else
        testsuit->tail->next = test;
    testsuit->tail = test;
}

void run_tests(struct TestSuit *testsuit) {
    struct Test *test;
    printf("start to run testsuit: %s%s%s\n", BLUE, \
        testsuit->testsuit_name, BLUE);
    test = testsuit->tests;
    while(test != (void*)0) {
        test->testfun();
        printf("%s%s, pass%s\n", GREEN, test->test_name, NORMAL);
        test = test->next;
    }
}