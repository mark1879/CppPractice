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
#include "function_template.h"
#include "variable_parameter_template.hpp"
#include "forward_args.hpp"
#include "template_specilization.hpp"
#include "template_argument_deduction.hpp"
#include "function_template_explicit_arguments.hpp"

using namespace std;

extern template class Blob<int>;
extern template int compare2(const char*, const char*);


int main(int argc, const char * argv[])
{

//    test_function_template();
//    cout << "compare2: " << compare2("hello", "aaa") << endl;

//    test_class_template();
//    Blob<int> ia2 = {1, 2};
    
//
//    test_variable_parameter_template();
//    test_forward_args();
//    test_template_specialization();
    
//    test_template_argument_deduction();
    
    test_function_template_explicit_arguments();
    
    return 0;
}
