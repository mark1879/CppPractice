//
//  main.cpp
//  Templates
//
//  Created by MarkWu on 2019/8/1.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include <map>
#include "class_template.hpp"
#include "function_template.hpp"
#include "variable_parameter_template.hpp"
#include "forward_args.hpp"
#include "template_specilization.hpp"

using namespace std;

void test(std::initializer_list<int>& a)
{
    for (auto iter = a.begin(); iter != a.end(); iter++)
    {
        cout << *iter << endl;
    }
}

void test_array(int arr[])
{
}

void test_array2(const int (&arr)[5])
{
}

void array_practice()
{
    int *arr_pointer = (int *)malloc(10 * sizeof(int));
    test_array(arr_pointer);

    int arr[] = {1, 2, 3, 4, 5};
    test_array(arr);

    test_array2({1, 2, 3, 4, 5});
}

int main(int argc, const char * argv[])
{
//    test_function_template();
//    test_class_template();
//    test_variable_parameter_template();
//    test_forward_args();
//    test_template_specialization();
    
    std::map<std::string, std::string> test;
    
    test["hello"] = "hello";
    test["hello"] = "hell, world";

    cout << test["hello"] << endl;
    
    return 0;
}
