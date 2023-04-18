//
//  initialize_list.hpp
//  ObjectOriented
//
//  Created by MarkWu on 2022/12/21.
//

#ifndef initialize_list_hpp
#define initialize_list_hpp

namespace InitializeList {
class Date {
public:
    Date(int y, int m, int d) : year_(y), month_(m), day_(d) { }
    
private:
    int year_;
    int month_;
    int day_;
};

class Product {
public:
    Product(const char* name, Date& date) : date_(date) {
        strcpy(name_, name);
    }
    
    Product(const char* name, int y, int m, int d) :
    date_(y, m, d) {
        strcpy(name_, name);
    }

private:
    char name_[128];
    Date date_;
};

class Test {
public:
    Test(int a) : b_(a), a_(b_) { }
    void Show() {
        cout << "a: " << a_ << ", b: " << b_ << endl;
    }
private:
    int a_;
    int b_;
};
};

using namespace InitializeList;

//int main() {
//    
////    Date date = {1988, 03, 27};
////    Product product("mark", date);
////
////    Product product2("mark2", 1988, 03, 14);
//    
//    Test test(10);
//    test.Show();
//
//    return 0;
//}


#endif /* initialize_list_h */
