//
//  main.cpp
//  Const
//
//  Created by MarkWu on 2023/3/6.
//

#include <iostream>
#include "const_first_order_pointer.hpp"
#include "const_second_order_pointer.hpp"
#include "reference.hpp"

using  namespace std;


//int main(int argc, const char * argv[]) {
//    // 声明时必须初始化
//    const int a = 20;
//
//    // 可以用于声明数组
//    int arr[a] = {0};
//    
//    int *p = (int *)&a;
//    *p = 30;
//
//    printf("%p, %p\n", &a, p);
//    printf("%d, %d, %d, %d\n", a, *p, *(&a), *((int *)&a));
////
//    
////    int b = 20;
////    // 声明时必须初始化
////    const int a = b;
////
////    // 可以用于声明数组
//////    int arr[a] = {0};
////
////    int *p = (int *)&a;
////    *p = 30;
////
////    printf("%p, %p\n", &a, p);
////    printf("%d, %d, %d, %d\n", a, *p, *(&a), *((int *)&a));
//    
//    return 0;
//}
