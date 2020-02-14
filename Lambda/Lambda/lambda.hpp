//
//  lambda.hpp
//  GenericAlgorithms
//
//  Created by MarkWu on 2020/2/6.
//  Copyright © 2020 Zego. All rights reserved.
//

#ifndef lambda_h
#define lambda_h

#include <iostream>
#include <vector>

using namespace std;

class TestClass
{
public:
    TestClass(int a)
    {
        value_a_ = a;
    }
    
    void print()
    {
        auto f = [=] () { cout << value_a_ << endl;};
        value_a_ = 102;
        f();
    }
    
private:
    int value_a_;
};

void test_capture_by_value()
{
    int value = 100;
    auto f = [value](){ cout << "value:" << value << endl; };
    
    value = 102;
    f();
    
    cout << endl;
}

void biggies(vector<string>& words, ostream& os = cout, char c = ' ')
{
    for_each(words.cbegin(), words.cend(), [&os, c](const string& str) { os << str << c; });
}


void test_capture_by_reference()
{
    int value = 100;
    auto f = [&value]() { cout << "value:" << value << endl; };
    
    value = 102;
    f();
    
    cout << endl;
    
    TestClass test(100);
    test.print();
    
    vector<string> vec_string = {"hello", "world"};
    biggies(vec_string);
    
    cout << endl;
}

void test_mutable()
{
    int value = 100;
    auto f = [=]() mutable { value = 101; };
    
    f();
    
    cout << "value: " << value << endl;
}

void test_return_type()
{
    
    vector<int> vec = {1, 2, -1, -2};
    transform(vec.begin(), vec.end(), vec.begin(), [](int i) -> double { if (i < 0) return i * 1.0; else return i; });
    for (auto it : vec)
        cout << it << "\t";
    cout << endl;
}

void test_generic_type_lambda()
{
    auto add = [](auto a, auto b) { return a + b; };
    cout << add(1, 2) << endl;
}

void test_capture_right_value()
{
    auto important = make_unique<int>(1);
    
    auto add = [v1 = 1, &important] (int x, int y) -> int {
        return v1 + (*important) + x + y;
    };
    
    cout << add(1, 1) << endl;
}


#endif /* lambda_h */
