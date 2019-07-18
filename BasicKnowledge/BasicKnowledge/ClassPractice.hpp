//
//  ClassPractice.hpp
//  BasicKnowledge
//
//  Created by MarkWu on 2018/2/3.
//  Copyright © 2018年 Zego. All rights reserved.
//

#ifndef ClassPractice_h
#define ClassPractice_h

namespace CLASSPRACTICE {
    class Shape
    {
    public:
        Shape(int width, int height) : m_nWidth(width), m_nHeight(height)
        {
            
        }
        //    {
        //        m_nWidth = width;
        //        m_nHeight = height;
        //    }
        
        void setWidth(int width)
        {
            m_nWidth = width;
        }
        
        void setHeight(int height)
        {
            m_nHeight = height;
        }
        
    protected:
        int m_nWidth;
        int m_nHeight;
    };
    
    //Shape::Shape(int width, int height) : m_nWidth(width), m_nHeight(height){}
    
    class PaintCost
    {
    public:
        int getCost(int area)
        {
            return area * 70;
        }
    };
    
    class Rectangle : public Shape, public PaintCost
    {
    public:
        Rectangle(int width, int height);
        int getArea()
        {
            return m_nWidth * m_nHeight;
        }
    };
    
    Rectangle::Rectangle(int width, int height):Shape(width, height)
    {
        
    }
}
#endif /* ClassPractice_h */
