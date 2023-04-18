//
//  emplace_back.hpp
//  SequentialContainers
//
//  Created by MarkWu on 2020/1/9.
//  Copyright © 2020 Zego. All rights reserved.
//

#ifndef emplace_back_h
#define emplace_back_h

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct A
{
    int x;
    double y;
    A(int a, double b):x(a),y(b){}
    
};

void using_emplace_back()
{
    vector<A> v;
    v.emplace_back(1, 2);
    cout << "size of vector: " << v.size() << endl << endl;
}

struct Complicated
{
    int year;
    double county;
    std::string name;
    
    Complicated(int a, double b, std::string c):year(a), county(b), name(c)
    {
        cout << "is constructed" << endl;
    }
    
    Complicated(const Complicated& other): year(other.year), county(other.county), name(std::move(other.name))
    {
        cout << "is moved" << endl;
    }
};

void performance_of_emplace_back()
{
    int anInt = 4;
    double aDouble = 5.0;
    std::string aString = "C++";
    
    std::map<int, Complicated> m;
    cout << "--map insert--" << endl;
    m.insert(std::make_pair(4, Complicated(anInt, aDouble, aString)));
    
    cout << "\n--map emplace--" << endl;
    m.emplace(4, Complicated(anInt, aDouble, aString));
    
    vector<Complicated> v;
    cout << "\n--vector emplace_back--" << endl;
    v.emplace_back(anInt, aDouble, aString);
    
    cout << "\n--vector push_back--" << endl;
    v.push_back(Complicated(anInt, aDouble, aString));
    
    cout << "\n--done--" << endl;
}

#endif /* emplace_back_h */
