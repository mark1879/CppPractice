//
//   function_template_explicit_arguments.hpp
//  Templates
//
//  Created by MarkWu on 2022/11/1.
//  Copyright © 2022 Zego. All rights reserved.
//

#ifndef _function_template_explicit_arguments_hpp
#define _function_template_explicit_arguments_hpp

template <typename T1, typename T2, typename T3>
T1 sum(T2 val1, T3 val2) {
    return val1 + val2;
}

void test_function_template_explicit_arguments() {
    int i = 100;
    long lng = 100;
    
    auto val3 = sum<long long>(i, lng);
}


#endif /* _function_template_explicit_arguments_h */
