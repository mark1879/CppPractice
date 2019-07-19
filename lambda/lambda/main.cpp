//
//  main.cpp
//  Lambda
//
//  Created by MarkWu on 2019/7/19.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>

using namespace std;

class Line
{
public:
    Line(unsigned int length)
    {
        length_ = length;
    }
    
    unsigned int GetLength() const
    {
        return length_;
    }
    
    void SetLength(unsigned int length)
    {
        length_ = length;
    }
    
    void TestLambda()
    {
        auto print_value = [this] { cout << "length: " << length_ << endl; };
        
        this->length_ = 101;
        
        print_value();
    }
    
private:
    unsigned int length_;
    
};

int main(int argc, const char * argv[])
{
    Line line(10);
    
    line.TestLambda();
    
    return 0;
}
