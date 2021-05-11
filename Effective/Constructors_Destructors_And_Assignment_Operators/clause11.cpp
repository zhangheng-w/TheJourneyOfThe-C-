/*
by author heng  20-11-25
在operator=中处理“自我赋值” p53

1、确保当对象自我赋值时operator-有良好行为。其中技术包括比较“来源对象“和”目标对象“的地址
   精心周到的语句顺序，以及copy-and-swap
2、确认任何函数如果操作一个以上的对象，而其中多个对象是同一对象时，其行为仍然正确
*/

#include <iostream>
using namespace std;

class Bitmap {
public :
    Bitmap() {}
    Bitmap(const Bitmap& b) {}

};

class Widget {
public :

    Widget(Bitmap* bp) : _bp(bp) {}
    Widget(const Widget& rhs) { _bp = rhs._bp; }
    Widget& operator=(const Widget& rhs) {
        //&rhs == this
        if (this == &rhs) return *this;
        delete _bp;
        _bp = new Bitmap(*rhs._bp);
        
        /*
        Bitmap* _pOrig = _bp;
        _bp = new Bitmap(*rhs._bp);
        delete _pOrig;
        return *this;*/

        /* Widget temp(rhs);
        swap(temp);
        return *this; */
    }

    Bitmap* bp() const { return _bp; }
    void swap(Widget& rhs) {  }

private :
    Bitmap* _bp;
};

void widgetTest() {
    Bitmap b1;
    //Bitmap *p = &b1;
    cout << "Bitmap Address: " << &b1 << "\n";
    Widget w1(&b1);
    cout << "Widget Address: " << &w1 << "\n";
    cout << "Widget In Bitmap Address: " << w1.bp() << "\n";
    w1=w1;

}

int main(int agrc, char const *agrv[] ) {
    widgetTest();
    return 0;
}
