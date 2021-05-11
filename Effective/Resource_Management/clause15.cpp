/*
by author heng  20-11-27
在资源管理类中提供对原始资源的访问


1、API往往要求访问原始资源（raw resources），所以每一个RAII class应该提供一个“取得其所管理之资源”的方法
2、对原始资源的访问可能经由显式转换或隐式转换，一般而言显式转换更为安全，但隐式转换对客户比较方便
*/
#include <memory>
#include <iostream>
using namespace std;


class Investment {
public :
    bool isTaxFree() const { return true; }
};

Investment* createInvestment() { return new Investment(); }

void test_1() {
    /*
    auto_ptr and shared_ptr 重载了operator-> and operator.
    允许隐式转换至指针底部
    */
    shared_ptr<Investment> pi1(createInvestment());
    bool taxable1 = !(pi1->isTaxFree());
    shared_ptr<Investment> pi2(pi1);
    bool taxable2 = !((*pi2).isTaxFree());
    cout << taxable1 << "\n" 
         << taxable2 << endl;
}


class FontHandle {

};


FontHandle getFont() { return FontHandle();};
void releaseFont(FontHandle fh) {}
void changeFontSize(FontHandle f, int newSize) {}

class Font {
public :
    explicit Font(FontHandle fh) : _f(fh) {}
    ~Font() { releaseFont(_f); }
    FontHandle get() const { return _f; }
    operator FontHandle() const { return _f; }

private :
    FontHandle _f;
};


void test_2() {
    Font f(getFont());
    int newFontSize = 100;
    changeFontSize(f.get(), newFontSize);     //显式转换
    changeFontSize(f, newFontSize);           //将Font隐式转换为FontHandle
    //Font fcopy = f;                           //??
    FontHandle fh = f;
}


int main(int agrc, char const *agrv[]) {
    test_1();
    test_2();
    return 0;
}

