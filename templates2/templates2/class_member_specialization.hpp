//
//  class_member_specialization.hpp
//  templates2
//
//  Created by MarkWu on 2023/5/18.
//

#ifndef class_member_specialization_hpp
#define class_member_specialization_hpp

template<typename T>
class ST
{
public:
    void info();
    
    // 正常实例化
    void info2()
    {
        printf("info2: base template: %d\n", code);
    }
    
    static int code;
};

template<typename T>
int ST<T>::code = 10;       // 正常实例化

template<>
int ST<int>::code = 100;    // int 特化

template<typename T>
void ST<T>::info()        // 正常实例化
{
     printf("info: base template: %d\n", code);
}

template<>
void ST<int>::info()        // int 特化
{
     printf("info：int specialization: %d\n", code);
}

void TestClassMemberSpecialization()
{
    ST<float> s1;
    s1.info();    // base，code = 10
    s1.info2();   // base，，code = 10

    ST<int> s2;
    s2.info();    //  int 特化，code = 100
    s2.info2();   //  base，code = 100
}




#endif /* class_member_specialization_h */
