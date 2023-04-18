//
//  test_iterator.hpp
//  SequentialContainers
//
//  Created by MarkWu on 2022/6/29.
//  Copyright © 2022 Zego. All rights reserved.
//

#ifndef test_iterator_hpp
#define test_iterator_hpp
#include <list>

void test_invalid_iterator_vector() {
    vector<int> vec = {1, 2, 3};
    print_vector(vec);
    
    auto it = vec.begin();
    cout << "it: " << *it << endl;
    
    auto p = &vec[0];
    cout << "p: " << *p << endl;
    
    auto &ref = vec.front();
    cout << "ref: " << ref << endl;
    
//    vec.insert(vec.begin(), 0);
//    vec.erase(vec.begin());
    vec.resize(1000 * 1000);
    
//    print_vector(vec);
    cout << "it: " << *(it + 1) << endl;
    cout << "p: " << *(p + 1) << endl;
    cout << "ref: " << ref << endl;
}

void test_invalid_iterator_list() {
    list<int> li = {1, 2, 3};
    
    auto it = li.begin();
    cout << "it: " << *it << endl;
    
    auto &ref = li.front();
    cout << "ref: " << ref << endl;
    
//    li.insert(li.begin(), 0);
    li.erase(li.begin());
    
    cout << "it: " << *it << endl;
    cout << "ref: " << ref << endl;
}

void test_invalid_iterator() {
//    test_invalid_iterator_list();
//    test_invalid_iterator_vector();
    
//    list<int> li;
//    li.push_back(1);
//    li.push_back(2);
//
//    auto it = li.begin();
//    it++;
//
//    cout << *it << endl;
//
//    li.erase(li.begin());
//
//    cout << *it << endl;
    
//    vector<int> vec = {1, 2, 3, 4};
//    auto it = vec.begin();
//    it++;
//    cout << *it << endl;
//    vec.erase(vec.begin());
//    cout << *it << endl;
    
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    auto it = vec.begin();
//    while (it != vec.end()) {
//        if (*it % 2) {
//            it = vec.insert(it, *it);
//            it += 2;
//        } else {
//            it = vec.erase(it);
//        }
//    }
//
//    print_vector(vec);
    
    auto begin = vec.begin();
    auto end = vec.end();
    
    while (begin != end) {
//        begin++;
        begin = vec.insert(begin, 42);
        begin++;
    }
}

#endif /* test_iterator_h */
