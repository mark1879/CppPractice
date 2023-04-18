//
//  template_argument_deduction.hpp
//  Templates
//
//  Created by MarkWu on 2022/10/23.
//  Copyright © 2022 Zego. All rights reserved.
//

#ifndef template_argument_deduction_hpp
#define template_argument_deduction_hpp


template <typename T>
void f(T a, T b) {
}

template<typename T>
void f2(const T a, const T b) {
}

template<typename T>
void fref(const T& a, const T& b) {
}


void test_template_argument_deduction() {
    int x = 10;
    const int y = 10;
    f(y, y);        // 忽略 const
    f2(x, x);       // 转 const
    fref(x, x);     // 转 const
    
    string s1("a value");
    const string s2("another value");
    f(s2, s2);      // 忽略 const
    f2(s1, s1);    //  转 const
    fref(s1, s1);  //  转 const
   

    int a[10] = {0};
    const int b[20] = {0};
    f(a, a);
    f(b, b);
    f2(a, a);
    f2(b, b);
    fref(a, a);
    fref(b, b);
}


#endif /* template_argument_deduction_h */
