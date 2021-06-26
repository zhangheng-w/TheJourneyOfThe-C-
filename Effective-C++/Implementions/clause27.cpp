/*
by author heng  20-12-02
��������ת�Ͷ���

1��������ԣ���������ת�ͣ��ر�����ע��Ч�ʵĴ����б���dynamic_cast 
2�����ת���Ǳ�Ҫ�ģ��Խ���������ĳ���������󡣿ͻ������øú����������轫ת�ͷŽ����ǵĴ�����
3������ʹ��C++styleת�ͣ���Ҫʹ�þ�ʽת��
*/

#include <iostream>
#include <vector>
#include <memory>
using namespace std;


/*
const_cast<T> (expression)                 ������������ĳ�����ת��
dynamic_cast<T> (expression)               ��ȫ����ת��
reinterpret_cast<T> (expression)           ִ�����ת��
static_cast<T> (expression)                ǿ����ʽת��
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
    doSomeWork(Widget(15));                 //��������ת��
    doSomeWork(static_cast<Widget>(15));    //C++ style

    int x = 3, y = 2;
    double d = static_cast<double>(x)/y;    //����������
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
    Base* pd = &d;           //������ת��  
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
        //static_cast<Window>(*this).onPesize();     //ת�ͣ�������ƭ������SpecialWindowΪWindow����
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
        if(SpecialWindow* psw = dynamic_cast<SpecialWindow*>(iter->get()) ) psw->onPesize();    //ת������
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