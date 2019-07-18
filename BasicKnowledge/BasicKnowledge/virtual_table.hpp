//
//  virtual_table.hpp
//  BasicKnowledge
//
//  Created by MarkWu on 2018/2/13.
//  Copyright © 2018年 Zego. All rights reserved.
//

#ifndef virtual_table_h
#define virtual_table_h

class BaseA{
public:
    virtual void f() { cout << "BaseA::f" << endl; }
    virtual void g() { cout << "BaseA::g" << endl; }
};

class BaseB {
public:
    virtual void f1() { cout << "BaseB::f1" << endl; }
    virtual void g1() { cout << "BaseB::g1" << endl; }
};

class ChildA : public BaseA, BaseB
{
public:
    void f() override { cout << "ChildA::f" << endl; }
    void f1() override {cout << "ChildA::f1" << endl; }
    void g1() override { cout << "ChildA::g1" << endl; }
    virtual void k() { cout << "ChildA::k" << endl; }
};

typedef void(*Fun)(void);

void test_virtual_table()
{
    ChildA childa;
    
    cout << "虚函数表地址：" << (long*)(&childa) << endl;
    cout << "虚函数表 — 第一个函数地址：" << (long*)*(long*)(&childa) << endl;
    
    ((Fun)*((long *)*(long *)(&childa) + 0))();
    ((Fun)*((long *)*(long *)(&childa) + 1))();
    ((Fun)*((long *)*(long *)(&childa) + 2))();
    ((Fun)*((long *)*(long *)(&childa) + 3))();
    ((Fun)*((long *)*(long *)(&childa) + 4))();
    
    ((Fun)*((long *)*((long *)(&childa) + 1) + 0))();
    ((Fun)*((long *)*((long *)(&childa) + 1) + 1))();
    
    //    // 突破编译限制
    //    BaseA *base = new ChildA();
    //    long * temp = (long *)*(long *)base + 2;
    //    ((Fun) * temp)();
}

#endif /* virtual_table_h */
