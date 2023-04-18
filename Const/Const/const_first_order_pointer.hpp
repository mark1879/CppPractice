//
//  const_first_order_pointer.hpp
//  Const
//
//  Created by MarkWu on 2023/3/7.
//

#ifndef const_first_order_pointer_hpp
#define const_first_order_pointer_hpp

using namespace std;

#define NDEBUG

#include <iostream>

//
#include <assert.h>

//int main()
//{
//    
////    const int a = 10;
////    const int b = 20;
////    int c = 30;
////    int d = 40;
//
////    int *p = &a;    // 不合法
//    
//    
//    // 常量指针
////    const int *p = &a;  // 合法
////    p = &b;             // 合法
////    p = &c;             // 合法
////    *p = 100;           // 不合法
////    int *pb = p;        // 不合法
//    
//    
//    // 常量指针
////    int const* p1 = &a;  // 合法
////    p1 = &b;            //  合法
////    p1 = &c;            //  合法
////    *p1 = 100;          //  不合法
////    int *pb = p1;        // 不合法
//   
//    
//    //  指针常量
////    int *const p2 = &a; // 不合法
////    int *const p2 = &c;   // 合法
////    p2 = &b;              // 不合法
////    p2 = &d;              // 不合法
////    *p2 = 300;              // 合法
////    int *pb = p2;           // 合法
////    const int *pcb = p2;     // 合法
//    
//    
////    const int *const p3 = &a;   // 合法
////    *p3 = 100;                  // 不合法
////    p3 = & b;                   // 不合法
////    p3 = &d;                    // 不合法
////    int *pb = p3;              // 不合法
////    const int *pcb = p3;      // 合法
//    
//    
////    const int *const p4 = &c;     // 合法
////    *p4 = 100;                    // 不合法
////    p4 = &b;                      // 不合法
////    p4 = &d;                      // 不合法
////    int *pb = p4;              // 不合法
////    const int *pcb = p4;      // 合法
//    
//    bool b = true;
//    
//    assert(b == false);
//    
////    ASSERT(b == false);
//    
//    
//    
//    return 0;
//}


#endif /* const_first_order_pointer_h */
