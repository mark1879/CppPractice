//
//  generic_algorithms.hpp
//  GenericAlgorithms
//
//  Created by MarkWu on 2020/1/22.
//  Copyright © 2020 Zego. All rights reserved.
//

#ifndef generic_algorithms_h
#define generic_algorithms_h
#include <vector>
#include <iostream>
#include <list>
#include <numeric>

using namespace std;


void test_find_library_types()
{
    vector<int> vec = {10, 11, 12, 13, 100, 101};
    int value = 13;
    
    // 查找范围不包含第二个参数。如果找到想要的元素，则返回结果指向它，否则返回第二个参数
    auto result = find(vec.cbegin(), vec.cend(), value);
    cout << "test_find_library_types: " << endl;
    cout << "result: " << *result << ", found it: " << !(result == vec.cend()) << endl;
    
    auto result2 = find(vec.cbegin(), vec.cbegin() + 3, value);
    cout << "result2: " << *result2 << ", found it: " << !(result2 == (vec.cbegin() + 3)) << endl;
    cout << endl;
}


void test_find_build_in_array()
{
    int iarr[] = {10, 11, 12, 13, 100, 101};
    int value = 13;
    
    int *result = find(begin(iarr), end(iarr), value);
    cout << "test_find_build_in_array:" << endl;
    cout << "result: " << *result << ", found it: " << !(result == end(iarr)) << endl;

    int *result2 = find(begin(iarr) + 1, begin(iarr) + 3, value);
    cout << "result2: " << *result2 << ", found it: " << !(result2 == (begin(iarr) + 3)) << endl;
    cout << endl;
}

void test_count()
{
    vector<int> vec = {1, 2, 3, 1, 2, 3, 10};
    // 第二个参数指定边界，不在搜索范围内
    cout << "count of 1: " << count(vec.cbegin(), vec.cbegin() + 4, 1) << endl;
    
    list<string> list_string = {"hello", "world", "hello", "world"};
    cout << "count of 'hello': " << count(list_string.cbegin(), list_string.cend(), "hello") << endl;
    
    cout << endl;
}

void test_accumulate()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "accumulate int: " << accumulate(vec.cbegin(), vec.cend() - 1, 0) << endl;
    
    vector<string> vec_string = {"good", "morning", "everyone"};
    cout << "accumulate string: " << accumulate(vec_string.cbegin(), vec_string.cend(), string("")) << endl;
}

void test_equal()
{
    vector<string> vec_string = {"hello", "world", "everyone"};
    list<string> list_string = {"hello", "world"};
    
    cout << "equal: " << equal(vec_string.cbegin(), vec_string.cbegin() + 2, list_string.cbegin()) << endl;
    
    list<const char*> list_cstring = {"hello", "world", "nobody"};
    cout << "equal: " << equal(vec_string.cbegin(), vec_string.cend(), list_cstring.cbegin()) << endl;
}

void test_fill()
{
    cout << "test_fill: " << endl;
    
    vector<int> vec(10, 5);
    
//    fill(vec.begin(), vec.end(), 5);
    
    for (auto &it : vec)
        cout << it << "\t";
    
    cout << endl;
}

void test_fill_n()
{
    cout << "test_fill_n: " << endl;
           
    vector<int> vec(20);

    fill_n(vec.begin(), vec.size(), 1);

    for (auto &it : vec)
       cout << it << "\t";

    cout << endl;
}

void test_back_inserter()
{
    cout << "test_back_inserter" << endl;
    vector<int> vec;
    auto it = back_inserter(vec);
    cout << "size: " << vec.size() << endl;
    *it = 100;
    cout << "value: " << *(vec.cbegin()) << endl;
    
    fill_n(back_inserter(vec), 10, 1);
    
    for (auto &it : vec)
        cout << it << "\t";
    
    cout << endl;
}

void test_copy()
{
    cout << "test_copy" << endl;
    
    vector<int> vec1(10);
    vector<int> vec2(10, 1);
    
    copy(vec2.begin(), vec2.end(), vec1.begin());
    
    cout << "std library: " << endl;
    for (auto it = vec1.cbegin(); it != vec1.cend(); it++)
        cout << *it << "\t";
    
    cout << endl;
    
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[sizeof(arr1)/sizeof(*arr1)];
    copy(begin(arr1), end(arr1), arr2);
    
    cout << "build-in array: " << endl;
    for (auto elem : arr2)
        cout << elem << "\t";
    
    cout << endl;
}

void test_replace()
{
    cout << "test_replace: " << endl;
    
    vector<int> vec1(5);
    replace(vec1.begin(), vec1.end(), 0, 1);
    
    for (auto &it : vec1)
           cout << it << "\t";
    
    cout << endl;
    
    vector<int> vec2;
    replace_copy(vec1.cbegin(), vec1.cend(), back_inserter(vec2), 1, 2);
    
    for (auto &it : vec2)
    cout << it << "\t";

    cout << endl;
}

void test_sort()
{
    cout << "test_sort: " << endl;
    
    vector<string> vec = {"it", "is", "a", "sunny", "day", ",", "it", "is", "a", "sunny", "day"};

    sort(vec.begin(), vec.end());
    for (auto &it : vec)
        cout << it << "\t";

    cout << endl;
    
    auto unique_end = unique(vec.begin(), vec.end());
    for (auto &it : vec)
        cout << it << "\t";
    
    cout << endl;
    vec.erase(unique_end, vec.end());
    for (auto &it : vec)
       cout << it << "\t";
    
    cout << endl;
}

#endif /* generic_algorithms_h */
