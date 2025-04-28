#include <gtest/gtest.h>

// 测试示例
TEST(ExampleTest, BasicAssertions) {
    EXPECT_EQ(2 + 2, 4);
}

TEST(ExampleTest, StringComparison) {
    EXPECT_STREQ("hello", "hello");
}