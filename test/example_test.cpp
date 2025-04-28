#include <gtest/gtest.h>

// 测试示例
TEST(ExampleTest, BasicAssertions) {
    EXPECT_EQ(2 + 2, 4);  // 确保 2 + 2 等于 4
}

TEST(ExampleTest, StringComparison) {
    EXPECT_STREQ("hello", "hello");  // 确保字符串相等
}