//
//  main.cpp
//  GoogleTest
//
//  Created by MarkWu on 2019/7/22.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include <gtest/gtest.h>

int Foo(int a, int b)
{
    if (a == 0 || b == 0)
        throw "don't do that";
    
    int c = a % b;
    
    if (c == 0)
        return b;
    
    return Foo(b, c);
}

TEST(FooTest, HandleNoneZeroInput)
{
//    ASSERT_EQ(2, Foo(4, 10));
    
     EXPECT_ANY_THROW(Foo(10, 1));
}

int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
