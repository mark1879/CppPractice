//
//  main.cpp
//  SequentialContainers
//
//  Created by MarkWu on 2020/1/9.
//  Copyright © 2020 Zego. All rights reserved.
//

#include <iostream>
#include "emplace_back.hpp"
#include "vector_testing.hpp"
#include "performance_testing.hpp"
#include "iterator_testing.hpp"

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, const char * argv[])
{
//    test_sequential_container();

//    performance_of_emplace_back();
    
//    performance_testing();
    
//    test_invalid_iterator();
    
//    char buf[10] = {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',};
//
//
//    for (int i = 0; i < 10; i++)
//        cout << (int)buf[i] << endl;
//
//    fgets(buf, 6, stdin);
//
//    cout << "len: " << strlen(buf) << endl;
    
//    for (int i = 0; i < 10; i++)
//        cout << (int)buf[i] << endl;
    
    vector<int> vec = {1, 2, 3, 4};
    auto it  = find(vec.begin(), vec.end(), 3);
    
    vec.erase(vec.begin(), it + 1);
    
    for (auto item : vec)
        cout << item << endl;
    
    return 0;
}
