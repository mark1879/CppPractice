//
//  base.hpp
//  ObjectOriented
//
//  Created by MarkWu on 2022/11/21.
//

#ifndef base_class_hpp
#define base_class_hpp

namespace  DeriveTest {

typedef void(*Fun)(void);

class Base {
public:
    int base_a_;
    
public:
    Base(int a) : base_a_(a) {
        cout << "Base() " << endl;
        cout << "this: " << this << endl;
        cout << "*this: " << (*(long *)this) << endl << endl;
    }
    
    ~Base() {
        cout << "~Base()" << endl;
    }
    
    virtual void Show() {
        cout << "Base Show()" << endl;
    }

    virtual void Show(int a) {
        cout << "Base Show(int), " << a << endl;
    }
};

class Derive : public Base {
public:
    Derive(int a) : Base(a / 2), derive_a_(a) {
        cout << "Derive()" << endl;
        cout << "this: " << this << endl;
        cout << "*this: " <<(*(long *)this) << endl << endl;
    }
    
    ~Derive() {
        cout << "~Derive()" << endl;
    }
    
    void Show() override {
        cout << "Derive Show()" << endl;
    }

    virtual void ShowD()  {
        cout << "Derive ShowD()" << endl;

    }
    
public:
    int derive_a_;
};

class Derive2 : public Derive {
public:
    Derive2(int a) : Derive(a / 2), derive2_a_(a) {
        cout << "Derive2()" << endl;
        cout << "this: " << this << endl;
        cout << "*this: " <<(*(long *)this) << endl << endl;
    }
    
    ~Derive2() {
        cout << "~Derive2()" << endl;
    }

    void ShowD() override {
        cout << "Derive2 ShowD()" << endl;
    }
    
public:
    int derive2_a_;
//    char test_[20];
};

};

using namespace DeriveTest;

void TestVisit() {
    Base base(100);
    base.Show();

    Derive derive(50);
    derive.Show();

    Base* pb = &base;
    pb->Show();

    Base* pb2 = &derive;
    pb2->Show();


    Base& bref = base;
    bref.Show();

    Base& bref2 = derive;
    bref2.Show();


    Derive* pd = &derive;
    pd->Show();

    Derive& dref = derive;
    dref.Show();
}

void DoubleDerive() {
    Base* pb = new Derive(100);
    
    for (int i = 0; i < 2; i++) {
        Fun pFun = (Fun)*((long*)*(long*)(pb) + i);
        pFun();

        printf(">>>>> %lx\n", *((long*)*(long*)(pb) + i));
    }
    
    delete pb;
}

void TestMembersMemory() {
    Base* pb = new Derive(100);

    int *p1 = (int *)((long *)pb + 1);
    cout << p1[0] << endl;
    cout << p1[1] << endl;
     
    delete pb;
}

void TrippleDerive() {
    Base* pb = new Derive2(100);
    
    for (int i = 0; i < 4; i++) {
        Fun pFun = (Fun)*((long*)*(long*)(pb) + i);
        pFun();
    }
}

//int main() {
//    
//    
//    
//    return 0;
//}




#endif /* base_h */
