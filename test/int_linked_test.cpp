//
// Created by QingZhiLiangCheng on 2025/4/29.
//
//TODO(QingZhiLiangCheng) 实现IntLinkedList测试
#include "gtest/gtest.h"
#include "../src/int_linked_list.h"

//TODO(Project 1): 删除#indef标签

TEST(IntLinkedListTest, AddFirstMultipleTimes) {
    IntLinkedList list;

    list.AddFirst(10);
    EXPECT_EQ(list.GetFirst(), 10);
    EXPECT_EQ(list.Size(), 1);

    list.AddFirst(20);
    EXPECT_EQ(list.GetFirst(), 20);
    EXPECT_EQ(list.Size(), 2);

    list.AddFirst(30);
    EXPECT_EQ(list.GetFirst(), 30);
    EXPECT_EQ(list.Size(), 3);
}

TEST(IntLinkedListTest, AddLastMultipleTimes) {
    IntLinkedList list;

    list.AddLast(10);
    EXPECT_EQ(list.GetFirst(), 10);
    EXPECT_EQ(list.Size(), 1);

    list.AddLast(20);
    EXPECT_EQ(list.GetFirst(), 10); // 第一个不变
    EXPECT_EQ(list.Size(), 2);

    list.AddLast(30);
    EXPECT_EQ(list.GetFirst(), 10);
    EXPECT_EQ(list.Size(), 3);
}

// 测试非常大的数据量下的稳定性
TEST(IntLinkedListTest, LargeAdditionsPerformance) {
    IntLinkedList list;

    const int count = 100000;
    for (int i = 0; i < count; ++i) {
        list.AddFirst(i);
    }

    EXPECT_EQ(list.Size(), count);
    EXPECT_EQ(list.GetFirst(), count - 1); // 最后一个进来的排最前

    for (int i = 0; i < count; ++i) {
        list.AddLast(i);
    }

    EXPECT_EQ(list.Size(), 2 * count);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/*
#ifdef ENABLE_TESTS
#endif*/
