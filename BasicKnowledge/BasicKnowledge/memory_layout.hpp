//
//  memory_layout.hpp
//  BasicKnowledge
//
//  Created by MarkWu on 2018/2/19.
//  Copyright © 2018年 Zego. All rights reserved.
//

#ifndef memory_layout_h
#define memory_layout_h

class Parent {
public:
    int iparent;
    Parent ():iparent (10) {}
    virtual void f() { cout << " Parent::f()" << endl; }
    virtual void g() { cout << " Parent::g()" << endl; }
    virtual void h() { cout << " Parent::h()" << endl; }
    
};

class Child : public Parent {
public:
    int ichild;
    Child():ichild(100) {}
    virtual void f() { cout << "Child::f()" << endl; }
    virtual void g_child() { cout << "Child::g_child()" << endl; }
    virtual void h_child() { cout << "Child::h_child()" << endl; }
};

class GrandChild : public Child{
public:
    int igrandchild;
    GrandChild():igrandchild(1000) {}
    virtual void f() { cout << "GrandChild::f()" << endl; }
    virtual void g_child() { cout << "GrandChild::g_child()" << endl; }
    virtual void h_grandchild() { cout << "GrandChild::h_grandchild()" << endl; }
};

void test_memory_layout()
{
    typedef void(*Fun)(void);

    GrandChild gc;
    Fun pFun = NULL;
    
    long** pVtab = (long**)&gc;
    
    for (int i=0; (Fun)pVtab[0][i] != nullptr; i++){
        if ( i >= 6) break;
        cout <<" [" << i << "] 0x"<< hex << pVtab[0][i] <<  endl;
        pFun = (Fun)pVtab[0][i];
        pFun();
    }
    cout << dec << endl;
    
    cout << "[1] Parent.iparent = " << *((int *)(pVtab + 1)) << endl;
    cout << "[2] Child.ichild = " << *((int *)(pVtab + 1) + 1) << endl;
    cout << "[3] GrandChild.igrandchild = " << *((int *)(pVtab + 1) + 2) << endl << endl;
}

#endif /* memory_layout_h */
