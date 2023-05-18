//
//  class_template_instantiation.hpp
//  templates2
//
//  Created by MarkWu on 2023/5/18.
//

#ifndef class_template_instantiation_hpp
#define class_template_instantiation_hpp

#include <typeinfo>

template<typename T, typename U> // 基本模板
class S
{
public:
   void info() {
       printf("base template\n");
   }
};

template<> // 特化
class S<int, int>
{
public:
   void info() {
       printf("int specialization\n");
   }
};

template<typename T, typename U> // 偏特化
class S<T*, U*>
{
public:
   void info() {
       printf("pointer partial specialization\n");
    }
};

template<typename T> // 偏特化
class S<T, int>
{
public:
   void info() {
       printf("int partial specialization\n");
    }
};

void TestClassSpecialization()
{
    S<double, double > s1;
    s1.info();     // base 模板

    S<int, int> s2;
    s2.info();     // int 特化
    
    S<float*, float*> s3;
    s3.info();      // T* 偏特化

    S<float, int> s4;
    s4.info();     // int 偏特化
}






#endif /* class_template_instantiation_h */
