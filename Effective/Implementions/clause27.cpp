/*
by author heng  20-12-02
尽量少做转型动作

1、如果可以，尽量避免转型，特别是在注重效率的代码中避免dynamic_cast 
2、如果转型是必要的，试将它隐藏在某个函数背后。客户随后调用该函数，而不需将转型放进他们的代码中
3、宁可使用C++style转型，不要使用旧式转型
*/

#include <iostream>
#include <vector>
#include <memory>
using namespace std;


/*
const_cast<T> (expression)                 被用来将对象的常量性转除
dynamic_cast<T> (expression)               安全向下转型
reinterpret_cast<T> (expression)           执意低型转型
static_cast<T> (expression)                强迫隐式转型
*/


class Widget {
public :
    explicit Widget(int size) : num(size) {}
    int getNum() const { return num; }

private :
    int num;
};

void doSomeWork(const Widget& w) {
    cout << w.getNum() << "\n";
}

void widgetTest() {
    doSomeWork(Widget(15));                 //函数风格的转型
    doSomeWork(static_cast<Widget>(15));    //C++ style

    int x = 3, y = 2;
    double d = static_cast<double>(x)/y;    //浮点数除法
    cout << d << "\n";
}


class Base { };
ostream& operator<<(ostream& out, const Base& b) {
    out << "Base Operator<<\n";
    return out;
}

class Derived : public Base { };
ostream& operator<<(ostream& out, const Derived& b) {
    out << "Derived Operator<<\n";
    return out;
}

void baseTest() {
    Derived d;
    Base* pd = &d;           //隐喻的转型  
    cout << d;
    cout << *pd;
}

class Window {
public :
    virtual void onPesize() { 
        cout << "Window the onPersize\n";
    }
};

class SpecialWindow : public Window {
public :
    virtual void onPesize() { 
        //static_cast<Window>(*this).onPesize();     //转型，不是欺骗编译器SpecialWindow为Window对象
        Window::onPesize();
        cout << "SpecialWindow the onPersize\n";
    }
    void blink() {}
};

typedef vector<shared_ptr<Window> > VPW;
typedef vector<shared_ptr<SpecialWindow> > VPSW;

void windowTest() {
    VPW winPtrs;
    for(VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter) {
        if(SpecialWindow* psw = dynamic_cast<SpecialWindow*>(iter->get()) ) psw->onPesize();    //转换类型
    }
    VPSW winPtrvs;
    for(VPSW::iterator iter = winPtrvs.begin(); iter != winPtrvs.end(); ++iter) {
        (*iter)->blink();
    }

    
}


int main(int agrc, char const *agrv[]) {
    widgetTest();
    baseTest();
    return 0;
}