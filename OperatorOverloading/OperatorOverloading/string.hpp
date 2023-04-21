//
//  cstring.hpp
//  OperatorOverloading
//
//  Created by MarkWu on 2023/4/19.
//

#ifndef string_hpp
#define string_hpp
#include <iostream>

class String
{
public:
    String(const char* p = nullptr)
    {
        AllocateAndFill(p);
    }
    
    ~String()
    {
        if (cstr_ != nullptr)
        {
            delete[] cstr_;
            cstr_ = nullptr;
        }
    }
    
    String(const String& src)
    {
        AllocateAndFill(src.cstr_);
    }
    
    String& operator=(const String& src)
    {
        if (this == &src)
            return *this;
        
        if (cstr_ != nullptr)
        {
            delete[] cstr_;
            cstr_ = nullptr;
        }
        
        AllocateAndFill(src.cstr_);
        
        return *this;
    }
    
    String(String&& src)
    {
        cstr_ = src.cstr_;
        src.cstr_ = nullptr;
    }
    
    String& operator=(String&& src)
    {
        if (this == &src)
            return *this;
        
        if (cstr_ != nullptr)
        {
            delete[] cstr_;
            cstr_ = nullptr;
        }
        
        cstr_ = src.cstr_;
        src.cstr_ = nullptr;
        
        return *this;
    }
    
    bool operator>(const String& str) const
    {
        return strcmp(cstr_, str.cstr_) > 0;
    }
    
    bool operator<(const String& str) const
    {
        return strcmp(cstr_, str.cstr_) < 0;
    }
    
    bool operator==(const String& str) const
    {
        return strcmp(cstr_, str.cstr_) == 0;
    }
    
    char& operator[](size_t index)
    {
        return cstr_[index];
    }
    
    const char& operator[](size_t index) const
    {
        return cstr_[index];
    }
    
    size_t length() const
    {
        return strlen(cstr_);
    }
    
    const char* c_str() const
    {
        return cstr_;
    }
    
    class iterator
    {
    public:
        iterator(char* p = nullptr) : p_(p) {}
        
        bool operator!=(const iterator& it)
        {
            return p_ != it.p_;
        }
        
        void operator++()
        {
            ++p_;
        }
        
        void operator++(int)
        {
            p_++;
        }
        
        char& operator*()
        {
            return *p_;
        }
    private:
        char* p_;
    };
    
    iterator begin()
    {
        return iterator(cstr_);
    }
    
    iterator end()
    {
        return iterator(cstr_ + strlen(cstr_));
    }
    
    friend std::ostream& operator<<(std::ostream& out, const String& str);
    friend String operator+(const String& lstr, const String& rstr);
    
private:
    void AllocateAndFill(const char* src)
    {
        if (this->cstr_ != nullptr)
            throw "cstr_ must be nullptr!";
        
        size_t str_len = 0;
        
        if (src != nullptr)
            str_len = strlen(src);
        
        this->cstr_ = new char[str_len + 1];
        strncpy(this->cstr_, src, str_len);
        cstr_[str_len] = '\0';
    }
    
    char* cstr_ = nullptr;
};

std::ostream& operator<<(std::ostream& out, const String& str)
{
    out << str.cstr_;
    return out;
}

String operator+(const String& lstr, const String& rstr)
{
    String tmp = new char[lstr.length() + rstr.length() + 1];
    strncpy(tmp.cstr_, lstr.cstr_, lstr.length());
    strncpy(tmp.cstr_ + lstr.length(), rstr.cstr_, rstr.length());

    tmp.cstr_[lstr.length() + rstr.length() + 1] = '\0';
    
    return tmp;
}

int main()
{
    
    String hello = "hello";
    String world = "world";
    
    hello[0] = 'H';
    std::cout << hello[0] << std::endl;
    
    String hello_world = hello + ", " + world;
    
    std::cout << hello_world << std::endl;
    
    for (auto it = hello_world.begin(); it != hello_world.end(); it++)
    {
        std::cout << *it << "\t";
    }
    
    std::cout << std::endl;
    
    for (auto ch : hello_world)
        std::cout << ch << "\t";
    
    std::cout << std::endl;
//
//    std::cout << (hello == "hello") << std::endl;
//    std::cout << (hello > "hell") << std::endl;
//    std::cout << (hello < "hell") << std::endl;
//
//    String empty_str;
//    std::cout << *empty_str.begin() << std::endl;
//    std::cout << empty_str[0] << std::endl;
    
    return 0;
}

#endif /* cstring_h */
