//
//  class_template.hpp
//  Templates
//
//  Created by MarkWu on 2019/11/15.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef class_template_h
#define class_template_h
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Blob
{
public:
    typedef T value_type;
    typedef typename vector<T>::size_type size_type;
    
    Blob();
    Blob(initializer_list<T> il);
    
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    T& back();
    T& operator[](size_type i);
    std::shared_ptr<std::vector<T>> GetData() { return data; }
    
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

void test_class_template();




#endif /* class_template_h */
