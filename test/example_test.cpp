#include <gtest/gtest.h>

// 测试示例
TEST(ExampleTest, BasicAssertions) {
    EXPECT_EQ(2 + 2, 4);
}

TEST(ExampleTest, StringComparison) {
    EXPECT_STREQ("hello", "hello");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}