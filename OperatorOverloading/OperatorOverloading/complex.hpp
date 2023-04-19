//
//  complex.hpp
//  OperatorOverloading
//
//  Created by MarkWu on 2023/4/18.
//

#ifndef complex_hpp
#define complex_hpp
#include <iostream>

class Complex
{
public:
    Complex(int real = 0, int image = 0)
        : real_(real)
        , image_(image)
    {
        std::cout << "Complex(int, int), real_: " << real_ << ", image_: " << image_ << std::endl;
    }
    
    Complex(const Complex& src)
    {
        std::cout << "Complex(const Complex& ), real_: " << src.real_ << ", image_: " << src.image_ << std::endl;
        real_ = src.real_;
        image_ = src.image_;
    }
    
    Complex(Complex&& src)
    {
        std::cout << "Complex(const Complex&& ), real_: " << src.real_ << ", image_: " << src.image_ << std::endl;
        real_ = src.real_;
        image_ = src.image_;
        
        src.real_ = 0;
        src.image_ = 0;
    }
    
    Complex& operator=(const Complex& src)
    {
        std::cout << "operator=(const Complex& ), real_: " << src.real_ << ", image_: " << src.image_ << std::endl;

        if (this == &src)
            return *this;
        
        real_ = src.real_;
        image_ = src.image_;
        
        return *this;
    }
    
    Complex& operator=(Complex&& src)
    {
        std::cout << "operator=(Complex&& ), real_: " << src.real_ << ", image_: " << src.image_ << std::endl;

        if (this == &src)
            return *this;
        
        real_ = src.real_;
        image_ = src.image_;
        
        src.real_ = 0;
        src.image_ = 0;
        
        return *this;
    }
    
    Complex operator+(const Complex& src)
    {
        std::cout << "operator+(const Complex& src), real_: " << src.real_ << ", image_: " << src.image_ << std::endl;

        return Complex(this->real_ + src.real_, this->image_ + src.image_);
    }
    
    // 后置++
    Complex operator++(int)
    {
        return Complex(real_++, image_++);
    }
    
    // 前置++
    Complex& operator++()
    {
        ++real_;
        ++image_;
        return *this;
    }
    
    void operator+=(const Complex& src)
    {
        real_ += src.real_;
        image_ += src.image_;
    }
    
    ~Complex()
    {
        std::cout << "~Complex(), real_: " << real_ << ", image_: " << image_ << std::endl;
    }
 
private:
    int real_;
    int image_;
    
    friend Complex operator+(const Complex& cl, const Complex& cr);
    friend std::ostream& operator<<(std::ostream& out, const Complex& src);
    friend std::istream& operator>>(std::istream& in, Complex& src);
};

// 编译器优先调用对象的运算符重载函数（成员方法），
// 如果没有找到，则在全局作用域寻找合适的运算符重载函数。
Complex operator+(const Complex& cl, const Complex& cr)
{
    return Complex(cl.real_ + cr.real_, cl.image_ + cr.image_);
}

// 对象调用"成员运算符重载"时，对象必须在左边。
// 所以 << 只能定义为 "全局算符重载"
std::ostream& operator<<(std::ostream& out, const Complex& src)
{
    out << "reaal_: " << src.real_ << "image_: " << src.image_ << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Complex& src)
{
    in >> src.real_ >> src.image_;
    return in;
}

//int main(int argc, const char * argv[])
//{
//    Complex c1(1, 1);
//    Complex c2(2, 2);
    
    
//    Complex c3 = c1 + c2;
    
    
    
    // 正确
//    Complex c31 = c1 + 30;
    
    // 错误，还没有定义 "全局算符重载"
//    Complex c41 = 40 + c1;
    
    // 正确，定义 "全局算符重载" 后
//    Complex c51 = 50 + c1;
    
    
    
//    Complex c5(5, 5);
//    Complex c5_cpy = c5++;
//    Complex c5_cpy2 = ++c5;
 
    
    
//    Complex c6(6, 6);
//    c6 += c6;
    
    
//    Complex c7(7, 7);
//    std::cout << c7 << std::endl;
    
//    Complex c8(8, 8);
//    
//    std::cin >> c8;
//    
//    return 0;
//}


#endif /* complex_h */
