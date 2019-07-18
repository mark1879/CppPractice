//
//  main.cpp
//  BasicKnowledge
//
//  Created by MarkWu on 2018/1/27.
//  Copyright © 2018年 Zego. All rights reserved.
//

#include<iostream>
#include<string>
#include <limits>
#include "DataTypeTest.hpp"
#include "ClassPractice.hpp"
#include "override_pratice.hpp"
#include "polymorphism_practice.hpp"
#include "virtual_table.hpp"
#include "time_practice.hpp"
#include "memory_layout.hpp"
#include <map>
#include <vector>

using namespace std;

template<typename T, typename U>
int sub(T a, U b)
{
    return a - b;
}

template<typename T, typename U>
auto add(T x, U y) ->decltype(x + y)
{
    return x + y;
}

int main(int argc, const char * argv[])
{

//    sub(100.10, 10);
//    add(100, 10.1);
//    add(1.1, 1);
    
    std::vector<std::shared_ptr<int>> list;
    
    for (int i = 0; i < 10; i++)
    {
        std::shared_ptr<int> element = std::make_shared<int>(i);
        list.push_back(element);
    }
    
    for (auto it = list.begin(); it != list.end(); it++)
    {
        
        if (*(it->get()) == 5)
        {
            cout << "test:" << *(it->get()) << endl;
            it = list.erase(it);
            cout << "test:" << *(it->get()) << endl;
        }
        else
        {
             cout << *(it->get()) << endl;
        }
       
    }
    
    cout << "verification: " << endl;
    
    for (auto it = list.begin(); it != list.end(); it++)
    {
        cout << *(it->get()) << endl;
    }
    
    return 0;
}
