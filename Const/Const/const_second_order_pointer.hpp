//
//  const_second_order_pointer.hpp
//  Const
//
//  Created by MarkWu on 2023/4/16.
//

#ifndef const_second_order_pointer_hpp
#define const_second_order_pointer_hpp
#include <iostream>

//int main()
//{
//    int a = 10;
//    int *p1 = &a;
//    int **p2 = &p1;
//
//    // 错误
////    const int **p2_c = p2;
////    const int **p2_c = &p1;
//
//
//    // const 修饰二级指针
//    // 正确
//    const int *p1_c = &a;
//    const int **p2_c = &p1_c;
//
//    // 正确
//    const int **p2_c1 = &p1_c;
//    p2_c = p2_c1;
//
//    // 正确
//    const int *p1_c1 = &a;
//    *p2_c = p1_c1;
//
//    // 不正确
////    **p2_c = 100;
//
//
//    // const 修饰一级指针
//    int *const* q = &p1;
//    // 正确
//    q = &p1;
//    // 不正确
////    q = &p1_c;
//    // 不正确
////    *q = p1;
//    // 正确
//    **q = 200;
//
//
//    // 普通的二级指针
//    int **const q1 = &p1;
//
//
//    return 0;
//}

#endif /* const_second_order_pointer_h */
