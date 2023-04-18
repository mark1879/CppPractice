//
//  test_atomic_operation.hpp
//  Concurrency
//
//  Created by MarkWu on 2022/9/1.
//

#ifndef test_atomic_operation_hpp
#define test_atomic_operation_hpp

#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> count1 = {0};
int b = 0;

struct A {
    float x;
    int y;
    long long z;
};

void test_atomic_operation() {
    std::thread t1([](){
        for (int i = 0; i < 1000; i++) {
            count1.fetch_add(1);
            b++;
        }
    });
    std::thread t2([](){
//        count1 += 1;     // 等价于 fetch_add
        
        for (int i = 0; i < 1000; i++) {
            count1++;    // 等价于 fetch_add
            b++;
        }
    });
    t1.join();
    t2.join();
    std::cout << count1 << std::endl;
    std::cout << b << std::endl;
    
    // 并非所有的类型都能提供原子操作，这是因为原子操作的可行性取决于具体的 CPU 架构，以及所实例化的类型结构是否能够满足该 CPU 架构对内存对齐 条件的要求，因而我们总是可以通过 std::atomic<T>::is_lock_free 来检查该原子类型是否需支持原子操作
    std::atomic<int> a;
    std::cout << std::boolalpha << a.is_lock_free() << std::endl;
    
    std::atomic<A> A;
    std::cout << std::boolalpha << A.is_lock_free() << std::endl;
}


#endif /* test_atomic_operation_h */
