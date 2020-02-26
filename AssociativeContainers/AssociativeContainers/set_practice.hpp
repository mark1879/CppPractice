//
//  set_practice.hpp
//  AssociativeContainers
//
//  Created by MarkWu on 2020/2/20.
//  Copyright © 2020 Zego. All rights reserved.
//

#ifndef set_practice_h
#define set_practice_h
#include <iostream>
#include <set>


void test_set_init(){
    set<string> set_empty;
    set<string> set_str = {"hello", "world", "hello", "everybody"};
    
    set<string> set_str2(set_str.cbegin(), set_str.cend());
}

void test_set_insert(){
    set<string> set_str = {"hello", "world", "hello", "everybody"};

    for (const auto &it : set_str){
        cout << it << endl;
    }
    
    
    set<int> set_int = {100, 20, 1};
    for (const auto &it : set_int){
          cout << it << endl;
      }
}

void test_using_set(){
    vector<string> vec_string = {"hello", "world", "hello", "everybody"};
    set<string> set_string = {"world"};
    
    map<string, size_t> word_count;
    
    for (auto it : vec_string){
        if (set_string.find(it) == set_string.end()){
            ++word_count[it];
        }
    }
    
    for (const auto &it : word_count){
        cout << it.first << " occurs " << it.second << (it.second > 0 ? " times" : " time")<< endl;
    }
    
    cout << endl;
}


#endif /* set_practice_h */
