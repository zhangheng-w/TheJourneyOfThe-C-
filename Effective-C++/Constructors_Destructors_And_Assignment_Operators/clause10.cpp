/*
by author heng  20-11-24
令operator= 返回一个reference to *this p52

1、令赋值(assignment)操作符返回一个reference to *this
*/

#include <iostream>
using namespace std;

class Widget {
public :
    Widget() : _num(0) {}
    Widget(const int& num) : _num(num) {}
    Widget& operator=(const Widget& rhs) { 
        _num = rhs._num;
        return *this;
    }

    Widget& operator+=(const Widget& rhs) {
        _num += rhs._num;
        return *this;
    }

    int num() const { return _num; }

private :
    int _num;
};

void widgetTest() {
    Widget w1(11);
    Widget w2 = w1;
    Widget w3(12);
    w3 += w1;
    cout << w1.num() << "\n"
         << w2.num() << "\n"
         << w3.num();
}

int main(int argc, char const *argv[]){
     widgetTest();
    return 0;
}


