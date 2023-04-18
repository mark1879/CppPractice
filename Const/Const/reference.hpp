//
//  reference.hpp
//  Const
//
//  Created by MarkWu on 2023/4/17.
//

#ifndef reference_hpp
#define reference_hpp
#include <iostream>
#include <vector>

int main()
{
    // 不正确，引用的本质是指针
//    int& r = 20;
    
//    int array[5] = {0};
//    int *p = array;
//    int (&q)[5] = array;
//
//    std::cout << sizeof(array) << ", " << sizeof(p) << ", " << sizeof(q) << std::endl;
    
    
//    int a = 20;
////     错误，右值只能引用右值
////    int &&r = a;
//
//    int &&r = 20;
//
//    r = a;
    
    
    // 错误，常量不能赋值给左值引用
//    int* &p1_c = (int *)0x0018ff44;
    
    // 正确，常量赋值给常引用
    int* const&p2_c = (int *)0x0018ff44;
    
    // 正确，常量赋值给右值引用
    int* &&p3_c = (int *)0x0018ff44;
    
    
    
    int a = 10;
    int *p = &a;

      // 错误，p不能赋值给常量
      // 转换成  const int**q = &p 分析
//    const int*&q = p;
    
    // 正确
    int *const p1 = &a;
    
    // 错误，p1是常量
    // 转换成 int **q1 = &p1 分析
//    int *&q1 = p1;
    
    const int *p2 = &a;
    // 错误
    // 转换成 int **q2 = &p2 分析
//    int *&q2 = p2;
    
    // 错误
    // 转换成 int **qe = &p 分析
//    const int *&q3 = p;
    
    return 0;
}


#endif /* reference_h */
 
