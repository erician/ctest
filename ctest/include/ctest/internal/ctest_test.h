#ifndef CTEST_INCLUDE_CTEST_INTERNAL_CTEST_TEST_H_
#define CTEST_INCLUDE_CTEST_INTERNAL_CTEST_TEST_H_

typedef void (*TestFun)();

/* 
 * we use googletest terms, for more info, please
 * visit: https://github.com/google/googletest/blob
 * /master/googletest/docs/primer.md.
 */
struct Test {
    char        *test_name;
    struct Test *next;
    TestFun     testfun;
};


#endif