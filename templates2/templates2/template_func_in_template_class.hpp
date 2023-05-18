//
//  template_func_in_template_class.hpp
//  templates2
//
//  Created by MarkWu on 2023/5/18.
//

#ifndef template_func_in_template_class_hpp
#define template_func_in_template_class_hpp

template <typename T>
class Printer
{
public:
    explicit Printer(const T& param):t(param){}
    //成员函数模板
    template<typename U>
    void add_and_print(const U& u);
private:
    T t;
};

// 两层 template 说明
template<typename T>
template<typename U>
void Printer<T>::add_and_print(const U& u)
{
    cout << t + u << endl;
}

void TestTemplateFuncInTemplateClass()
{
    Printer<int> p(42);
    p.add_and_print<double>(1.1);
}

#endif /* template_func_in_template_class_h */
