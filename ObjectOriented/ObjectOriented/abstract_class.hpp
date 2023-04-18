//
//  abstract_class.hpp
//  ObjectOriented
//
//  Created by MarkWu on 2022/12/5.
//

#ifndef abstract_class_hpp
#define abstract_class_hpp
#include <iostream>

using namespace std;

namespace AbstractClass {

class Base {
public:
    Base() {
        cout << "Base()" << endl;
    }
    
    virtual ~Base() {
        cout << "~Base()" << endl;
    }
    
    void NonVirtualFunc() {
        cout << "Base::NonVirtualFunc()" << endl;
    }
    
    virtual void VirtualFunc() {
        cout << "Base::VirtualFunc()" << endl;
    }
    
    virtual void PureVirtualFunc() = 0;
    
protected:
    std::string name_ = "Test Abstract Class";
};

class Derive : public Base {
public:
    Derive() {
        cout << "Derive()" << endl;
    }
    
    ~Derive() {
        cout << "~Derive()" << endl;
    }
    
    void VirtualFunc() override {
        cout << "Derive::VirtualFunc()" << endl;
    }
    
    void PureVirtualFunc() override {
        cout << "Derive::PureVirtualFunc()" << endl;
    }
};

};


//int main() {
//    
//    AbstractClass::Base* pb = new AbstractClass::Derive();
//    pb->NonVirtualFunc();
//    pb->VirtualFunc();
//    pb->PureVirtualFunc();
//    
//    delete pb;
//    
//    return 0;
//}


#endif /* abstract_class_h */
