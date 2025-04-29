//
// Created by QingZhiLiangCheng on 2025/4/29.
//

#ifndef CHENGZILIST_INT_LINKED_LIST_H
#define CHENGZILIST_INT_LINKED_LIST_H

// 不难发现，事实上一个简单的链表是由一个个节点所组成的,
// 一个好的思想是封装的时候我们要细化到最小的结构和模块，
// 这是一种工程化的思想，所以这里你需要实现IntNode类并用IntNode类构成IntList类，并体会这种思想的好处。
//TODO(Project 1 - Task 1) 实现IntLinkedList类
// - 定义一个名为IntLinkedList类 用于管理IntNode组成的链表
// - 实现一个指向链表第一个节点的指针 first_
// - 实现必要的构造函数和析构函数
// - 实现AddFirst和GetFirst两个功能
//      - void AddFirst(int data);
//      - auto GetFirst() -> int

//但是上面的IntLinkedList仍然存在问题
//因为我们可以绕过这个中间人(IntLinkedList) 直接访问里面的naked data structure
//甚至可以操控data和next域
//我们可以使用private关键字达到想要的效果
//TODO(Project 1 - Task 2) Public vs. Private
// 将first_成员声明为private，那么这个成员变量只能在IntLinkedList类的成员函数中被访问和修改

//你会发现 事实上 IntNode仅仅是一个IntLinkedList的一个特性
//IntNode好像并没有作为一个直接交互的项目 它没有自己的函数声明 更像是一个属性
//所以我们会使用嵌套类(nested classed)
//TODO(Project 1 - Task 3) Nested Classes
// 将IntNode作为内部类插入IntLinkedList中 并删除`src/int_node.h`文件
// 实现AddLast函数 `void AddLast(int data)`
// 实现Size函数 (如果有能力可以试一下迭代和递归两种方法)

//在Improvement 3中实现的Size和AddLast的缺点非常明显
//如果迭代的话需要O(n)的复杂度 如果递归的话 开销可能会更大(可以去理解一下递归的原理)
//为此，我们只需在 `SLList` 类中添加一个 `size_` 变量来跟踪当前链表的长度
//这种将重要数据保存起来以加快后续访问速度的做法，有时被称为 缓存（caching）
//这是计算机中一个典型的哲学思想: 权衡取舍. 说白了 就是拿着空间换效率
//现在计算机发展的水平来说 更缺乏的时间 因为我们的内存和硬盘还是蛮够用的
//原来在打孔纸带的时候算力是一种服务(因为需要排队用机房的机子) 而现在算力又成了一种服务
//TODO(Project 1 - Task 4) Cashing
// 加入`size_`变量来跟踪链表的长度
// 记得在对应的函数中都要维护size_
//其实也可以加一个tail_ 来记录尾节点
//但是其实会引发一个问题（其实我觉得并不是特别要紧）这个问题将在Project 2：LinkedList中提到

//截止到现在你实现的代码有一个潜在的bug,
//就是当建立空`int_linked_list`的时候再调用AddLast 会报错
//因为在`p->next`的时候`first_`是nullptr
//所以我们要进行特殊判断 be like
//问题是 加上特殊情况判断可能显得代码变得复杂 冗长
//而且每当我们增加功能的时候 可能都要加上或多或少的特殊情况判断 而且可能在bug出现之前我们并不能意识到这里存在特殊情况
//所以一种更好的方式 是使用有虚拟头结点的链表
//TODO(Project 1 - Task 5) Sentinel Head Node
// 在原有基础上 实现有虚拟头结点的链表 并在必要的函数中进行维护

#include<iostream>
class IntLinkedList {
private:
    // 嵌套类：IntNode
    class IntNode {
    public:
        int data_;
        IntNode* next_;

        explicit IntNode(int data) : data_(data), next_(nullptr) {}
    };

    // 使用虚拟头节点 sentinel_
    IntNode* sentinel_;
    int size_;

public:
    // 构造函数：初始化带有虚拟头节点的链表
    IntLinkedList() {
        sentinel_ = new IntNode(0); // 虚拟节点数据无意义
        size_ = 0;
    }

    // 析构函数：释放所有节点内存
    ~IntLinkedList() {
        IntNode* current = sentinel_->next_;
        while (current != nullptr) {
            IntNode* next = current->next_;
            delete current;
            current = next;
        }
        delete sentinel_;
    }

    // 在头部添加节点
    void AddFirst(int data) {
        IntNode* newNode = new IntNode(data);
        newNode->next_ = sentinel_->next_;
        sentinel_->next_ = newNode;
        ++size_;
    }

    // 获取第一个节点的数据
    int GetFirst() const {
        if (size_ == 0) {
            throw std::out_of_range("List is empty");
        }
        return sentinel_->next_->data_;
    }

    // 在尾部添加节点
    void AddLast(int data) {
        IntNode* current = sentinel_;
        while (current->next_ != nullptr) {
            current = current->next_;
        }
        current->next_ = new IntNode(data);
        ++size_;
    }

    // 获取链表大小 O(1)
    int Size() const {
        return size_;
    }

    // 递归方式获取大小（可选）
    int SizeRecursive() const {
        return sizeRecursiveHelper(sentinel_->next_);
    }

private:
    // 递归辅助函数
    int sizeRecursiveHelper(IntNode* node) const {
        if (node == nullptr) return 0;
        return 1 + sizeRecursiveHelper(node->next_);
    }
};


#endif //CHENGZILIST_INT_LINKED_LIST_H
