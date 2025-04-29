//
// Created by QingZhiLiangCheng on 2025/4/28.
//

#ifndef CHENGZILIST_SIMPLE_LIST_H
#define CHENGZILIST_SIMPLE_LIST_H
// TODO(Project 1): 定义SimpleList类并实现其基本功能
// SimpleList是一个简单的链表节点类，包含两个成员变量：
// - next_: 指向下一个节点的指针
// - data_: 存储的数据
// 需要完成以下任务：
// 1. 实现构造函数，用于初始化节点的数据和指针
// 2. 实现size函数，用于计算链表的长度
class SimpleList {
public:
    SimpleList* _next;
    int _data;
    SimpleList():_next(nullptr),_data(0) {}
    SimpleList(SimpleList* next,int data):_next(next),_data(data) {}
};
#endif //CHENGZILIST_SIMPLE_LIST_H
