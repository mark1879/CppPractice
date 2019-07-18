//
//  polymorphism_practice.hpp
//  BasicKnowledge
//
//  Created by MarkWu on 2018/2/11.
//  Copyright © 2018年 Zego. All rights reserved.
//

#ifndef polymorphism_practice_h
#define polymorphism_practice_h

namespace POLYMORPHISM {
    class Shape {
    protected:
        int width, height;
    public:
        Shape( int a=0, int b=0)
        {
            width = a;
            height = b;
        }
        virtual int area()
        {
            cout << "Parent class area :" <<endl;
            return 0;
        }
        
        virtual int area2() = 0;
    };
    class Rectangle: public Shape{
    public:
        Rectangle( int a=0, int b=0):Shape(a, b) { }
        int area () override
        {
            cout << "Rectangle class area :" <<endl;
            return (width * height);
        }
        int area2() override
        {
            return -1;
        }
    };
    class Triangle: public Shape{
    public:
        Triangle( int a=0, int b=0):Shape(a, b) { }
        int area () override
        {
            cout << "Triangle class area :" <<endl;
            return (width * height / 2);
        }
        int area2() override
        {
            return -1;
        }
    };
    
    void test_poly_morphism()
    {
        Shape *shape;
        Rectangle rec(10,7);
        Triangle  tri(10,5);
        
        //    抽象类不能创建对象
        //    Shape shape1 = rec;
        //    shape1.area();
        
        Shape *shape2 = &rec;
        shape2->area();
        
        Shape& shape3 = rec;
        shape3.area();
        
        // store the address of Triangle
        shape = &tri;
        // call triangle area.
        shape->area();
    }
};

#endif /* polymorphism_practice_h */
