//
//  performance_testing.hpp
//  SequentialContainers
//
//  Created by MarkWu on 2022/6/28.
//  Copyright © 2022 Zego. All rights reserved.
//

#ifndef performance_testing_hpp
#define performance_testing_hpp
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <chrono>

using namespace std;

#define MAX_NUM 1000 * 100

//#define PUSH_BACK

void performance_testing_vector() {
    vector<int> vec = {1, 2, 3};
    
    std::chrono::milliseconds start_time = std::chrono::duration_cast< std::chrono::milliseconds >(
          std::chrono::system_clock::now().time_since_epoch()
      );
   
    for (int i = 0; i < MAX_NUM; i++) {
#ifdef PUSH_BACK
        vec.push_back(i);
#else
        vec.insert(vec.begin() + 2, i);
#endif
    }
    
   
   std::chrono::milliseconds end_time = std::chrono::duration_cast< std::chrono::milliseconds >(
       std::chrono::system_clock::now().time_since_epoch()
   );
    
    cout << "vector, time consumed: "<< (end_time.count() - start_time.count()) << endl;
}

void performance_testing_list() {
    list<int> li;
    
    std::chrono::milliseconds start_time = std::chrono::duration_cast< std::chrono::milliseconds >(
          std::chrono::system_clock::now().time_since_epoch()
      );
   
    for (int i = 0; i < MAX_NUM; i++) {
#ifdef PUSH_BACK
        li.push_back(i);
#else
        li.insert(li.begin(), i);
#endif
    }
    
   
   std::chrono::milliseconds end_time = std::chrono::duration_cast< std::chrono::milliseconds >(
       std::chrono::system_clock::now().time_since_epoch()
   );
    
    cout << "list, time consumed: "<< (end_time.count() - start_time.count()) << endl;
}

void performance_testing_deque() {
    deque<int> de = {1, 2, 3};
    
    std::chrono::milliseconds start_time = std::chrono::duration_cast< std::chrono::milliseconds >(
          std::chrono::system_clock::now().time_since_epoch()
      );
   
    for (int i = 0; i < MAX_NUM; i++) {
#ifdef PUSH_BACK
        de.push_back(i);
#else
        de.insert(de.begin() + 2, i);
#endif
    }
    
   
   std::chrono::milliseconds end_time = std::chrono::duration_cast< std::chrono::milliseconds >(
       std::chrono::system_clock::now().time_since_epoch()
   );
    
    cout << "deque, time consumed: "<< (end_time.count() - start_time.count()) << endl;
}

void performance_testing() {
    performance_testing_vector();
    performance_testing_list();
    performance_testing_deque();
}


#endif /* performance_testing_h */
