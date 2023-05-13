//
//  bind1st_bind2nd.hpp
//  BindAndFunction
//
//  Created by MarkWu on 2023/5/12.
//

#ifndef bind1st_bind2nd_hpp
#define bind1st_bind2nd_hpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void Print(const std::vector<int>& data)
{
    for (const auto& it : data)
        std::cout << it << "\t";
    
    std::cout << std::endl;
}

template<typename Iterator, typename Compare>
Iterator my_find_if(Iterator begin, Iterator end, Compare comp)
{
    for (; begin != end; ++begin)
    {
        if (comp(*begin))
            return begin;
    }
    
    return end;
}

template<typename Compare, typename T>
class _MyBind1st
{
public:
    _MyBind1st(Compare comp, T val)
        : comp_(comp)
        , val_(val)
    {}
    
    bool operator()(const T& second)
    {
        return comp_(val_, second);
    }
    
private:
    Compare comp_;
    T val_;
};



template<typename Compare, typename T>
_MyBind1st<Compare, T> mybind1st(Compare comp, const T& val)
{
    return _MyBind1st<Compare, T>(comp, val);
}

int main(int argc, const char * argv[])
{
    std::vector<int> data;
    srand(time(nullptr));
    
    for (int i = 0; i < 10; i++)
        data.push_back(rand() % 100 + 1);
    
    Print(data);
    
    std::sort(data.begin(), data.end(), std::less<int>());
    
    Print(data);
    
//    auto it1 = std::find_if(data.begin(), data.end(),  std::bind1st(std::less<int>(), 20));
    auto it1 = my_find_if(data.begin(), data.end(),  mybind1st(std::less<int>(), 20));
    if (it1 != data.end())
        data.insert(it1, 20);
    
    Print(data);
    
    auto it2 = std::find_if(data.begin(), data.end(), std::bind2nd(std::greater<int>(), 21));
    if (it2 != data.end())
        data.insert(it2, 21);
    
    Print(data);
    
    return 0;
}


#endif /* bind1st_bind2nd_h */
