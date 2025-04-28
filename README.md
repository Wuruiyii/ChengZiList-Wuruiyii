### 情栀凉橙的QingZhiList项目介绍
📅Date: 2025.04.28 -- ing

在学弟学妹问我怎么学C++的时候，我一般建议他们试着去实现List, LinkedList, ArrayList 用上面向对象的知识…… 为了帮助大家掌握C++和数据结构的知识，我设计并开发了一个名为ChengZiList的简单的项目

ChengZiList的灵感来源于我之前看的两个课程: CS61B 和 CMU15445。CS61B在课程初期通过循序渐进的方式，深入探讨了链表和动态数组的设计与实现，这让我受益匪浅。而在参与的CMU15445的bustub项目的时候，我对其中Google Test框架的单元测试功能产生了兴趣，同时我比较喜欢国外这种写项目的这种方式。

基于这些启发，我在ChengZiList中提供了完整的文档，并使用Google Test框架编写了全面的测试用例。项目从简单的链表实现入手，逐步引入双向循环链表以及更复杂的数据结构。在这个过程中，诸如“为什么需要虚拟头节点”、“双向链表的优势是什么”、“为什么要进行动态扩容”等问题都会迎刃而解。同时，学习者还能通过实践深刻体会到C++中面向对象特性——如封装、继承、多态和重载的魅力所在。

### 克隆仓库
转到此处[New repository](https://github.com/new)在您的账户下创建新的存储库。选择一个名称（例如`ChengZiList-yourname）
在您的电脑上克隆情栀凉橙的ChengZiList仓库
```bash
git clone https://github.com/QingZhiLiangCheng/ChengZiList.git ChengZiList-QingZhiLiangCheng
```
接下来将情栀凉橙的ChengZiList镜像到您自己的ChengZiList存储库. 假设您的GitHub名称是`student`,仓库名称是`ChengZiList-yourname`
```bash
cd ChengZiList-QingZhiLiangCheng

# if you pull / push over HTTPS
git push https://github.com/student/ChengZiList-yourname.git main

# if you pull / push over SSH
git push git@github.com:student/ChengZiList-yourname.git main
```
现在可以删除情栀凉橙的仓库的克隆
```shell
cd ..
rm -rf ChengZiList-QingZhiLiangCheng
```
将您自己的仓库克隆到您的计算机
```shell
# If you pull / push over HTTPS
git clone https://github.com/student/ChengZiList-yourname.git

# If you pull / push over SSH
$ git clone git@github.com:student/ChengZiList-yourname.git
```
将情栀凉橙的存储库添加为第二个远程仓库。这允许您从情栀凉橙的存储库中检索更改

```shell
git remote add QingZhiLiangCheng https://github.com/QingZhiLiangCheng/ChengZiList.git
```
现在，您可以根据需要从情栀凉橙的存储库中提取更改

```bash
git pull QingZhiLiangCheng main
```
我建议搭建在Ubuntu或者是macOS上开发 如果您用的是Windows其实也没问题(我用的是Ubuntu hhh)

请大家遵守代码规范，我使用的是Google C++代码规范 [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) 当然国内Google C++代码规范可能用的比较少？ 遵循别的开发规范也可以 但是一定要尽量遵守开发规范
