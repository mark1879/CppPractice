//
//  virtual_table.hpp
//  ObjectOriented
//
//  Created by MarkWu on 2022/11/5.
//

#ifndef virtual_table_hpp
#define virtual_table_hpp

#include <iostream>

using namespace std;

namespace VirtuallTable {

class Base {
public:
    Base() {
        cout << "Base()" << endl;
    }
    
    ~Base() {
        cout << "~Base()" << endl;
    }
    
    virtual void f() { cout << "Base::f" << endl; }
    virtual void g() { cout << "Base::g" << endl; }
    virtual void h() { cout << "Base::h" << endl; }
    void k() { cout << "Base::k" << endl;}
};

class Base1 {
public:
    virtual void f1() { cout << "Base1::f1" << endl; }
    virtual void g1() { cout << "Base1::g1" << endl; }
    virtual void h1() { cout << "Base1::h1" << endl; }
};

class Base2 {
public:
    virtual void f2() { cout << "Base2::f2" << endl; }
    virtual void g2() { cout << "Base2::g2" << endl; }
    virtual void h2() { cout << "Base2::h2" << endl; }
};


typedef void(*Fun)(void);

void TestBase() {
    Base b;
    cout << "虚函数表地址：" << (long*)(&b) << endl;
   
    // Invoke the first virtual function
    for (int i = 0; i < 3; i++) {
        Fun pFun = (Fun)*((long*)*(long*)(&b) + i);
        pFun();
    }
}

// 一般继承（无虚函数覆盖）
class SingleNoCover : Base {
public:
    SingleNoCover() {
        cout << "SingleNoCover()" << endl;
    }
    
    ~SingleNoCover() {
        cout << "~SingleNoCover()" << endl;
    }
    
    virtual void f_s_no_cover() { cout << "SingleNoCover::f_s_no_cover" << endl; }
    virtual void g_s_no_cover() { cout << "SingleNoCover::g_s_no_cover" << endl; }
    virtual void h_s_no_cover() { cout << "SingleNoCover::h_s_no_cover" << endl; }
};

void TestSingleNoCover() {
    SingleNoCover single_no_cover;
    cout << "虚函数表地址：" << (long*)(&single_no_cover) << endl;
    
    for (int i = 0; i < 6; i++) {
        Fun pFun = (Fun)*((long*)*(long*)(&single_no_cover) + i);
        pFun();
    }
}

// 一般继承（有虚函数覆盖）
class SingleCover : Base {
public:
    virtual void f() { cout << "SingleCover::f" << endl; }
    virtual void g_s_cover() { cout << "SingleCover::g_s_cover" << endl; }
    virtual void h_s_cover() { cout << "SingleCover::h_s_cover" << endl; }
};

void TestSingleCover() {
    SingleCover cover;
    cout << "虚函数表地址：" << (long*)(&cover) << endl;
    
    for (int i = 0; i < 5; i++) {
        Fun pFun = (Fun)*((long*)*(long*)(&cover) + i);
        pFun();
    }
}


//多重继承（无虚函数覆盖）
class MultipleNoCover : public Base, Base1  {
public:
    virtual void f_m_no_cover() { cout << "MultipleNoCover::f_m_no_cover" << endl; }
    virtual void g_m_no_cover() { cout << "MultipleNoCover::g_m_no_cover" << endl; }
    virtual void h_m_no_cover() { cout << "MultipleNoCover::h_m_no_cover" << endl; }
};

void TestMultipleNoCover() {
    MultipleNoCover d;
//    long** pVtab = (long**)&d;
    
    cout << endl << "<<<<<< line1: " << endl;
    
    Fun pFun = NULL;
    pFun = (Fun)*((long*)*(long*)((long*)&d+0)+0);
//   pFun = (Fun)pVtab[0][0];
   pFun();
   pFun = (Fun)*((long*)*(long*)((long*)&d+0)+1);
//   pFun = (Fun)pVtab[0][1];
   pFun();
   pFun = (Fun)*((long*)*(long*)((long*)&d+0)+2);
//   pFun = (Fun)pVtab[0][2];
   pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)&d+0)+3);
    pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)&d+0)+4);
    pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)&d+0)+5);
    pFun();
    
    cout << endl << "<<<<<< line2:" << endl;
    
    pFun = (Fun)*((long*)*(long*)((long*)&d+1)+0);
//   pFun = (Fun)pVtab[1][0];
   pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)&d+1)+1);
//   pFun = (Fun)pVtab[1][1];
   pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)&d+1)+2);
//   pFun = (Fun)pVtab[1][2];
   pFun();
}

//多重继承（无虚函数覆盖）
class MultipleCover : public Base, Base1, Base2 {
public:
    virtual void f() { cout << "MultipleCover::f" << endl; }
    virtual void f1() { cout << "MultipleCover::f1" << endl; }
    virtual void f2() { cout << "MultipleCover::f2" << endl; }
    virtual void g_m_cover() { cout << "MultipleCover::g_m_cover" << endl; }
    virtual void h_m_cover() { cout << "MultipleCover::h_m_cover" << endl; }
    
    void k() { cout << "MultipleCover::k" << endl;}
};

void TestMultipleCover() {
    MultipleCover d;
//    long** pVtab = (long**)&d;
    
    cout << endl << "<<<<<< line1: " << endl;
    
    Fun pFun = NULL;
    pFun = (Fun)*((long*)*(long*)((long*)&d+0)+0);
//   pFun = (Fun)pVtab[0][0];
   pFun();
   pFun = (Fun)*((long*)*(long*)((long*)&d+0)+1);
//   pFun = (Fun)pVtab[0][1];
   pFun();
   pFun = (Fun)*((long*)*(long*)((long*)&d+0)+2);
//   pFun = (Fun)pVtab[0][2];
   pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)&d+0)+3);
    pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)&d+0)+4);
    pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)&d+0)+5);
    pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)&d+0)+6);
    pFun();
    
    cout << endl << "<<<<<< line2: " << endl;
    
    pFun = (Fun)*((long*)*(long*)((long*)&d+1)+0);
//   pFun = (Fun)pVtab[1][0];
   pFun();

    pFun = (Fun)*((long*)*(long*)((long*)&d+1)+1);
//   pFun = (Fun)pVtab[1][1];
   pFun();

    pFun = (Fun)*((long*)*(long*)((long*)&d+1)+2);
//   pFun = (Fun)pVtab[1][2];
   pFun();
    
    cout << endl << "<<<<<< line3: " << endl;
    
    pFun = (Fun)*((long*)*(long*)((long*)&d+2)+0);
//   pFun = (Fun)pVtab[1][0];
   pFun();

    pFun = (Fun)*((long*)*(long*)((long*)&d+2)+1);
//   pFun = (Fun)pVtab[1][1];
   pFun();

    pFun = (Fun)*((long*)*(long*)((long*)&d+2)+2);
//   pFun = (Fun)pVtab[1][2];
   pFun();
}

void TestVirtualVisit() {
    Base* base = new MultipleCover();
//    base->f();
//    base->g();
//    base->k();
    
    Fun pFun = NULL;
    pFun = (Fun)*((long*)*(long*)((long*)base+0)+0);
    pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)base+0)+1);
    pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)base+0)+2);
    pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)base+0)+3);
    pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)base+0)+4);
    pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)base+0)+5);
    pFun();
    
    pFun = (Fun)*((long*)*(long*)((long*)base+0)+6);
    pFun();
    
    cout << "<<<<<<" << endl;
    
    pFun = (Fun)*((long*)*(long*)((long*)base+1)+0);
//   pFun = (Fun)pVtab[1][0];
   pFun();

    pFun = (Fun)*((long*)*(long*)((long*)base+1)+1);
//   pFun = (Fun)pVtab[1][1];
   pFun();

    pFun = (Fun)*((long*)*(long*)((long*)base+1)+2);
//   pFun = (Fun)pVtab[1][2];
   pFun();
    
    cout << "<<<<<<" << endl;
    
    pFun = (Fun)*((long*)*(long*)((long*)base+2)+0);
//   pFun = (Fun)pVtab[1][0];
   pFun();

    pFun = (Fun)*((long*)*(long*)((long*)base+2)+1);
//   pFun = (Fun)pVtab[1][1];
   pFun();

    pFun = (Fun)*((long*)*(long*)((long*)base+2)+2);
//   pFun = (Fun)pVtab[1][2];
   pFun();

}

};


//int main() {
//    VirtuallTable::TestBase();
//    VirtuallTable::TestSingleNoCover();
//    VirtuallTable::TestSingleCover();

//    VirtuallTable::TestMultipleNoCover();

//    VirtuallTable::TestMultipleCover();
//    TestVirtualVisit();
//
//    return 0;
//}

#endif /* virtual_table_h */
