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

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) { }

void test_class_template()
{
    Blob<int> ia;
    Blob<int> ia2 = {1, 2};
    Blob<int> ia3({1, 2, 3});
    Blob<string> ia4 = {"hello", "the" "world"};
    Blob<string> ia5({"hello", "the" "world"});
}

#endif /* class_template_h */
