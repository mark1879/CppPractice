//
//  custom_operations.hpp
//  GenericAlgorithms
//
//  Created by MarkWu on 2020/2/2.
//  Copyright © 2020 Zego. All rights reserved.
//

#ifndef custom_operations_h
#define custom_operations_h

#include <vector>
#include <iostream>

void print(const vector<string>& vec, string name)
{
    cout << name.c_str() << endl;
    for (auto const &it : vec)
        cout << it << "\t";
    
    cout << endl;
}

void test_custom_sort()
{
    vector<string> vec1 = {"hello", "aloha", "no", "yes", "hello", "guys", "everybody", "ccccc"};
    vector<string> vec2 = vec1;

    // 先按照字典排序
    sort(vec1.begin(), vec1.end());
    print(vec1, "sort vec1:");
    
    stable_sort(vec2.begin(), vec2.end());
    print(vec2, "stable_sort vec2:");
    
    cout << endl << "resort by length:" << endl << endl;
    
    // 按照字符串长度排序
    sort(vec1.begin(), vec1.end(), [](const string& str1, const string& str2) {return str1.size() < str2.size();});
    print(vec1, "sort vec1:");
       
    stable_sort(vec2.begin(), vec2.end(), [](const string& str1, const string& str2){return str1.size() < str2.size();});
    print(vec2, "stable_sort vec2:");
    
    cout << endl;
}

void test_find()
{
    vector<string> vec = {"hello", "aloha", "no", "everyone", "hello", "aloha", "no", "guys"};
    string str_target = "hello";
    auto ret_find = find(vec.cbegin(), vec.cend(), str_target);
    if (ret_find != vec.cend())
        cout << "find, got: " << *ret_find << endl;
    else
        cout << "find, no " << str_target << endl;
    
    cout << endl;
    
    int str_size = 6;
    auto ret_find_if = find_if(vec.cbegin(), vec.cend(), [str_size](const string& a) { return a.size() >= str_size; });
    if (ret_find_if != vec.cend())
           cout << "find_if, got: " << *ret_find_if << endl;
       else
           cout << "find_if, no size >= " << str_size << endl;
    
    cout << endl;
    
    vector<string> vec_to_find = {"aloha", "no"};
    auto ret_find_first_of = find_first_of(vec.cbegin(), vec.cend(), vec_to_find.cbegin(), vec_to_find.cend());
    if (ret_find_first_of != vec.cend())
        cout << "find_first_of, got: " << *ret_find_first_of << endl;
    else
        cout << "find_first_of, nop!" << endl;
    
    cout << endl;
    
    auto ret_find_first_of_2 = find_first_of(vec.cbegin(), vec.cend(), vec_to_find.cbegin(), vec_to_find.cend(), [](const string& str1, const string& str2){
        return str1 == str2;
    });
    
    if (ret_find_first_of_2 != vec.cend())
        cout << "ret_find_first_of_2, got: " << *ret_find_first_of_2 << endl;
    else
        cout << "ret_find_first_of_2, nop!" << endl;
       
    cout << endl;
    
    auto ret_find_end = find_end(vec.cbegin(), vec.cend(), vec_to_find.cbegin(), vec_to_find.cend());
   if (ret_find_end != vec.cend())
       cout << "ret_find_end, got: " << *(ret_find_end + 2) << endl;
   else
       cout << "ret_find_end, nop!" << endl;
      
   cout << endl;
    
    auto ret_find_end_2 = find_end(vec.cbegin(), vec.cend(), vec_to_find.cbegin(), vec_to_find.cend(), [](const string& str1, const string str2){
        cout << "str1: " << str1 << "  str2: " << str2 << endl;
        return str1 == str2;
    });
    
    if (ret_find_end_2 != vec.cend())
        cout << "ret_find_end_2, got: " << *(ret_find_end_2 + 2) << endl;
    else
        cout << "ret_find_end_2, nop!" << endl;
         
    cout << endl;
}

void test_search()
{
    vector<string> vec = {"hello", "aloha", "no", "everyone", "hello", "aloha", "no", "guys"};
    vector<string> vec_to_find = {"aloha", "no"};
    auto ret_search = search(vec.cbegin(), vec.cend(), vec_to_find.cbegin(), vec_to_find.cend());
    if (ret_search != vec.cend())
        cout << "ret_search, got: " << *(ret_search + 2) << endl;
    else
        cout << "ret_search, nop!" << endl;
       
    cout << endl;
}

void test_partition()
{
    vector<string> vec = {"hello", "aloha", "no", "yes", "everyone", "hello", "guys", "eeeee", "ccccc", "hello1"};
    sort(vec.begin(), vec.end());
    
    vector<string> vec2 = vec;

    for_each(vec.cbegin(), vec.cend(), [](const string& str) { cout << str << "\t"; });
    cout << endl;
    for_each(vec2.cbegin(), vec2.cend(), [](const string& str) { cout << str << "\t"; });
    cout << endl;
    
    auto ret_partition = partition(vec.begin(), vec.end(), [](const string& str) { return str.size() >= 5; });
    for_each(vec.begin(), ret_partition, [](const string& str) { cout << str << "\t"; });
    
    cout << endl;
    
    auto ret_stable_partition = stable_partition(vec2.begin(), vec2.end(), [](const string& str) { return str.size() >= 5; });
    for_each(vec2.begin(), ret_stable_partition, [](const string& str) { cout << str << "\t"; });
    
    cout << endl;
}

void test_for_each()
{
    vector<string> vec = {"hello", "aloha", "no", "yes", "everyone", "hello", "guys", "eeeee", "ccccc"};

    for_each(vec.cbegin(), vec.cend(), [](const string& str) { cout << str.c_str() << "\t"; });
    
    cout << endl;
}

void test_transform()
{
    string s("hello");
    transform(s.begin(), s.end(), s.begin(),
    [](unsigned char c) -> unsigned char {
        return toupper(c);
    });

    vector<size_t> ordinals;
    transform(s.begin(), s.end(), std::back_inserter(ordinals),
    [](unsigned char c) -> size_t {
        return c;
    });

    cout << s << ':';
    for (auto ord : ordinals) {
        cout << ' ' << ord;
    }

    cout << endl;
}

void test_count_if()
{
     std::vector<int> v{ 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
    
    // determine how many integers in a std::vector match a target value.
    int target1 = 3;
    int target2 = 5;
    size_t num_items1 = std::count(v.begin(), v.end(), target1);
    size_t num_items2 = std::count(v.begin(), v.end(), target2);
    std::cout << "number: " << target1 << " count: " << num_items1 << '\n';
    std::cout << "number: " << target2 << " count: " << num_items2 << '\n';

    // use a lambda expression to count elements divisible by 3.
    size_t num_items3 = std::count_if(v.begin(), v.end(), [](int i){return i % 3 == 0;});
    std::cout << "number divisible by three: " << num_items3 << '\n';
}

#endif /* custom_operations_h */
