//
//  forward_args.hpp
//  Templates
//
//  Created by MarkWu on 2019/11/20.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef forward_args_h
#define forward_args_h
#include <iostream>
#include <utility>
#include "line.hpp"

template<typename... Args>
void work(Args&&... args)
{
}

void test_forward_args()
{
    Line line;
    
    work(line, line);
}

#endif /* forward_args_h */
