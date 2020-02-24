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
#include <vector>
#include <utility>

using namespace std;

class Line
{
public:
    Line(int len);             // 简单的构造函数
    Line(const Line &obj);     // 拷贝构造函数
    Line(Line&& obj);
    ~Line();                   // 析构函数
    
private:
    int *ptr = nullptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "Normal constructor allocating ptr, len: " << len << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}

// 拷贝构造
Line::Line(const Line &obj)
{
    cout << "Copy constructor allocating ptr, len: " << *obj.ptr << endl;
    ptr = new int;
    *ptr = *obj.ptr;    // copy the value
}

// 移动构造
Line::Line(Line&& obj)
{
    cout << "Move constructor, len: " << *obj.ptr << endl;
    this->ptr = obj.ptr;
    obj.ptr = nullptr;
}

Line::~Line(void)
{
    cout << "Freeing memory!" << endl;
    
    if (ptr != nullptr){
        cout << "ptr is not null, len: " << *ptr << endl;
        delete ptr;
    } else {
        cout << "ptr is null" << endl;
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

void test_init_map(){
    map<string, size_t> word_count1;
    map<string, size_t> word_count2 = {{"hello", 1}, {"world", 2}};
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

void test_map_insert_object(){
    cout << "test_insert_object: " << endl;
    
    map<string, Line> test_map;
    
    test_map.insert({"hello", Line(1)});
    test_map.insert({"hello", Line(2)});

    cout << endl << "<<< size: " << test_map.size() << endl;
}

void test_map_emplace_object(){
    cout << endl << endl << "test_emplace_object: " << endl;

    map<string, Line> test_map;
    
    test_map.emplace("hello", Line(11));
    test_map.emplace("hello", Line(12));
    
    cout << endl << "<<< size: " << test_map.size() << endl << endl;
}

#endif /* map_practice_h */
