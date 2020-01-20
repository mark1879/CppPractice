//
//  function_template.hpp
//  Templates
//
//  Created by MarkWu on 2019/11/15.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef function_template_h
#define function_template_h
#include <iostream>
using namespace std;

template<unsigned N, unsigned M>
int compare(const int (&p1)[N], const int (&p2)[M])
{
    return strcmp(p1, p2);
}

template<class T>
constexpr inline int compare2(const T& str1, const T& str2)
{
    return strcmp(str1, str2);
}

template<typename T, unsigned N>
void traverse(const T (&arr1)[N])
{
    for (auto it : arr1)
        cout << it << endl;
}

template<typename T>
void traverse2(std::initializer_list<T> li)
{
    for (auto it : li)
        cout << it << endl;
}

void test_function_template()
{
//    cout << "compare: " << compare({1, 2}, {1, 2}) << endl;
//    cout << "compare2: " << compare2("hello1", "hello1") << endl;
    
//    traverse({3, 4, 5});
    
//    traverse2({3, 4, 5, 6});
}

#endif /* function_template_h */
