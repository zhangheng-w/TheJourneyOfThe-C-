/*
 * Created by he on 2021/2/5.
 *
 * 1、Derived class类的名称会遮掩 Base class内的名称。 在 public 继承下从来没有人希望如此
 * 2、为了让被遮掩的名称重见天日，可使用 using 声明式或转交函数
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

    //让Base中mf1 和 mf3 所有可见
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

