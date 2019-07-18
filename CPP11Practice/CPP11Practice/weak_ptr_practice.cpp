//
//  weak_ptr_practice.cpp
//  CPP11Practice
//
//  Created by MarkWu on 2019/3/28.
//  Copyright © 2019 Zego. All rights reserved.
//

#include "weak_ptr_practice.hpp"
#include <memory>
#include <iostream>

using namespace std;

int main()
{
    int * pointer = new int;
    
//    shared_ptr<int> p1(pointer);
//    shared_ptr<int> p2(pointer);
    
    std::shared_ptr<int> shared_pointer = std::make_shared<int>(1);
    
    *shared_pointer = 100;
    
    cout << *shared_pointer << endl;
    
    std::weak_ptr<int> weak_pointer = shared_pointer;
    
    auto temp_pointer = weak_pointer.lock();
    
    cout << *temp_pointer << endl;
    
    cout << shared_pointer.use_count() << endl;
    
    return 0;
}
