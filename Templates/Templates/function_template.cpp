//
//  function_template.cpp
//  Templates
//
//  Created by MarkWu on 2022/10/17.
//  Copyright © 2022 Zego. All rights reserved.
//

#include "function_template.h"

template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

template<class T>
int compare2(const T str1, const T str2)
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
//    char hi[3] = "hi";
//    char mom[4] = "mom";
//
//    cout << "compare: " << compare(hi, mom) << endl;
    
    cout << "compare2: " << compare2("hello1", "hello2") << endl;
    
//    traverse({3, 4, 5});
    
//    traverse2({3, 4, 5, 6});
}
