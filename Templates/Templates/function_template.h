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
int compare(const char (&p1)[N], const char (&p2)[M]);

template<class T>
int compare2(const T str1, const T str2);

template<typename T, unsigned N>
void traverse(const T (&arr1)[N]);

template<typename T>
void traverse2(std::initializer_list<T> li);

void test_function_template();



#endif /* function_template_h */
