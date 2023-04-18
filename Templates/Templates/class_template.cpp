//
//  class_template.cpp
//  Templates
//
//  Created by MarkWu on 2022/10/17.
//  Copyright © 2022 Zego. All rights reserved.
//

#include "class_template.hpp"

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
