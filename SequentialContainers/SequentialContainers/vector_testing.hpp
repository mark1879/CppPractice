//
//  sequential_container_practice.hpp
//  C++11Practice
//
//  Created by MarkWu on 2019/11/8.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef sequential_container_practice_h
#define sequential_container_practice_h
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void test_iterator()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    
    cout << "顺序遍历(iterator): " << endl;
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << "\t";
        *it = *it + 1;
    }
    
    cout << endl;
    
    cout << "顺序遍历(const_iterator): " << endl;
    for (vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); it++)
    {
        cout << *it << "\t";
    }
    
    cout << endl;
    
    cout << "顺序遍历: " << endl;
    for (auto it = vec.cbegin(); it != vec.cend(); it++)
    {
        cout << *it << "\t";
    }

    cout << endl;
    
    cout << "逆序遍历(iterator): " << endl;
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
    {
        cout << *it << "\t";
        *it = *it - 1;
    }
    
    cout << endl;
    
    cout << "逆序遍历(const_iterator): " << endl;
    for (vector<int>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
    {
        cout << *it << "\t";
    }
    
    cout << endl;
    
    cout << "逆序遍历: " << endl;
    for (auto it = vec.crbegin(); it != vec.crend(); it++)
    {
        cout << *it << "\t";
    }
      
    cout << endl;
}

void test_traversing()
{
    vector<int> vec = {1, 2, 4};
    for (auto& item : vec)
    {
        cout << item << endl;
        // 改变元素的值
        item = 100;
    }

    for (auto item : vec)
    {
        cout << item << endl;
        // 不改变元素的值
        item = 100;
    }
}

template<class T>
void print_vector(vector<T>& vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << "\t";
    }
       
    cout << endl;
}

void test_reference_and_value_type()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    // 改变vec中的值
    vec[0] = 100;
    print_vector(vec);
    
    
    vector<int>::reference second_element = vec[1];
    // 改变vec中的值
    second_element = 101;
    print_vector(vec);
    
    
    vector<int>::value_type third_element = vec[2];
    // 不会改变vec中的值，会复制
    third_element = 102;
    print_vector(vec);
}

void test_constructor()
{
    // 构造空容器
    vector<int> vec;
    
    // 列表初始化
    vector<int> vec1{1, 2, 3, 4, 5};
    
    // 拷贝vec中的内容
    vector<int> vec2(vec1);
    print_vector(vec);
    
    
    // 拷贝两个元素之间的元素
    vector<int> vec3(vec2.begin(), vec2.begin() + 2);
    print_vector(vec);
}
                  
void test_assignment()
{
    vector<int> vec{1, 2, 3};
    
    vector<int> vec1{10, 11, 12, 13, 14};
    
    // 将vec中的内容赋值给vec1
    vec1 = vec;
    print_vector(vec1);
    
    vec1 = {0, 0, 0, 1};
    print_vector(vec1);
    
//    vec1.swap(vec);
    swap(vec, vec1);
    cout << "swapped: " << endl;
    print_vector(vec);
    print_vector(vec1);
}

void test_insert()
{
    vector<int> vec{1, 2, 3};
    vec.push_back(4);
    vec.insert(vec.cbegin(), 5);
    vec.insert(vec.cbegin(), 2, 10);
    vec.insert(vec.cend(), {11, 11});
    print_vector(vec);
    
    vector<int> copy;
    copy.insert(copy.cbegin(), vec.cend() - 5, vec.cend());
    print_vector(copy);
}

void test_assign() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b;
    b.assign(a.cbegin(), a.cend());
    
    print_vector(a);
    print_vector(b);
    
    vector<int> c;
    c.assign(10, 100);
    print_vector(c);
}

void test_relation_operator() {
    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2, 4};
    vector<int> c = {1, 2};
    vector<int> d = {1, 3};
    
    cout << (a < b) << endl;
    cout << (a > c) << endl;
    cout << (a < d) << endl;
}

void test_assessing_elements() {
    vector<int> vec = {1, 3, 5, 7};
    
    print_vector(vec);
    
    auto temp = vec.begin() + 1;
    (*temp)++;
    
    auto &front = vec.front();
    front++;
    
    print_vector(vec);
    
//    cout << vec.at(5) << endl;
}

void test_deleting_elements() {
    vector<int> vec = {1, 2, 3, 4};
    
    vec.erase(vec.begin());
    vec.erase(vec.begin(), vec.begin() + 1);
    vec.clear();
    

    
    print_vector(vec);
}

void test_resize() {
    vector<int> vec(10, 42);
    print_vector(vec);
    
    vec.resize(15);
    print_vector(vec);
    
    vec.resize(25, -1);
    print_vector(vec);
    
    vec.resize(5);
    print_vector(vec);
}

void test_sequential_container()
{
//    test_relation_operator();
    
//    test_assign();
    
//    test_iterator();
//    test_reference_and_value_type();
//    test_constructor();
    
//    test_assignment();
    
//    test_insert();
    
//    test_assessing_elements();
    
//    test_deleting_elements();
    
//    test_resize();
    
    vector<int> vec;
    deque<int> deq;
    
    for (int i = 0; i < 1000 * 10; i++) {
        cout << "i: " << i << endl;
        vec.push_back(i);
        cout << "vector capacity: " << vec.capacity() << endl;
        
        deq.push_back(i);
        cout << "deque capacity: " << deq.max_size() << endl;
        
        cout << endl << endl;
    }
}





#endif /* sequential_container_practice_h */
