# DataStructure-Practise
数据结构练习记录 by Doclinzh(www.doclinzh.com)  
这是在武汉大学大二期间, 学习陈刚老师数据结构时积累的一些相关的C++代码。主要包括：
* 几种基本数据结构及相关算法的实现
* 相应的课后习题及部分应用探索  

代码以学习探索为主要目的，数据结构知识与C++水平都还十分浅薄，欢迎其他开发者提出改进意见或参与共同开发。

## 目录结构说明
        ├── backtracking                             // 回溯相关
        │   ├── 3_1.cpp
        │   ├── 3_2_better.cpp                       // 对3_2的优化
        │   ├── 3_2.cpp
        │   └── n_queens.cpp
        ├── binary_tree
        │   ├── binary_tree.cpp                      // 测试接口与调用示例
        │   ├── binary_tree.h
        │   ├── binary_tree_iterator.cpp
        │   ├── binary_tree_iterator.h               // 提供四种遍历方法迭代器(4_1)
        │   ├── complete_binary_tree.cpp
        │   └── complete_binary_tree.h               // (4_3)
        ├── linear_lists
        │   ├── linear_list.h
        │   ├── linked_list
        │   │   ├── doubly_circular_linked_list.cpp
        │   │   ├── doubly_circular_linked_list.h
        │   │   ├── linked_list.cpp
        │   │   └── linked_list.h
        │   ├── polynomial.cpp
        │   ├── polynomial.h                         // (2_0)
        │   ├── polynomial_main.cpp                  // 需与polynomial.cpp共同编译
        │   └── sequential_list
        │       ├── sequential_list.cpp
        │       └── sequential_list.h
        ├── other                                    // 其他题目解答
        │   ├── 1_1.cpp
        │   ├── 1_2.cpp
        │   ├── 1_3.cpp
        │   ├── 1_4.cpp
        │   ├── 1_5.cpp
        │   ├── 4_2.cpp
        │   ├── 4_4.cpp
        │   └── 5_0.cpp                              // 不完全符合要求，算法参照iterator
        ├── questions                                // 练习题目
        │   ├── fifth_exercise.txt
        │   ├── first_exercise.txt
        │   ├── forth_exercise.txt
        │   ├── second_exercise.txt
        │   └── third_exercise.txt
        ├── queue
        │   ├── queue.cpp
        │   └── queue.h
        ├── README.md
        └── stack
            ├── stack.cpp
            └── stack.h

编译环境：
* Ubuntu14.04 gcc(4.8.4)
* Ubuntu14.04 clang(3.8)
* Windows10 Dev-c++(gcc)

TODO:
expression in stack  
baggage problem in backtracking  
complete tree in array  
threaded binary tree  
tree and forests  
huffman tree  
graph  