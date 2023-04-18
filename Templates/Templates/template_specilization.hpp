//
//  template_specilization.hpp
//  Templates
//
//  Created by MarkWu on 2019/11/22.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef template_specilization_h
#define template_specilization_h
#include <iostream>
#include "line.hpp"

template<typename T>
void sum(T t1, T t2)
{
    std::cout << sizeof(t1) << ", " << sizeof(t2) << std::endl;
}

template<>
void sum(int t1, int t2)
{
    std::cout << sizeof(t1) << ", " << sizeof(t2) << std::endl;
}

void test_template_specialization()
{
    sum(1, 2);
    sum("hello", "world");
    sum(Line(), Line());
}
#endif /* template_specilization_h */
