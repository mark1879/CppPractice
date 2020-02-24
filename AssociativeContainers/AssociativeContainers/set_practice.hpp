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
