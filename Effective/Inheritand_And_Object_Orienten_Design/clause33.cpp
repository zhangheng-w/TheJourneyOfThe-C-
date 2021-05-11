/*
 * Created by he on 2021/2/5.
 *
 * 1��Derived class������ƻ����� Base class�ڵ����ơ� �� public �̳��´���û����ϣ�����
 * 2��Ϊ���ñ����ڵ������ؼ����գ���ʹ�� using ����ʽ��ת������
*/

#include <iostream>
using namespace std;

int x;
void someFunc() {
    double x;
    x = 1.1;
    cout << x << endl;
}

class Base {
private:
    int x;

public:
    virtual void mf1() = 0;
    virtual void mf1(int) {}
    virtual void mf2() { cout << "Base--mf2" << endl; }

    void mf3() {}
    void mf3(double) {}
};

class Derived : public Base {
public:

    //��Base��mf1 �� mf3 ���пɼ�
    using Base::mf1;
    using Base::mf3;

    virtual void mf1() { cout << "Derived--mf1" << endl; }
    void mf3() { cout << "Derived--mf2" << endl; }
    void mf4();
};

void Derived::mf4() {
    mf2();
}

void BaseAndDerivedTest() {
    Derived derived;
    int x = 0;
    derived.mf4();
    derived.mf1();
    derived.mf1(x);   //err
    derived.mf2();
    derived.mf3();
    derived.mf3(x);   //err
}


int main(int agrc, const char *agrv[]) {
    someFunc();
    BaseAndDerivedTest();
    return 0;
}

