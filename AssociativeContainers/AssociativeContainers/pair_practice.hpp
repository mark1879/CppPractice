//
//  pair_practice.hpp
//  AssociativeContainers
//
//  Created by MarkWu on 2020/2/26.
//  Copyright © 2020 Zego. All rights reserved.
//

#ifndef pair_practice_h
#define pair_practice_h
#include <iostream>
#include <utility>

using namespace std;

void test_pair(){
    pair<string, size_t> word_count;
    word_count.first = "hello";
    word_count.second = 10;
    
    pair<string, size_t> word_count2 = {"hello", 10};
    pair<string, size_t> word_count3 = make_pair("hello", 11);
    pair<string, size_t> word_count4 = make_pair("everybody", 10);
    
    cout << "word_count == word_count2, " << (word_count == word_count2) << endl;
    cout << "word_count == word_count3, " << (word_count == word_count3) << endl;
    cout << "word_count != word_count3, " << (word_count != word_count3) << endl;
    
    cout << endl;
    
    cout << "word_count <= word_count2, " << (word_count <= word_count2) << endl;
    cout << "word_count >= word_count2, " << (word_count >= word_count2) << endl;
    cout << "word_count < word_count3, " << (word_count < word_count3) << endl;
    cout << "word_count < word_count4, " << (word_count < word_count4) << endl;
}



#endif /* pair_practice_h */
