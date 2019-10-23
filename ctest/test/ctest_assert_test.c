#include "include/ctest/ctest.h"

TEST(assert, true_should_pass) {
    ASSERT_TRUE(1 == 1);
    ASSERT_TRUE(1);
}

TEST(assert, false_should_pass) {
    ASSERT_FALSE(1 == 2);
}

TEST(assert, eq_should_pass) {
    ASSERT_EQ(1, 1);
}

TEST(assert, ne_should_pass) {
    ASSERT_NE(1, 2);
}

TEST(assert, lt_should_pass) {
    ASSERT_LT(1, 2);
}

TEST(assert, le_should_pass) {
    ASSERT_LE(1, 1);
}

TEST(assert, gt_should_pass) {
    ASSERT_GT(2, 1);
}

TEST(assert, ge_should_pass) {
    ASSERT_GE(1, 1);
}



