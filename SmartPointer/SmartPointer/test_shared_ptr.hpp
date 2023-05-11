//
//  test_shared_ptr.hpp
//  SmartPointer
//
//  Created by MarkWu on 2023/5/11.
//

#ifndef test_shared_ptr_hpp
#define test_shared_ptr_hpp

#include <iostream>
#include <memory>
#include <functional>

void TestUniquePtr()
{
    std::unique_ptr<int> ptr(new int);
    *ptr = 100;
    std::unique_ptr<int> ptr2(std::move(ptr));

    std::unique_ptr<int> ptr3;
    ptr3 = std::move(ptr2);
    
        
//        std::unique_ptr<int> ptr4 = GetSmartPtr<int>();
//        ptr4 = GetSmartPtr<int>();
}

void TestSharedPtrInt()
{
    std::shared_ptr<int> ptr = std::make_shared<int>();
    *ptr = 0;

    std::thread t1 = std::thread([&ptr](){
        for (int i = 0; i < 10000; i++)
            *ptr += 1;
    });

    std::thread t2 = std::thread([&ptr](){
        for (int i = 0; i < 10000; i++)
            *ptr += 1;
    });
    
//    std::thread t3 = std::thread([&ptr](){
//        for (int i = 0; i < 10000; i++)
//            *ptr += 1;
//    });

    t1.join();
    t2.join();
//    t3.join();

    std::cout << *ptr << std::endl;
}

void TestSharedPtrVector()
{
//    std::shared_ptr<int> ptr = std::make_shared<int>();
//    *ptr = 0;
        
    std::shared_ptr<std::vector<int>> ptr = std::make_shared<std::vector<int>>();
    ptr->push_back(0);

    std::thread t1 = std::thread([&ptr](){
        for (int i = 0; i < 1000; i++)
            (*ptr)[0] += 1;
    });

    std::thread t2 = std::thread([&ptr](){
        for (int i = 0; i < 1000; i++)
            (*ptr)[0] += 1;
    });

    t1.join();
    t2.join();

    std::cout << (*ptr)[0] << std::endl;
}

void TestDeletor()
{
    std::unique_ptr<int, std::function<void(int*)>> ptr(new int[100], [](int *p)->void {
        delete []p;
    });
}


int main(int argc, const char * argv[])
{
//    TestSharedPtrInt();

    return 0;
}



#endif /* test_shared_ptr_h */
