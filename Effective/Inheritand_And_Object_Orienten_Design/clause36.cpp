/*
 * Created by weyiua on 2021/6/19.
 * 36. 绝不重新定义继承而来的non-virtual函数
 * * 适用于B对象的每一件事，也适用于D对象，因为每一个D对象都是一个B对象
 * * B的derived class一定会继承mf的接口和实现，因为mf是B的一个non-virtual函数
 *
 * 绝对不要重新定义继承而来的non-virtual函数
 */

#include <iostream>
using namespace std;

class B {
public:
    void mf() { cout << "B::mf()\n"; }
};

class D : public B {

    void mf() { cout << "D::mf()\n"; }
};

void testOne() {
    D x;
    B* pb = &x;
    pb->mf();
    D* pd = &x;
    //pd->mf(); err BD都定义了non-virtual函数mf 造成报错
}

//public继承意味is-a(是一种)的关系

int main(int agrc, const char *agrv[]) {
    testOne();
    return 0;
}