/*
by author heng  20-11-27
����Դ���������ṩ��ԭʼ��Դ�ķ���


1��API����Ҫ�����ԭʼ��Դ��raw resources��������ÿһ��RAII classӦ���ṩһ����ȡ����������֮��Դ���ķ���
2����ԭʼ��Դ�ķ��ʿ��ܾ�����ʽת������ʽת����һ�������ʽת����Ϊ��ȫ������ʽת���Կͻ��ȽϷ���
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
    auto_ptr and shared_ptr ������operator-> and operator.
    ������ʽת����ָ��ײ�
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
    changeFontSize(f.get(), newFontSize);     //��ʽת��
    changeFontSize(f, newFontSize);           //��Font��ʽת��ΪFontHandle
    //Font fcopy = f;                           //??
    FontHandle fh = f;
}


int main(int agrc, char const *agrv[]) {
    test_1();
    test_2();
    return 0;
}

