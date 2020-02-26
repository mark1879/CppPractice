//
//  map_practice.hpp
//  AssociativeContainers
//
//  Created by MarkWu on 2020/2/20.
//  Copyright © 2020 Zego. All rights reserved.
//

#ifndef map_practice_h
#define map_practice_h
#include <map>
#include <unordered_map>
#include <vector>
#include <utility>
#include "line.hpp"

using namespace std;

void test_init_map(){
    map<string, size_t> word_count1;
    map<string, size_t> word_count2 = {{"hello", 1}, {"world", 2}, {"everybody", 3}};
    
    map<string, size_t> word_count3(word_count2.cbegin(), word_count2.cend());
    for (const auto &w : word_count3){
           cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
    
    cout << endl;
    
    unordered_map<string, size_t> word_count4(word_count2.cbegin(), word_count2.cend());
    for (const auto &w : word_count4){
           cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
    
    cout << endl;

    multimap<string, size_t> word_count5(word_count2.cbegin(), word_count2.cend());
    word_count5.insert({"hello", 100});
    for (const auto &w : word_count5){
           cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
    
    cout << endl;

    unordered_multimap<string, size_t> word_count6(word_count2.cbegin(), word_count2.cend());
    word_count6.insert({"world", 100});
    for (const auto &w : word_count6){
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
}

void test_map_traverse(){
    vector<string> vec_string = {"hello", "world", "hello", "everybody"};
    map<string, size_t> word_count;
    
    for (auto it : vec_string){
        // 如果it在map中不存在，map会自动增加(it, 0)
        ++word_count[it];
    }
    
    
    for (const auto &w : word_count){
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
    
    cout << endl;
    
    for (auto it = word_count.begin(); it != word_count.end(); it++){
        cout << it->first << " occurs " << it->second << ((it->second > 1) ? " times" : " time") << endl;
    }
    
    cout << endl;

    for (auto it = word_count.cbegin(); it != word_count.cend(); it++){
       cout << it->first << " occurs " << it->second << ((it->second > 1) ? " times" : " time") << endl;
    }
    
    cout << endl;
    
    for (auto it = word_count.rbegin(); it != word_count.rend(); it++){
        cout << it->first << " occurs " << it->second << ((it->second > 1) ? " times" : " time") << endl;
    }

    cout << endl;

    for (auto it = word_count.crbegin(); it != word_count.crend(); it++){
        cout << it->first << " occurs " << it->second << ((it->second > 1) ? " times" : " time") << endl;
    }

    cout << endl;
}

void test_map_insert(){
    vector<string> vec_str = {"hello", "everybody", "yes", "we", "can"};
    map<string, size_t> word_count;
    
    for (const auto &it : vec_str){
        // 如果it在map中不存在，map会自动增加(it, 0)
        ++word_count[it];
    }
    
    auto ret = word_count.insert({"hello", 1});
    if (!ret.second){
        ++ret.first->second;
    }
    
    // make_pair会自动推导数据类型
    ret = word_count.insert(make_pair("yes", 1));
    if (!ret.second){
        ++ret.first->second;
    }
    
    // pair构造函数需要指定数据类型
    ret = word_count.insert(pair<string, size_t>("we", 1));
    if (!ret.second){
        ++ret.first->second;
    }
    
    ret = word_count.insert(map<string, std::size_t>::value_type("can", 1));
    if (!ret.second){
        ++ret.first->second;
    }
    
    for (const auto &it : word_count){
        cout << it.first << " occurs " << it.second << (it.second > 0 ? " times" : " time") << endl;
    }
}

void test_map_emplace(){
    vector<string> vec_str = {"hello", "everybody", "yes", "we", "can"};
    map<string, size_t> word_count;

    for (const auto &it : vec_str){
       // 如果it在map中不存在，map会自动增加(it, 0)
       ++word_count[it];
    }

    // uses pair's template constructor
    auto ret = word_count.emplace("hello", 1);
    if (!ret.second){
       ++ret.first->second;
    }

    // uses pair's move constructor
    ret = word_count.emplace(make_pair("yes", 1));
    if (!ret.second){
       ++ret.first->second;
    }

    // uses pair's move constructor
    ret = word_count.emplace(pair<string, size_t>("we", 1));
    if (!ret.second){
       ++ret.first->second;
    }

    ret = word_count.emplace(map<string, std::size_t>::value_type("can", 1));
    if (!ret.second){
       ++ret.first->second;
    }

    for (const auto &it : word_count){
       cout << it.first << " occurs " << it.second << (it.second > 0 ? " times" : " time") << endl;
    }
}

void test_map_insert_object_1(){
    cout << "test_insert_object_1: " << endl;
    
    map<string, Line> test_map;
    
    test_map.insert({"hello", Line(1)});
    test_map.insert({"hello", Line(2)});

    cout << endl << "<<< size: " << test_map.size() << endl;
}

void test_map_emplace_object_1(){
    cout << endl << endl << "test_emplace_object_1: " << endl;

    map<string, Line> test_map;
    
    test_map.emplace("hello", Line(11));
    test_map.emplace("hello", Line(12));
    
    cout << endl << "<<< size: " << test_map.size() << endl << endl;
}

void test_map_insert_object_2(){
    cout << "test_insert_object_2: " << endl;
    
    map<string, Line> test_map;
    Line line(1);
    
    cout << "<<<" << endl;
    test_map.insert({"hello", line});
    cout << "<<<" << endl;
    line.SetLength(2);
    test_map.insert({"hello", line});

    cout << endl << "<<< size: " << test_map.size() << endl;
}

void test_map_emplace_object_2(){
    cout << endl << endl << "test_emplace_object_2: " << endl;

    map<string, Line> test_map;
    Line line(11);
    
    cout << "<<<" << endl;
    test_map.emplace("hello", line);
    cout << "<<<" << endl;
    line.SetLength(12);
    test_map.emplace("hello", line);
    
    cout << endl << "<<< size: " << test_map.size() << endl << endl;
}

#endif /* map_practice_h */
