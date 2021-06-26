/*
by author heng  20-11-25
��operator=�д������Ҹ�ֵ�� p53

1��ȷ�����������Ҹ�ֵʱoperator-��������Ϊ�����м��������Ƚϡ���Դ���󡰺͡�Ŀ����󡰵ĵ�ַ
   �����ܵ������˳���Լ�copy-and-swap
2��ȷ���κκ����������һ�����ϵĶ��󣬶����ж��������ͬһ����ʱ������Ϊ��Ȼ��ȷ
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
