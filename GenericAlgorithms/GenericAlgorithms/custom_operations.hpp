//
//  custom_operations.hpp
//  GenericAlgorithms
//
//  Created by MarkWu on 2020/2/2.
//  Copyright © 2020 Zego. All rights reserved.
//

#ifndef custom_operations_h
#define custom_operations_h

#include <vector>
#include <iostream>

bool isShorter(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}

void print(const vector<string>& vec, string name)
{
    cout << name.c_str() << endl;
    for (auto &it : vec)
        cout << it << "\t";
    
    cout << endl;
}

void test_custom_sort()
{
    vector<string> vec1 = {"hello", "aloha", "no", "yes", "hello", "guys", "everybody", "ccccc"};
    vector<string> vec2 = vec1;

    // 先按照字典排序
    sort(vec1.begin(), vec1.end());
    print(vec1, "sort vec1");
    
    stable_sort(vec2.begin(), vec2.end());
    print(vec2, "stable_sort vec2");
    
    cout << endl << "using isShorter:" << endl << endl;
    
    // 按照字符串长度排序
    sort(vec1.begin(), vec1.end(), isShorter);
    print(vec1, "sort vec1");
       
    stable_sort(vec2.begin(), vec2.end(), isShorter);
    print(vec2, "stable_sort vec2");
    
    cout << endl;
}

void test_find_if()
{
    vector<string> vec = {"hello", "aloha", "no", "yes", "everyone", "hello", "guys", "eeeee", "ccccc"};
    int str_size = 5;
    
    cout << "find string that size equals " << str_size << endl;
    auto it = find_if(vec.cbegin(), vec.cend(), [str_size](const string& a) { return a.size() == str_size; });
    if (it != vec.cend())
           cout << "got it!" << endl;
       else
           cout << "nop!" << endl;
}

void test_partition()
{
    vector<string> vec = {"hello", "aloha", "no", "yes", "everyone", "hello", "guys", "eeeee", "ccccc"};
    
    auto partion = partition(vec.begin(), vec.end(), [](const string& str) { return str.size() >= 5; });
    
    for (auto it = vec.begin(); it != partion; it++)
        cout << *it << "\t";
    
    cout << endl;
}

void test_lambda()
{
    vector<string> vec = {"hello", "alex", "hello", "mark1"};
    stable_sort(vec.begin(), vec.end(), [](const string& a, const string& b){ return a.size() < b.size(); });
    
    print(vec, "stable_sort:vec");
    
    
    // 值捕获，在lambda创建时，而不是调用时
    int value = 100;
    auto print = [&value]() { cout << "value: " << ++value << endl; };
    
    value = 101;
    print();
    
    vector<int> vec_int = {1, 2, 3, -1, -2, -3};
    transform(vec_int.begin(), vec_int.end(), vec_int.begin(), [](int i){ if(i < 0) return -i; else return i;});
    
    for (const auto& it : vec_int)
        cout << it << "\t";
    
    cout << endl;
}

#endif /* custom_operations_h */
