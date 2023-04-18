//
//  member_functions.hpp
//  ObjectOriented
//
//  Created by MarkWu on 2022/12/27.
//

#ifndef member_functions_hpp
#define member_functions_hpp
#include <iostream>


namespace MemberFunctions {
class Test {
public:
    Test() : a_(100) { }
    
    void Show() {
        std::cout << "Show()" << std::endl;
    }
    
    void Show() const {
        std::cout << "Show() const" << std::endl;
    }
    
private:
    int a_;
};

class Test2 {
public:
    Test2(int a) : a_(a)
    { }
    
    void Func() {
        std::cout << "Test2::Func()" << std::endl;
    }
    
    static void StaticFunc() {
        std::cout << "Test2::StaticFunc()" << std::endl;
    }
    
public:
    int a_;
    static int s_b_;
};

int Test2::s_b_ = 10;

};

using namespace MemberFunctions;

//int main() {
    
//    const MemberFunctions::Test test;
//    test.Show();
    
//    Test2 test2(1);
//    int *p_1 = &test2.a_;
//    *p_1 = 11;
//    std::cout << test2.a_ << std::endl;
//
//
//    int Test2::*p_2 = &Test2::a_;
//    test2.*p_2 = 21;
//    std::cout << test2.a_ << std::endl;
//
//
//    int *p_s_b = &Test2::s_b_;
//    *p_s_b = 100;
//    std::cout << Test2::s_b_ << std::endl;
//
//
//    void (Test2::*func)() = &Test2::Func;
//    (test2.*func)();
//
//    void (*static_func)() = &Test2::StaticFunc;
//    (*static_func)();

//
    
//    return 0;
//}



#endif /* member_functions_h */
