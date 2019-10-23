#ifndef CTEST_INCLUDE_CTEST_CTEST_H_
#define CTEST_INCLUDE_CTEST_CTEST_H_

#ifndef CTEST_INCLUDE_CTEST_INTERNAL_CTEST_TESTSUIT_H_
#include "ctest/internal/ctest_testsuit.h"
#endif

#ifndef CTEST_INCLUDE_CTEST_INTERNAL_CTEST_COLOR_H_
#include "ctest/internal/ctest_color.h"
#endif

#include <stdio.h>
#include <stdlib.h>

extern struct TestSuit *testsuit;

#define TEST(testsuit_name, test_name) \
CTEST(testsuit_name, test_name, _)

#define CTEST(testsuit_name, test_name, _) \
void testsuit_name##_##test_name(); \
__attribute__((constructor)) \
void register##_##testsuit_name##_##test_name() { \
    /* for now, we didn't consider multiple testsuits. */ \
    register_test(testsuit, #testsuit_name, #test_name, \
        testsuit_name##_##test_name); \
} \
void testsuit_name##_##test_name()

/*
 * ASSERT_XXX
 */
#define PRINT_PASS  \
    printf("%s%s\t\tpass%s\n\n", GREEN, __func__, NORMAL);

#define PRINT_FAILED_AND_EXIT PRINT_FAILED \
    exit(-1);

#define PRINT_FAILED \
    printf("%s%s\t\tfailed%s\n", RED, __func__, NORMAL); \
    printf("file: %s, line: %d\n", __FILE__, __LINE__);

#define ASSERT_TRUE(cond) \
if (!(cond)) { \
    PRINT_FAILED_AND_EXIT \
}

#define ASSERT_FALSE(cond)      ASSERT_TRUE(!(cond))

#define ASSERT_EQ(val1, val2)   ASSERT_TRUE(val1 == val2)
#define ASSERT_NE(val1, val2)   ASSERT_TRUE(val1 != val2)
#define ASSERT_LT(val1, val2)   ASSERT_TRUE(val1 < val2)
#define ASSERT_LE(val1, val2)   ASSERT_TRUE(val1 <= val2)
#define ASSERT_GT(val1, val2)   ASSERT_TRUE(val1 > val2)
#define ASSERT_GE(val1, val2)   ASSERT_TRUE(val1 >= val2)

#endif
