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
    set<string> set_str = {"hello", "world"};
    auto ret = set_str.insert("hello");
    if (!ret.second){
        cout << "no insertion" << endl;
    }

    ret = set_str.insert("iCan");
    if (ret.second){
        for (auto it = ret.first; it != set_str.end(); it++){
            cout << *it << "\t";
        }
    }
    
    cout << endl;
    
    for (const auto &it : set_str){
        cout << it << "\t";
    }
    
    cout << endl;
    
    set<string> set_str2 = {"yes", "we", "can"};
    set_str.insert(set_str2.begin(), set_str2.end());
    
    for (const auto &it : set_str){
           cout << it << "\t";
    }
       
    cout << endl;
}

void test_set_emplace(){
    set<string> set_str = {"hello", "world"};
    auto ret = set_str.emplace("hello");
    if (!ret.second){
       cout << "no insertion" << endl;
    }

    ret = set_str.emplace("iCan");
    if (ret.second){
       for (auto it = ret.first; it != set_str.end(); it++){
           cout << *it << "\t";
       }
    }

    cout << endl;

    for (const auto &it : set_str){
       cout << it << "\t";
    }

    cout << endl;
}

void test_set_traverse(){
    set<string> set_str = {"hello", "world", "hello", "everybody"};

    for (const auto &it : set_str){
        cout << it << "\t";
    }
    
    cout << endl;

    for (auto it = set_str.begin(); it != set_str.end(); it++){
        cout << *it << "\t";
    }
    
    cout << endl;

    for (auto it = set_str.cbegin(); it != set_str.cend(); it++){
        cout << *it << "\t";
    }

    cout << endl;

    for (auto it = set_str.rbegin(); it != set_str.rend(); it++){
        cout << *it << "\t";
    }

    cout << endl;
    
    for (auto it = set_str.crbegin(); it != set_str.crend(); it++){
        cout << *it << "\t";
    }

    cout << endl;
}

void test_set_erase(){
    auto print_set = [](const set<string> &set_str){
        for (const auto &it : set_str){
            cout << it << "\t";
        }
        cout << endl;
    };
    
    set<string> set_str = {"hello", "world", "everybody", "yes", "we", "can"};
    
    print_set(set_str);
    
    // 返回被删除的元素的个数
    auto ret1 = set_str.erase("hello");
    cout << "ret1: " << ret1 << endl;
    
    auto it1 = set_str.find("we");
    // 返回被删除元素的下一个位置的元素
    auto ret2 = set_str.erase(it1);
    cout << "ret2: " << *ret2 << endl;
    
    print_set(set_str);
    
    auto it2 = set_str.find("world");
    // 返回it2
    auto ret3 = set_str.erase(set_str.cbegin(), it2);
    cout << "ret3: " << *ret3 << endl;
    
    print_set(set_str);
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
