//
// Created by QingZhiLiangCheng on 2025/4/28.
//

// TODO(QingZhiLiangCheng): 实现Simple_list单元测试
#include "gtest/gtest.h"
#include "../src/simple_list.h"
//TODO(Project 1): 删除#indef标签
#ifdef ENABLE_TESTS
// 测试SimpleList类的构造函数
TEST(SimpleListTest, Constructor) {
    // 创建一个单独的节点
    SimpleList node(42);
    EXPECT_EQ(node.data_, 42);
    EXPECT_EQ(node.next_, nullptr);
}

// 测试SimpleList类的size函数
TEST(SimpleListTest, SizeFunction) {
    // 创建一个空链表
    SimpleList *head = nullptr;
    EXPECT_EQ(head ? head->size() : 0, 0);

    // 创建一个单节点链表
    SimpleList node1(10);
    head = &node1;
    EXPECT_EQ(head->size(), 1);

    // 创建一个多节点链表
    SimpleList node2(20);
    SimpleList node3(30);
    node1.next_ = &node2;
    node2.next_ = &node3;
    EXPECT_EQ(head->size(), 3);
}

// 测试链表的数据完整性
TEST(SimpleListTest, DataIntegrity) {
    // 创建一个链表：10 -> 20 -> 30
    SimpleList node3(30);
    SimpleList node2(20, &node3);
    SimpleList node1(10, &node2);

    // 检查每个节点的数据是否正确
    EXPECT_EQ(node1.data_, 10);
    EXPECT_EQ(node1.next_->data_, 20);
    EXPECT_EQ(node1.next_->next_->data_, 30);
    EXPECT_EQ(node1.next_->next_->next_, nullptr);
}

// 测试链表的动态插入（可选）
TEST(SimpleListTest, DynamicInsertion) {
    // 创建一个链表：10 -> 20
    SimpleList node2(20);
    SimpleList node1(10, &node2);

    // 动态插入一个新节点：10 -> 15 -> 20
    SimpleList newNode(15, node1.next_);
    node1.next_ = &newNode;

    // 验证插入后的链表结构
    EXPECT_EQ(node1.data_, 10);
    EXPECT_EQ(node1.next_->data_, 15);
    EXPECT_EQ(node1.next_->next_->data_, 20);
    EXPECT_EQ(node1.next_->next_->next_, nullptr);
}

// 测试空链表的行为
TEST(SimpleListTest, EmptyList) {
    SimpleList *head = nullptr;

    // 检查空链表的size函数行为
    EXPECT_EQ(head ? head->size() : 0, 0);

    // 检查空链表的next_行为
    EXPECT_EQ(head, nullptr);
}

#endif // SIMPLE_LIST_H